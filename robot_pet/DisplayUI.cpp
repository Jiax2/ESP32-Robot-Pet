#include "DisplayUI.h"
#include "config.h"

#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>

#define BLACK   GC9A01A_BLACK
#define WHITE   GC9A01A_WHITE
#define CYAN    GC9A01A_CYAN
#define GREEN   GC9A01A_GREEN
#define RED     GC9A01A_RED

Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_RST);

void setupDisplay() {
  tft.begin();
  drawStaticScreen();
}

void drawStaticScreen() {
  tft.fillScreen(BLACK);

  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.setCursor(55, 55);
  tft.println("ROBOT PET");

  tft.fillCircle(90, 155, 15, GREEN);
  tft.fillCircle(150, 155, 15, GREEN);

  tft.setTextColor(WHITE);
  tft.setCursor(45, 105);
  tft.print("Angle:");

  tft.setCursor(55, 200);
  tft.print("Status:");
}

void updateAngleText(int angle) {
  // borrar solo la zona donde va el número
  tft.fillRect(130, 105, 80, 25, BLACK);

  tft.setTextColor(WHITE);
  tft.setTextSize(2);
  tft.setCursor(130, 105);
  tft.print(angle);
}

void updateStatusText(bool running) {
  // borrar solo la zona del estado
  tft.fillRect(145, 200, 80, 25, BLACK);

  tft.setTextSize(2);
  tft.setCursor(145, 200);

  if (running) {
    tft.setTextColor(GREEN);
    tft.print("ON");
  } else {
    tft.setTextColor(RED);
    tft.print("OFF");
  }
}