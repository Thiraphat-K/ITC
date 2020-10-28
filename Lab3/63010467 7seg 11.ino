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

void setup() {
 pinMode(segmentA, OUTPUT);
 pinMode(segmentB, OUTPUT);
 pinMode(segmentC, OUTPUT);
 pinMode(segmentD, OUTPUT);
 pinMode(segmentE, OUTPUT);
 pinMode(segmentF, OUTPUT);
 pinMode(segmentG, OUTPUT);
 pinMode(segmentDP, OUTPUT);
}



void loop() {
  displayNumber();
}

void displayNumber()
{
   for(int digit = 0 ; digit <=8 ; digit++)
   {
      switch(digit)
      {
      case 1://--6--//
      for(int i = 0;i<=100;i++)
      {
      digitalWrite(D6,1);
      displaySegment(6);
      delay(1);
      digitalWrite(D6,0);
      delay(1);
      }
      break;
      
      case 2://--6-3--//
      for(int i = 0; i<=100 ;i++)
      {
      digitalWrite(D8,1);
      displaySegment(6);
      delay(1);
      digitalWrite(D8,0); 
      delay(1);
      digitalWrite(D6,1);
      displaySegment(3);
      delay(1);
      digitalWrite(D6,0); 
      delay(1);
      }
      break;

      case 3://--6-3-0--//
      for(int i = 0; i<=100 ;i++)
      {
      digitalWrite(D9,1);
      displaySegment(6);
      delay(1);
      digitalWrite(D9,0); 
      delay(1);
      digitalWrite(D8,1);
      displaySegment(3);
      delay(1);
      digitalWrite(D8,0); 
      delay(1);
      digitalWrite(D6,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D6,0); 
      delay(1);
      }
      break;

      case 4://--6-3-0-1--//
      for(int i = 0; i<=100 ;i++)
      {
      digitalWrite(D12,1);
      displaySegment(6);
      delay(1);
      digitalWrite(D12,0); 
      delay(1);
      digitalWrite(D9,1);
      displaySegment(3);
      delay(1);
      digitalWrite(D9,0); 
      delay(1);
      digitalWrite(D8,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D8,0); 
      delay(1);
      digitalWrite(D6,1);
      displaySegment(1);
      delay(1);
      digitalWrite(D6,0); 
      delay(1);
      }
      break;

      case 5://--3-0-1-0--//
      for(int i = 0; i<=100 ;i++)
      {
      digitalWrite(D12,1);
      displaySegment(3);
      delay(1);
      digitalWrite(D12,0); 
      delay(1);
      digitalWrite(D9,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D9,0); 
      delay(1);
      digitalWrite(D8,1);
      displaySegment(1);
      delay(1);
      digitalWrite(D8,0); 
      delay(1);
      digitalWrite(D6,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D6,0); 
      delay(1);
      }
      break;

      case 6://--0-1-0-6--//
      for(int i = 0; i<=100 ;i++)
      {
      digitalWrite(D12,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D12,0); 
      delay(1);
      digitalWrite(D9,1);
      displaySegment(1);
      delay(1);
      digitalWrite(D9,0); 
      delay(1);
      digitalWrite(D8,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D8,0); 
      delay(1);
      digitalWrite(D6,1);
      displaySegment(4);
      delay(1);
      digitalWrite(D6,0); 
      delay(1);
      }
      break;

      case 7://--1-0-6-7--//
      for(int i = 0; i<=100 ;i++)
      {
      digitalWrite(D12,1);
      displaySegment(1);
      delay(1);
      digitalWrite(D12,0); 
      delay(1);
      digitalWrite(D9,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D9,0); 
      delay(1);
      digitalWrite(D8,1);
      displaySegment(4);
      delay(1);
      digitalWrite(D8,0); 
      delay(1);
      digitalWrite(D6,1);
      displaySegment(6);
      delay(1);
      digitalWrite(D6,0); 
      delay(1);
      }
      break;

      case 8://--0-6-7-9--//
      for(int i = 0; i<=100 ;i++)
      {
      digitalWrite(D12,1);
      displaySegment(0);
      delay(1);
      digitalWrite(D12,0); 
      delay(1);
      digitalWrite(D9,1);
      displaySegment(4);
      delay(1);
      digitalWrite(D9,0); 
      delay(1);
      digitalWrite(D8,1);
      displaySegment(6);
      delay(1);
      digitalWrite(D8,0); 
      delay(1);
      digitalWrite(D6,1);
      displaySegment(7);
      delay(1);
      digitalWrite(D6,0); 
      delay(1);
      }
      break;
      delay(500);
    }
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
