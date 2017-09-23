/*
	***	SERIAL MONITOR PARA LCD ***
	por: Marlon soares
	marlonslbr@gmail.com

  Circuito:
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

// inclui a biblioteca para o LCD
#include <LiquidCrystal.h>


// Cria o objeto lcd e define os terminais usados para a conexao
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(115200);	//Inicia a serial com 115200 bauds de velocidade
  
  lcd.begin(16, 2);		//Configura o display para 16x2
  lcd.print("Digite alguma coisa!");
}

void loop() {
  if(Serial.available()){	//Se receber alguma coisa pela serial..
    lcd.clear();			//Limpe o display

    char recebido[32]="";		//Limpe a variável "recebido"
    						//Limpe a variável "recebido"
    for(int x=0;x<32;x++){	//Limpe a variável "recebido"
      recebido[x]=' ';		//Limpe a variável "recebido"
    }
    
    int a=0;				//Conta o numero de caracteres recebidos
    while(Serial.available()>0){	//Enquanto receber alguma coisa da serial..
      recebido[a]=Serial.read(); 		//Salve na variável "recebido"
      a++;							//e incrementa a variável "a" para o novo caracter
    }
    
    lcd.setCursor(0,0);		//Configure o cursor para a primeira linha
    for(int x=0;x<16;x++){ 	//Exiba os primeiros 16 caracteres na primera linha
      lcd.print(recebido[x]);
    }

    lcd.setCursor(0,1);		//Configure o cursor para a segunda linha
    for(int x=16;x<32;x++){	//Exiba os próximos 16 caracteres na segunda linha
      lcd.print(recebido[x]);
    }

    						//Se vocẽ tive um display com mais de 2 linhas...
    						//copie o bloco acima e substitua apenas a
    						//linha do cursor.
    
  }
}							//FIM do LOOP

