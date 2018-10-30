/*
 * CommonStructure.h
 *
 *  Created on: 19 nov. 2017
 *      Author: HZGF0437
 */

#include "stdint.h"

#ifndef COMMONSTRUCTURE_H_
#define COMMONSTRUCTURE_H_

#define DEVICEID_SIZE                        ( 4+1 )
#define DOMID_SIZE                           ( 4+1 )
#define KEY_SIZE                             ( 256+1 )
#define KEYID_SIZE                           ( 4+1 )
#define TOKEN_SIZE                           ( 64+1 )
#define DATA_SIZE                            ( 512+1 )
#define REQID_SIZE                           ( 4+1 )
#define INS_SIZE                             ( 4+1 )
#define RESPCODE_SIZE                        ( 4+1 )
#define IN_MAX_MESSAGE_SIZE                  ( REQID_SIZE + DEVICEID_SIZE + DOMID_SIZE + TOKEN_SIZE + INS_SIZE + DATA_SIZE + 6*3)
#define OUT_MAX_MESSAGE_SIZE                 ( REQID_SIZE + RESPCODE_SIZE + DATA_SIZE + 3*6)

typedef struct IN_NW{
	uint32_t size;
	char stream[IN_MAX_MESSAGE_SIZE];
}in_nw_t;

typedef enum instruction{
	READ_DOMID, UPDATE_DOMID, CREATE_DOM, ADD_KEY, READ_KEY, UPDATE_KEY, DELETE_KEY, SET_IO, GET_IO, SET_IO_DIR, SET_LED, SET_ALL_IO_DIR
}instruction_t;

typedef struct command{
	uint32_t userID;
	instruction_t instruction;
	char data[DATA_SIZE];
}command_t;

typedef struct incomingMessage{
	uint32_t userID;
	uint32_t deviceID;
	uint32_t domainID;
	uint32_t tokenSize;
	char token[TOKEN_SIZE];
	command_t command;
}incomingMessage_t;

typedef struct responseMessage{
	uint32_t userID;
	int responsecode;
	char data[DATA_SIZE];
}response_t;

typedef enum eventType{
	GET_KEY,
	NW_IN, NW_OUT,
	EXT_COMMAND, INT_COMMAND,
	EXT_MESSAGE, INT_MESS_0, INT_MESS_1, INT_MESS_2, INT_MESS_3,
	RESPONSE, INT_RESP_0, INT_RESP_1, INT_RESP_2, INT_RESP_3,
}eventType_t;

typedef struct event{
	eventType_t eventType;
	union {
		incomingMessage_t incomingMessage;
		command_t command;
		response_t response;
		in_nw_t nw;
	} eventData;
}event_t;

typedef struct Domain{
	char DomId[DOMID_SIZE];
	uint32_t nbChilDom;
}domain_t;

typedef struct Key{
	struct Key* next;
	char KeyID[KEYID_SIZE];
	char Key[KEY_SIZE];
}key_t;


#endif /* COMMONSTRUCTURE_H_ */
