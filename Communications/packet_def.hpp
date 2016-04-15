/*********************Syncronization Library for Atmega 2560*******************
******************************************************************************

Developed By: Michael Fay for Rocksat-X 2016
******************************************************************************/

#ifndef __PACKET_DEF_H__
#define __PACKET_DEF_H__

/******************************* Includes ************************************/
#include <stdint.h>
/*********************** Memory Constants ************************************/

/***************** Macro's and Definitions************************************/

#ifndef AWK
	#define AWK 0x01       //AWK packet code
#endif

#ifndef READ_MEM
	#define READ_MEM 0x02   //If wanting to set a register in the reciever
#endif

#ifndef SEND_DATA
	#define SEND_DATA 0x03 //If wanting to send a data stream to reciever
#endif

#ifndef SYNC_CLOCK
	#define SYNC_CLOCK 0x04 // Used to for syncronization across a multi_nodial network
#endif

#ifndef GET_DEVICE_ID
	#define GET_DEVICE_ID 0x05 // Used to for getting device id from a node
#endif

#ifndef GET_DEVICE_NAME
	#define GET_DEVICE_NAME 0x06 // Used to for getting device name from a node
#endif

// NERIC packet for m2m communication
typedef struct
{
	uint8_t reciever_id; // Reciever I2C ID
	uint8_t sender_id;   // sender ID
	uint8_t command;     //command to be sent
	uint8_t data_len;    // length of the data
	void  * data;        // pointer to the data to be sent < 255
	uint8_t crc;         // CRC check sum

} IMP;


#endif  
	//protection againest multi_import problems


/*********************** Function Proto's ************************************/
