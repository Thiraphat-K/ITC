#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
#define device 33 //Change everytime if u change I2C for stepMotr.

const hd44780_I2Cexp lcd ; 
const int LCD_COLS = 16 ;
const int LCD_ROWS = 2 ;
const int button = 9 ; // If we use input switch to Arduino D9.
const float offsetdegree = 1.422222;  // == (Countstep in 360 degree) divine by 360.
byte data = NULL;

//<For change value>
int countbutton = 1; // If we press button it will plus everytime.
float offsetdisplay = 0;
int Stepcount = 1;

bool clockwise = NULL; //Clockwise or Counterclockwise.
bool flag = false;

void setup()
{
  Wire.begin(); // Start I2C bus
  Serial.begin(9600); // Setup serial for debug
  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) { hd44780::fatalError(status); }
  lcd.noCursor();
}

void loop()
{
  bool Button = digitalRead(button);
  float Dg = Stepcount / offsetdegree;
  
  lcd.setCursor(0, 0);
  lcd.print((int)(Dg));
  if(Dg >= 0 && Dg <= 9)
  {lcd.setCursor(1, 0);
  lcd.print((char)223);}
  if(Dg > 9 && Dg <= 99)
  {lcd.setCursor(2, 0);
  lcd.print((char)223);}
  if(Dg > 99)
  {lcd.setCursor(3, 0);
  lcd.print((char)223);}
    
  if (countbutton % 2 == 0) { lcd.setCursor(0, 1);  lcd.print("HALF STEP"); }
  if (countbutton % 2 == 1) { lcd.setCursor(0, 1);  lcd.print("FULL STEP"); }
  
  if (millis() - offsetdisplay > 500) { offsetdisplay = millis();  lcd.clear(); }

  //Check for button
  if (!Button and flag == false)
  {
    countbutton++;
    flag = true;
  }
  if (Button) { flag = false; } 

  //Clockwise
  if (Dg <= 360  and countbutton % 2 == 1)
  {
    clockwise = true;
    for (int i = 1 ; i <= 4; i++) 
    {
      switch (i)
      {
        case 1: data = B00010111; break;
        case 2: data = B00100111; break;
        case 3: data = B01000111; break;
        case 4: data = B10000111; break;
      }
      Wire.beginTransmission(device);
      Wire.write(data);
      Wire.endTransmission();
      delay(5);
    }
    Stepcount++;
    if (Dg >= 359 ){ countbutton++; }// If degree is plus till it larger than 360 ,then change countbutton to even. 
  }

  //Counterclockwise
  else if (Dg >= 0 and countbutton % 2 == 0)
  {
    clockwise = false;
    for (int i = 1 ; i <= 8; i++) // sets the value (range from 1 to 8)
    {
      switch (i)
      {
        case 1: data = B10000111; break; 
        case 2: data = B11000111; break; 
        case 3: data = B01000111; break; 
        case 4: data = B01100111; break; 
        case 5: data = B00100111; break; 
        case 6: data = B00110111; break; 
        case 7: data = B00010111; break; 
        case 8: data = B10010111; break;
      }
      Wire.beginTransmission(device);
      Wire.write(data);
      Wire.endTransmission();
      delay(5);
    }
    Stepcount--; //To count degree
    if (Dg <= 0){ countbutton++; } // If degree is minus till it less than 0 ,then change countbutton to odd .
  }

}
