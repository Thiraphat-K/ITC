void setup() {
  pinMode(2,INPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if(digitalRead(2) == 1)
  {
   digitalWrite(9,1);
   digitalWrite(10,0);
   digitalWrite(11,0);
  }
  else if(digitalRead(3) == 1)
  {
   digitalWrite(9,0);
   digitalWrite(10,1);
   digitalWrite(11,0);
  }
  else if(digitalRead(4) == 1)
  {
    digitalWrite(9,0);
    digitalWrite(10,0);
    digitalWrite(11,1);
  }
  else
  {
    digitalWrite(9,0);
    digitalWrite(10,0);
    digitalWrite(11,0);
  }
}
