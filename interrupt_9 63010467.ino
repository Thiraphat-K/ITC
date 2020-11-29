int led8 = 8;
int led9 = 9;
int led10 = 10;
int led11 = 11;
int led12 = 12;
int BUTTON = 3;
int i;
int state;
void setup()
{
  attachInterrupt(digitalPinToInterrupt(BUTTON) , switch1, CHANGE);
  Serial.begin(9600);
  pinMode(led8, OUTPUT);
  pinMode(led9, OUTPUT);
  pinMode(led10, OUTPUT);
  pinMode(led11, OUTPUT);
  pinMode(led12, OUTPUT);
  pinMode(13, OUTPUT);

  pinMode(BUTTON, INPUT_PULLUP);
}
void loop()
{
  for (i = 50; i > 0; i--)
  {
    for (int j = 0; j <= 50 - i ; j++)
    {
      digitalWrite(led8, HIGH);
      delay(i);
      digitalWrite(led8, LOW);
      digitalWrite(led9, HIGH);
      delay(i);
      digitalWrite(led9, LOW);
      digitalWrite(led10, HIGH);
      delay(i);
      digitalWrite(led10, LOW);
      digitalWrite(led11, HIGH);
      delay(i);
      digitalWrite(led11, LOW);
      digitalWrite(led12, HIGH);
      delay(i);
      digitalWrite(led12, LOW);
      Serial.println(i);
    }
  }

}

void switch1()
{
  if (digitalRead(BUTTON) == LOW)
    digitalWrite(13, HIGH);
  else
    digitalWrite(13, LOW);
}
