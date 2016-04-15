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
extern uint8   	device_id;       //your device ID

extern uint8   	master_id;    		//master id

extern uint8 *  network_devices;	//network devies array

extern uint8 	network_size;  	//size of network device array aka
									//network size

extern uint8    data_pin_bank;	//Pin bank that the data pins reside on. i.e. P1

extern uint8   	data0;			//data line 0
extern uint8   	data1;			//data line 1 -- For differential signaling

extern int8	device_enable;  // device enable pin. If this pin is not high ignore all requests.
									//if master node define device id = -1

extern uint8   	mm_clock; 	//m2m clock signal for master-master communication 


/***************** Macro's and Definitions************************************/

/*********************** Function Proto's ************************************/

/***************** Global Variables*******************************************/

static boolean        known_Master;   //private variable to see if we have a known master on the network. 

//Function to set and read on device reg's
void readMemLocation(uint8 reg, void * data)
{
	* data = &reg;
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
		
		uint8 device_id; 
		uint8 i; 

		IMP tmp_pkt; 
		uint8 tmp_data;

		//setting defaults for the packet
		tmp_pkt.sender_id 	= 	device_id;
		tmp_pkt.command		= 	AWK; 
		tmp_pkt.data_len	= 	1;
		tmp_pkt.data 		=   (void *) tmp_data;
		tmp_pkt.crc			=	0xFF;

		//ping from 0 -> 255
		for(int i = 0; i < network_size ; i ++)
		{
			tmp_pkt.reciever_id = i; 
			
			if(recieved_buffer == 0)
			{
				network_devices[i] = false; 
			}
		}
}


#ifdef DEBUG
//Function to display out all attached network devices
void printNetwork()
{
	uint8 counter;  //declaring loop counter
	counter = 0;      //init loop counter

	//print all indexs in array of getNetworkNodes
	for(counter; counter < network_size ; counter ++)
	{

		//ping each device availabe on the network
		//get details about each device.
		//store details in array
	}
}
#endif

//Function to ping device with ID as param
void ping(boolean success, uint8 * reciever_id_parm, ...)
{
	uint8 device_id; 
	uint8 i; 

	IMP tmp_pkt; 
	uint8 tmp_data;
	tmp_data = device_id;

	tmp_pkt.reciever_id =   reciever_id_parm;
	tmp_pkt.sender_id 	= 	device_id;
	tmp_pkt.command		= 	AWK; 
	tmp_pkt.data_len	= 	1;
	tmp_pkt.data 		=   (void *) tmp_data;
	tmp_pkt.crc			=	0xFF;


	network_write_pkt(& tmp_pkt); 
}


//function to write a packet to the wire
void network_write_pkt(IMP * pkt)
{
	uint8 i = 0;

	write_byte(START_BYTE);

	write_byte(& pkt.reciever_id);
	write_byte(& pkt.sender_id);
	write_byte(& pkt.command);

	for(i = 0; i < pkt.data_len; i++)
	{
		write_byte(&(data[i]));
	}

	write_byte(& tmp_pkt.crc);
	write_byte(END_BTYE);
}

//function to write a singular byte
void write_byte(void * byte)
{
	//loop through each device_id bit
	for(i = 0; i < 8; i++)
	{
		tmp_byte = (*uint8) & ~(1 << i);	// We want to isolate a singular bit for transmission

		if(tmp_byte = 0) // if 0 set d0  low and d1  high
		{
			BANK &= ~(1 << data0 | 1 << data1);
			BANK |=  (0 << data0 | 1 << data1);
		}
		else if(tmp_byte = 1)	// if 1 set d0  high and d1  low
		{
			BANK &= ~(1 << data0 | 1 << data1);
			BANK |=  (1 << data0 | 0 << data1);

		}
		else 						// if neither set d0  low and d1  low
		{
			BANK &= ~(1 << data0 | 1 << data1);
			BANK |=  (0 << data0 | 0 << data1);

		}
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
