```C
/*******************************************************************************/
/*  © Université Lille 1, The Pip Development Team (2015-2017)                 */
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

#include <stdint.h>
#include <pip/fpinfo.h>
#include <pip/paging.h>
#include <pip/vidt.h>
#include <pip/api.h>
#include <pip/compat.h>

extern int printf(const char *c,...);
#define returnServiceAddress 0x801000
 struct xQueueCreateParameters_s {
   uint32_t lenght;
   uint32_t size_type;
   uint32_t returnCall;
 };
typedef struct xQueueCreateParameters_s xQueueCreateParameters;



struct xQueueSendParameters_s {
  uint32_t queue;
  uint32_t * itemToQueue;
  uint32_t tickToWait;
};
typedef struct xQueueSendParameters_s xQueueSendParameters;



struct xQueueReceiveParameters_s {
  uint32_t queue;
  uint32_t * bufferReceive;
  uint32_t tickToWait;
};

struct sbrkService{
  uint32_t size;
  uint32_t begin;
};
typedef struct xQueueReceiveParameters_s xQueueReceiveParameters;

INTERRUPT_HANDLER(serviceRoutineAsm,serviceRoutine)
  printf("Service routing return\r\n");
  printf("Data from service at %x",data1);

END_OF_INTERRUPT

//


struct AMessage
 {
    char ucMessageID;
    char ucData[ 20 ];
 } xMessage;


struct comCanal
{
  uint32_t numberOfChannels;
  uint32_t * listOfChannel;
};

uint32_t returnAddr;
void main()
{

    // FreeRTOS gave us more memory pages at 0x904000
    uint32_t paging = initPaging((void*)0x904000,(void*)(0x904000+(100*0x1000)));

    // We create differents services structures.
    xQueueCreateParameters * createArgs = (xQueueCreateParameters*) allocPage(); //Queue create
    xQueueSendParameters * sendArgs = (xQueueSendParameters*) allocPage(); // Queue send
    xQueueReceiveParameters * recArgs = (xQueueReceiveParameters*) allocPage(); // que receive

    // we create a simple message structre, for queue send
    struct AMessage *pxMessage = (struct AMessage*) allocPage();
    // we create a simple message structre, for queue receive
    struct AMessage *pxReceive = (struct AMessage*) allocPage();
    // we create a simple sbrk service structre, for more memory from the parent
    struct sbrkService * sbrkD = (struct sbrkService*) allocPage();
    // we create a canal list structre, in order to map it into each child
    struct comCanal * comList = (struct comCanal *) allocPage();
    printf("Starting services test\r\n");
    printf("Struct Queue create service\r\n");
    createArgs->lenght = 10;
    createArgs->size_type = (uint32_t)sizeof(struct AMessage);
    createArgs->returnCall = (uint32_t)0xDEADBEEF;
    printf("Notifying my parent for service\r\n ");
    Pip_Notify(0,0x80,0x15,createArgs);
    printf("Je respire\r\n");
    /* FreeRTOS gave us in createArgs->returnCall the address of the queue */
    printf("Go back to execution with %x\n",(createArgs->returnCall));

    printf("Starting sending service\r\n");

    pxMessage->ucMessageID = 0x11;
    int i;
    for(i=0;i<20;i++)
      pxMessage->ucData[i] = i;

    sendArgs->queue = (uint32_t) (createArgs->returnCall);
    sendArgs->itemToQueue = (uint32_t) pxMessage;
    sendArgs->tickToWait = 0;

    printf("Sending to parent send command\r\n");
    Pip_Notify(0,0x80,0x16,sendArgs);

    printf("Starting receiving service\r\n");

    recArgs->queue = (uint32_t) (createArgs->returnCall);
    recArgs->tickToWait = 0;
    recArgs->bufferReceive = (void *) pxReceive;

    Pip_Notify(0,0x80,0x17,recArgs);

    printf("Go back to execution\r\n");
    struct AMessage * message = (struct AMessage*) recArgs->bufferReceive;
    printf("Check the content of the message %x\r\n",recArgs->bufferReceive);
    for(i=0;i<20;i++)
      printf("%d\r\n",pxReceive->ucData[i]);

    printf("Starting sbrk service test \r\n");
    sbrkD->size = 10;
    sbrkD->begin = 0xA04000;
    Pip_Notify(0,0x80,0x18,sbrkD);


    printf("Back to execution\r\n");

    printf("Test map queue list into each partitions\r\n");
    comList->listOfChannel = allocPage();
    comList->numberOfChannels = 10;
    for(i = 0;i<10;i++)
      comList->listOfChannel[i] = i;
    Pip_Notify(0,0x80,0x19,comList);

    /* All avaible channels are present in 0xBAAD0000 */
    for(i = 0;i<10;i++)
    printf("Data in %x is %x\r\n",0xBAAD0000+i*4,*(uint32_t*)(0xBAAD0000+i*4));
    for(;;);

}

```
