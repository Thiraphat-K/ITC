/*
Use the I2C bus with EEPROM device
EEPROM 8 (Vcc) to Vcc
EEPROM 4 (GND) to GND
EEPROM 5 (SDA) to Arduino Analog Pin 4(SDA)
EEPROM 6 (SCL) to Arduino Analog Pin 5(SCL)
EEPROM 7 (WP) to GND
/* Memory length in bytes
24C01 = 128
24C02 = 256
24C04 = 512
24C08 = 1024
24C16 = 2048
24C64 = 8192
24C128= 16384
24C256= 32768
*/
#define memorylength 512
#include <Wire.h>
byte deviceAddress; // Address of EEPROM chip
unsigned int eepromAddress;
char arr[16] = {
0x41, 0x42, 0x43, 0x44, 0x45, 0x61, 0x62, 0x63, 0x64, 0x65,
0x31, 0x32, 0x33, 0x34, 0x35, 0x36};
char arr2[4] = {0x37, 0x38, 0x39, 0x30};
char str[] = " CE-KMITL";
void writeEEPROM_byte(int device,int address, byte data )
{
Wire.beginTransmission(device | address >> 8);
//Wire.write((int)(address >> 8)); // MSB
Wire.write((int)(address & 0xFF)); // LSB
Wire.write(data);
Wire.endTransmission();
delay(10);
}
void setup()
{
byte eepromAddress = 0; 
byte eepromData = 128;
byte i;
Serial.begin(9600); // Setup serial for debug
Wire.begin(); // Start I2C bus
for(i = 1; i < 127; i++ ) // sets the value (range from 1 to 127)
{
Wire.beginTransmission(i); // transmit to device
if (Wire.endTransmission() == 0) // I2C devices found
{
deviceAddress = i;
Serial.print("I2C Device Address: "); // Print Device Address
Serial.println(deviceAddress, HEX); // print as an ASCII-encoded hexa);
break;
}
}
writeEEPROM_byte(deviceAddress, eepromAddress, eepromData);
Serial.println(readEEPROM_byte(deviceAddress, eepromAddress), HEX);
writeEEPROM_page(deviceAddress, eepromAddress , (byte *)arr, sizeof(arr));
writeEEPROM_page(deviceAddress, 0x10, (byte *)arr2, sizeof(arr2));
writeEEPROM_page(deviceAddress, 0x14 , (byte *)str, sizeof(str));
}
void loop()
{
}
void writeEEPROM_page(int device, int address, byte* buffer, byte length )
{
byte i;
Wire.beginTransmission(device | address >> 8);
//Wire.write((int)(address >> 8)); // MSB
Wire.write((int)(address & 0xFF)); // LSB
for ( i = 0; i < length; i++)
Wire.write(buffer[i]);
Wire.endTransmission();
delay(10);
}
byte readEEPROM_byte(int device,int address )
{
byte rdata = 0;
Wire.beginTransmission(device | address >> 8);
//Wire.write((int)(address >> 8)); // MSB
Wire.write((int)(address & 0xFF)); // LSB
Wire.endTransmission();
Wire.requestFrom(device, 1);
if (Wire.available())
rdata = Wire.read();
return rdata;
}
