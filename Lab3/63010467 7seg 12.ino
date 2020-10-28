void setup()
{
Serial.begin(9600);
}
void loop()
{
int sensorValue = analogRead(A0);
Serial.println(sensorValue);
delay(200);
float voltage = sensorValue * (5.0 / 1023.0);
Serial.println(voltage);
}
