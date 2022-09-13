#include <IRremote.hpp>
 

 
void setup()
{
  Serial.begin(9600);
  IrSender.begin(4, ENABLE_LED_FEEDBACK); 
  pinMode(6,INPUT_PULLUP); // button 1
    pinMode(5,INPUT_PULLUP); // button 2
  
}
 
void loop() {
  
  if (digitalRead(6) == LOW){
     Serial.println("ok");
   IrSender.sendNEC(0xA8, 0x19, 2);
      delay(30);
      } else if(digitalRead(5) == LOW){
          IrSender.sendNEC(0xA8, 0x11, 2);
      delay(30);
      }
 

delay(1);
  
  }
