/*******************************************************************************/
/*  © Université Lille 1, The Pip Development Team (2015-2016)                 */
/*                                                                             */
/*  This software is a computer program whose purpose is to run a minimal,     */
/*  hypervisor relying on proven properties such as memory isolation.          */
/*                                                                             */
/*  This software is governed by the CeCILL license under French law and       */
/*  abiding by the rules of distribution of free software.  You can  use,      */
/*  modify and/ or redistribute the software under the terms of the CeCILL     */
/*  license as circulated by CEA, CNRS and INRIA at the following URL          */
/*  "http://www.cecill.info".                                                  */
/*                                                                             */
/*  As a counterpart to the access to the source code and  rights to copy,     */
/*  modify and redistribute granted by the license, users are provided only    */
/*  with a limited warranty  and the software's author,  the holder of the     */
/*  economic rights,  and the successive licensors  have only  limited         */
/*  liability.                                                                 */
/*                                                                             */
/*  In this respect, the user's attention is drawn to the risks associated     */
/*  with loading,  using,  modifying and/or developing or reproducing the      */
/*  software by the user in light of its specific status of free software,     */
/*  that may mean  that it is complicated to manipulate,  and  that  also      */
/*  therefore means  that it is reserved for developers  and  experienced      */
/*  professionals having in-depth computer knowledge. Users are therefore      */
/*  encouraged to load and test the software's suitability as regards their    */
/*  requirements in conditions enabling the security of their systems and/or   */
/*  data to be ensured and,  more generally, to use and operate it in the      */
/*  same conditions as regards security.                                       */
/*                                                                             */
/*  The fact that you are presently reading this means that you have had       */
/*  knowledge of the CeCILL license and that you accept its terms.             */
/*******************************************************************************/


/* Standard includes. */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* FreeRTOS includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "timers.h"

/* Standard demo includes. */
#include "blocktim.h"
#include "flash_timer.h"
#include "semtest.h"
#include "GenQTest.h"
#include "QPeek.h"
#include "countsem.h"
#include "dynamic.h"
#include "QueueOverwrite.h"
#include "QueueSet.h"
#include "recmutex.h"
#include "EventGroupsDemo.h"
#include "death.h"
#include "TimerDemo.h"
#include "BlockQ.h"
#include "flop.h"
#include "TaskNotify.h"
#include "IntQueue.h"
#include "service.h"
#include "queue.h"


#include "task.h"
#include <pip/fpinfo.h>
#include <pip/debug.h>
#include <pip/paging.h>
#include <pip/compat.h>








/*f a [potential] error has been detected.  Increasing the toggle rate in the
presense of an error gives visual feedback of the system status. */
#define mainNO_ERROR_CHECK_TASK_PERIOD      pdMS_TO_TICKS( 5000UL )
#define mainERROR_CHECK_TASK_PERIOD         pdMS_TO_TICKS( 1000UL )

/* The priorities of the various demo application tasks. */
#define mainSEM_TEST_PRIORITY               ( tskIDLE_PRIORITY + 1 )
#define mainBLOCK_Q_PRIORITY                ( tskIDLE_PRIORITY + 1 )
#define mainGEN_QUEUE_TASK_PRIORITY         ( tskIDLE_PRIORITY )
#define mainQUEUE_OVERWRITE_TASK_PRIORITY   ( tskIDLE_PRIORITY )
#define mainMATHS_TASK_PRIORITY             ( tskIDLE_PRIORITY )

/* The base period used by the timer test tasks. */
#define mainTIMER_TEST_PERIOD               ( 50 )

/* Parameters that are passed into the check tasks for no other purpose other
* than to check the port does this correctly. */
#define mainREG_TEST_1_PARAMETER            ( 0x12345678UL )
#define mainREG_TEST_2_PARAMETER            ( 0x87654321UL )

/*-----------------------------------------------------------*/

/*
*  * The function that implements the check task, as described at the top of this
*   * file.
*    */
static void prvCheckTask( void *pvParameters );

/*
*  * Entry points for the register check tasks, as described at the top of this
*   * file.
*    */
static void prvRegTest1Entry( void *pvParameters );
static void prvRegTest2Entry( void *pvParameters );

/*
 * Perform any hardware/peripheral related initialisation necessary to run the
 * demo.
 */
static void prvSetupHardware( void );

/*
*  * The implementation of the register check tasks, which are implemented in
*   * RegTest.S.  These functions are called by prvRegTest1Entry() and
*    * prvRegTest2Entry() respectively.
*     */
/*-----------------------------------------------------------*/

/* Constants used by the register check tasks when checking the FPU registers. */
const double dRegTest1_st7 = 7.0, dRegTest1_st6 = 6.0, dRegTest1_st5 = 5.0, dRegTest1_st4 = 4.0, dRegTest1_st3 = 3.0, dRegTest1_st2 = 2.0, dRegTest1_st1 = 1.0;
const double dRegTest2_st7 = 700.0, dRegTest2_st6 = 600.0, dRegTest2_st5 = 500.0, dRegTest2_st4 = 400.0, dRegTest2_st3 = 300.0, dRegTest2_st2 = 200.0, dRegTest2_st1 = 100.0;

/* Counters used by the register check tasks to indicate that they are still
* executing without having discovered any errors. */
volatile uint32_t ulRegTest1Counter, ulRegTest2Counter;
volatile uint32_t ulCheckLoops = 0;






extern void* _partition1, *_epartition1;
extern void* _partition2, *_epartition2;
extern void* _partition3, *_epartition3;
extern void* _partition4, *_epartition4;
extern void* _partition5, *_epartition5;

static const struct {uint32_t start, end;} part1 = {
	(uint32_t)&_partition1, (uint32_t)&_epartition1,
};


static const struct {uint32_t start, end;} part2 = {
	(uint32_t)&_partition2, (uint32_t)&_epartition2,
};

static const struct {uint32_t start, end;} part3 = {
	(uint32_t)&_partition3, (uint32_t)&_epartition3,
};

static const struct {uint32_t start, end;} part4 = {
	(uint32_t)&_partition4, (uint32_t)&_epartition4,
};

static const struct {uint32_t start, end;} part5 = {
	(uint32_t)&_partition5, (uint32_t)&_epartition5,
};

void parse_bootinfo(pip_fpinfo* bootinfo)
{
	if(bootinfo->magic == FPINFO_MAGIC)
	printf("\tBootinfo seems to be correct.\r\n");
	else {
		printf("\tBootinfo is invalid. Aborting.\r\n");
	}


	printf("\tAvailable memory starts at 0x%x and ends at 0x%x\r\n",(uint32_t)bootinfo->membegin,      (uint32_t)bootinfo->memend);


	printf("\tPip revision %s\r\n",bootinfo->revision);
	return;
}

void main()
{

    pip_fpinfo * bootinfo = (pip_fpinfo*)0xFFFFC000;
	printf("Hello I'm FreeRTOS\r\n");
	printf("We're going to start the Real-time \r\n");

	//Get Bootinfo for the available memory
	parse_bootinfo(bootinfo);

	//Initialize the avaible pages
	uint32_t paging = initPaging((void*)bootinfo->membegin,(void*)bootinfo->memend);
	//Creating protected domains

	printf("Finished initialisation\r\n");
	vTaskStartScheduler();
	for(;;);
}


void vApplicationMallocFailedHook(){
	return ;
}

void vAssertCalled(const char * file, unsigned long line){
}
