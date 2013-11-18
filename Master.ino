/* Will Keyser
 * 2013
 * -----------------------
 * DMX512 Master
 * with 3 potentiometers
 * one for each color (RGB)
 */

#include <DmxMaster.h>
// Init the Pins used for PWM
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

// Init the Pins used for 10K pots
const int redPotPin = 0;
const int greenPotPin = 1;
const int bluePotPin = 2;

// Init our Vars
int currentColorValueRed;
int currentColorValueGreen;
int currentColorValueBlue;

void setup()
{
  DmxMaster.usePin(3);
  
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
  
  DmxMaster.maxChannel(4);
}

void loop()
{
  
// Read the voltage on each analog pin then scale down to 0-255 and inverting the value for common anode
  currentColorValueRed = (255 - map( analogRead(redPotPin), 0, 1024, 0, 255 ) ); 
  currentColorValueBlue = (255 - map( analogRead(bluePotPin), 0, 1024, 0, 255 ) );
  currentColorValueGreen = (255 - map( analogRead(greenPotPin), 0, 1024, 0, 255 ) );

// Write the color to each channel using PWM and the value gathered above
  DmxMaster.write(redPin, currentColorValueRed);
  DmxMaster.write(bluePin, currentColorValueBlue);
  DmxMaster.write(greenPin, currentColorValueGreen);

}
