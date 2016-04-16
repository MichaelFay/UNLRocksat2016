


//function to write a packet to the wire
void networkWritePacket(IMP * pkt)
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
void writeByte(void * byte)
{
	//loop through each device_id bit
	for(i = 0; i < 8; i++)
	{
		tmp_byte = (*uint8) & ~(1 << i);	// We want to isolate a singular bit for transmission

		if(tmp_byte = 0) // if 0 set d0  low and d1  high
		{
			COMM_BANK &= ~(1 << data0 | 1 << data1);
			COMM_BANK |=  (0 << data0 | 1 << data1);
		}
		else if(tmp_byte = 1)	// if 1 set d0  high and d1  low
		{
			COMM_BANK &= ~(1 << data0 | 1 << data1);
			COMM_BANK |=  (1 << data0 | 0 << data1);

		}
		else 						// if neither set d0  low and d1  low
		{
			COMM_BANK &= ~(1 << data0 | 1 << data1);
			COMM_BANK |=  (0 << data0 | 0 << data1);

		}
	}
}
