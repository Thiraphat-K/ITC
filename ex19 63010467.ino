#define led1 9
#define led2 10
void setup(){
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}
void loop()
{  
    int bt = analogRead(A0);                           
 Serial.println(bt);
  if(bt<=511){
   digitalWrite(led1,1);
   digitalWrite(led2,0);

  }
  else{
  digitalWrite(led2,1);
  digitalWrite(led1,0);

  }
}
