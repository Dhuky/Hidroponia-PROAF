#include <DallasTemperature.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include "GravityTDS.h"
#include <Arduino.h>
#include <OneWire.h>
#include <RTClib.h>
#include <Wire.h>
#include <EEPROM.h>
#include <DHT.h>

#define pinoLDR A0
#define pHsense A1
#define TdsSensorPin A2
#define bomba_reservatorio 7
#define DHTpin 6
#define DS18B20 5

#define OLED_RESET 4
#define DHTtype DHT11
DHT dht (DHTpin, DHTtype);
Adafruit_SSD1306 display(OLED_RESET);
RTC_DS3231 rtc;
OneWire ourWire(DS18B20);
DallasTemperature sensors(&ourWire);
GravityTDS gravityTds;

int tempmax = 0, tempmin = 0, from_ad = 0, measure;
int valorLDR = 0,  temperaturaDHT, umidadeDHT, samples = 10;
float luminosidade = 0, temperaturaDS18B20 = 0;
float adc_resolution = 1024.0, Po, temperature = 30, tdsValue;
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
double voltage;

void rotina_irrigacao();
void leitura_dht();
void leituraldr();
void leitura_ds18b20();
void leitura_pH();
void leitura_tds();

void setup() {
  dht.begin();
  rtc.begin();
  sensors.begin();
  Wire.begin();
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  Serial.begin(9600);
  gravityTds.setPin(TdsSensorPin);
  gravityTds.setAref(5.0);
  gravityTds.setAdcRange(1024);
  gravityTds.begin();

  pinMode(bomba_reservatorio, OUTPUT);
  digitalWrite(bomba_reservatorio, LOW);
}

void loop () {

  DateTime now = rtc.now();

  leitura_dht();
  rotina_irrigacao();
  leituraldr();
  leitura_ds18b20();
  leitura_pH();
  leitura_tds();

  display.setTextColor(WHITE);
  display.setTextSize(1);
  
  display.display();
  display.clearDisplay();
  display.setCursor(0, 0);
  display.print(now.day(), DEC);
  display.print('/');
  display.print(now.month(), DEC);
  display.print('/');
  display.print(now.year(), DEC);
  display.setCursor(94, 0);
  display.print(now.hour(), DEC);
  display.print(':');
  display.print(now.minute(), DEC);
  display.setCursor(0, 10);
  display.print("Temperatura: ");
  display.print(temperaturaDHT);
  display.print(" C");
  display.setCursor(0, 25);
  display.print("Umidade: ");
  display.print(umidadeDHT);
  display.print(" %");
  display.setCursor(0, 10);
  display.drawLine(0, 20, 128, 20, SSD1306_WHITE);
  display.display();
  delay(3000);
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print(now.day(), DEC);
  display.print('/');
  display.print(now.month(), DEC);
  display.print('/');
  display.print(now.year(), DEC);
  display.setCursor(94, 0);
  display.print(now.hour(), DEC);
  display.print(':');
  display.print(now.minute(), DEC);
  display.setCursor(0, 10);
  display.print("Luminosi.: ");
  display.print(luminosidade);
  display.print(" %");
  display.setCursor(0, 25);
  display.print("Temp. sol.: ");
  display.print(temperaturaDS18B20);
  display.print(" C");
  display.setCursor(0, 10);
  display.drawLine(0, 20, 128, 20, SSD1306_WHITE);
  display.display();
  delay(3000);
  display.clearDisplay();

  display.setCursor(0, 0);
  display.print(now.day(), DEC);
  display.print('/');
  display.print(now.month(), DEC);
  display.print('/');
  display.print(now.year(), DEC);
  display.setCursor(94, 0);
  display.print(now.hour(), DEC);
  display.print(':');
  display.print(now.minute(), DEC);
  display.setCursor(0, 10);
  display.print("Condut.: ");
  display.print(tdsValue, 0);
  display.print(" ppm");
  display.setCursor(0, 25);
  display.print("pH: ");
  display.print(Po, 3);
  display.setCursor(0, 10);
  display.drawLine(0, 20, 128, 20, SSD1306_WHITE);
  display.display();
  delay(3000);
  display.clearDisplay();
}
