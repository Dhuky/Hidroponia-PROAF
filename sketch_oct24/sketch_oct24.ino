#include <Wire.h>
#include <RTClib.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <Arduino.h>

#define pinoLDR A0
#define pHsense A1
#define bomba_reservatorio 7
#define DHTpin 6
#define DS18B20 5

#define DHTtype DHT11
DHT dht (DHTpin, DHTtype);
RTC_DS3231 rtc;
OneWire ourWire(DS18B20);
DallasTemperature sensors(&ourWire);

int tempmax = 0, tempmin = 0, from_ad = 0, measure; //pHsense = A1;
int valorLDR = 0,  temperaturaDHT, umidadeDHT, samples = 10;
float luminosidade = 0, temperaturaDS18B20 = 0, pHvalue = 0;
float adc_resolution = 1024.0, Po;
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
unsigned long previousMillis = 0;
const long intervalo = 60000;
double voltage;

void rotina_irrigacao();
void leitura_dht();
void leituraldr();
void leitura_ds18b20();
void leitura_pH();

void setup() {
  dht.begin();
  rtc.begin();
  sensors.begin();
  Serial.begin(9600);

  pinMode(bomba_reservatorio, OUTPUT);

  digitalWrite(bomba_reservatorio, LOW);
}

void loop () {

  unsigned long currentMillis = millis();
  DateTime now = rtc.now();

  leitura_dht();
  rotina_irrigacao();
  leituraldr();
  leitura_ds18b20();
  leitura_pH();

  if (currentMillis - previousMillis >= intervalo) {
    previousMillis = currentMillis;

    Serial.print(now.day(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.year(), DEC);
    Serial.print(" / ");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(" / ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.println();

    Serial.print("Luminosidade lida: ");
    Serial.print(luminosidade);
    Serial.println(" %");

    Serial.print ("Temperatura: ");
    Serial.print (temperaturaDHT);
    Serial.println(" C°");

    Serial.print ("Umidade: ");
    Serial.print (umidadeDHT);
    Serial.println(" %");

    Serial.print("Temperatura solução nutritiva: ");
    Serial.print(temperaturaDS18B20);
    Serial.println(" C°");

    Serial.print("PH: ");
    Serial.println(Po, 3);

    Serial.println("");
  }
}
