/**
 *  Deze Code is compleet geschreven door Tom Zevering
 *  Pinouts available hier: (Voeg link toe met foto van pinouts)
 *  
 */
//Libraries
#include <CapacitiveSensor.h> //Capacative sensor Library
#include <Adafruit_NeoPixel.h> //Neopixel Library

//Deze variable zijn puur om te debuggen
bool debugConsole = false;
int capTreshold = 100; //De gevoeligheid van de sensor
int mode = 0; //de startmode van de SWITCH
int zone = 1; //Word gebruikt om de zones te tracken.
bool next = true; //Word gebruikt voor het spel als controlle waarde.
int zoneOud = 0; //Word gebruikt om de randomiser te beinvloeden.
bool gedrukt;
int punten=0;
int timersnelheid=30; //Het aantal deca-seconden voordat een pin een timeout geeft omdat er niet word gedrukt.

//Capacasive sensor Benodigdheden
CapacitiveSensor sensor1 = CapacitiveSensor(2, 3); //Pin 3 sensor
CapacitiveSensor sensor2 = CapacitiveSensor(4, 5); //Pin 5 sensor
CapacitiveSensor sensor3 = CapacitiveSensor(6, 7); //Pin 7 sensor
CapacitiveSensor sensor4 = CapacitiveSensor(9, 10); //Pin 10 sensor
long measurement1;
long measurement2;
long measurement3;
long measurement4;
bool cap1;
bool cap2;
bool cap3;
bool cap4;

//NeoPixel Benodigdheden
#define PIXEL_PIN   13
#define PIXEL_COUNT 16
Adafruit_NeoPixel strip(PIXEL_COUNT, PIXEL_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  Serial.begin(9600);
  strip.begin(); // Initialize NeoPixel strip object (REQUIRED)
  strip.show();  // Initialize all pixels to 'off'
  pinMode(LED_BUILTIN, OUTPUT); //Zet de onboard Led aan
  digitalWrite(LED_BUILTIN, HIGH);
  neoPixelStartup();
}

void loop() {
  sensorMeting(); //Leest de grove waarden van de sensor.
  capacativenRegister(); //Zet de waarde van de sensor om naar boolians
  hetSpel(); //De basis code van het simon zegt spel.
}
