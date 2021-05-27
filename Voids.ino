void debug1() { //Als debug om de waarde te lezen.
  Serial.print(measurement1);
  Serial.print("\t");
  Serial.print(measurement2);
  Serial.print("\t");
  Serial.print(measurement3);
  Serial.print("\t");
  Serial.println(measurement4);
}


void capacativenRegister() { //Zal de boolian van de knoppen updaten.
  gedrukt = false;
  if (measurement1 > capTreshold) { //Cap 1
    cap1 = true;
    gedrukt = true;
    if (debugConsole == true) {
      Serial.println("cap1 True");
    }
  }
  else {
    cap1 = false;
  }
  if (measurement2 > capTreshold) { //Cap 2
    cap2 = true;
    gedrukt = true;
    if (debugConsole == true) {
      Serial.println("cap2 True");
    }
  }
  else {
    cap2 = false;
  }
  if (measurement3 > capTreshold) { //Cap 3
    cap3 = true;
    gedrukt = true;
    if (debugConsole == true) {
      Serial.println("cap3 True");
    }
  }
  else {
    cap3 = false;
  }
  if (measurement4 > capTreshold) { //Cap 4
    cap4 = true;
    gedrukt = true;
    if (debugConsole == true) {
      Serial.println("cap4 True");
    }
  }
  else {
    cap4 = false;
  }
  delay(40);
}


void sensorMeting() {//Leest de waardes van de sensor af
  measurement1 =  sensor1.capacitiveSensor(30);
  measurement2 =  sensor2.capacitiveSensor(30);
  measurement3 =  sensor3.capacitiveSensor(30);
  measurement4 =  sensor4.capacitiveSensor(30);
  delay(40);
  debug1(); //Deze void print alle sensorwaarden in de serial window
}

void neoPixelStartup() { //Regelt de start Cyclus van de NeoPixel
  neoPixelWipe(strip.Color(  100, 0,   0), 100);
  neoPixelWipe(strip.Color(  0, 100,   0), 50);
  neoPixelWipe(strip.Color(  0, 0,   0), 10);
  neoPixelZone2(strip.Color(  0, 200,   127), 50); //beach blue
  neoPixelZone1(strip.Color(  255, 100,   20), 50); //Goud kleur
  neoPixelZone4(strip.Color(  151, 22,   191), 50); //bronze
  neoPixelZone3(strip.Color(  200, 50,  20), 50); //amethyst
  delay(1500);
  neoPixelWipe(strip.Color(  0, 0,   0), 10);
}

//De code om de 4 individuele zones aan/ uit te zetten.
void neoPixelZone1(uint32_t color, int wait) {
  for (int i = 6; i <= 9; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void neoPixelZone2(uint32_t color, int wait) {
  for (int i = 2; i <= 5; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void neoPixelZone3(uint32_t color, int wait) {
  for (int i = 14; i <= 16; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
  for (int i = 0; i <= 1; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void neoPixelZone4(uint32_t color, int wait) {
  for (int i = 10; i <= 13; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }

}

void neoPixelWipe(uint32_t color, int wait) {
  for (int i = 0; i <= strip.numPixels(); i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}

void neoPixelController(int mode, bool next) {
  switch (mode) {
    case 1:
      neoPixelZone1(strip.Color(  50, 0,   0), 10);    // Black/off
      neoPixelZone2(strip.Color(  0, 0,   0), 10);
      neoPixelZone3(strip.Color(  0, 0,   0), 10);
      neoPixelZone4(strip.Color(  0, 0,   0), 10);
      next = false;
      break;
    case 2:
      neoPixelZone2(strip.Color(  0, 50,   0), 10);    // Groen
      neoPixelZone1(strip.Color(  0, 0,   0), 10);
      neoPixelZone3(strip.Color(  0, 0,   0), 10);
      neoPixelZone4(strip.Color(  0, 0,   0), 10);
      next = false;
      break;
    case 3:
      neoPixelZone3(strip.Color(  0, 0,   50), 10);    // Blauw
      neoPixelZone1(strip.Color(  0, 0,   0), 10);
      neoPixelZone2(strip.Color(  0, 0,   0), 10);
      neoPixelZone4(strip.Color(  0, 0,   0), 10);
      next = false;
      break;
    case 4:
      neoPixelZone4(strip.Color(  50, 0,   50), 10);    // Paars
      neoPixelZone1(strip.Color(  0, 0,   0), 10);
      neoPixelZone2(strip.Color(  0, 0,   0), 10);
      neoPixelZone3(strip.Color(  0, 0,   0), 10);
      next = false;
      break;
  }
}

//De basiscode van het spelletje, hier word de zone gekozen
//en gecontrolleerd of de juiste knop is aangeraakt
void hetSpel() {
  zoneOud = zone; //Deze code kiest een random zone, en zal de kans op een dubbelle zone verkleinen.
  zone = random(1, 5);
  if (zone = zoneOud) {
    zone = random(1, 5);
  }
  Serial.println(zone);

  while (cap1 == true && cap2 == true && cap3 == true && cap4 == true) {
    foutAntwoord(); //Deze code weerhoud je er van alle 4 de knoppen tegelijkertijd in te drukken.
  }
  if (zone == 1) {
    neoPixelController(1, true); //neoPixelController(int "Zone", bool "true");
    int timer = timersnelheid; //zet de waarde voor de timeout pin
    while (gedrukt == false) {
      sensorMeting(); //Leest de grove waarden van de sensor.
      capacativenRegister(); //Zet de waarde van de sensor om naar boolians
      timer--;
      if (timer <= 0) {
        break;
        foutAntwoord();
      }
    }
    if (cap1 == true) {
      neoPixelWipe(strip.Color(  100, 0,   0), 5);
      goedAntwoord();
      delay(100);
    }
    else {
      foutAntwoord();
    }
    neoPixelWipe(strip.Color(  20, 20,   20), 5);
    delay(100);
  }
  if (zone == 2) {
    neoPixelController(2, true); //neoPixelController(int "Zone", bool "true");
    int timer = timersnelheid; //zet de waarde voor de timeout pin
    while (gedrukt == false) {
      sensorMeting(); //Leest de grove waarden van de sensor.
      capacativenRegister(); //Zet de waarde van de sensor om naar boolians
      timer--;
      if (timer <= 0) {
        break;
        foutAntwoord();
      }
    }
    if (cap2 == true) {
      neoPixelWipe(strip.Color(  0, 100,   0), 5);
      goedAntwoord();
      delay(100);
    }
    else {
      foutAntwoord();
    }
    neoPixelWipe(strip.Color(  20, 20,   20), 5);
    delay(100);
  }
  if (zone == 3) {
    neoPixelController(3, true); //neoPixelController(int "Zone", bool "true");
    int timer = timersnelheid; //zet de waarde voor de timeout pin
    while (gedrukt == false) {
      sensorMeting(); //Leest de grove waarden van de sensor.
      capacativenRegister(); //Zet de waarde van de sensor om naar boolians
      timer--;
      if (timer <= 0) {
        break;
        foutAntwoord();
      }

    }
    if (cap3 == true) {
      neoPixelWipe(strip.Color(  0, 0,   50), 5);
      goedAntwoord();
      delay(100);
    }
    else {
      foutAntwoord();
    }

    neoPixelWipe(strip.Color(  20, 20,   20), 0);
    delay(100);
  }
  if (zone == 4) {
    neoPixelController(4, true); //neoPixelController(int "Zone", bool "true");
    int timer = timersnelheid; //zet de waarde voor de timeout pin
    while (gedrukt == false) {
      sensorMeting(); //Leest de grove waarden van de sensor.
      capacativenRegister(); //Zet de waarde van de sensor om naar boolians
      timer--;
      if (timer <= 0) {
        break;
        foutAntwoord();
      }
    }
    if (cap4 == true) {
      neoPixelWipe(strip.Color(  50, 0,   50), 5);
      goedAntwoord();
      delay(100);
    }
    else {
      foutAntwoord();
    }
    neoPixelWipe(strip.Color(  20, 20,   20), 0);
    delay(100);
  }
}

void goedAntwoord() {
  punten++;
}


void foutAntwoord() { //Laat het aantal punten zien na een fout antwoord.
  neoPixelWipe(strip.Color(  255, 0,   0), 5);
  delay(1500);
  neoPixelWipe(strip.Color(  0, 0,   0), 5);
  punten - 1;
  neoPixelWipeCustom(strip.Color(  0,  100,    100), 200, punten);
  neoPixelWipeCustom(strip.Color(  100, 50,   10), 250, punten - 16);
  neoPixelWipeCustom(strip.Color(  200, 50,  20), 300, punten - 32);
  neoPixelWipeCustom(strip.Color(  0, 200,   127), 400, punten - 48);
  neoPixelWipeCustom(strip.Color(  255, 0,   255), 500, punten - 54);
  delay(1500);
  punten = 0;
}
void neoPixelWipeCustom(uint32_t color, int wait, int x) {
  for (int i = 0; i <= x && i <= 16; i++) { // For each pixel in strip...
    strip.setPixelColor(i, color);         //  Set pixel's color (in RAM)
    strip.show();                          //  Update strip to match
    delay(wait);                           //  Pause for a moment
  }
}
