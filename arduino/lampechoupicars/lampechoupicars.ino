#define DECODE_NEC 
#include <IRremote.hpp>
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

#define PIN 2
#define NUM_LEDS 12
 

#define REC_PIN 3



 Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, PIN, NEO_GRB + NEO_KHZ800);
void setup()
{
  Serial.begin(9600);
 
  IrReceiver.begin(REC_PIN, ENABLE_LED_FEEDBACK);
  // This is for Trinket 5V 16MHz, you can remove these three lines if you are not using a Trinket
  #if defined (__AVR_ATtiny85__)
    if (F_CPU == 16000000) clock_prescale_set(clock_div_1);
  #endif
  // End of trinket special code

  strip.begin();
  strip.setBrightness(100);
  strip.show(); // Initialize all pixels to 'off'
 colorWipe(strip.Color(127, 127, 127), 50);
}

void loop() {
  // put your main code here, to run repeatedly:
if (IrReceiver.decode()) {
      Serial.println(IrReceiver.decodedIRData.decodedRawData, HEX);
     IrReceiver.printIRResultShort(&Serial); // optional use new print version
      IrReceiver.resume(); // Enable receiving of the next value

if(IrReceiver.decodedIRData.decodedRawData==0xBA45FF00){
colorWipe(strip.Color(255, 0, 0), 50);

}else if(IrReceiver.decodedIRData.decodedRawData==0xB946FF00){
   colorWipe(strip.Color(127, 127, 127), 50); // white
}
else if(IrReceiver.decodedIRData.decodedRawData==0xB847FF00){
    colorWipe(strip.Color(0, 0, 255), 50); // Blue
}
else if(IrReceiver.decodedIRData.decodedRawData==0xBB44FF00){
   theaterChase(strip.Color(0, 255, 0), 50); // green
}
else if(IrReceiver.decodedIRData.decodedRawData==0xBF40FF00){
    theaterChase(strip.Color(127, 0, 0), 50); // Red
}
else if(IrReceiver.decodedIRData.decodedRawData==0xBC43FF00){
   theaterChase(strip.Color(0, 0, 127), 50); // Blue
}
else if(IrReceiver.decodedIRData.decodedRawData==0xF807FF00){
   rainbow(20);
}
else if(IrReceiver.decodedIRData.decodedRawData==0xEA15FF00){
    rainbowCycle(20);
}
else if(IrReceiver.decodedIRData.decodedRawData==0xF609FF00){
   theaterChaseRainbow(50);
}   
else if(IrReceiver.decodedIRData.decodedRawData==0xE619FF00){
   colorWipe(strip.Color(0, 0, 0), 50);
}  
/*
 // Some example procedures showing how to display to the pixels:
  colorWipe(strip.Color(255, 0, 0), 50); // Red
  colorWipe(strip.Color(0, 255, 0), 50); // Green
  colorWipe(strip.Color(0, 0, 255), 50); // Blue
//colorWipe(strip.Color(0, 0, 0, 255), 50); // White RGBW
  // Send a theater pixel chase in...
  theaterChase(strip.Color(127, 127, 127), 50); // White
  theaterChase(strip.Color(127, 0, 0), 50); // Red
  theaterChase(strip.Color(0, 0, 127), 50); // Blue

  rainbow(20);
  rainbowCycle(20);
  theaterChaseRainbow(50);
*/

}
}



// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}

void rainbow(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256; j++) {
    for(i=0; i<strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i+j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;
for (int k=0;k<=20;k++){
  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}
}
//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j=0; j<100; j++) {  //do 10 cycles of chasing
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, c);    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j=0; j < 256; j++) {     // cycle all 256 colors in the wheel
    for (int q=0; q < 3; q++) {
      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, Wheel( (i+j) % 255));    //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i=0; i < strip.numPixels(); i=i+3) {
        strip.setPixelColor(i+q, 0);        //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if(WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if(WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
