/*
Use the I2C bus with EEPROM device
EEPROM 8 (Vcc) to Vcc
EEPROM 4 (GND) to GND
EEPROM 5 (SDA) to Arduino Analog Pin 4(SDA) EEPROM 6 (SCL) to Arduino Analog Pin 5(SCL) EEPROM 7 (WP) to GND
/* Memory length in bytes 24C01 = 128
24C02 = 256
24C04 = 512
24C08 = 1024 24C16 = 2048 24C64 = 8192 24C128= 16384 24C256= 32768 */
#define memorylength 512 
#include <Wire.h>
byte deviceAddress;




void setup()
{
byte eepromAddress = 0;
byte eepromData = 128;
byte i;
writeEEPROM_byte(deviceAddress, eepromAddress, eepromData);
Serial.begin(9600); 
Wire.begin();
for(i = 1; i < 127; i++ )
// Address of EEPROM chip
// Setup serial for debug // Start I2C bus
// sets the value (range from 1 to 127)
// transmit to device // I2C devices found
// Print Device Address
// print as an ASCII-encoded hexa);
{
  Wire.beginTransmission(i);
  if (Wire.endTransmission() == 0)
  {
    deviceAddress = i;
    Serial.print("I2C Device Address: "); 
    Serial.println(deviceAddress, HEX);
  }  
}



} 
void loop() {
  
}
