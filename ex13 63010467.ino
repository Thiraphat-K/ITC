int i;
void setup() {
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
}

void loop() {
  for(i=8;i<13;i++){
digitalWrite(i,1);
delay(250);
digitalWrite(i,0);
delay(250);
  }
  for(i=11;i>8;i--){
digitalWrite(i,1);
delay(250);
digitalWrite(i,0);
delay(250);
  }
}
