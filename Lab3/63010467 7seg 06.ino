int segmentA = A0;
int segmentB = A1;
int segmentC = A2;
int segmentD = A3;
int segmentE = A4;
int segmentF = A5;
int segmentG = 4;
int segmentDP = 5;
int D5 = 8;
int D6 = 9;
int D9 = 10;
int D10 = 11;
void setup()
{
 pinMode(segmentA, OUTPUT);
 pinMode(segmentB, OUTPUT);
 pinMode(segmentC, OUTPUT);
 pinMode(segmentD, OUTPUT);
 pinMode(segmentE, OUTPUT);
 pinMode(segmentF, OUTPUT);
 pinMode(segmentG, OUTPUT);
 pinMode(segmentDP, OUTPUT);
}
void loop()
{
 displayNumber();
}
void displayNumber()
{
 for(int digit = 0 ; digit <=9 ; digit++)
 {
  digitalWrite(D5,1);
  delay(200);
  displaySegment(digit);
  digitalWrite(D5,0);
  delay(200);

  digitalWrite(D6,1);
  delay(200);
  displaySegment(digit);
  digitalWrite(D6,0);
  delay(200);

  digitalWrite(D9,1);
  delay(200);
  displaySegment(digit);
  digitalWrite(D9,0);
  delay(200);

  digitalWrite(D10,1);
  delay(200);
  displaySegment(digit);
  digitalWrite(D10,0);
  delay(200);
 }
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
 }
}
