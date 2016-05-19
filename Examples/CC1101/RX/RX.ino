#include "cc1101.h"
#include "macros.h"
#include "pins.h"
#include "registers.h"
#include <String.h>
// Include application, user and local libraries
 #include "LCD_Launchpad.h"

// Variables
LCD_LAUNCHPAD myLCD;

unsigned long lastrx; 
unsigned long elapsed; 

CC1101Radio Radio;

#define LED RED_LED

void setup()
{
  
  myLCD.init();
    
  myLCD.displayText("Hello");
  
  Serial.begin(9600);
  Serial.println("Ballz");
  delay(100);
  Radio.Init();
  Radio.SetDataRate(4); // Needs to be the same in Tx and Rx
  Radio.SetLogicalChannel(2); // Needs to be the same as receiver
  pinMode(LED, OUTPUT);     
	lastrx=millis();
  Radio.RxOn();
  

}

byte RX_buffer[61]={0};
byte sizerx,i,flag;

void loop()
{
  Serial.println("Ballz"); 
  unsigned char tmp; 
  for (int j = 0 ; j < 25 ; j ++)
  {
    
    for(int i = 0 ; i < 10 ; i ++ )
    {
      delay(10);
      if(Radio.CheckReceiveFlag())
      {
        lastrx = millis();
        sizerx=Radio.ReceiveData(RX_buffer);
        // Should be one byte
        //Serial.write(RX_buffer[0]);
        Serial.println( RX_buffer[0], DEC);
        myLCD.clear();
        //String:String(RX_buffer[0], tmp);
        //myLCD.displayText(tmp);
        delay(1000);
      
        Radio.RxOn();
      }
    } 
    //String:String(j, tmp);
    //myLCD.displayText(tmp);
    Radio.SetLogicalChannel(j);
  }
  
}


