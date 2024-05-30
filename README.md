# Headphones Artefact

Project made for a LARP where the character is deaf and has created an artifact that allows him to hear.

## Hardware

- Arduino Nano Every
- 3 Adafruit Neopixel 8mm through hole diffused
- 1 push button
- 1 Sensor Sparkfun Sound mode

## Wiring

See `main.h` for wiring.

## Software

There are three modes available:

- Sound Mode
- Solid Mode
- Fade Mode

The default mode is SOUND mode. To change the mode, do a long press on the button.

A short press on the button will change the color.

### Sound Mode

In this mode, the sound will change the LED brightness.
This is done using an exponential smoothing, the ALPHA factor can be changed if needed.

### Solid Mode

This mode will display solid color with no change.

### Fade Mode

In this mode, the brightness will fade from lower to higher and then down.
