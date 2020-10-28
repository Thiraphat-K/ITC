void setup() {
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int f = analogRead(A7);
  Serial.println(f);

  if(f>0 && f<=146)
  {
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,0);
  }

  if(f>147 && f<=292)
  {
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,0);
  }

  if(f>293 && f<=438)
  {
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,0);
  }

  if(f>439 && f<=584)
  {
    digitalWrite(6,0);
    digitalWrite(7,1);
    digitalWrite(8,1);
  }
  
  if(f>585 && f<=730)
  {
    digitalWrite(6,0);
    digitalWrite(7,0);
    digitalWrite(8,1);
  }

  if(f>731 && f<=876)
  {
    digitalWrite(6,1);
    digitalWrite(7,0);
    digitalWrite(8,1);
  }

  if(f>877 && f<=1023)
  {
    digitalWrite(6,1);
    digitalWrite(7,1);
    digitalWrite(8,1);
  }
  
}
