#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
const hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 1;
const int button = 9;

//<For change value>
int i = 15;
int Start = 1;
int End = 5;

//<For change character>

uint8_t char1[8]  = {0x02, 0x0E, 0x00, 0x0E, 0x1E, 0x0A, 0x0A, 0x0E}; // Char ธี
uint8_t char2[8] = {0x00, 0x00, 0x00, 0x0E, 0x0E, 0x02, 0x06, 0x06}; // Char ร
uint8_t char3[8] = {0x04, 0x07, 0x00, 0x1A, 0x0A, 0x0E, 0x0E, 0x0A}; // Char พั
uint8_t char4[8] = {0x00, 0x00, 0x00, 0x1D, 0x15, 0x1D, 0x1F, 0x15}; // Char ฒ
uint8_t char5[8] = {0x01, 0x07, 0x04, 0x1A, 0x0A, 0x0A, 0x0F, 0x0B}; // Char น์

//<For declare prototype>
void lcd_display(int);

void setup()
{
  Serial.begin(115200);

  int status;
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  if (status) {
    hd44780::fatalError(status);
  }
  lcd.lineWrap();
}

void loop()
{
  //<For create character>
  lcd.createChar(1, char1);
  lcd.createChar(2, char2);
  lcd.createChar(3, char3);
  lcd.createChar(4, char4);
  lcd.createChar(5, char5);
  bool Button = digitalRead(button);
  if (Button)
  {
    i--;
    lcd_display(i);
    if (i > 15) {
      i = 0;
    }
    else if (i < 0  ) {
      i = 15;
    }
  }
  else
  {
    i++;
    lcd_display(i);
    if (i > 15) {
      i = 0;
    }
    else if (i < 0  ) {
      i = 15;
    }
  }
}

void lcd_display(int i)
{
  lcd.setCursor(i, 0);
  for (int j = Start ; j <= End; j++) {
    lcd.write(k);
  }
  delay(500);
  lcd.clear();
}