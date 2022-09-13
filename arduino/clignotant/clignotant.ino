#include <FastLED.h>
#define LED_PIN 5
#define NUM_LEDS 10
#define BTN_PIN_GAUCHE 6
#define BTN_PIN_DROIT 7
#define BTN_PIN_WARNING 8
int warning=0;
int gauche=0;
int droit=0;
CRGB leds[NUM_LEDS];


  
void setup(){
  pinMode(2,OUTPUT);
    pinMode(3,OUTPUT);
    pinMode(BTN_PIN_GAUCHE, INPUT_PULLUP);
        pinMode(BTN_PIN_DROIT, INPUT_PULLUP);
            pinMode(BTN_PIN_WARNING, INPUT_PULLUP);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
     for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(0, 255 - 10*i, 10*i );
    FastLED.setBrightness(100);
    FastLED.show();
    delay(50);
  }

}
 
void loop(){
   if(digitalRead(BTN_PIN_WARNING)==LOW && warning==0){
    warning=1;
  while(warning=1){
  digitalWrite(2,HIGH);
    digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(2,LOW);
    digitalWrite(3,LOW);
  delay(500);
  if(digitalRead(BTN_PIN_WARNING)==LOW && warning==1 ){
    warning=0;
  digitalWrite(2,LOW);
    digitalWrite(3,LOW);
    delay(500);
    break;
  }
  }
   }
 else   if(digitalRead(BTN_PIN_GAUCHE)==LOW && gauche==0){
 gauche=1;
 while(gauche=1){
 digitalWrite(2,HIGH);
  delay(500);
  digitalWrite(2,LOW);
  delay(500);
  if(digitalRead(BTN_PIN_GAUCHE)==LOW && gauche==1){
 gauche=0;
  digitalWrite(2,LOW);
  delay(500);
  break;
  }
 }


  
   }
else     if(digitalRead(BTN_PIN_DROIT)==LOW && droit==0){
  droit=1;
  while(droit=1){
 digitalWrite(3,HIGH);
  delay(500);
  digitalWrite(3,LOW);
  delay(500);
if(digitalRead(BTN_PIN_DROIT)==LOW && droit==1){
droit=0;
  digitalWrite(3,LOW);
  delay(500);
break;
   }   }
}

   
}
