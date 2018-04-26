#include <Adafruit_CircuitPlayground.h>

int sound;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Audio Level Display!");
  
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  CircuitPlayground.mic.SoundPressureLevel(10);
  Serial.println(sound);
  delay(100);
}
