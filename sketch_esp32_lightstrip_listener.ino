#include <FastLED.h>

#define NUM_LEDS 60
#define DATA_PIN 5
#define BRIGHTNESS 255 // We leave this at maximum, the webpage handles the fading!

CRGB leds[NUM_LEDS];

void setup() {
  // Open the USB ears of the ESP32
  Serial.begin(115200); 
  
  FastLED.addLeds<WS2812B, DATA_PIN, GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  FastLED.clear();
  FastLED.show();
}

void loop() {
  // If the webpage is sending us a message...
  if (Serial.available() > 0) {
    
    // 1. Look for the secret password 'L', 'E', 'D' so we know it's a color message
    if (Serial.read() == 'L') {
      while(Serial.available() < 2) { } // Wait a tiny millisecond
      if (Serial.read() == 'E' && Serial.read() == 'D') {
        
        // 2. The password is correct! Now wait for all 180 color bytes to arrive (60 LEDs x 3 colors)
        while(Serial.available() < NUM_LEDS * 3) { } 
        
        // 3. Scoop up the colors and put them directly on the strip!
        Serial.readBytes((char*)leds, NUM_LEDS * 3);
        FastLED.show();
      }
    }
  }
}