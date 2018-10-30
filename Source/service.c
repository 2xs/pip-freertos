#include <stdint.h>
#include "FreeRTOS.h"

#include "task.h"
#include "timers.h"
#include "StackMacros.h"
#include <pip/paging.h>
#include <pip/api.h>
#include <pip/vidt.h>
#include <pip/compat.h>
#include "service.h"







void init_service(TCB_t * partition){

    partition->services = (uint32_t*) allocPage();

    printf("Service initialized for %x\r\n",(uint32_t)partition);
}

void add_service(service_t service,TCB_t * partition){

    partition->services[service->index] = service->function;
}

void remove_service(service_t service, TCB_t * partition){

    partition->services[service->index] = 0;
}


void enable_service(TCB_t * partition){

    if(mapPageWrapper((uint32_t)partition->services,(uint32_t)partition,(void*) 0xFFFF0000))
        printf("Error in enabling service for %x\r\n",(uint32_t)partition);

    return ; 
}
void disable_service(service_t service,uint32_t partition){

    return ;
}



