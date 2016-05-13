/*****************************************************************************
*********************Syncronization Library for Atmega 2560*******************
******************************************************************************

Developed By: Michael Fay for Rocksat-X 2016

File Name: primative.c
Last revised:
Version Number:

Tested By:
Last Tested:
******************************************************************************/



#ifndef __PRIMATIVE_H__
#define __PRIMATIVE_H__ 


/******************************* Includes ************************************/
#include <stdint.h>

/*********************** Memory Constants ************************************/

/***************** Macro's and Definitions************************************/

#define int8 int8_t
#define int16 int16_t
#define int32 int32_t

#define uint8 uint8_t 
#define uint16 uint16_t
#define uint32 uint32_t

#define boolean bool 
#define TRUE 1
#define true 1

#define FALSE 0
#define false 0

#define HIGH TRUE
#define high true 

#define LOW FALSE
#define low false


typedef void (*callback)(void);


/*********************** Function Proto's ************************************/

/***************** Global Variables*******************************************/

#endif