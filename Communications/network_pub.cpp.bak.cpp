/*****************************************************************************
*********************Syncronization Library for Atmega 2560*******************
******************************************************************************

Developed By: Michael Fay for Rocksat-X 2016

File Name: network_pub.c
Last revised:
Version Number:

Tested By:
Last Tested:
******************************************************************************/



/******************************* Includes ************************************/
#include "network.hpp"
#include "primative.hpp"
/*********************** Memory Constants ************************************/
extern uint8   device_id;       //your device ID

extern uint8   master_id;    		//master id

extern uint8 * network_devices;	//network devies array

extern uint8   network_size;  	//size of network device array aka
									//network size


/***************** Macro's and Definitions************************************/

/*********************** Function Proto's ************************************/

/***************** Global Variables*******************************************/

static boolean        known_Master;   //private variable to see if we have a known master on the network. 

//Function to set and read on device reg's
void readReg(uint8 reg, void * data)
{
	&data = reg;
}

//Function to define network master
void defineNetMaster(uint8 * status)
{
	//see if there is already a master assigned. If so connect to it.
	if(known_Master == TRUE)
	{
		*status = known_master; 
	}
	//If network doesn't have master, attempt to build network tree.
	else 
	{
		//if network tree can't be build return a 0 and output an error
			//Define itself as the master. And wait for an awk command. If one is recieved
			//try to build a network.

		//else create network and build a tree of the network
			//We can worry about the tree later.

	}
		
	//Once master has been detected, attempt to ping master.

		//if network can't ping, requect from a seconardy node on network status of master and log the event it
		//we can build it later.

}

//Function to sync to master
void syncToMaster(uint8 * status)
{
	/*Local Variables*/
	uint8 loop_temp;

	//See if network is busy, if so wait until it is no longer busy.
		//We can do this with a busy loop or an interrupt driven pin.

	//Once bus is free attempt to ping master. If master doesn't reply
	//try three more times
    do
	{

	}while(loop_temp)
	// If master never responds go into async and log the time of the event and an error message


	// If we have a successful conection, tell master that we would like to sync
	// Wait for reply from master and verify the data.

}

//Function to verify master activity
void verifyMasterAvail(uint8 * status, uint8 master_id, uint8 ping_amount, uint8 time_delay)
{
	// Check to see bus activity, if bus is not active send awk to master
		//Try 3 times if ping amount is 0 or use ping_amount
		//use time_delay specified or if 0 use 100 ms


}
//Function to request current master
void currentMasterAddress(void * master_id, uint8 size)
{
	//return current master address if master is known otherwise return
	//this device address

}

//Fuction to get current nodes on network and common name.
void getNetworkNodes(void * data, uint8 ptr_size)
{
		//ping from 0 -> 255
}

//Function to display out all attached network devices
void printNetwork()
{
	uint8 counter;  //declaring loop counter
	counter = 0;      //init loop counter

	//print all indexs in array of getNetworkNodes
	for(counter; counter < network_size ; counter ++)
	{
		//get details about each device.
		//store details in array
	}
}

//Function to talk with another device. It uses a standard message dictionary.
//Note: The device must support the network request are all hell breaks lose.


//Function to send current packet pending. Note the buffer stores up to 8 packets.


/*********************** Note's ************************************/
/*
We do not have to worry about bus delay as the bus delay will always be relatively constant,
therefor, it will not matter since the data will just be shifted over.







*/
