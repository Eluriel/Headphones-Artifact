#include <Arduino.h>
#include <FastLED.h>        // https://github.com/FastLED/FastLED
#include <OneButton.h>

FASTLED_USING_NAMESPACE

// Input / Output
#define BUTTON_PIN 4
#define NEOPIXEL_PIN 6
#define ENVELOPE_PIN A4 // Envelope Pin of the Sparkfun Sound Detector Module

// Application constants
#define NUM_LEDS 3
#define BRIGHTNESS      255 // Min: 0, Max: 255
#define SATURATION      255 // Min: 0, Max: 255
#define MIN_VAL          10 // Min: 0, Max: 75
#define MAX_VAL         200 // Min: 75, Max: 750
#define HUE_INIT         HUE_AQUA // < 255
#define HUE_CHANGE       32 // < 255
#define ALPHA           0.1 // Smoothing factor (0 < alpha <= 1)

enum LedModes {
  SOUND_MODE = 0,
  SOLID_MODE = 1,
  FADE_MODE = 2,
};

enum FadeDirection {
  STANDARD = 0,
  REVERSE = 1,
};