#include <SPI.h>
#include <Adafruit_GFX.h>
#include <TT_Max72xx.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
// i.e. connect CS to 10, DIN to 11, CLK to 13
int numberOfHorizontalDisplays = 8;
int numberOfVerticalDisplays = 1;

TT_Max72xx matrix = TT_Max72xx(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "TinkerTech :)";
int wait = 20; // In milliseconds

void setup() {

  matrix.setIntensity(7); // Use a value between 0 and 15 for brightness

  for(int i = 0; i < 4; i++) {
    matrix.setPosition(i, i, 0);  // The i'th display is at <i, 0>
  }

  for(int i = 0; i < 8; i++) {
    matrix.setRotation(i, 1);     // rotate all TinkerTech displays 90 degrees
  }
}

void loop() {
  matrix.printToDisplay(tape, wait);
}
