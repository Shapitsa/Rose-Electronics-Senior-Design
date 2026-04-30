#include <DMXSerial.h>

// Pins
const int outputPin1 = 6; 
const int outputPin2 = 9;
const int outputPin3 = 11;
const int outputPin4 = 5;
const int outputPin5 = 3;

const int startChannel = 0 * 5 + 1;

#define pin1DefaultLevel 0
#define pin2DefaultLevel 0
#define pin3DefaultLevel 0
#define pin4DefaultLevel 0
#define pin5DefaultLevel 0

void setup()
{
  DMXSerial.init(DMXReceiver);

  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(outputPin4, OUTPUT);
  pinMode(outputPin5, OUTPUT);
}

void loop()
{
  // Calculate how long no data bucket was received
  unsigned long lastPacket = DMXSerial.noDataSince();


if (lastPacket <5000){
  
  int ch1 = DMXSerial.read(startChannel); 
  int ch2 = DMXSerial.read(startChannel +1);
  int ch3 = DMXSerial.read(startChannel +2);
  int ch4 = DMXSerial.read(startChannel +3);
  int ch5 = DMXSerial.read(startChannel +4);
  
  analogWrite(outputPin1, ch1);
  analogWrite(outputPin2, ch2);
  analogWrite(outputPin3, ch3);
  analogWrite(outputPin4, min(ch4, 140));
  analogWrite(outputPin5, min(ch5, 220));

}


}