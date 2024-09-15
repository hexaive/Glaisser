/*[Geekble X 메이커창작과] : GLaDOS_Glados_Main Code */
/*-----------------------------------------------------------------------------------*/
#include <DynamixelShield.h>
#include <Dynamixel2Arduino.h>
#include "CytronMotorDriver.h"
/*-----------------------------------------------------------------------------------*/
//setting MotorDriver Pin
// MotorDriver PWM 2 = Pin 12, DIR 2 = Pin 11.
CytronMD linear(PWM_DIR, 12, 11); 
/*-----------------------------------------------------------------------------------*/
#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DEBUG_SERIAL soft_serial
#elif defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
  #define DEBUG_SERIAL SerialUSB    
#else
  #define DEBUG_SERIAL Serial
#endif
/*-----------------------------------------------------------------------------------*/

const uint8_t DXL_ID4 = 4;
const uint8_t DXL_ID3 = 3;
const uint8_t DXL_ID2 = 2;
const uint8_t DXL_ID1 = 1;
int i=1;
int dmx_speed=100;
int command=0;
int cmd=0;
const float DXL_PROTOCOL_VERSION = 1.0;
unsigned long previoustime1, previoustime2, time;
int dmx_1_angle = 1000;
int dmx_2_angle = 512;
int dmx_4_angle = 4000;
int switch_angle = 1;
/*-----------------------------------------------------------------------------------*/
DynamixelShield dxl;
using namespace ControlTableItem;
/*-----------------------------------------------------------------------------------*/
void dmx_1_up();
void dmx_1_down();
void dmx3_up();
void dmx3_down();
void linear_up();
void linear_down();
void dmx_4_left();
void doridori();
void dmx_4_center();
/*-----------------------------------------------------------------------------------*/
void doridori(){
    dxl.setGoalPosition(DXL_ID2, 812);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 212);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    digitalWrite(3,HIGH);
    delay(10);
    digitalWrite(3,LOW);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 812);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 212);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    delay(250);
}
/*-----------------------------------------------------------------------------------*/
void turn_center(){
  dxl.setGoalPosition(DXL_ID4, 4000);
  for(i=0; i<=4000; i=i+50){
    dxl.setGoalPosition(DXL_ID4, i);
    delay(20);
  }
}
/*-----------------------------------------------------------------------------------*/
void dmx_4_left(){
  unsigned long time = millis();

  if(time -  previoustime2 >= 30){
    previoustime2 = time;
    if(dmx_4_angle != 0 && dmx_4_angle <= 4000){
      if(3000<=dmx_4_angle && dmx_4_angle<=4000){
        dmx_speed = 60;
      }
      else if(2500<=dmx_4_angle && dmx_4_angle<=3000){
        dmx_speed = 55;
      }
      else if(2000<=dmx_4_angle && dmx_4_angle<=2500){
        dmx_speed = 50;
      }
      else if(1700<=dmx_4_angle && dmx_4_angle<=2000){
        dmx_speed = 45;
      }
      else if(800<=dmx_4_angle && dmx_4_angle<=1700){
        dmx_speed = 40;
      }
      else if(500<=dmx_4_angle && dmx_4_angle<=800){
        dmx_speed = 30;
      }
      else if(0<=dmx_4_angle && dmx_4_angle<=500){
        dmx_speed = 10;
      }
      dmx_4_angle -= dmx_speed;
      dxl.setGoalPosition(DXL_ID4, dmx_4_angle);
    }
  }
}
/*-----------------------------------------------------------------------------------*/
void dmx_4_center(){
  unsigned long time = millis();

  if(time -  previoustime2 >= 30){
    previoustime2 = time;
    if(dmx_4_angle != 4000 && dmx_4_angle >= 0){
      if(0<=dmx_4_angle && dmx_4_angle<=1000){
        dmx_speed = 60;
      }
      else if(1000<=dmx_4_angle && dmx_4_angle<=1500){
        dmx_speed = 55;
      }
      else if(1500<=dmx_4_angle && dmx_4_angle<=2000){
        dmx_speed = 50;
      }
      else if(2000<=dmx_4_angle && dmx_4_angle<=2300){
        dmx_speed = 45;
      }
      else if(2300<=dmx_4_angle && dmx_4_angle<=3200){
        dmx_speed = 40;
      }
      else if(3200<=dmx_4_angle && dmx_4_angle<=3500){
        dmx_speed = 30;
      }
      else if(3500<=dmx_4_angle && dmx_4_angle<=4000){
        dmx_speed = 10;
      }
      dmx_4_angle += dmx_speed;
      dxl.setGoalPosition(DXL_ID4, dmx_4_angle);
    }
  }
}
/*-----------------------------------------------------------------------------------*/
void dmx_1_down(){
  unsigned long time = millis();

  if(time -  previoustime1 >= 60){
    previoustime1 = time;
    if(dmx_1_angle != 0 && dmx_1_angle <= 1000){
      dmx_1_angle -= 10;
      dxl.setGoalPosition(DXL_ID1, dmx_1_angle);
    }
  }
}
/*-----------------------------------------------------------------------------------*/
void dmx_1_up(){
  unsigned long time = millis();

  if(time -  previoustime1 >= 60){
    previoustime1 = time;
    if(dmx_1_angle != 1000 && dmx_1_angle >= 0){
      dmx_1_angle += 10;
      dxl.setGoalPosition(DXL_ID1, dmx_1_angle);
    }
  }
}
/*-----------------------------------------------------------------------------------*/
void linear_down(){
  linear.setSpeed(225);
  //11초
}
/*-----------------------------------------------------------------------------------*/
void linear_up(){
  linear.setSpeed(-225);
  //11초
}
/*-----------------------------------------------------------------------------------*/
void dmx3_up(){
  dxl.torqueOff(DXL_ID3);
  dxl.setOperatingMode(DXL_ID3, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID3);
  dxl.setGoalPosition(DXL_ID3, 19000);
}
/*-----------------------------------------------------------------------------------*/
void dmx3_down(){
  dxl.torqueOff(DXL_ID3);
  dxl.setOperatingMode(DXL_ID3, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID3);
  dxl.setGoalPosition(DXL_ID3, 2000);
}
/*-----------------------------------------------------------------------------------*/
void setup() {
  Serial.begin(9600);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,INPUT);
  
  dxl.begin(9600);
  dxl.setPortProtocolVersion(DXL_PROTOCOL_VERSION);

  dxl.ping(DXL_ID1);
  dxl.torqueOff(DXL_ID1);
  dxl.setOperatingMode(DXL_ID1, OP_POSITION);
  dxl.torqueOn(DXL_ID1);
  dxl.setGoalPosition(DXL_ID1, 1000);
  
  dxl.ping(DXL_ID2);
  dxl.torqueOff(DXL_ID2);
  dxl.setOperatingMode(DXL_ID2, OP_POSITION);
  dxl.torqueOn(DXL_ID2);
  dxl.setGoalPosition(DXL_ID2, 512);
  
  dxl.ping(DXL_ID3);
  dxl.torqueOff(DXL_ID3);
  dxl.setOperatingMode(DXL_ID3, OP_POSITION);
  dxl.torqueOn(DXL_ID3);
  dxl.setGoalPosition(DXL_ID3, 2000);

  dxl.ping(DXL_ID4);
  dxl.torqueOff(DXL_ID4);
  dxl.setOperatingMode(DXL_ID4, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID4);
  dxl.setGoalPosition(DXL_ID4, 4000);
  
  dxl.torqueOff(DXL_ID3);
  dxl.setOperatingMode(DXL_ID3, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID3);
  dxl.setGoalPosition(DXL_ID3, 10000);
  delay(2000);
}
/*-----------------------------------------------------------------------------------*/
void loop(){
  //if(switch_angle == 0){
  //  unsigned long time = millis();

  //  if(time -  previoustime1 >= 20){
  //    previoustime1 = time;
  //    if(dmx_4_angle != 6000){
  //        dmx_4_angle += 10;
  //        dxl.setGoalPosition(DXL_ID4, dmx_4_angle);
  //    }
  //  }
  //}
  //else if(switch_angle == 1){
  //  unsigned long time = millis();

  //  if(time -  previoustime1 >= 20){
  //    previoustime1 = time;
  //    if(dmx_4_angle != 2000){
  //        dmx_4_angle -= 10;
  //        dxl.setGoalPosition(DXL_ID4, dmx_4_angle);
  //    }
  //  }
  //}
  //if(dmx_4_angle == 2000){
  //      switch_angle = 0;
  //}
  //else if(dmx_4_angle == 6000){
  //      switch_angle = 1;
  //}
  
  int run_g = digitalRead(5);
  if(run_g == HIGH){
    dxl.setGoalPosition(DXL_ID1, 1000);
    dxl.setGoalPosition(DXL_ID2, 512);
    dxl.setGoalPosition(DXL_ID3, 2000);
    dxl.setGoalPosition(DXL_ID4, 4000);
    delay(2000);
    while(true){
      if(dmx_1_angle >= 0){
        dmx_1_down();
        dmx3_up();
        linear_up();
      }
      if(dmx_4_angle >= 0){
        dmx_4_left();
      }
      if(dmx_1_angle == 0){
        linear.setSpeed(0);
        break;
      }
    }
    dxl.setGoalPosition(DXL_ID2, 812);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 212);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    digitalWrite(3,HIGH);
    delay(10);
    digitalWrite(3,LOW);
    delay(13000);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 812);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 212);
    delay(250);
    dxl.setGoalPosition(DXL_ID2, 512);
    delay(250);

    while(true){
      if(dmx_1_angle <= 1000){
        dmx_1_up();
        dmx3_down();
        linear_down();
      }
      if(dmx_4_angle <= 4000){
        dmx_4_center();
      }
      if(dmx_1_angle == 1000){
        linear.setSpeed(0);
        break;
      }
    }
    dxl.setGoalPosition(DXL_ID1, 1000);
    dxl.setGoalPosition(DXL_ID2, 512);
    dxl.setGoalPosition(DXL_ID4, 4000);
    dxl.setGoalPosition(DXL_ID3, 10000);
    dmx_4_angle = 4000;
    delay(2000);
    digitalWrite(4,HIGH);
    delay(10);
    digitalWrite(4,LOW);
  }
}
/*-----------------------------------------------------------------------------------*/
