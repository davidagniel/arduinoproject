#include <FastLED.h>
#define LED_PIN 2
#define NUM_LEDS 21
#define BTN_PIN 4
int compt=0; // variable de comptage
int oldcompt=0;
CRGB leds[NUM_LEDS];


void setup() {
  
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();
pinMode(BTN_PIN, INPUT_PULLUP); 
 for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(0, 255 - 10*i, 10*i );
    FastLED.setBrightness(2*i);
    FastLED.show();
    delay(50);
  }
  // Turn lights from blue to magenta from right to left 
  for (int i=NUM_LEDS; i>0; i--){
    leds[i] = CRGB(10*i,0 , 255-10*i);
    FastLED.setBrightness(100-i);
    FastLED.show();
    delay(50);
  }
//attachInterrupt(digitalPinToInterrupt(2),mafonction,FALLING);

}

void loop() {

  if(digitalRead(BTN_PIN)==LOW){
  compt=compt+1;
  }
if (compt != oldcompt){
if (compt<0) compt=1;
if (compt>3) compt=1;
switch (compt){
  case 1:

 Serial.println("vert");

  for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(0,255,0);
    FastLED.setBrightness(10);
    FastLED.show();
   
  }
 
 break;

  case 2:
 Serial.println("rouge");

  for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(255,0,0);
    FastLED.setBrightness(50);
    FastLED.show();
  }
 
 break;


  case 3:

 Serial.println("bleu");

  for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(0,0,255);
    FastLED.setBrightness(50);
    FastLED.show();
   
  }
 
 break;



}
oldcompt=compt;
delay(300);

}
}
