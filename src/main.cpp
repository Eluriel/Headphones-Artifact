#include <Arduino.h>
#include <Adafruit_NeoPixel.h>

#define NEOPIXEL_PIN 21
#define NUMPIXELS 3

Adafruit_NeoPixel pixels(NUMPIXELS, NEOPIXEL_PIN, NEO_GRB + NEO_KHZ800);
int dir = 1;
int bright = 0;
// put function declarations here:
void setup() {
  Serial.begin(9600);
  pixels.begin();
  randomSeed(analogRead(0));
}

void loop() {
  pixels.clear();

  for(int i=0; i<NUMPIXELS; i++) {

  uint32_t blueFade = pixels.ColorHSV(43650,255,bright); //set blueFade color to variable bright
  pixels.fill(blueFade);                                 //fill strip with color blueFade
  pixels.show();                                         //send data to strip
  bright = bright + dir;                                //change bright by +1 or -1
  if(bright > 100 || bright < 1) dir = dir * -1;        //set dir to +1 or -1
  delay(1000); 

  int sensorValue = analogRead(1);
  Serial.println(sensorValue);
  }
}
