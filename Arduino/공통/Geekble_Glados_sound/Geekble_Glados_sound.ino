#include <DFRobotDFPlayerMini.h>
#include <SoftwareSerial.h>

DFRobotDFPlayerMini player;

void setup() {
  // 시리얼 통신 초기화
  Serial2.begin(9600);
  player.begin(Serial2);
  delay(1);
  player.volume(20); // 볼륨 설정 (0 ~ 30)
}

void loop() {
  player.play(1);
  delay(85000);
}
