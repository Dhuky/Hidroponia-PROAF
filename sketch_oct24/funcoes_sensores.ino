
void leituraldr(){
    valorLDR = analogRead(pinoLDR);
    luminosidade = map(valorLDR, 1024, 0, 0, 100);
}

void leitura_dht() {
  temperaturaDHT = dht.readTemperature();
  if (dht.readTemperature() > tempmax) tempmax = dht.readTemperature();
  if (dht.readTemperature() < tempmax) tempmin = dht.readTemperature();
  umidadeDHT = dht.readHumidity();
}
