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

#ifndef __NETWORK_PRIMATIVE__
#define __NETWORK_PRIMATIVE__

/******************************* Includes ************************************/
#include "primative.hpp"

/*********************** Memory Constants ************************************/

/***************** Macro's and Definitions************************************/
#define network_type_t8 uint8

enum network_transmission_types_t
{
	NERI 		= 0,
	CC1101		= 1,
	LOG 		= 2,
	SERIAL		= 3,
	WIRE 		= 4,
	SPI 		= 5,
	UNKNOWN		= 6
};
/*******************Global Variables******************************************/

/*********************** Function Proto's ************************************/

#endif //protect againest multiple definitions
/*********************** Note's **********************************************/
/*




*/
