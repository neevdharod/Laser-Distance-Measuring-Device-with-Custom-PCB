#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
HardwareSerial lidar(1);

const int measureButton = D0;
const int unitButton = D1;
const int lidarRx = D7;
const int lidarTx = D6;

int unitMode = 0;
float lastMeters = -1;

bool lastMeasure = HIGH;
bool lastUnit = HIGH;

void showText(String top, String mainText, String bottom) {
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print(top);
  display.setTextSize(2);
  display.setCursor(0, 22);
  display.print(mainText);
  display.setTextSize(1);
  display.setCursor(0, 56);
  display.print(bottom);
  display.display();
}

bool readLuna(float &meters) {
  unsigned long start = millis();
  while (millis() - start < 700) {
    if (lidar.available() >= 9) {
      if (lidar.read() == 0x59 && lidar.peek() == 0x59) {
        byte data[9];
        data[0] = 0x59;
        data[1] = lidar.read();
        for (int i = 2; i < 9; i++) data[i] = lidar.read();
        byte sum = 0;
        for (int i = 0; i < 8; i++) sum += data[i];
        if (sum == data[8]) {
          int cm = data[2] + data[3] * 256;
          if (cm > 0) {
            meters = cm / 100.0;
            return true;
          }
        }
      }
    }
  }
  return false;
}

String valueText() {
  if (lastMeters < 0) return "--";
  char buf[20];
  if (unitMode == 0) sprintf(buf, "%.2f m", lastMeters);
  if (unitMode == 1) sprintf(buf, "%.0f cm", lastMeters * 100.0);
  if (unitMode == 2) sprintf(buf, "%.2f ft", lastMeters * 3.28084);
  if (unitMode == 3) sprintf(buf, "%.1f in", lastMeters * 39.3701);
  return String(buf);
}

void refreshScreen() {
  if (lastMeters < 0) showText("Distance Meter", "Ready", "Press MEASURE");
  else showText("Distance", valueText(), "MEASURE again | UNIT");
}

void setup() {
  pinMode(measureButton, INPUT_PULLUP);
  pinMode(unitButton, INPUT_PULLUP);
  Wire.begin(D9, D10);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  lidar.begin(115200, SERIAL_8N1, lidarRx, lidarTx);
  refreshScreen();
}

void loop() {
  bool measureNow = digitalRead(measureButton);
  bool unitNow = digitalRead(unitButton);

  if (lastMeasure == HIGH && measureNow == LOW) {
    showText("Measuring", "Wait", "");
    float m;
    if (readLuna(m)) lastMeters = m;
    else showText("Error", "No read", "Try again");
    if (lastMeters >= 0) refreshScreen();
    delay(250);
  }

  if (lastUnit == HIGH && unitNow == LOW) {
    unitMode = (unitMode + 1) % 4;
    refreshScreen();
    delay(250);
  }

  lastMeasure = measureNow;
  lastUnit = unitNow;
}
