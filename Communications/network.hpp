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
#include "/Users/michaelfay/Desktop/Rocksat/Atmega/328p/device.h"


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

/*********************** Function Proto's ************************************/

\\class definitions


#endif //protect againest multiple definitions
/*********************** Note's **********************************************/
/*




*/
