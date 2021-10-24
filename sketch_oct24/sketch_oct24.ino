#include <Wire.h>
#include <RTClib.h>
#include <DHT.h>

#define pinoLDR A0
#define bomba_reservatorio 7
#define DHTpin 6

#define DHTtype DHT11
DHT dht (DHTpin, DHTtype);
RTC_DS3231 rtc;

int tempmax = 0, tempmin = 0;
int valorLDR = 0,  temperaturaDHT, umidadeDHT;
float luminosidade = 0;
char daysOfTheWeek[7][12] = {"Domingo", "Segunda", "Terça", "Quarta", "Quinta", "Sexta", "Sábado"};
unsigned long previousMillis = 0;
const long intervalo = 60000;

void rotina_irrigacao();
void leitura_dht();
void leituraldr();

void setup() {
  dht.begin();
  rtc.begin();
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

    Serial.println("");
  }
}
