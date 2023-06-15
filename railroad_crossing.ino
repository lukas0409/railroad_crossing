/* 적외선센서, SG90을 이용한 철도건널목 아두이노 제어 
본 프로그램은 1종 건널목 기준으로 제작되었음
차단기 (양측)
적외선센서 필요

MP3모듈을 이용한 경보시스템은 미제작
건널목 안내표지 설치필요

☆☆☆ 2개 동시제어시 외부전력 사용 (미사용시 보드고장) ☆☆☆
AAA건전지 4개 */

#include <Servo.h> // 서보모터 라이브러리

Servo myservo; // 서보모터 이름정의
Servo myservo1; // 서보모터 이름정의
int pos = 0; // 서보모터 각도
int sensor = 8; // 센서 8번핀
int val; // 

void setup() {
  // put your setup code here, to run once:
  myservo.attach(7); // SG90 핀지정
  myservo1.attach(11); // SG90 핀지정
  pinMode(sensor, INPUT); // 센서 입력지정
}

void loop() {
  val = digitalRead(sensor);  // 센서값 읽어옴
  
  if (val == 1) {          // 기차감지
    myservo.write(90); // 건널목 차단
    myservo1.write(90); // 건널목 차단
    delay(500);
  } 

  if (val == 0) { // 기차 감지X
    myservo.write(180); // 건널목 차단 해제
    myservo1.write(90); // 건널목 차단
    delay(500);
  }
}
