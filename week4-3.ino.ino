
#include <Stepper.h> //引入步進馬達函示庫

const int stepsPerRevolution = 2048;  //此馬達轉一圈為2048步
const int RPM = 10; //馬達旋轉速度
bool press=false;
//宣告Stepper物件，的步數和引腳
//引角依序對應驅動版的1N1、1N3、1N2、1N4
Stepper myStepper(stepsPerRevolution, 13, 14, 12, 27);  

void setup() {  
  Serial.begin(115200);
  myStepper.setSpeed(RPM);  //設定馬達轉速
}

void loop() {
  //正轉一圈
  if(digitalRead(22)==HIGH&&press==false){
  myStepper.step(stepsPerRevolution);press=true;}
  else if(digitalRead(22)==LOW&&press==true){press=false;}
  //delay(500);
  //倒轉一圈
  if(digitalRead(23)==HIGH&&press==false){
  myStepper.step(-stepsPerRevolution);press=true;}
  else if(digitalRead(23)==LOW&&press==true){press=false;}
  //delay(500);
}
