#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Max72xxPanel.h>

int pinCS = 10; // Attach CS to this pin, DIN to MOSI and CLK to SCK (cf http://arduino.cc/en/Reference/SPI )
// i.e. connect CS to 10, DIN to 11, CLK to 13
int numberOfHorizontalDisplays = 8;
int numberOfVerticalDisplays = 1;

Max72xxPanel matrix = Max72xxPanel(pinCS, numberOfHorizontalDisplays, numberOfVerticalDisplays);

String tape = "TinkerTech :)";
int wait = 20; // In milliseconds

void setup() {

  matrix.setIntensity(7); // Use a value between 0 and 15 for brightness

  matrix.setPosition(0, 0, 0); // The first display is at <0, 0>
  matrix.setPosition(1, 1, 0); // The second display is at <1, 0>
  matrix.setPosition(2, 2, 0); // The third display is at <2, 0>
  matrix.setPosition(3, 3, 0); // And the last display is at <3, 0>

  // TODO: IS THERE ANY WAY TO WRITE THIS IN A LOOP?
  matrix.setRotation(0, 1);
  matrix.setRotation(1, 1);
  matrix.setRotation(2, 1);
  matrix.setRotation(3, 1);
  matrix.setRotation(4, 1);
  matrix.setRotation(5, 1);
  matrix.setRotation(6, 1);
  matrix.setRotation(7, 1);
}

void loop() {
  matrix.printToDisplay(tape, wait);
}

