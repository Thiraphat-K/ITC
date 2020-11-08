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
  //address check
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

  //step motor
  Wire.requestFrom(device, 1); // recive 1 bytes from slave device
  char x = Wire.read(); // Read pin state
  Serial.print("\t pin state : In = "); // Print pin state
  Serial.print(x, BIN); // print as an ASCII-encoded binary);
  x = x & 0x0f;

  if ((x & 1) == 0)
  {
    data = 0x80 | x;
    for (int i = 1 ; i <= 4; i++) // sets the value (range from 1 to 4)
    {
      switch (i) {

        case 1: data = B00010111; break;
        case 2: data = B00100111; break;
        case 3: data = B01000111; break;
        case 4: data = B10000111; break;
      }
      Wire.beginTransmission(device); // transmit to device
      Wire.write(data); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed
      Serial.print("\n Out = "); // Print pin state
      Serial.print(data, BIN); // print as an ASCII-encoded binary);

    }

  }
  else
  {
    data = 0x80 | x;
    for (int i = 1 ; i <= 4; i++) // sets the value (range from 1 to 4)
    {
      switch (i) {
        case 1: data = B10000111; break;
        case 2: data = B01000111; break;
        case 3: data = B00100111; break;
        case 4: data = B00010111; break;
      }

      Wire.beginTransmission(device); // transmit to device
      Wire.write(data); // sends one byte
      Wire.endTransmission(); // stop transmitting
      delay(5); // wait for stepper speed

      Serial.print("\n Out = "); // Print pin state
      Serial.print(data, BIN); // print as an ASCII-encoded binary);

    }
  }
}
