/*
  Machine Control - Digital Output Example

  This sketch shows how to send values on the
  DIGITAL OUT channels on the Machine Control.
  Please remember that pin "24V IN" of the connector
  DIGITAL_OUTPUTS must be connected to 24V.
  The DIGITAL OUT channels are high side switches
  capable to handle up to 0.5A. There is an over current
  protection that open the channel when the current is
  above 0.7A with a +-20% tolerance.
  The over current protection can be set to have two
  different behaviors, and it is the same for all channels:
    1) Latch mode: when the over current is detected
       the channel is opened, and will remain opened until
       it is toggled via software.
    2) Auto retry: when the over current is detected
       the channel is opened, but after some tens of
       milliseconds the channel will automatically try
       to close itself again. In case of a persistent
       overcurrent the channel will continuously toggle.
  
  The circuit:
   - Portenta H7
   - Machine Control

  This example code is in the public domain.
*/

#include <Arduino_MachineControl.h>

void setup() {
  Serial.begin(9600);
  // The loop starts only when the Serial Monitor is opened.
  while (!Serial);

  MachineControl_DigitalOutputs.begin();

  //Set over current behavior of all channels to latch mode:
  MachineControl_DigitalOutputs.setLatch();

  // Uncomment this line to set over current behavior of all
  // channels to auto retry mode instead of latch mode:
  //MachineControl_DigitalOutputs.setRetry();
  
  //At startup set all channels to OPEN
  MachineControl_DigitalOutputs.writeAll(0);
}


void loop() {
  Serial.println("DIGITAL OUT:");
  
  // Set all channels to CLOSED
  MachineControl_DigitalOutputs.writeAll(255);
  Serial.print("All channels are CLOSED for 1 s...");
  delay(1000);
  
  // Set all channels to OPEN
  MachineControl_DigitalOutputs.writeAll(0);
  Serial.println("now they are OPEN.");
  delay(1000);

  // Toggle each channel for 1 s, one by one
  
  MachineControl_DigitalOutputs.write(0, HIGH);
  Serial.print("CH0 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(0, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(1, HIGH);
  Serial.print("CH1 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(1, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(2, HIGH);
  Serial.print("CH2 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(2, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(3, HIGH);
  Serial.print("CH3 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(3, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(4, HIGH);
  Serial.print("CH4 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(4, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(5, HIGH);
  Serial.print("CH5 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(5, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(6, HIGH);
  Serial.print("CH6 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(6, LOW);
  Serial.println("now is OPEN.");

  MachineControl_DigitalOutputs.write(7, HIGH);
  Serial.print("CH7 is CLOSED for 1 s...");
  delay(1000);
  MachineControl_DigitalOutputs.write(7, LOW);
  Serial.println("now is OPEN.");

  Serial.println();
  delay(1000);
}