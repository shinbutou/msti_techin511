/*
 * Initial code by ArduinoGetStarted.com
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-neopixel-led-strip
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL  2   // Arduino pin that connects to NeoPixel
#define NUM_PIXELS     2  // The number of LEDs (pixels) on NeoPixel
Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

float smoothness_pts = 3333; // Larger this number is, slower the change would be
float gamma = 0.33; // Affecting the width of peak (more or less darkness)
float beta = 0.5; // Shifting the gaussian to be symmetric

void setup() {
  NeoPixel.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);

  // Turning on pixels one by one with delay between each pixel as the initialization process
  // for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
  //   NeoPixel.setPixelColor(pixel, NeoPixel.Color(87, 87, 87));
  //   NeoPixel.show();

  //   delay(200); // Pause between each pixel

  //   if (pixel == NUM_PIXELS - 1) {
  //     NeoPixel.clear();
  //     NeoPixel.show();
  //   }
  // }

  // Blue lighting: 169, 169, 255f
  // Yellow Lighting: 255, 150, 5
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
      NeoPixel.setPixelColor(pixel, NeoPixel.Color(169, 169, 255));
    }
  NeoPixel.show();
}

void loop() {
  // The breathing light function
  // for (int t = 0; t < smoothness_pts ; t++) {
  //   float brightness_value = 255.0 * (exp( - (pow(((t / smoothness_pts) - beta) / gamma, 2.0)) / 2.0)) - 20;
  //   // Serial.println(brightness_value); // Value-testing
  //   for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
  //     NeoPixel.setPixelColor(pixel, NeoPixel.Color(brightness_value, brightness_value, brightness_value));
  //   }
  //   NeoPixel.show();
  // }
  
}
