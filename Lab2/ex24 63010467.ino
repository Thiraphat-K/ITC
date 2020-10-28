void setup() {
  Serial.begin(9600);

}

void loop() {
  int ldr = analogRead(A0);
  Serial.println(ldr);

}
