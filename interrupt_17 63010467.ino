#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
#define button2 9
#define button1 8
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int sec = 0;
int minutes = 0;
int hours = 0;
int flag = 1;
bool flagbutton1 = true;
bool flagbutton2 = true;

void setup()
{
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) // non zero status means it was unsuccesful
  {
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 15624;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
  Serial.begin(9600);

}

void loop()
{
  if (digitalRead(button2) == 0 and flagbutton2) {
    sec = 0;
    minutes = 0;
    hours = 0;
    flag = 1;
    flagbutton2 = false;
  }
  if (digitalRead(button1) == 0 and flagbutton1)
  {
    flag++;
    flagbutton1 = false;
    flagbutton2 = true;

  }
  else if (digitalRead(button1) == 1)
    flagbutton1 = true;

   
  Serial.println(flag);
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
  lcd.print(":");
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
  delay(60);
  lcd.clear();
}

ISR(TIMER1_COMPA_vect)
{
  if (flag % 2 == 0 and flagbutton2) {
    sec ++ ;

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
}
