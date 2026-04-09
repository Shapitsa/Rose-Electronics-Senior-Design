# Rose-Electronics-Senior-Design

## 2026-04-09

Debugging session.  Using "DMX Cat" test tool, which the Arduino
receiver using the Conceptinetics DMX library doesn't like.

References:

* Using [DMXcat](https://www.citytheatrical.com/products/electronics/other-electronic/dmxcat-multi-function-test-tool)
* Conceptinetics libraries in use _probably_ from here:  https://github.com/alfo/arduino-libraries

Using the o-scope we determined that the DMXcat is sending plausible DMX data,
at the std bit rate of 250kHz.  This looks superficially the same as data sent
by both the Arduino master Anna has and also the example from the DMXSerial
Arduino library.

The problem remains a mystery... will pick it up 
