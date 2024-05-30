#include "main.h"

CRGB leds[NUM_LEDS];
int mode = 0;
int currentHue = HUE_INIT;
float smoothedValue = 0.0; // Exponential smoothing

OneButton btn = OneButton(
  BUTTON_PIN,  // Input pin for the button
  true,        // Button is active LOW
  true         // Enable internal pull-up resistor
);

void setup() {
  Serial.begin(9600);

  pinMode(ENVELOPE_PIN, INPUT); 

  // Define the LED and put them to black
  FastLED.addLeds<NEOPIXEL,NEOPIXEL_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Black;
  }

  // Put default HUE value
  currentHue = HUE_INIT;

  // Update the LED Strip
  FastLED.show(); 

  // Change the color when doing a simple click
  btn.attachClick([](){
    Serial.println("Change Color");
    currentHue += HUE_CHANGE;
    if(currentHue > 255)
      currentHue = 0;
  });

  // Perform a long press to change the mode
  btn.attachLongPressStart([]() {
    Serial.println("Change Mode");
    mode += 1;
  });
}
void solidMode(){
    for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(currentHue, SATURATION, 255/2);
  }
}

void soundMode(){
  // Read from sound sensor
  int analogVal = analogRead(A0);

  if(analogVal > MAX_VAL)
    analogVal = MAX_VAL;

  if(analogVal < MIN_VAL)
    analogVal = MIN_VAL;

  // Convert the value from analog input to 0-BRIGHTNESS
  int val = map(analogVal, MIN_VAL, MAX_VAL, 0, BRIGHTNESS);

  // Apply exponential smoothing
  smoothedValue = ALPHA * val + (1.0 - ALPHA) * smoothedValue;

  for(int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CHSV(currentHue, SATURATION, smoothedValue);
  }
}

void loop() {
  switch (mode) {
    case SOUND_MODE:
      soundMode();
      break;
    case SOLID_MODE:
      solidMode();
      break;
    case FADE_MODE:
      // fadeMode();
      break;
    default:
      // Reset to first mode
      mode = 0;
      break;
  }

  // Update the LED Strip
  FastLED.show();

  // Refresh the button
  btn.tick();

  delay(10);
}