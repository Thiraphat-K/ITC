void setup() {
//  int inf = 10; ข้อ 27
  Serial.begin(9600);
//  pinMode(inf,OUTPUT);ข้อ 27
}

void loop() {
  int ir = analogRead(A0);
  Serial.println(ir);
  
//  if(ir<=1000) ข้อ 27
//  {
//    digitalWrite(inf,1);
//  }
//  else
//  {
//    digitalWrite(inf,0);
//  }
}
