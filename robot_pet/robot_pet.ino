#include "config.h"
#include "DisplayUI.h"
#include "RobotServo.h"

int angle = 0;
bool goingUp = true;
bool running = false;

bool lastButtonState = HIGH;
unsigned long lastButtonTime = 0;
unsigned long lastServoTime = 0;

const unsigned long debounceDelay = 250;
const unsigned long servoInterval = 300;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  setupDisplay();
  setupServo();

  updateAngleText(angle);
  updateStatusText(running);

  Serial.println("Robot Pet test started");
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    unsigned long now = millis();

    if (now - lastButtonTime > debounceDelay) {
      running = !running;
      lastButtonTime = now;

      updateStatusText(running);

      Serial.println(running ? "Servo ON" : "Servo OFF");
    }
  }

  lastButtonState = buttonState;

  if (!running) {
    return;
  }

  unsigned long now = millis();

  if (now - lastServoTime >= servoInterval) {
    lastServoTime = now;

    moveServoTo(angle);
    updateAngleText(angle);

    Serial.print("Angle: ");
    Serial.println(angle);

    if (goingUp) {
      angle += 30;

      if (angle >= 180) {
        angle = 180;
        goingUp = false;
      }
    } else {
      angle -= 30;

      if (angle <= 0) {
        angle = 0;
        goingUp = true;
      }
    }
  }
}