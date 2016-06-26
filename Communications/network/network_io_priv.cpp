#include "network_io_priv.hpp"

#include "cc1101.h"
//Function to init packet
void init(uint8 * network_type_param)
{

	//init all vars used to protect againest un marked bits

	_byte_full 			= 0; 
	_packet_full 		= 0;
	_crc_check_pass 	= 0;
	pkt_failed 			= 0; 

	_rx_data_buffer[MAX_RX_DATA_STREAM]  = 0; 

	_pkt_data_overflow 	= 0; 
	_rx_data_byte 		= 0;
	_bits_recieved 		= 0; 
	_pkt_location 		= 0; 
	_network_type 		= 0; 
	_data_stream_counter	= 0; 


	_data_packet = 0;

	_rx_callback_ftn 	= NULL;

	_network_type = * network_type_param;

	//setting NERI comm line 0 and 1 as inputs
	COMM_DDR &= ~( ( 1 << NERI_LINE_0 ) | (1 << NERI_LINE_1) );

}

//function to write a packet to the wire
void sendPkt(NERI * pkt)
{
	switch(_network_type)
	{
		//write to wire if network type is 0
		case 0: wireWrite(pkt); break;
		//case CC1101: cc1101Write(); break; 
		default: break; 

	}	

}


//function to write a packet to the wire "network"
void wireWrite(NERI * pkt)
{
	uint8 i = 0;
	uint8 end_seq = END_BTYE;

	write_byte(START_BYTE);

	write_byte(& pkt.reciever_id);
	write_byte(& pkt.sender_id);
	write_byte(& pkt.command);

	for(i = 0; i < pkt.data_len; i++)
	{
		write_byte(&(data[i]));
	}

	write_byte(& pkt.crc);
	write_byte(& end_seq);

}


//function to write a singular byte
void wireWriteByte(void * byte)
{

	uint8 i; 

	INTERRUPTS_OFF();

	//Set direction reg to output 
	COMM_DDR |= ( ( 1 << NERI_LINE_0 ) | (1 << NERI_LINE_1) );

	
	//loop through each device_id bit
	for(i = 0; i < 8; i++)
	{
		tmp_byte = (*uint8) & ~(1 << i);	// We want to isolate a singular bit for transmission

		if(tmp_byte = 0) // if 0 set d0  low and d1  high
		{
			COMM_BANK &= ~(1 << NERI_LINE_0 | 1 << NERI_LINE_1);
			COMM_BANK |=  (0 << NERI_LINE_0 | 1 << NERI_LINE_1);
		}
		else if(tmp_byte = 1)	// if 1 set d0  high and d1  low
		{
			COMM_BANK &= ~(1 << NERI_LINE_0 | 1 << NERI_LINE_1);
			COMM_BANK |=  (1 << NERI_LINE_0 | 0 << NERI_LINE_1);

		}
		else 						// if neither set d0  low and d1  low
		{
			COMM_BANK &= ~(1 << NERI_LINE_0 | 1 << NERI_LINE_1);
			COMM_BANK |=  (0 << NERI_LINE_0 | 0 << NERI_LINE_1);

		}

		DELAY_MICRO_SEC(COMM_TRANSMIT_DELAY);
	}


	COMM_DDR &= ~( ( 1 << NERI_LINE_0 ) | (1 << NERI_LINE_1) );

	INTERRUPTS_ON();

}

//function to write
void wireBitRecieve()
{
	uint8 tmp_comm_line_0; 
	uint8 tmp_comm_line_1;

	tmp_comm_line_0 = ( COMM_BANK_READ & ( 1 << NERI_LINE_0 ) ); 
	tmp_comm_line_1 = ( COMM_BANK_READ & ( 1 << NERI_LINE_1 ) );

	//Logical 1 has been transmitted! Good nothing fucking broke
	if(tmp_comm_line_0 == TRUE && tmp_comm_line_1 == FALSE)
	{
		_rx_data_byte = 1 << _bits_recieved;
	}
	else if(tmp_comm_line_0 == FALSE && tmp_comm_line_1 == TRUE)
	{
		_rx_data_byte = 0 << _bits_recieved; 
	}
	else
	{
		pkt_failed = TRUE; 
		_rx_data_byte = 1 << _bits_recieved;
	}


	//Check to see if full byte has been recieved. 
	if( _bits_recieved > 7 )
	{
		processPacket();
		_bits_recieved = 0;
	}
	else
	{
		_bits_recieved ++;
	}
	
}

//When byte is full call this to see where the packet should be placed. 
void processPacket()
{
	switch(_pkt_location)
	{
		case 0: 
			_data_packet.reciever_id = _rx_data_byte;
			_pkt_location ++;  
			break;
		
		case 1: 
			_data_packet.sender_id   = _rx_data_byte; 
			_pkt_location ++; 
			break;

		case 2:
			 _data_packet.command     = _rx_data_byte;
			 _pkt_location ++; 
			 break; 

		case 3:
			 _data_packet.data_len    = _rx_data_byte;
			 _pkt_location ++; 
			 break;  
		
		case 4: 
			if(_data_packet.data_len > MAX_RX_DATA_STREAM)
				_pkt_data_overflow = TRUE; 
			_data_stream_counter = 0; 

			processDataStream();  //process incoming array of bits
			_pkt_location ++; 
			break;
			
		case 5:
			_data_packet.crc  		 = _rx_data_byte;
			_crc_check_pass = crc.checkPkt(_data_packet);  
			 						//TODO: NERIlement CRC Checksum
			if(_crc_check_pass == FALSE)
			{

				//0 opens the error log on SD_CARD and EEPROM 
			 	log.open(0);
			 	log.write("ERROR 0002: CRC checksum failed. ");
			 	log.write("Writing pkt to pkt_fail.csv for ");
			 	log.write("further analysis of error.")
			 	log.close(); 
			}

			_pkt_location ++; 
			break; 

		case 6: 
			//process and finish constructing packet for processing.
			if(_crc_check_pass == TRUE)
			{
				//We are checking againest over-righting 
				if( ( rx_current_bytes_written + _data_packet.data_len )	 >
				 	( RX_DATA_BUFFER_MAX   ) ) 
				{

					current_rx_data_buffer_location = rx_data_buffer;
					//TODO: Do we want to flush the data to EEPROM or the SD_CARD
					#ifdef DEBUG
							//1 opens event log: SD_CARD
							log.open(1);
							log.write("Resetting buffer location. This probably fucked shit up!");
							log.close(1);
					#endif
				}

				//adding the amount of bytes we are about to 
				//write to the current location of the buffer
				
				current_rx_data_buffer_location += _data_packet.data_len; 
				memcpy ( rx_data_buffer, _rx_data_buffer, _data_packet.data_len + 1 );
			}
			else
			{
				#ifdef DEBUG
					//TODO: add serial output so we know when shit hits the fan!
				#endif
				
				//write to error log
				log.open(0);
				log.write("CRC checksum failed. Initiating a retransmit.");
				log.close(0);



			}
			_pkt_location = 0; 

			if(_rx_callback_ftn != NULL)
				_rx_callback_ftn();

			break;

		default:

			log.open(0);
			log.write("ERROR 0003: Unkown packet state. Something fucked up.");
			log.close(0);

			break; 
	}

}

//Function to process only the data * of the packet
void processDataStream()
{
	if( _pkt_data_overflow >= TRUE )
	{
		log.open(0);
		log.write("ERROR 0001: \t");
		log.write("Data trying to be sent by: ");
		log.write("%d ", _data_packet.sender_id);
		log.write("is to large.\n \t");
		log.write("Writing out to EEPROM and SD_Card");
		log.close(0);

		_pkt_data_overflow = 2; //trianry logic to say that we already handled the exception
	}


	//max allowed packets is good. lets start recieving. 
	else
	{
		_rx_data_buffer[_data_stream_counter] = _rx_data_byte;
		_data_stream_counter ++; //increment array
	}

}

//Function to start recieving data
void startRecieve()
{
	//setting NERI comm line 0 and 1 as inputs
	COMM_DDR &= ~( ( 1 << NERI_LINE_0 ) | (1 << NERI_LINE_1) );
	INTERRUPTS_ON();

}

//Function to stop recieving

void stopRecieving()
{
	INTERRUPTS_OFF();
}


//Function to set recieve callback function 
void setPktRecieveCallback(callback callback_fuct)
{
	//callback function to be called after packet is recieved. 
	_rx_callback_ftn = callback_fuct;
}



