
void rotina_irrigacao() {

  DateTime now = rtc.now();

  //Primeira rotina
  if ((now.hour() == 0) && (now.minute() >= 0) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() >= 0) && (now.hour() < 4) && (now.minute() >= 30) && (now.minute() < 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 4) && (now.minute() >= 0) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 4) && (now.minute() >= 30) && (now.minute() < 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  //Segunda rotina
  if ((now.hour() == 5) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 5) && (now.minute() >= 15)&&(now.hour() <45)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 5) && (now.minute() >= 45) && (now.minute() < 59)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 6) && (now.minute() >= 0) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 6) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 6) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }
  if ((now.hour() == 7) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 7) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 7) && (now.minute() >= 30) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }
  if ((now.hour() == 8) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 8) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 8) && (now.minute() >= 15) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 8) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 9) && (now.minute() >= 0) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 9) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 9) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  //terceira rotina
  if ((now.hour() == 10) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 10) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 10) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 10) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 11) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 11) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 11) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 11) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 12) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 12) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 12) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 12) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 13) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 13) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 13) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 13) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 14) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 14) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 14) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 14) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 15) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 15) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 15) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 15) && (now.minute() >= 45) && (now.minute() <= 59)) { //vai dar merda aqui
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 16) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  //Quarta rotina
  if ((now.hour() == 16) && (now.minute() >= 15) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 16) && (now.minute() >= 30) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 17) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 17) && (now.minute() >= 15) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 17) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 18) && (now.minute() >= 0) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 18) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 18) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }
  if ((now.hour() == 19) && (now.minute() >= 0) && (now.minute() < 30)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 19) && (now.minute() >= 30) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 19) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 20) && (now.minute() >= 0) && (now.minute() < 15)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() == 20) && (now.minute() >= 15) && (now.minute() < 45)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }

  if ((now.hour() == 20) && (now.minute() >= 45) && (now.minute() <= 59)) {
    digitalWrite(bomba_reservatorio, LOW);
  } else if ((now.hour() >= 21) && (now.hour() < 23) && (now.minute() >= 0) && (now.minute() < 59)) {
    digitalWrite(bomba_reservatorio, HIGH);
  }
}
