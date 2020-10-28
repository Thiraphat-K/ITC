#define DELAY_TIME 1

int segmentA = 13;
int segmentB = A1;
int segmentC = A2;
int segmentD = A3;
int segmentE = A4;
int segmentF = A5;
int segmentG = 4;
int segmentDP = 5;
int D6 = 8;
int D12 = 9;
int D9 = 10;
int D8 = 11;
int volt = A0;

void setup() {
 pinMode(segmentA, OUTPUT);
 pinMode(segmentB, OUTPUT);
 pinMode(segmentC, OUTPUT);
 pinMode(segmentD, OUTPUT);
 pinMode(segmentE, OUTPUT);
 pinMode(segmentF, OUTPUT);
 pinMode(segmentG, OUTPUT);
 pinMode(segmentDP, OUTPUT);
 pinMode(volt, INPUT);
 Serial.begin(9600);
}



void loop() {
  displayNumber();
}

void displayNumber()
{
//   for(int digit = 0 ; digit <= 10 ; digit++)
//   {
      int volt_int = Vs();
      digitalWrite(D6,0);
      digitalWrite(D8,0);
      digitalWrite(D9,0);
      digitalWrite(D12,1);
      //Serial.print("digit 1: ");
      //Serial.println(volt_int/1000);
      displaySegment(volt_int/1000);
      volt_int %= 1000;
      displaySegment(11);
      //displaySegment(1);
      delay(DELAY_TIME);
      
      digitalWrite(D6,0);
      digitalWrite(D8,0);
      digitalWrite(D9,1);
      digitalWrite(D12,0);
      //Serial.print("digit 2: ");
      //Serial.println(volt_int/100);
      displaySegment(volt_int/100);
      volt_int %= 100;
      displaySegment(10);
      //displaySegment(2);
      delay(DELAY_TIME);
      
      digitalWrite(D9,0);
      digitalWrite(D6,0);
      digitalWrite(D8,1);
      digitalWrite(D12,0);
      //Serial.print("digit 3: ");
      //Serial.println(volt_int/10);
      displaySegment(volt_int/10);
      volt_int %= 10;
      displaySegment(11);
      //displaySegment(10);
      //displaySegment(3);
      delay(DELAY_TIME);
      
      digitalWrite(D12,0);
      digitalWrite(D6,1);
      digitalWrite(D8,0);
      digitalWrite(D9,0);
      //Serial.print("digit 4: ");
      //Serial.println(volt_int);
      displaySegment(volt_int);
      displaySegment(11);
      //displaySegment(4);
      delay(DELAY_TIME);
      
  // }
}

int Vs()
{
  int sensorValue = analogRead(volt);
  Serial.println(sensorValue);
  delay(1);
  float voltage = sensorValue * (10.00 / 1023.0);
  Serial.println(voltage);
  return 100*voltage;
}

void displaySegment(int numberToDisplay)
{
 switch (numberToDisplay)
 {
 case 1: //แสดงผลเลข 1
digitalWrite(segmentA, 0);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 0);
digitalWrite(segmentE, 0);
digitalWrite(segmentF, 0);
digitalWrite(segmentG, 0);
break;
case 2: //แสดงผลเลข 2
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 0);
digitalWrite(segmentD, 1);
digitalWrite(segmentE, 1);
digitalWrite(segmentF, 0);
digitalWrite(segmentG, 1);
break;

case 3: //แสดงผลเลข 3
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 1);
digitalWrite(segmentE, 0);
digitalWrite(segmentF, 0);
digitalWrite(segmentG, 1);
break;

case 4: //แสดงผลเลข 4
digitalWrite(segmentA, 0);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 0);
digitalWrite(segmentE, 0);
digitalWrite(segmentF, 1);
digitalWrite(segmentG, 1);
break;

case 5: //แสดงผลเลข 5
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 0);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 1);
digitalWrite(segmentE, 0);
digitalWrite(segmentF, 1);
digitalWrite(segmentG, 1);
break;

case 6: //แสดงผลเลข 6
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 0);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 1);
digitalWrite(segmentE, 1);
digitalWrite(segmentF, 1);
digitalWrite(segmentG, 1);
break;

case 7: //แสดงผลเลข 7
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 0);
digitalWrite(segmentE, 0);
digitalWrite(segmentF, 0);
digitalWrite(segmentG, 0);
break;

case 8: //แสดงผลเลข 8
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 1);
digitalWrite(segmentE, 1);
digitalWrite(segmentF, 1);
digitalWrite(segmentG, 1);
break;

case 9: //แสดงผลเลข 9
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 1);
digitalWrite(segmentE, 0);
digitalWrite(segmentF, 1);
digitalWrite(segmentG, 1);
break;

case 0: //แสดงผลเลข 0
digitalWrite(segmentA, 1);
digitalWrite(segmentB, 1);
digitalWrite(segmentC, 1);
digitalWrite(segmentD, 1);
digitalWrite(segmentE, 1);
digitalWrite(segmentF, 1);
digitalWrite(segmentG, 0);
break;

case 10:
digitalWrite(segmentDP, 1);
break;

case 11:
digitalWrite(segmentDP, 0);
break;

 }
}
