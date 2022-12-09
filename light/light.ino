/*
 * Initial code by ArduinoGetStarted.com
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-neopixel-led-strip
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL  2   // Arduino pin that connects to NeoPixel
#define NUM_PIXELS     18  // The number of LEDs (pixels) on NeoPixel
Adafruit_NeoPixel NeoPixel(NUM_PIXELS, PIN_NEO_PIXEL, NEO_GRB + NEO_KHZ800);

float smoothness_pts = 3333; // Larger this number is, slower the change would be
float gamma = 0.33; // Affecting the width of peak (more or less darkness)
float beta = 0.5; // Shifting the gaussian to be symmetric

int timer = 0; // Shifting

void setup() {
  NeoPixel.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)
  Serial.begin(9600);

  // Turning on pixels one by one with delay between each pixel as the initialization process
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
    NeoPixel.setPixelColor(pixel, NeoPixel.Color(87, 87, 87));
    NeoPixel.show();

    delay(200); // Pause between each pixel

    if (pixel == NUM_PIXELS - 1) {
      NeoPixel.clear();
      NeoPixel.show();
    }
  }
}

void loop() {
  // The breathing light function
  for (int t = 0; t < smoothness_pts ; t++) {
    float brightness_value = 255.0 * (exp( - (pow(((t / smoothness_pts) - beta) / gamma, 2.0)) / 2.0)) - 20;
    timer += 1;
    // Serial.println(brightness_value); // Value-testing
    if (timer % 100 == 0) {
      Serial.println(timer); // Value-testing
    }

    for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {
      if (timer <= 1000) {
        NeoPixel.setPixelColor(pixel, NeoPixel.Color(brightness_value, brightness_value, brightness_value));
        Serial.println("White");
      } else if (timer > 1000 && timer <= 2000) { // Blue lighting: 121, 121, 255
        NeoPixel.setPixelColor(pixel, NeoPixel.Color(brightness_value * 121.0 / 255.0, brightness_value * 121.0 / 255.0, brightness_value));
        Serial.println("Blue");
      } else { // Yellow Lighting: 255, 150, 5
        NeoPixel.setPixelColor(pixel, NeoPixel.Color(brightness_value, brightness_value * 150.0 / 255.0, brightness_value * 5.0 / 255.0));
        Serial.println("Yellow");
      }
    }
    NeoPixel.show();
  }
}
