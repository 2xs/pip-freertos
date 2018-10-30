#ifndef _SERVICE_H
#define _SERVICE_H





#define Configuration           1
#define Task_Creation           2
#define Task_Control            3
#define Kernel_Control          4
#define Task_Notification       5
#define Task_Utilities          6
#define Queue_Managment         7
#define Queue_Set               8
#define Semaphore               9
#define Software_Timer          10
#define Event_Group             11
#define Stream_Buffer           12
#define Message_Buffer          13
#define Coroutine_spec          14

















struct service_s
{
    uint32_t index;
    uint32_t function;
};

typedef struct service_s * service_t;

//services
//

void init_service(TCB_t * partition);
void add_service(service_t service,TCB_t * partition);
void remove_service(service_t service, TCB_t * partition);
void enable_service(TCB_t * partition);
void disable_service(service_t service, uint32_t partition);




#endif
