#include <Wire.h>
#include "rgb_lcd.h"

int buttonPIN = 2;
String messages[] = {"Be Gone Thot", "The Government is Always Watching", "Your mom", "Sah Dude"};

int buttonRead = 0;

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 0;
const int colorB = 0;



void setup() {
  pinMode(buttonPIN, INPUT);
  
  lcd.begin(16, 2);
    
    lcd.setRGB(colorR, colorG, colorB);
    
    // Print a message to the LCD.
    lcd.print("Hola");

    delay(1000);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  messageCycle();
}

void messageCycle(){
 int buttonRead = digitalRead(buttonPIN);

    int i=0;

    while(buttonPIN==true){
      for (i; i<sizeof(messages); i++){
        lcd.print(messages[i]);
      }
      if(i==sizeof(messages)){
        messageCycle();
      }
    }
    lcd.print("Try me");
}

