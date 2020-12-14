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
#define memorylength 2048
#include <Wire.h>
byte deviceAddress; // Address of EEPROM chip
unsigned int eepromAddress;
const int led1 = 8;
const int led2 = 7;

char arr1[16] = "THIRAPHAT";
char arr2[16] = "63010467";
char arr3[16] = "1509966044969";

void setup()
{
  byte eepromData;
  byte i;

  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600); // Setup serial for debug
  Wire.begin(); // Start I2C bus
  for (i = 1; i < 127; i++ ) // sets the value (range from 1 to 127)
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
  eepromAddress = 0;
  eepromData = 128;
  writeEEPROM_byte(deviceAddress, eepromAddress, eepromData);
  writeEEPROM_page(deviceAddress, 0x202, (byte *)arr1, sizeof(arr1));
  writeEEPROM_page(deviceAddress, 0x402 , (byte *)arr2, sizeof(arr2));
  //char str[] = "CE-KMITL";
  writeEEPROM_page(deviceAddress, 0x602, (byte *)arr3, sizeof(arr3));
  byte ch;
  Serial.println(" ");
  eepromAddress = 0; // first address
  ch = readEEPROM_byte(deviceAddress, eepromAddress); // access the first address from the memory
  while (ch != 0)
  {
    Serial.print((char) ch); // print content to serial port
    eepromAddress++; // increase address
    ch = readEEPROM_byte(deviceAddress, eepromAddress); // access an address from the memory
  }

  delay(2000);
  Serial.println(" ");
  dumpEEPROM(deviceAddress, 0, memorylength);
}
void loop()
{
  eepromAddress = 0x402;
  for (int i = 0; i < 8; i++)
  {
    for (int j = readEEPROM_byte(deviceAddress, eepromAddress+i) - '0'; j > 0; j--)
    {
      digitalWrite(led2, HIGH);
      delay(250);
      digitalWrite(led2, LOW);
      delay(250);
    }
    //if(i<8){
    digitalWrite(led1, HIGH);
    delay(500);
    digitalWrite(led1, LOW);
    delay(500);//}
  }
  digitalWrite(led1, HIGH);
  digitalWrite(led2, HIGH);
  delay(1000);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  delay(1000);
}

void writeEEPROM_byte(int device, unsigned int address, byte data )
{
  Wire.beginTransmission(device);
  Wire.beginTransmission(device | (int(address >> 8) & 0b111));
  Wire.write((int)(address & 0xFF));
  Wire.write(data);
  Wire.endTransmission();
  delay(10);
}
byte readEEPROM_byte(int device, unsigned int address )
{
  byte rdata = 0;
  Wire.beginTransmission(device);
  Wire.beginTransmission(device | (int(address >> 8) & 0b111));
  Wire.write((int)(address & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(device, 1);
  if (Wire.available())
    rdata = Wire.read();
  return rdata;
}
void writeEEPROM_page(int device, unsigned int address, byte* buffer, byte length )
{
  byte i;
  Wire.beginTransmission(device);
  Wire.beginTransmission(device | (int(address >> 8) & 0b111));
  Wire.write((int)(address & 0xFF));
  for ( i = 0; i < length; i++)
  {
    Wire.write(buffer[i]);
  }
  Wire.endTransmission();
  delay(10);
}
void dumpEEPROM(byte device, unsigned address, unsigned length)
{
  unsigned startAddress = address;
  unsigned stopAddress = address + length;
  for (unsigned i = startAddress; i < stopAddress; i += 16)
  {
    char buffer[16]; // page of EEPROM
    char temp[4];
    sprintf(temp, "%04x: ", i); // print address
    Serial.print(temp);
    readEEPROM_page(device, i, buffer, 16);

    for (int j = 0; j < 16; j++)
    {
      sprintf(temp, "%02x ", byte(buffer[j])); // print data (hexa)
      Serial.print(temp);
    }
    Serial.print(" ");
    for (int j = 0; j < 16; j++) // print data (ASCII)
    {
      if (isprint(buffer[j]))
        Serial.print(buffer[j]);
      else
        Serial.print('.');
    }
    Serial.println(" ");
  }
}
byte readEEPROM_page(int device, unsigned int address, byte *buffer, int length )
{
  byte i;
  Wire.beginTransmission(device);
  Wire.beginTransmission(device | (int(address >> 8) & 0b111));
  Wire.write((int)(address & 0xFF));
  Wire.endTransmission();
  Wire.requestFrom(device, length);
  for ( i = 0; i < length; i++ )
    if (Wire.available())
      buffer[i] = Wire.read();
}
