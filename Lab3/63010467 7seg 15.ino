#define DELAY_TIME 1

int segmentA = A5;
int segmentB = 8;
int segmentC = 3;
int segmentD = 5;
int segmentE = 6;
int segmentF = 9;
int segmentG = 2;
int segmentDP = 4;
int D6 = 7;
int D12 = A2;
int D9 = A3;
int D8 = A4;
int temp = A0;
int Vo;
float R1 = 10000;
float logR2, R2, T, Tc;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;

void setup() {
 pinMode(segmentA, OUTPUT);
 pinMode(segmentB, OUTPUT);
 pinMode(segmentC, OUTPUT);
 pinMode(segmentD, OUTPUT);
 pinMode(segmentE, OUTPUT);
 pinMode(segmentF, OUTPUT);
 pinMode(segmentG, OUTPUT);
 pinMode(segmentDP, OUTPUT);
 pinMode(temp, INPUT);
 Serial.begin(9600);
}



void loop() {
  displayNumber();
}

void displayNumber()
{

      Vo = 1023-analogRead(temp);
      R2 = R1 * (1023.0 / (float)Vo - 1.0);
      logR2 = log(R2);
      T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
      Tc = T - 273.15;
     Serial.println(Tc);
     int temp_int = Tc*100;
//   for(int digit = 0 ; digit <= 10 ; digit++)
//   {
      digitalWrite(D6,0);
      digitalWrite(D8,0);
      digitalWrite(D9,0);
      digitalWrite(D12,1);
      //Serial.print("digit 1: ");
      //Serial.println(volt_int/1000);
      displaySegment(temp_int/1000);
      temp_int %= 1000;
      displaySegment(11);
      //displaySegment(1);
      delay(DELAY_TIME);
      
      digitalWrite(D6,0);
      digitalWrite(D8,0);
      digitalWrite(D9,1);
      digitalWrite(D12,0);
      //Serial.print("digit 2: ");
      //Serial.println(volt_int/100);
      displaySegment(temp_int/100);
      temp_int %= 100;
      displaySegment(10);
      //displaySegment(2);
      delay(DELAY_TIME);
      
      digitalWrite(D9,0);
      digitalWrite(D6,0);
      digitalWrite(D8,1);
      digitalWrite(D12,0);
      //Serial.print("digit 3: ");
      //Serial.println(volt_int/10);
      displaySegment(temp_int/10);
      temp_int %= 10;
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
      displaySegment(temp_int);
      displaySegment(11);
      //displaySegment(4);
      delay(DELAY_TIME);
      
  // }
}

//หาอุณหภูมิ
/*int Tp()
{
  Vo = 1023-analogRead(temp);
  R2 = R1 * (1023.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  Tc = T - 273.15;
  Serial.println(Tc);
}*/
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
