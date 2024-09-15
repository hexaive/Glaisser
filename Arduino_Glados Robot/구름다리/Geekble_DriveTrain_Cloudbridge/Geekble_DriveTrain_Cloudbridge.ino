/*[Geekble X 메이커창작과] : GLaDOS_DriveTrain_lineTrace Code */
/*-----------------------------------------------------------------------------------*/
 #include "CytronMotorDriver.h"
 /*------------------------------------------------------------------------------------*/
 //motorDriver_pin_name_setting
CytronMD rightMotor(PWM_DIR, 10, 9);  // PWM 1 = Pin 10, DIR 1 = Pin 9.
CytronMD leftMotor(PWM_DIR, 12, 11); // PWM 2 = Pin 12, DIR 2 = Pin 11.
/*------------------------------------------------------------------------------------*/
//lineTracing_pin_setting
const int leftSensorPin = A0; // 왼쪽 라인 트레이싱 센서 아날로그 핀 설정
const int rightSensorPin = A1; // 오른쪽 라인 트레이싱 센서 아날로그 핀 설정
const int line_limit = 810; // 라인 감지 임계값 설정 (수정 0~1024)
int Switch = 2;
/*------------------------------------------------------------------------------------*/
// Drivetrain_Movement_Setting
void forward(){
  leftMotor.setSpeed(100);   //좌측 모터 정회전(정회전 1~255 | 역회전 -1~-255 | 정지 0)
  rightMotor.setSpeed(100);  //우측 모터 정회전(정회전 1~255 | 역회전 -1~-255 | 정지 0)
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
void stop(){
  leftMotor.setSpeed(0);   //좌측 모터 정회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
  rightMotor.setSpeed(0);  //우측 모터 정회전(정회전 0~255 | 역회전 -1~-255 | 정지 0)
}
/*------------------------------------------------------------------------------------*/
//set-up
void setup() {
  Serial.begin(9600); // 시리얼 통신 시작
  pinMode(Switch,OUTPUT);
}
/*------------------------------------------------------------------------------------*/
//lineTracing_main-code
void loop() {
  int leftSensorValue = analogRead(leftSensorPin); // 왼쪽 라인 센서 값 읽기
  int rightSensorValue = analogRead(rightSensorPin); // 오른쪽 라인 센서 값 읽기
  digitalWrite(Switch,HIGH);
  Serial.print("Left Sensor: ");  
  Serial.print(leftSensorValue);  // 왼쪽 센서 값을 시리얼 모니터에 출력
  Serial.print("  Right Sensor: ");
  Serial.println(rightSensorValue); // 오른쪽 센서 값을 시리얼 모니터에 출력
  forward();
  if (leftSensorValue > line_limit && rightSensorValue < line_limit) { //왼쪽 센서만 검은색 선을 감지 했을때 (좌회전)
    turnleft();
    delay(20);
  }
  if (rightSensorValue > line_limit && leftSensorValue < line_limit) { //오른쪽 센서만 검은색 선을 감지 했을때 (우회전)
    turnright();
    delay(20);
  }
  if(leftSensorValue > line_limit && rightSensorValue > line_limit){ // 양쪽 센서가 모두 검은색 선을 감지 했을때 (정지) 
    stop();
    delay(10);
  }
  delay(5);
}
/*------------------------------------------------------------------------------------*/
