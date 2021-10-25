
void leituraldr() {
  valorLDR = analogRead(pinoLDR);
  luminosidade = map(valorLDR, 1024, 0, 0, 100);
}

void leitura_dht() {
  temperaturaDHT = dht.readTemperature();
  if (dht.readTemperature() > tempmax) tempmax = dht.readTemperature();
  if (dht.readTemperature() < tempmax) tempmin = dht.readTemperature();
  umidadeDHT = dht.readHumidity();
}

void leitura_ds18b20() {
  sensors.requestTemperatures();
  temperaturaDS18B20 = sensors.getTempCByIndex(0);
}
