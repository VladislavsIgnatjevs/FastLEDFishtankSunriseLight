#include "FastLED.h"

#define NUM_LEDS 27
#define DATA_PIN 2

#define LENGTH_MINUTES 60

CRGB leds[NUM_LEDS];

void setup() {
  delay(2000);
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
}


void loop() {
  FastLED.show();

  sunrise();
}

void sunrise() {

  // length
  static const uint8_t sunriseLength = LENGTH_MINUTES;

  //interval of color change
  static const uint8_t interval = (sunriseLength * 60) / 256;

  //start with 0 color on the palette
  static uint8_t heatIndex = 0;

  // HeatColors_p
  CRGB color = ColorFromPalette(HeatColors_p, heatIndex);

  //fill strip
  fill_solid(leds, NUM_LEDS, color);

  // slowly increase the color
  EVERY_N_SECONDS(interval) {

    if (heatIndex < 255) {
      heatIndex++;
    }
  }
}
