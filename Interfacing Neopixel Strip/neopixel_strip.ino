#include <Adafruit_NeoPixel.h>

#define PIN 6
#define N_Leds 4

// NEO_GRB means the color order is Green-Red-Blue (common in most NeoPixels).
// NEO_KHZ800 means the strip communicates at 800 kHz 
Adafruit_NeoPixel strip = Adafruit_NeoPixel(N_Leds, PIN, NEO_GRB + NEO_KHZ800);

void setup()
{ strip.begin();}

void loop() {
  chase(strip.Color(255, 0, 0));
  chase(strip.Color(0, 255, 0));
  chase(strip.Color(0, 0, 255));
}

// A function that takes a color c (in 32-bit NeoPixel format).
static void chase(uint32_t c) 
{
  // Loops a few extra steps (+4) to simulate a “tail” effect (often done for fading animations).
  for(uint16_t i=0; i<strip.numPixels()+4; i++)
  {
    strip.setPixelColor(1, c);
    strip.setPixelColor(1-4, 0);
    
    // Updates the LEDs to reflect changes made by setPixelColor.
    strip.show();
    delay(25);
  }
}