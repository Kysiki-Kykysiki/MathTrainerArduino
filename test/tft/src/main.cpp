#include <Arduino.h>
#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"
#include "TempResistor.h"

#define TFT_CS 10
#define TFT_DC 9

Adafruit_ILI9341 tft(TFT_CS, TFT_DC);

const int WIND = 5;

int buf[WIND];
int bufIndx = 0;

int smooth(int newVal){
    buf[bufIndx] = newVal;
    bufIndx = (bufIndx + 1) % WIND;

    int sum = 0;
    for(int i = 0; i < WIND; i++) sum += buf[i];
    return (int)(sum / WIND);
}

void drawBar(int y, int val, int maxVal, uint16_t color){
    const int X = 10, W = 220, H = 20;
    int fill = map(val, 0, maxVal, 0, W);
    tft.fillRect(X, y, fill, H, color);
    tft.fillRect(X + fill, y, W - fill, H, ILI9341_DARKGREY);
}


void redrawNumber(int x, int y, int newVal, int oldVal, uint16_t color){
    char tmp[6];
    tft.setTextSize(2);

    sprintf(tmp, "%4d", oldVal);
    tft.setTextColor(ILI9341_BLACK);
    tft.setCursor(x,y);
    tft.print(tmp);

    sprintf(tmp, "%4d", newVal);
    tft.setTextColor(color);
    tft.setCursor(x,y);
    tft.print(tmp);
}

TempResistor tempRes;

void setup() {
    Serial.begin(9600);

    tft.begin();
    tft.setRotation(1);
    tft.fillScreen(ILI9341_BLACK);

    // int init = analogRead(A0);
    int init = tempRes.get_temp();
    for(int i = 0; i < WIND; i++) buf[i] = init;

    tft.setTextSize(2);
    tft.setTextColor(ILI9341_WHITE);
    tft.setCursor(112,8);
    tft.print("SENSOR");

    tft.setTextColor(ILI9341_RED);
    tft.setCursor(10, 40);
    tft.print("RAW:");

    tft.setTextColor(ILI9341_GREEN);
    tft.setCursor(10, 112);
    tft.print("AVG(N=5):");

    tft.setTextColor(ILI9341_YELLOW);
    tft.setCursor(10, 184);
    tft.print("NOISE:");


}
int prewNoisy = 0;
int prewAvg = 0;
int prewNoise = 0;



void loop() {
    // int raw = analogRead(A0);
    int raw = tempRes.get_temp();

    int noisy = constrain(raw + random(-20, 20),-24,80);

    int avg = smooth(noisy);

    int noise = abs(noisy - avg);
    
    drawBar(60, noisy, 80, ILI9341_RED);
    drawBar(130, avg, 80, ILI9341_GREEN);
    drawBar(200, noise, 80, ILI9341_YELLOW);

    redrawNumber(250, 40, noisy, prewNoisy, ILI9341_RED);
    redrawNumber(250, 110, avg, prewAvg, ILI9341_GREEN);
    redrawNumber(250, 180, avg, prewAvg, ILI9341_YELLOW);

    prewNoisy = noisy;
    prewAvg = avg;
    prewNoise = noise;


    Serial.print("RAW: ");
    Serial.print(raw);
    Serial.print(" AVG: ");
    Serial.print(avg);
    Serial.print(" Noise: ");
    Serial.println(noise);

    delay(100);

}
