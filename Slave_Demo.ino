/* Will Keyser
 * 2013
 * -----------------------
 * DMX512 Slave Demo
 * with 3 MOSFET driven channels
 * one for each color (RGB)
 */
 
#include <DMXSerial.h>

// Variables for demo program
int RedChannel =   1;
int GreenChannel = 2;
int BlueChannel =  3;

const int RedPin =    9;  // PWM output pin for Red Light.
const int GreenPin =  6;  // PWM output pin for Green Light.
const int BluePin =   5;  // PWM output pin for Blue Light.

#define RedDefaultLevel   100
#define GreenDefaultLevel 200
#define BlueDefaultLevel  255

void setup () {
  DMXSerial.init(DMXReceiver);
  
  // set some default values
  DMXSerial.write(RedChannel, 80);
  DMXSerial.write(GreenChannel, 0);
  DMXSerial.write(BlueChannel, 0);
  
  // enable pwm outputs
  pinMode(RedPin,   OUTPUT); // sets the digital pin as output
  pinMode(GreenPin, OUTPUT);
  pinMode(BluePin,  OUTPUT);
}


void loop() {
  // Calculate how long no data backet was received
  unsigned long lastPacket = DMXSerial.noDataSince();
  
  if (lastPacket < 5000) {
    // read recent DMX values and set pwm levels 
    analogWrite(RedPin,   DMXSerial.read(RedChannel));
    analogWrite(GreenPin, DMXSerial.read(GreenChannel));
    analogWrite(BluePin,  DMXSerial.read(BlueChannel));

  } else {
    // Show pure red color, when no data was received since 5 seconds or more.
    analogWrite(RedPin,   RedDefaultLevel);
    analogWrite(GreenPin, GreenDefaultLevel);
    analogWrite(BluePin,  BlueDefaultLevel);
  } // if
}

// End.
