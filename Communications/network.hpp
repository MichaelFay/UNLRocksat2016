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
#include "network_io_priv.hpp"

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
extern const uint8_t   device_id;       //your device ID

extern uint8_t   master_id;    				  //master id

extern uint8_t  *network_devices;			  //network devies array

extern uint8_t   network_size ;  				//size of network device array aka
												//network size

extern uint8    data_clock_line;	//Pin that the data pins reside on. i.e. P1

extern uint8   	data0;			//data line 0
extern uint8   	data1;			//data line 1 -- For differential signaling

extern int8	device_enable;  // device enable pin. If this pin is not high ignore all requests.
							//if master node define device id = -1

extern uint8   	mm_clock; 	//m2m clock signal for master-master communication

extern uint8  recieved_buffer_size;


network_io network; 
//network_io network; 

/*********************** Function Proto's ************************************/


#endif //protect againest multiple definitions
/*********************** Note's **********************************************/
/*




*/
