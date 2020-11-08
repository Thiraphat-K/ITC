// Write data to I2C slave device
#include <Wire.h>
void setup()
{
  Wire.begin(); // Start I2C bus
  Serial.begin(115200); // Setup serial for debug
  pinMode(LED_BUILTIN, OUTPUT);
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
  Wire.requestFrom(device, 1); // recive 1 bytes from slave device
  char x = Wire.read(); // Read pin state
  Wire.requestFrom(device, 1, 0);
  Serial.print("\t pin state : In = "); // Print pin state
  Serial.print(x, BIN); // print as an ASCII-encoded binary);
  x = x & 0x0f;
  if ((x & 4) != 4)
  {
    for (data = 32 ; data <= 63; data++) // sets the value (range from 0 to 255)
    {
      Wire.beginTransmission(device); // transmit to device
      Wire.write(data); // sends one byte
      Wire.endTransmission(); // stop transmitting
      Serial.print("pin state : Out = "); // Print pin state
      Serial.println(data, BIN); // print as an ASCII-encoded binary)
    }
  }
  else
  {
    for (data = 0 ; data <= 31; data++) // sets the value (range from 0 to 255)
    {
      Wire.beginTransmission(device); // transmit to device
      Wire.write(data); // sends one byte
      Wire.endTransmission(); // stop transmitting
      Serial.print("pin state : Out = "); // Print pin state
      Serial.println(data, BIN); // print as an ASCII-encoded binary);
    }
  }
  delay(10);
}
