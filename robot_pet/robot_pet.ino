#include "config.h"
#include "DisplayUI.h"
#include "RobotServo.h"

int angle = 0;
bool goingUp = true;

bool running = false;
bool lastButtonState = HIGH;

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  setupDisplay();
  setupServo();

  drawTestScreen(angle);

  Serial.println("Robot Pet test started");
  Serial.println("Pulsa BOOT para encender/apagar servo");
}

void loop() {
  bool buttonState = digitalRead(BUTTON_PIN);

  if (lastButtonState == HIGH && buttonState == LOW) {
    running = !running;

    if (running) {
      Serial.println("Servo ENCENDIDO");
    } else {
      Serial.println("Servo APAGADO");
    }

    delay(300);
  }

  lastButtonState = buttonState;

  if (!running) {
    return;
  }

  moveServoTo(angle);
  drawTestScreen(angle);

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

  delay(500);
}