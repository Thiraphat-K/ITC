int i;
int led = 13;
void setup() {
  Serial.begin(9600);  
  pinMode(led,OUTPUT);
}

void loop() {
  for(i=1;i<1600;i++)
  {
    digitalWrite(led,HIGH);
    delay(500/i);
    digitalWrite(led,LOW);
    delay(1500/i);
    Serial.println((500/i)+(1500/i));
  }
}
