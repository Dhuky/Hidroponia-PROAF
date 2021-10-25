#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);

void setup() {
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {

  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);

  display.setCursor(0, 0);
  display.print("25/10/2021");
  display.setCursor(94, 0);
  display.print("16:02");
  display.setCursor(0, 10);
  display.print("Temperatura:");
  display.print(" 50.8");
  display.print(" C");
  display.setCursor(0, 25);
  display.print("Umidade:");
  display.print(" 31.3");
  display.print(" %");
  display.setCursor(0, 10);
  display.drawLine(0, 20, 128, 20, SSD1306_WHITE);
  delay(2000);
  display.startscrollleft(0x00, 0x0F);
  delay(4100);
  display.stopscroll();
  delay(2000);
  display.display();
  display.clearDisplay();
  
  display.setCursor(0, 0);
  display.print("25/10/2021");
  display.setCursor(94, 0);
  display.print("16:02");
  display.setCursor(0, 10);
  display.print("Luminosi.:");
  display.print(" 50");
  display.print(" %");
  display.setCursor(0, 25);
  display.print("Temp. sol.:");
  display.print(" 35.6");
  display.print(" C");
  display.setCursor(0, 10);
  display.drawLine(0, 20, 128, 20, SSD1306_WHITE);
  delay(2000);
  display.startscrollleft(0x00, 0x0F);
  delay(4100);
  display.stopscroll();
  display.display();
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print("25/10/2021");
  display.setCursor(94, 0);
  display.print("16:02");
  display.setCursor(0, 10);
  display.print("Condut.:");
  display.print(" 100");
  display.print(" ppm");
  display.setCursor(0, 25);
  display.print("pH:");
  display.print(" 7");
  display.print(" ");
  display.setCursor(0, 10);
  display.drawLine(0, 20, 128, 20, SSD1306_WHITE);
  delay(2000);
  display.startscrollleft(0x00, 0x0F);
  delay(4100);
  display.stopscroll();
  display.display();
  display.clearDisplay();

  //display.display();
}
