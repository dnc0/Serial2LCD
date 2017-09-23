/*
	***	SERIAL MONITOR TO LCD ***
	by: Marlon soares
	marlonslbr@gmail.com

  The circuit:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

*/

// include the library code:
#include <LiquidCrystal.h>


// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(115200);	//Start serial por at 115200 bauds  
  
  lcd.begin(16, 2);		//Set the LCD type for 16x2
  lcd.print("Type something!");
}

void loop() {
  if(Serial.available()){	//If recive something in serial...
    lcd.clear();			//clear the display

    char recive[32]="";		//Clear the recive variable..
    						//Clear the recive variable..
    for(int x=0;x<32;x++){	//Clear the recive variable..
      recive[x]=' ';		//Clear the recive variable..	
    }
    
    int a=0;				//Count the number of character
    while(Serial.available()>0){	//While recive something on the serial...
      recive[a]=Serial.read(); 		//Save it on "recive" variable array
      a++;							//and incremment a for the next character
    }
    
    lcd.setCursor(0,0);		//Set the cursor for the first line of display
    for(int x=0;x<16;x++){ 	//Print the first 16 characters
      lcd.print(recive[x]);
    }

    lcd.setCursor(0,1);		//Set the cursor for the second line of display
    for(int x=16;x<32;x++){	//Print the second 16 characters
      lcd.print(recive[x]);
    }

    						//If you have an display w/ more than 2 lines...
    						//simple copy the block above switching the 
    						//line of the cursor.
    
  }
}							//END of LOOP

