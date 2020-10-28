
void setup(){

  Serial.begin(9600);
}
void loop()
{  
    int bt = analogRead(A0);                           
 Serial.println(bt); 
}
