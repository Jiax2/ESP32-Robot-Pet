#include "RobotServo.h"
#include "config.h"

#include <ESP32Servo.h>

Servo headServo;

void setupServo() {
  headServo.attach(SERVO_PIN);
  headServo.write(90);
}

void moveServoTo(int angle) {
  headServo.write(angle);
}