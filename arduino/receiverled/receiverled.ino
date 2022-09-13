#define DECODE_NEC 
#include <IRremote.hpp>
#include <FastLED.h>
#define LED_PIN 3
#define NUM_LEDS 63
 
#define REC_PIN 2
 CRGB leds[NUM_LEDS];
void setup()
{
  Serial.begin(9600);
 
  IrReceiver.begin(REC_PIN, ENABLE_LED_FEEDBACK);
  FastLED.addLeds<WS2812, LED_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
  FastLED.clear();
  FastLED.show();

}


void loop() {
 
 if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     IrReceiver.printIRResultShort(&Serial); // optional use new print version
      IrReceiver.resume(); // Enable receiving of the next value
if(IrReceiver.decodedIRData.decodedRawData ==0xA55AFF00){
   for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(0, 0, 0 );
    FastLED.setBrightness(100);
    FastLED.show();
   //jaune
  }}else if(IrReceiver.decodedIRData.decodedRawData==0xAC53FF00){
     for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(255, 255, 0 );
    FastLED.setBrightness(100);
    FastLED.show();
    }
  //rouge
  }else if(IrReceiver.decodedIRData.decodedRawData==0xAF50FF00){
     for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(255, 0, 0 );
    FastLED.setBrightness(100);
    FastLED.show();
    }
  //violet
  }else if(IrReceiver.decodedIRData.decodedRawData==0xEF10FF00){
     for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(255, 0, 255 );
    FastLED.setBrightness(100);
    FastLED.show();
    }
  //rose
  }else if(IrReceiver.decodedIRData.decodedRawData==0xA857FF00){
     for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(249, 66, 158 );
    FastLED.setBrightness(100);
    FastLED.show();
    }
  
  }else if(IrReceiver.decodedIRData.decodedRawData==0xAB54FF00){
     for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(250, 164, 1 );
    FastLED.setBrightness(100);
    FastLED.show();
    }
  
  }else if(IrReceiver.decodedIRData.decodedRawData==0xEB14FF00){
     for (int i=0; i<NUM_LEDS; i++){
    leds[i] = CRGB(255, 255, 255 );
    FastLED.setBrightness(100);
    FastLED.show();
    }
  
  }



  
  }
  
}
