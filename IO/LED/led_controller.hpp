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

#ifndef __LED_CONNTROLLER_H__
#define __LED_CONNTROLLER_H__ 

/******************************* Includes ************************************/
#include "bsp.h"
/*********************** Memory Constants ************************************/

/***************** Macro's and Definitions************************************/

/*******************Global Variables******************************************/																			//network size


/*********************** Function Proto's ************************************/

class led_controller
{
public:
	void setLedOn(void * pin_number);
	void setLedOff(void * pin_number);

private: 
	void writeByte(void * byte);
	void networkWritePacket(IMP * pkt);
	void bitRecieve();
};

#endif //protect againest multiple definitions
/*********************** Note's **********************************************/
/*




*/
