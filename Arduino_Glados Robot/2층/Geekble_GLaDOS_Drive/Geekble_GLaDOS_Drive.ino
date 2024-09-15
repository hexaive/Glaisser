/*[Geekble X 메이커창작과] : GLaDOS_DriveTrain_lineTrace Code */
/*-----------------------------------------------------------------------------------*/
//LeftFowardMotor : RightDriver M1A(Black) M1B(Red) 
//LeftBackwardMotor : LeftDriver M1A(Black) M1B(Red) 
//RightFowardMotor : LeftDriver M2A(Black) M2B(Red) 
//RightbackwardMotor : RightDriver M2A(Red) M2B(Black) 
/*-----------------------------------------------------------------------------------*/
 #include "CytronMotorDriver.h"
 /*------------------------------------------------------------------------------------*/
 //motorDriver_pin_name_setting
CytronMD rightMotor(PWM_DIR, 10, 9);  // PWM 1 = Pin 11, DIR 1 = Pin 10.
CytronMD leftMotor(PWM_DIR, 12, 11); // PWM 2 = Pin 13, DIR 2 = Pin 12.
/*------------------------------------------------------------------------------------*/
//lineTracing_pin_setting
const int leftSensorPin = A0; // 왼쪽 라인트레이싱 센서 아날로그 핀 설정
const int rightSensorPin = A1; // 오른쪽 라인 트레이싱 센서 아날로그 핀 설정
const int line_limit = 730; // 라인 감지 임계값 설정 (수정 0~1024)
int Switch = 2;
int flage = 0;
int cmd;
int cam = 0;
int check = 0;
/*------------------------------------------------------------------------------------*/
// Drivetrain_Movement_Setting
void forward(){
  leftMotor.setSpeed(180);   //좌측 모터 정회전(정회전 1~255 | 역회전 -1~-255 | 정지 0)
  rightMotor.setSpeed(180);  //우측 모터 정회전(정회전 1~255 | 역회전 -1~-255 | 정지 0)
}
void backward(){
  leftMotor.setSpeed(-150);   //좌측 모터 역회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
  rightMotor.setSpeed(-150);  //우측 모터 역회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
}
void turnleft(){
  leftMotor.setSpeed(-250);   //좌측 모터 역회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
  rightMotor.setSpeed(250);  //우측 모터 정회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
}
void turnright(){
  leftMotor.setSpeed(250);   //좌측 모터 정회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
  rightMotor.setSpeed(-250);  //우측 모터 역회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
}
void Stop(){  //함수 꼬일 거 같아서 앞에 대문자로 바꿔놨음.
  //뒤에 코드도 바꿔놓긴 했는데 혹시 모르니까 확인해봐
  leftMotor.setSpeed(0);   //좌측 모터 정회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
  rightMotor.setSpeed(0);  //우측 모터 정회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
}
void blink_led(){
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
  digitalWrite(Switch,LOW);
  delay(100);
  digitalWrite(Switch,HIGH);
  delay(100);
}
/*------------------------------------------------------------------------------------*/
//set-up
void setup() {
  Serial.begin(9600); // 시리얼 통신 시
  pinMode(7,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(3,INPUT);
  pinMode(4,INPUT);
  pinMode(5,OUTPUT);
  pinMode(Switch,OUTPUT);

  digitalWrite(5,LOW);
  digitalWrite(2,LOW);
  while(true){
    if(flage == 0){
      if(Serial.available()){
        cmd = Serial.read();
        Serial.println(cmd);
    
        if(cmd=='2'){
          flage = 1;
          digitalWrite(6,HIGH);
          delay(10);
          digitalWrite(6,LOW);
          break;
        }
      }
    }
  }
}
/*------------------------------------------------------------------------------------*/
//lineTracing_main-code
void loop() {
  
  int leftSensorValue = analogRead(leftSensorPin); // 왼쪽 라인 센서 값 읽기
  int rightSensorValue = analogRead(rightSensorPin); // 오른쪽 라인 센서 값 읽기
  int ok_sign = digitalRead(4);
  int cam_sign = digitalRead(3);
  digitalWrite(Switch,HIGH);
  forward();
  if (leftSensorValue > line_limit && rightSensorValue < line_limit) { //왼쪽 센서만 검은색 선을 감지 했을때 (좌회전)
    turnleft();
    delay(20);
  }
  if(rightSensorValue > line_limit && leftSensorValue < line_limit) { //오른쪽 센서만 검은색 선을 감지 했을때 (우회전)
    turnright();
    delay(20);
  }
  if(leftSensorValue > line_limit && rightSensorValue > line_limit){ // 양쪽 센서가 모두 검은색 선을 감지 했을때 (정지) 
    digitalWrite(5,HIGH);
    //Serial.println("line declear");
    Stop();
    delay(10);
    digitalWrite(5,LOW);
    //Serial.println("line stop");
    while(true){
      digitalWrite(5,LOW);
      cam_sign = digitalRead(3);
      if(cam_sign == HIGH){
        Serial.println("0");
        delay(20);
      }
      if(Serial.available()){
        cmd = Serial.read();
        Serial.println(cmd);
    
        if(cmd=='9'){
          digitalWrite(7,HIGH);
          digitalWrite(2,HIGH);
          delay(10);
          digitalWrite(2,LOW);
          blink_led();
          digitalWrite(7,LOW);
        }
      }
      ok_sign = digitalRead(4);
      if(ok_sign == HIGH){
        Serial.println("AWS");
        forward();
        delay(500);
        break;
      }
    }
 }

  delay(5);
}
/*------------------------------------------------------------------------------------*/
