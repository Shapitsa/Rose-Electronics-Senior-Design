#include <Conceptinetics.h>

#define DMX_SLAVE_CHANNELS 5
#define RXEN_PIN 2

DMX_Slave dmx_slave(DMX_SLAVE_CHANNELS, RXEN_PIN);

const int outputPin1 = 6; 
const int outputPin2 = 9;
const int outputPin3 = 11;
const int outputPin4 = 5;
const int outputPin5 = 3;

void setup()
{
  pinMode(outputPin1, OUTPUT);
  pinMode(outputPin2, OUTPUT);
  pinMode(outputPin3, OUTPUT);
  pinMode(outputPin4, OUTPUT);
  pinMode(outputPin5, OUTPUT);

  dmx_slave.setStartAddress(1);
  dmx_slave.enable();
}

void loop()
{
  int ch1 = dmx_slave.getChannelValue(1);
  int ch2 = dmx_slave.getChannelValue(2);
  int ch3 = dmx_slave.getChannelValue(3);
  int ch4 = dmx_slave.getChannelValue(4);
  int ch5 = dmx_slave.getChannelValue(5);

  analogWrite(outputPin1, ch1);
  analogWrite(outputPin2, ch2);
  analogWrite(outputPin3, ch3);
  analogWrite(outputPin4, min(ch4, 140));
  analogWrite(outputPin5, min(ch5, 220));
}