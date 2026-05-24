#include "DisplayUI.h"
#include "config.h"

#include <Adafruit_GFX.h>
#include <Adafruit_GC9A01A.h>

#define BLACK   GC9A01A_BLACK
#define WHITE   GC9A01A_WHITE
#define CYAN    GC9A01A_CYAN
#define GREEN   GC9A01A_GREEN

Adafruit_GC9A01A tft(TFT_CS, TFT_DC, TFT_RST);

void setupDisplay() {
  tft.begin();
  tft.fillScreen(BLACK);

  tft.setTextColor(GREEN);
  tft.setTextSize(2);
  tft.setCursor(45, 90);
  tft.println("DISPLAY OK");
}

void drawTestScreen(int angle) {
  tft.fillScreen(BLACK);

  tft.setTextColor(CYAN);
  tft.setTextSize(2);
  tft.setCursor(55, 70);
  tft.println("ROBOT PET");

  tft.setTextColor(WHITE);
  tft.setCursor(55, 120);
  tft.print("Angle:");
  tft.println(angle);

  tft.fillCircle(90, 170, 15, GREEN);
  tft.fillCircle(150, 170, 15, GREEN);
}