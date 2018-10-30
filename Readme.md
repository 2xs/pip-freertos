# FreeRTOS portage to PIP kernel.

- `Demo/Common/`: FreeRTOS original extension (version 9.0)
- `Demo/pip-kernel/`: FreeRTOS entry point
- `libfreertos/`: user-space FreeRTOS library
- `Source/`: FreeRTOS core and portage sources

## Required changes :
- In `Source/include/FreeRTOSConfig.h` change the macro MAX_PAGE size of default allocated memory size for each child
- In main.c, you have to initialize the available memory for FreeRTOS with Libpip function initPaging. In the case of using FreeRTOS as the root partition, you can do it like this :
``` C
initPaging((void*)bootinfo->membegin,(void*)bootinfo->memend);
```
or in FreeRTOS as support for subpartition :
``` C
  initPaging((void*)0x1C00000,(void*)(0x1C00000+(MAX_PAGE*0x1000)));
```
bootinfo is a C struct available for each root partition, given by Pip through the entrypoint first parameter.

## To add new task-partitions :
- To add task-partitions for FreeRTOS, you have to put them into `Demo/pip-kernel/Support_Files/aes.hpartitions_images/`
- Include the binary corresponding to the task into `Demo/pip-kernel/Support_Files/partition.S`
- Create a new protected task into your source code, example for two binary file per task-partition :

  In partitions.S
  ```assembly
  .section .partition1
  .incbin "Support_Files/partitions_images/part1.bin"

  .section .partition2
  .incbin "Support_Files/partitions_images/part2.bin"
  ```
  In main.c :
  ``` C
  extern void* _partition1, *_epartition1;
  extern void* _partition2, *_epartition2;
  static const struct {
      uint32_t start, end;
  } partitions[] = { { (uint32_t) &_partition1, (uint32_t) &_epartition1 },
      (uint32_t) &_partition2, (uint32_t) &_epartition2 };
  ```
  You have to create the task-partition with the function xTaskCreateProtected :
  ``` C
  uint32_t size = partitions[0].end - partitions[0].start;
  xTaskCreateProtected(partitions[0].start, "partition name", size, NULL, configMAX_PRIORITIES - 1, NULL);
  ```


## To use FreeRTOS task-partition services

FreeRTOS for Pip implment a set of services. Theses services are :
* QUEUE message service
* SBRK-like service
* to be continue...

Theses services are implemented through Pip software interrupt mechanism.


### Queue message service

The queue message service is accessible via notifying FreeRTOS for Pip with this interrupt numbers :
```C
#define queueCreate     0x15
#define queueSend       0x16
#define queueReceive    0x17
#define channelCom      0x19
```
Each service is associated to a data structure containing all required information by FreeRTOS for Pip.
Otherwise, in the child partition, for creating a queue, the structure is :

```C
struct xQueueCreateParameters_s {
  uint32_t lenght;
  uint32_t size_type;
  uint32_t returnCall;
};
typedef struct xQueueCreateParameters_s xQueueCreateParameters;
```
All other associated structure are available in `Source/portable/GCC/pip-kernel/partitionServices.h`

And the procedure is :
```C
xQueueCreateParameters * createArgs = (xQueueCreateParameters*) allocPage();
createArgs->lenght = SIZE_OF_THE_QUEUE;
createArgs->size_type = SIZE_OF_EACH_MESSAGE;
createArgs->returnCall = (uint32_t)0xDEADBEEF;

Pip_Notify(0,0x80,0x15,createArgs);
/* */

```
List of parameters :
  - 0 for the parent (FreeRTOS),
  - 0x80 is the service interrupt number in FreeRTOS
  - 0x15 is the service code for createQueue,
  - createArgs is the pointer to the structure needed for Queue creating


An example of typical child partition using theses services is available in `Service_example.md`
