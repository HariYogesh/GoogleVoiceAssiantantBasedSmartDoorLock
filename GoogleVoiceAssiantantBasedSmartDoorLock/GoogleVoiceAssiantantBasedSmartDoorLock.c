/////////////////////////////////////////////////////////////////////////////////////////////////////
///  Project Name : GoogleVoiceAssiantantBasedSmartDoorLock
//
//  Target Board : atmega32
//
//  Date Created : 06-Apr-18 10:54:15 AM
// 
//  Online Resource  : www.electronicsforstudents.com
//
//  Libraries Included : -->wifiadvanced 
/////////////////////////////////////////////////////////////////////////////////////////////////////


#include<avr/io.h>
#include<util/delay.h>
#include "serial.h"
#include"servo.h"
#include "lcd.h"


int main()
{
	
	 lcd_init();
	 lcd_string("welcome");
    serial_init(9600);
     serial_select(2);
     wifi_init();
	 
     wifi_connect("JioFi2_17F9CF","mnms7zi2si");
	 _delay_ms(1000);
	 
	 lcd_string("wifi_conntd");
	 _delay_ms(1000);
	 servo_init();
	 char response[25];
	 char result[25];
		while (1)
	{
	
		 lcd_string("geting_info");
		 lcd_gotoxy(0,1);
		 lcd_string("from_server");
		  
		wifi_http("http://api.clobous.com/Hari1311/data/retrieve?door",response);
		
		
	    lcd_clear();
		lcd_string(response);
		jsonparser(response,"door",result);
		
		
				if(compare(result,"lock")==1)
					{
						set_180();// connect sevo to pin pd5
					}
					
					
			if(compare(result,"unlock")==1)
			 {
				set_0();
			 }

	}


}