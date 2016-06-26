/*****************************************************************************
*********************Syncronization Library for Atmega 2560*******************
******************************************************************************

Developed By: Michael Fay for Rocksat-X 2016

File Name:
Last revised:
Version Number:

Tested By:
Last Tested:
******************************************************************************/

#ifndef __NETWORK_H__
#define __NETWORK_H__ 

/******************************* Includes ************************************/
#include <stdint.h>
#include <stdbool.h>
#include "bsp.h"
#include "primative.hpp"

#ifndef __PACKET_DEF_H__
  #include "packet_def.hpp"
#endif

#ifndef __LOG_H__
  #include "log.hpp"
#endif

#ifndef START_BYTE
	#define START_BYTE 0x33
#endif

#ifndef END_BYTE
	#define END_BYTE 0x3C 
#endif

/*********************** Memory Constants ************************************/

/***************** Macro's and Definitions************************************/

/*******************Global Variables******************************************/
extern const uint8_t   device_id;       		//your device ID
	
extern uint8_t   master_id;    				  	//master id

extern uint8_t  *network_devices;			  	//network devies array

extern uint8_t   network_size ;  				//size of network device array aka
												//network size

extern uint8    data_clock_line;				//Pin that the data pins reside on. i.e. P1

extern int8	device_enable;  					// device enable pin. If this pin is not high ignore all requests.
												//if master node define device id = -1

extern uint8   	mm_clock; 						//m2m clock signal for master-master communication

extern uint8  recieved_buffer_size;


network_io networks_io; 
//network_io network; 

/*********************** Function Proto's ************************************/
class network_t
{
public:
	void init( network_type_t8 comm_type );
	boolean send( NERI * pkt );
	boolean setRecieve();
	boolean haveRecieved();

private:
	enum network_transmission_types_t network_transmission_types = UNKNOWN;
	void defineNetMaster(uint8 * status);
	void syncToMaster(uint8 * status);
	void verifyMasterAvail(uint8 * status, uint8 master_id, uint8 ping_amount, uint8 time_delay);
	void currentMasterAddress(void * master_id, uint8 size);
	void getNetworkNodes(void * data, uint8 ptr_size);
	void printNetworkDebug();
	void ping(boolean success, uint8 * reciever_id_parm, ...)
};




#endif //protect againest multiple definitions
/*********************** Note's **********************************************/
/*




*/
