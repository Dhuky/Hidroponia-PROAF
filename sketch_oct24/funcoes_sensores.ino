
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

void leitura_pH() {
  measure = analogRead(pHsense);
  voltage = 5 / 1024.0 * measure; 
  Po = 7 + ((2.5 - voltage) / 0.18);
}

void leitura_tds(){
  gravityTds.setTemperature(temperature);
  gravityTds.update();
  tdsValue = gravityTds.getTdsValue();
}
