#include <Servo.h>
Servo turret;        // Create Servo object to control the servo
#define ZERO_SPEED 1500
#define LEFT_ADJUST_SMALL 9
#define LEFT_ADJUST 12
#define RIGHT_ADJUST_SMALL 12
#define RIGHT_ADJUST 15

#define FIRE_PIN 7

void setup() {
  turret.attach(9);  // Servo is connected to digital pin 9
  Serial.begin(9600);
  pinMode(FIRE_PIN, OUTPUT);
  digitalWrite(FIRE_PIN, LOW);
}

void loop() {
  turret.writeMicroseconds(1500);
  while (Serial.available() > 0){
    char c = Serial.read();
    Serial.println("yea");

    if (c == 'l'){
      turret.writeMicroseconds(ZERO_SPEED - LEFT_ADJUST_SMALL);
      delay(50);
    }else if (c == 'L'){
      turret.writeMicroseconds(ZERO_SPEED - LEFT_ADJUST);
      delay(50);
    }else if (c == 'r'){
      turret.writeMicroseconds(ZERO_SPEED + RIGHT_ADJUST_SMALL);
      delay(50);
    }else if (c == 'R'){
      turret.writeMicroseconds(ZERO_SPEED + RIGHT_ADJUST);
      delay(50);
    }else if (c == 'f'){
      digitalWrite(FIRE_PIN, HIGH);
      delay(1000);
      digitalWrite(FIRE_PIN, LOW);
    }
  }  
}
