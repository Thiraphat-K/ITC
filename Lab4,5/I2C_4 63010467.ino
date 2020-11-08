// Write data to I2C slave device
#include <Wire.h>
void setup()
{
  Wire.begin(); // Start I2C bus
  Serial.begin(115200); // Setup serial for debug
}
void loop()
{
  byte address, data, device;
  for (address = 1; address < 127; address++ ) // sets the value (range from 1 to 127)
  {
    Wire.beginTransmission(address); // transmit to address
    if (Wire.endTransmission() == 0) // I2C devices found
    {
      device = address;
      Serial.print("\n I2C Device Address: "); // Print Device Address
      Serial.println(address, HEX); // print as an ASCII-encoded hexa);
    }
  }
  for (data = 0 ; data <= 255; data++) // sets the value (range from 0 to 255)
  {
    Wire.beginTransmission(device); // transmit to device
    Wire.write(data); // sends one byte
    Wire.endTransmission(); // stop transmitting
    Serial.print("\npin state : Out = "); // Print pin state
    Serial.print(data, BIN); // print as an ASCII-encoded binary);
    delay(10); // wait for 10 milliseconds

  }
}
