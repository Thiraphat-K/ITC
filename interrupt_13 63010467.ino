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


void setup()
{
  Serial.begin(9600);
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
  Serial.print("Sec = ");
  Serial.print(sec);
  Serial.print(" ,Minutes = ");
  Serial.print(minutes);
  Serial.print(" ,Hours = ");
  Serial.println(hours);

}
ISR(TIMER1_COMPA_vect)
{
  sec++ ;
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
