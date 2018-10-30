#ifndef _FREERTOS_ACCESS_h
#define _FREERTOS_ACCESS_h
#ifndef anyIntAsm
	#define anyIntAsm 0x00700140
#endif

#ifndef anyIntHandler
	#define anyIntHandler 0x0070462e
#endif

#ifndef __Arch_APICall_0
	#define __Arch_APICall_0 0x0070060c
#endif

#ifndef __Arch_APICall_1
	#define __Arch_APICall_1 0x0070062e
#endif

#ifndef __Arch_APICall_2
	#define __Arch_APICall_2 0x00700695
#endif

#ifndef __Arch_APICall_3
	#define __Arch_APICall_3 0x00700709
#endif

#ifndef __Arch_APICall_4
	#define __Arch_APICall_4 0x0070070f
#endif

#ifndef __Arch_APICall_5
	#define __Arch_APICall_5 0x00700740
#endif

#ifndef __Arch_APICall_6
	#define __Arch_APICall_6 0x00700789
#endif

#ifndef channelService
	#define channelService 0x00704f0c
#endif

#ifndef checkAccess
	#define checkAccess 0x00704891
#endif

#ifndef code
	#define code 0x00700000
#endif

#ifndef collect
	#define collect 0x007009ac
#endif

#ifndef createPartition
	#define createPartition 0x007008ec
#endif

#ifndef deletePartition
	#define deletePartition 0x007009a0
#endif

#ifndef dispatch
	#define dispatch 0x00700950
#endif

#ifndef dRegTest1_st1
	#define dRegTest1_st1 0x00706910
#endif

#ifndef dRegTest1_st2
	#define dRegTest1_st2 0x00706908
#endif

#ifndef dRegTest1_st3
	#define dRegTest1_st3 0x00706900
#endif

#ifndef dRegTest1_st4
	#define dRegTest1_st4 0x007068f8
#endif

#ifndef dRegTest1_st5
	#define dRegTest1_st5 0x007068f0
#endif

#ifndef dRegTest1_st6
	#define dRegTest1_st6 0x007068e8
#endif

#ifndef dRegTest1_st7
	#define dRegTest1_st7 0x007068e0
#endif

#ifndef dRegTest2_st1
	#define dRegTest2_st1 0x00706948
#endif

#ifndef dRegTest2_st2
	#define dRegTest2_st2 0x00706940
#endif

#ifndef dRegTest2_st3
	#define dRegTest2_st3 0x00706938
#endif

#ifndef dRegTest2_st4
	#define dRegTest2_st4 0x00706930
#endif

#ifndef dRegTest2_st5
	#define dRegTest2_st5 0x00706928
#endif

#ifndef dRegTest2_st6
	#define dRegTest2_st6 0x00706920
#endif

#ifndef dRegTest2_st7
	#define dRegTest2_st7 0x00706918
#endif

#ifndef getFunctionCallInfo
	#define getFunctionCallInfo 0x00704897
#endif

#ifndef getNumberOfPartition
	#define getNumberOfPartition 0x0070293d
#endif

#ifndef getPartitionList
	#define getPartitionList 0x00702943
#endif

#ifndef halt
	#define halt 0x0070000e
#endif

#ifndef handleGPF
	#define handleGPF 0x00704591
#endif

#ifndef inb
	#define inb 0x00700826
#endif

#ifndef initPartitionServices
	#define initPartitionServices 0x00705124
#endif

#ifndef inl
	#define inl 0x007008aa
#endif

#ifndef inw
	#define inw 0x00700868
#endif

#ifndef irqTimer
	#define irqTimer 0x00700128
#endif

#ifndef keyAsm
	#define keyAsm 0x00700138
#endif

#ifndef keyHandler
	#define keyHandler 0x007045fe
#endif

#ifndef main
	#define main 0x00705683
#endif

#ifndef mapPage
	#define mapPage 0x00700930
#endif

#ifndef mappedInChild
	#define mappedInChild 0x00700994
#endif

#ifndef memcpy
	#define memcpy 0x00705146
#endif

#ifndef my_memcpy
	#define my_memcpy 0x00704a1e
#endif

#ifndef outaddrl
	#define outaddrl 0x007008c9
#endif

#ifndef outb
	#define outb 0x00700803
#endif

#ifndef outl
	#define outl 0x00700887
#endif

#ifndef outw
	#define outw 0x00700845
#endif

#ifndef pageMapCount
	#define pageMapCount 0x00700908
#endif

#ifndef parse_bootinfo
	#define parse_bootinfo 0x00705614
#endif

#ifndef pfAsm
	#define pfAsm 0x00700130
#endif

#ifndef pfHandler
	#define pfHandler 0x007045db
#endif

#ifndef Pip_AllocPage
	#define Pip_AllocPage 0x0070032f
#endif

#ifndef Pip_Debug_Putc
	#define Pip_Debug_Putc 0x007007c3
#endif

#ifndef Pip_Debug_PutDec
	#define Pip_Debug_PutDec 0x007001f3
#endif

#ifndef Pip_Debug_PutHex
	#define Pip_Debug_PutHex 0x00700188
#endif

#ifndef Pip_Debug_Puts
	#define Pip_Debug_Puts 0x00700158
#endif

#ifndef Pip_FreePage
	#define Pip_FreePage 0x0070037a
#endif

#ifndef Pip_InitPaging
	#define Pip_InitPaging 0x0070027b
#endif

#ifndef Pip_MapPageWrapper
	#define Pip_MapPageWrapper 0x00700407
#endif

#ifndef Pip_MapPageWrapper_RONLY
	#define Pip_MapPageWrapper_RONLY 0x007004f8
#endif

#ifndef Pip_Notify
	#define Pip_Notify 0x007005e9
#endif

#ifndef Pip_RegisterInterrupt
	#define Pip_RegisterInterrupt 0x007003b2
#endif

#ifndef pip_time
	#define pip_time 0x0070096c
#endif

#ifndef Pip_VCLI
	#define Pip_VCLI 0x007003d1
#endif

#ifndef Pip_VSTI
	#define Pip_VSTI 0x007003ec
#endif

#ifndef prepare
	#define prepare 0x00700918
#endif

#ifndef print
	#define print 0x007053ab
#endif

#ifndef printf
	#define printf 0x007055df
#endif

#ifndef pvPortMalloc
	#define pvPortMalloc 0x00705700
#endif

#ifndef pvTaskIncrementMutexHeldCount
	#define pvTaskIncrementMutexHeldCount 0x00703943
#endif

#ifndef pxPortInitialiseStack
	#define pxPortInitialiseStack 0x00704484
#endif

#ifndef queueCreateService
	#define queueCreateService 0x007048f6
#endif

#ifndef queueReceiveService
	#define queueReceiveService 0x00704c33
#endif

#ifndef queueSendService
	#define queueSendService 0x00704a69
#endif

#ifndef registerIntBase
	#define registerIntBase 0x00700393
#endif

#ifndef resume
	#define resume 0x00700974
#endif

#ifndef sbrkService
	#define sbrkService 0x00704df0
#endif

#ifndef serviceRoutine
	#define serviceRoutine 0x00705058
#endif

#ifndef serviceRoutineAsm
	#define serviceRoutineAsm 0x00700148
#endif

#ifndef setFunctionCallInfo
	#define setFunctionCallInfo 0x007048bc
#endif

#ifndef _start
	#define _start 0x00700000
#endif

#ifndef ulPortSetInterruptMask
	#define ulPortSetInterruptMask 0x00704872
#endif

#ifndef unmapPage
	#define unmapPage 0x00700984
#endif

#ifndef uxListRemove
	#define uxListRemove 0x007020be
#endif

#ifndef uxQueueMessagesWaiting
	#define uxQueueMessagesWaiting 0x00701a90
#endif

#ifndef validChild
	#define validChild 0x007045ab
#endif

#ifndef validChildAsm
	#define validChildAsm 0x00700150
#endif

#ifndef vAssertCalled
	#define vAssertCalled 0x007056fe
#endif

#ifndef vListInitialise
	#define vListInitialise 0x00701f78
#endif

#ifndef vListInitialiseItem
	#define vListInitialiseItem 0x00701fb9
#endif

#ifndef vListInsert
	#define vListInsert 0x00702025
#endif

#ifndef vListInsertEnd
	#define vListInsertEnd 0x00701fc6
#endif

#ifndef vPortAPICErrorHandler
	#define vPortAPICErrorHandler 0x0070487f
#endif

#ifndef vPortAPICErrorHandlerWrapper
	#define vPortAPICErrorHandlerWrapper 0x0070004c
#endif

#ifndef vPortAPICSpuriousHandler
	#define vPortAPICSpuriousHandler 0x00700124
#endif

#ifndef vPortCentralInterruptHandler
	#define vPortCentralInterruptHandler 0x0070488f
#endif

#ifndef vPortCentralInterruptWrapper
	#define vPortCentralInterruptWrapper 0x00700098
#endif

#ifndef vPortClearInterruptMask
	#define vPortClearInterruptMask 0x0070487d
#endif

#ifndef vPortEnterCritical
	#define vPortEnterCritical 0x00704829
#endif

#ifndef vPortExitCritical
	#define vPortExitCritical 0x0070483b
#endif

#ifndef vPortFree
	#define vPortFree 0x007058e4
#endif

#ifndef vPortStartFirstTask
	#define vPortStartFirstTask 0x0070003c
#endif

#ifndef vPortTimerHandler
	#define vPortTimerHandler 0x00700054
#endif

#ifndef vPortYieldCall
	#define vPortYieldCall 0x00700014
#endif

#ifndef vQueueAddToRegistry
	#define vQueueAddToRegistry 0x00701dd7
#endif

#ifndef vQueueWaitForMessageRestricted
	#define vQueueWaitForMessageRestricted 0x00701e23
#endif

#ifndef vSetTaskBuffer
	#define vSetTaskBuffer 0x00703cb6
#endif

#ifndef vTaskCheckIfProtected
	#define vTaskCheckIfProtected 0x007025bf
#endif

#ifndef vTaskMissedYield
	#define vTaskMissedYield 0x0070323e
#endif

#ifndef vTaskPlaceOnEventList
	#define vTaskPlaceOnEventList 0x00702ebc
#endif

#ifndef vTaskPlaceOnEventListRestricted
	#define vTaskPlaceOnEventListRestricted 0x00702f74
#endif

#ifndef vTaskPriorityInherit
	#define vTaskPriorityInherit 0x007036a4
#endif

#ifndef vTaskSetTimeOutState
	#define vTaskSetTimeOutState 0x0070311f
#endif

#ifndef vTaskStartScheduler
	#define vTaskStartScheduler 0x00702949
#endif

#ifndef vTaskSuspendAll
	#define vTaskSuspendAll 0x007029d8
#endif

#ifndef vTaskSwitchContext
	#define vTaskSwitchContext 0x00702d38
#endif

#ifndef xGetTaskBuffer
	#define xGetTaskBuffer 0x00703cd0
#endif

#ifndef xGetTaskWhereTo
	#define xGetTaskWhereTo 0x00703ce6
#endif

#ifndef xPortStartScheduler
	#define xPortStartScheduler 0x0070475e
#endif

#ifndef xQueueGenericCreate
	#define xQueueGenericCreate 0x00700ad3
#endif

#ifndef xQueueGenericReceive
	#define xQueueGenericReceive 0x007012b5
#endif

#ifndef xQueueGenericReset
	#define xQueueGenericReset 0x007009bc
#endif

#ifndef xQueueGenericSend
	#define xQueueGenericSend 0x00700bbd
#endif

#ifndef xQueueGenericSendFromISR
	#define xQueueGenericSendFromISR 0x0070110e
#endif

#ifndef xTaskCheckForTimeOut
	#define xTaskCheckForTimeOut 0x0070315c
#endif

#ifndef xTaskGenericCreate
	#define xTaskGenericCreate 0x00702685
#endif

#ifndef xTaskGenericNotify
	#define xTaskGenericNotify 0x0070395e
#endif

#ifndef xTaskGenericNotifyFromISR
	#define xTaskGenericNotifyFromISR 0x00703ae6
#endif

#ifndef xTaskGetSchedulerState
	#define xTaskGetSchedulerState 0x0070366b
#endif

#ifndef xTaskGetTickCount
	#define xTaskGetTickCount 0x00702b4a
#endif

#ifndef xTaskIncrementTick
	#define xTaskIncrementTick 0x00702b68
#endif

#ifndef xTaskPartitionCreate
	#define xTaskPartitionCreate 0x0070212d
#endif

#ifndef xTaskPriorityDisinherit
	#define xTaskPriorityDisinherit 0x007037e1
#endif

#ifndef xTaskRemoveFromEventList
	#define xTaskRemoveFromEventList 0x0070302c
#endif

#ifndef xTaskResumeAll
	#define xTaskResumeAll 0x007029e5
#endif

#ifndef xTaskSwitchToProtectedTask
	#define xTaskSwitchToProtectedTask 0x007025d8
#endif

#ifndef xTimerCreateTimerTask
	#define xTimerCreateTimerTask 0x00703cfc
#endif

#ifndef xTimerGenericCommand
	#define xTimerGenericCommand 0x00703d73
#endif

#endif
