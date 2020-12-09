#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
int pingPin = 3;
int inPin = 2;
#define button2 9
#define button1 8
#define button3 10
#define device 0x24
#define BUZZER_PIN  13
#include <Adafruit_NeoPixel.h>
#define PIN 7
#define NUMPIXELS 8
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int sec = 0;
int minutes = 0;
int hours = 0;
bool flagbutton1 = true;
bool flagbutton2 = true;
bool flagbutton3 = true;
bool reset = false;
int stepcount = 0;
int timebuzz = 0;

int flag = 0;
void clockwise();
void digital();
void ulsound();
bool soundon = false;
int heatlevel;
bool lightcheck = false;
int color;
long microsecondsToCentimeters(long microseconds);
long duration, cm;
void setup()
{
  pixels.begin();
  pinMode(PIN , OUTPUT);
  pixels.show();
  pinMode(BUZZER_PIN, OUTPUT);
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  //For Declaration of LCD--------------------------------------------------------------------------
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status)
  {
    hd44780::fatalError(status);
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
  ulsound();
  if (cm < 10)
  {

    if (lightcheck == true)
    {
      if (color == 1)
      {
        for (int i = 0; i < NUMPIXELS; i++)
        {
          pixels.setPixelColor(i, pixels.Color(10, 0, 0));
          pixels.show();
        }
      }
      if (color == 2)
      {
        for (int i = 0; i < NUMPIXELS; i++)
        {
          pixels.setPixelColor(i, pixels.Color(40, 0, 0));
          pixels.show();
        }
      }
      if (color == 3)
      {
        for (int i = 0; i < NUMPIXELS; i++)
        {
          pixels.setPixelColor(i, pixels.Color(100, 0, 0));
          pixels.show();
        }
      }
    }
    if (lightcheck == false)
    {
      for (int i = 0; i < NUMPIXELS; i++)
      {
        pixels.setPixelColor(i, pixels.Color(0, 0, 0));
        pixels.show();
      }
    }
    if (!digitalRead(button1) and flagbutton1 and (sec > 0 or minutes > 0))
    {
      flag++;
      lightcheck = true;
      flagbutton1 = false;
    }
    else if (digitalRead(button1))
      flagbutton1 = true;

    if (!digitalRead(button2)  and flagbutton2 and flag % 2 == 0)
    {
      sec += 30;
      flagbutton2 = false;
    }
    else if (digitalRead(button2))
      flagbutton2 = true;
    if (flag % 2 == 1)
    {
      clockwise();
    }
    int button3state = digitalRead(button3);
    //Serial.println(button3state);
    //Serial.print("heat");
    //Serial.println(heatlevel);
    lcd.setCursor(0, 0);
    lcd.print("Heat : ");
    if (digitalRead(button3) == 0 and flagbutton3)
    {
      flagbutton3 = false;
      heatlevel++;
      if (heatlevel == 1)
      {

        lcd.setCursor(8, 0);
        lcd.print(" LOW  ");
        color = 1;
      }
      if (heatlevel == 2)
      {

        lcd.setCursor(8, 0);
        lcd.print("MEDIUM");
        color = 2;
      }
      if (heatlevel == 3)
      {

        lcd.setCursor(8, 0);
        lcd.print(" HIGH ");
        color = 3;
      }
      if (heatlevel > 2)
      {
        heatlevel = 0;
      }
      //lightcheck = false;
    }
    else if (digitalRead(button3))
      flagbutton3 = true;

    //--------------------------------Time
    lcd.setCursor(0, 1);
    lcd.print("Time : ");
    if (hours == 0)
    {
      lcd.print("00");
    }
    else if (hours > 9)
    {
      lcd.print(hours);
    }
    else
    {
      lcd.print("0");
      lcd.print(hours);
    }
    lcd.print(":");
    if (minutes == 0)
    {
      lcd.print("00");
    }
    else if (minutes > 9)
    {
      lcd.print(minutes);
    }
    else
    {
      lcd.print(0);
      lcd.print(minutes);
    }
    lcd.print(":");
    if (sec == 0)
    {
      lcd.print("00");
    }
    else if (sec > 9)
    {
      lcd.print(sec);
    }
    else
    {
      lcd.print("0");
      lcd.print(sec);
    }

    //----------------------Sound end
    if (hours == 0 and minutes == 0 and sec == 0 and soundon)
    {
      lightcheck = false;
      timebuzz++;
      if (timebuzz >= 20)
      {
        digitalWrite(BUZZER_PIN, LOW);
      }
      if (timebuzz >= 30)
      {
        digitalWrite(BUZZER_PIN, HIGH);
      }
      if (timebuzz >= 60)
      {
        digitalWrite(BUZZER_PIN, LOW);
        soundon = false;
        timebuzz = 0;
      }
    }
    //Serial.println(timebuzz);
  }
}

//Loop for Interrupt
ISR(TIMER1_COMPA_vect)
{
  if (cm < 15)
  {
    if (flag % 2 == 1 )
    {
      sec--;
      if (hours == 0 and minutes == 0 and sec == 0)
      {
        digitalWrite(BUZZER_PIN, HIGH);
        soundon = true;
        flag++;
        sec = 0;
      }
    }
    if (flag % 2 == 0)
    {
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
    if (flag % 2 == 1)
    {
      if (hours > 0 and minutes <= 0)
      {
        hours-- ;
        minutes = 59;
      }
      if (minutes > 0 and sec <= 0)
      {
        minutes-- ;
        sec = 59;
      }
    }
  }
}

void clockwise()
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
    stepcount++;
    delay(5);
  }
}

void ulsound()
{

  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  digitalWrite(pingPin, HIGH);
  digitalWrite(pingPin, LOW);
  pinMode(inPin, INPUT);
  duration = pulseIn(inPin, HIGH);
  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}
