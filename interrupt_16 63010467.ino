int led8 = 8;
int led9 = 9;
int led10 = 10;
int led11 = 11;
int led12 = 12;
int BUTTON = 3;
int i;
int state;
bool pressed = false;
float sec = 0;
float minutes = 0;
float hours = 0;
bool D8light = false;
bool D9light = false;


void setup()
{
  pinMode(8 , OUTPUT);
  pinMode(9 , OUTPUT);

  Serial.begin(9600);
  noInterrupts();
  TCCR1A = 0;
  TCCR1B = 0;
  TCNT1 = 0;
  OCR1A = 31249;
  TCCR1B |= (1 << WGM12);
  TCCR1B |= (1 << CS12);
  TIMSK1 |= (1 << OCIE1A);
  interrupts();
}
void loop()
{
  Serial.print("Sec = ");
  Serial.print((int)sec/2);
  Serial.print(" ,Minutes = ");
  Serial.print(minutes);
  Serial.print(" ,Hours = ");
  Serial.println(hours);

  if (D8light)
    digitalWrite( 8 , 1);
  else
    digitalWrite( 8 , 0);

  if (D9light)
    digitalWrite( 9 , 1);
  else
    digitalWrite( 9 , 0);



}
ISR(TIMER1_COMPA_vect)
{
  sec++ ;
  if ((int)sec % 3 == 2)
  {
    D8light = true;
  }
  if ((int)sec % 3 == 0)
  {
    D8light = false;
  }
  if ((int)sec/2 % 60 == 0)
  {
    D9light = true;
  }
  if ((int)sec/2 % 60 == 2)
  {
    D9light = false;
  }



  if (sec/2 >= 60)
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
