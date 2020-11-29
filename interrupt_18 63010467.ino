#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
#define button2 9
#define button1 8
#define device 0x21
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
unsigned long time_a;
int sec = 0;
int minutes = 0;
int hours = 0;
bool flagbutton1 = true;
bool flagbutton2 = true;
bool reset = false;
int stepcount = 0;
int flag = 1;
void ctclockwise_full();
void clockwise_full();
void clockwise_half();


void setup()
{
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  time_a = millis();
  //For Declaration of LCD--------------------------------------------------------------------------
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) // non zero status means it was unsuccesful
  {
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }

  //For Interrupt Declaration-----------------------------------------------------------------------
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 62499;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}

void loop()
{

  if (!digitalRead(button1) and flagbutton1)
  {
    flag++;
    flagbutton1 = false;
  }
  else if (digitalRead(button1))
    flagbutton1 = true;

  if (!digitalRead(button2)  and flagbutton2)
  {
    flag++;
    reset = true;
    flagbutton2 = false;
  }
  else if (digitalRead(button2))
    flagbutton2 = true;


  if (millis() - time_a > 60)
  {

    lcd.setCursor(0, 0);
    if (hours == 0) {
      lcd.print("00");
    }
    else if (hours > 9) {
      lcd.print(hours);
    }
    else {
      lcd.print("0");
      lcd.print(hours);
    }
    lcd.print(".");
    if (minutes == 0) {
      lcd.print("00");
    }
    else if (minutes > 9) {
      lcd.print(minutes);
    }
    else {
      lcd.print(0);
      lcd.print(minutes);
    }
    lcd.print(".");
    if (sec == 0) {
      lcd.print("00");
    }
    else if (sec > 9) {
      lcd.print(sec);
    }
    else {
      lcd.print("0");
      lcd.print(sec);
    }
    lcd.print(" h.m.s");



    time_a = millis();

  }


  if (flag % 2 == 1 and !reset)
  {
    if (sec>30 && sec<60)
    {
      clockwise_half();
      lcd.setCursor(0, 1);
      lcd.print("Half Step");
    }
    else
    {
      clockwise_full();
      lcd.setCursor(0, 1);
      lcd.print("Full Step");
    }
    stepcount++;
    Serial.println(stepcount);
  }
  else if (reset and stepcount >= 0)
  {
    ctclockwise_full();
    if (stepcount <= 1)
    {
      reset = false;
    }
  }
  if (stepcount==1164)
  {
    stepcount = 0;
  }
}

//Loop for Interrupt
ISR(TIMER1_COMPA_vect)
{
  if (flag % 2 == 1 and !reset)
    sec++;

  if (sec >= 60)
  {
    minutes++ ;
    sec = 0;
  }
  if (minutes >= 60)
  {
    hours++ ;
    minutes = 0;
  }
}


void clockwise_full()
{
  byte data = 0x80;
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
    delay(10);
  }
}

void ctclockwise_full()
{

  sec = 0;
  minutes = 0;
  hours = 0;
  byte data = 0x80;

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
    stepcount--;
    delay(5);
  }
}

void clockwise_half()
{
  byte data = 0x80;
  for (int i = 1 ; i <= 8; i++) // sets the value (range from 1 to 4)
  {
    switch (i) {
      case 1: data = B10010111; break;
      case 2: data = B00010111; break;
      case 3: data = B00110111; break;
      case 4: data = B00100111; break;
      case 5: data = B01100111; break;
      case 6: data = B01000111; break;
      case 7: data = B11000111; break;
      case 8: data = B10000111; break;
    }
    Wire.beginTransmission(device); // transmit to device
    Wire.write(data); // sends one byte
    Wire.endTransmission(); // stop transmitting
    delay(10);
  }
}
