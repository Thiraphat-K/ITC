#include <Wire.h>
void setup()
{
  Wire.begin(); // Start I2C bus
  Serial.begin(115200); // Setup serial for debug
}
void loop()
{
  byte address, data, device;
  data = 0x80;
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

  for (int i = 1 ; i <= 4; i++) // sets the value (range from 1 to 8)
  {
    Wire.beginTransmission(device); // transmit to device
    Wire.write(data); // sends one byte
    Wire.endTransmission(); // stop transmitting
    Serial.print("pin state : Out = "); // Print pin state
    Serial.print(data, BIN); // print as an ASCII-encoded binary);
    delay(5); // wait for stepper speed
    data = data >> 1;
    Wire.requestFrom(device, 1); // receive 1 bytes from slave device
    int x = Wire.read(); // Read pin state
    Serial.print("\t, In = "); // Print pin state
    Serial.println(x, BIN); // print as an ASCII-encoded binary);
  }
}
