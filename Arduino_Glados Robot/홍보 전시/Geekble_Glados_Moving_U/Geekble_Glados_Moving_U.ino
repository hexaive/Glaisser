  #include <DynamixelShield.h>
#include <Dynamixel2Arduino.h>
#include "CytronMotorDriver.h"

// Configure the motor driver.
CytronMD motor1(PWM_DIR, 12, 11);  // PWM 2 = Pin 13, DIR 2 = Pin 12.

#if defined(ARDUINO_AVR_UNO) || defined(ARDUINO_AVR_MEGA2560)
  #include <SoftwareSerial.h>
  SoftwareSerial soft_serial(7, 8); // DYNAMIXELShield UART RX/TX
  #define DEBUG_SERIAL soft_serial
#elif defined(ARDUINO_SAM_DUE) || defined(ARDUINO_SAM_ZERO)
  #define DEBUG_SERIAL SerialUSB    
#else
  #define DEBUG_SERIAL Serial
#endif

const uint8_t DXL_ID4 = 4;
const uint8_t DXL_ID3 = 3;
const uint8_t DXL_ID2 = 2;
const uint8_t DXL_ID1 = 1;
int i=1;
int dmx_speed=100;
int command=0;
const float DXL_PROTOCOL_VERSION = 1.0;
unsigned long previoustime1, previoustime2, time;

int dmx_1_angle = 1000;
int dmx_4_angle = 4000;



DynamixelShield dxl;

using namespace ControlTableItem;

void setup() {
  
  Serial.begin(9600);
  pinMode(5,INPUT);
  pinMode(4,OUTPUT);
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
  digitalWrite(4,LOW);
  
  delay(1000);
}
void loop(){
  while(true){
    if(dmx_1_angle >= 0){
      dmx_1_down();
      dmx3_up();
      linier_up();
    }
    if(dmx_4_angle <= 8000){
      dmx_4_right();
    }
    if(dmx_1_angle == 0){
      motor1.setSpeed(0);
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
      linier_down();
    }
    if(dmx_4_angle >= 4000){
      dmx_4_center2();
    }
    if(dmx_1_angle == 1000){
      motor1.setSpeed(0);
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
    if(dmx_1_angle >= 0){
      dmx_1_down();
      dmx3_up();
      linier_up();
    }
    if(dmx_4_angle >= 0){
      dmx_4_left();
    }
    if(dmx_1_angle == 0){
      motor1.setSpeed(0);
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
      linier_down();
    }
    if(dmx_4_angle <= 4000){
      dmx_4_center();
    }
    if(dmx_1_angle == 1000){
      motor1.setSpeed(0);
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
void turn_center(){
  dxl.setGoalPosition(DXL_ID4, 4000);
  for(i=0; i<=4000; i=i+50){
    dxl.setGoalPosition(DXL_ID4, i);
    delay(20);
  }
}
void dmx_4_left(){
  unsigned long time = millis();

  if(time -  previoustime2 >= 30){
    previoustime2 = time;
    if(dmx_4_angle != 0 && dmx_4_angle <= 5000){
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

void dmx_4_right(){
  unsigned long time = millis();

  if(time -  previoustime2 >= 30){
    previoustime2 = time;
    if(dmx_4_angle != 8000 && dmx_4_angle >= 3000){
      if(4000<=dmx_4_angle && dmx_4_angle<=5000){
        dmx_speed = 60;
      }
      else if(5000<=dmx_4_angle && dmx_4_angle<=5500){
        dmx_speed = 55;
      }
      else if(5500<=dmx_4_angle && dmx_4_angle<=6000){
        dmx_speed = 50;
      }
      else if(6000<=dmx_4_angle && dmx_4_angle<=6300){
        dmx_speed = 45;
      }
      else if(6300<=dmx_4_angle && dmx_4_angle<=7200){
        dmx_speed = 40;
      }
      else if(7200<=dmx_4_angle && dmx_4_angle<=7500){
        dmx_speed = 30;
      }
      else if(7500<=dmx_4_angle && dmx_4_angle<=8000){
        dmx_speed = 10;
      }
      dmx_4_angle += dmx_speed;
      dxl.setGoalPosition(DXL_ID4, dmx_4_angle);
    }
  }
}

void dmx_4_center(){
  unsigned long time = millis();

  if(time -  previoustime2 >= 30){
    previoustime2 = time;
    if(dmx_4_angle != 4000 && dmx_4_angle >= -100){
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
void dmx_4_center2(){
  unsigned long time = millis();

  if(time -  previoustime2 >= 30){
    previoustime2 = time;
    if(dmx_4_angle != 4000 && dmx_4_angle <= 9000){
      if(7000<=dmx_4_angle && dmx_4_angle<=8000){
        dmx_speed = 60;
      }
      else if(6500<=dmx_4_angle && dmx_4_angle<=7000){
        dmx_speed = 55;
      }
      else if(6000<=dmx_4_angle && dmx_4_angle<=6500){
        dmx_speed = 50;
      }
      else if(5700<=dmx_4_angle && dmx_4_angle<=6000){
        dmx_speed = 45;
      }
      else if(4800<=dmx_4_angle && dmx_4_angle<=5700){
        dmx_speed = 40;
      }
      else if(4500<=dmx_4_angle && dmx_4_angle<=4800){
        dmx_speed = 30;
      }
      else if(4000<=dmx_4_angle && dmx_4_angle<=4500){
        dmx_speed = 10;
      }
      dmx_4_angle -= dmx_speed;
      dxl.setGoalPosition(DXL_ID4, dmx_4_angle);
    }
  }
}
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
void linier_down(){
  motor1.setSpeed(225);
  //11초
}
void linier_up(){
  motor1.setSpeed(-225);
  //11초
}
void dmx3_up(){
  dxl.torqueOff(DXL_ID3);
  dxl.setOperatingMode(DXL_ID3, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID3);
  dxl.setGoalPosition(DXL_ID3, 22000);
}
void dmx3_down(){
  dxl.torqueOff(DXL_ID3);
  dxl.setOperatingMode(DXL_ID3, OP_EXTENDED_POSITION);
  dxl.torqueOn(DXL_ID3);
  dxl.setGoalPosition(DXL_ID3, 2000);
}
