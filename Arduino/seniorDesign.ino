#include <Conceptinetics.h>

#define DMX_MASTER_CHANNELS 5
#define TXEN_PIN 10

DMX_Master dmx_master(DMX_MASTER_CHANNELS, TXEN_PIN);

void setup()
{
  pinMode(TXEN_PIN, OUTPUT);
  dmx_master.enable();
}

void loop()
{
  dmx_master.setChannelValue(1, 0); // petals 1-4
  dmx_master.setChannelValue(2, 0); // petals 5-8
  dmx_master.setChannelValue(3, 0); // petals 9-12
  dmx_master.setChannelValue(4, 150); //UV lights
  dmx_master.setChannelValue(5, 150); //LED Lights

  delay(30);
}