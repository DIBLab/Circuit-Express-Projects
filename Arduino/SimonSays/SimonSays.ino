#include <Adafruit_CircuitPlayground.h>
void setup() {
  // put your setup code here, to run once:
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (CircuitPlayground.leftButton()){
    CircuitPlayground.redLED(HIGH);
  }
  else{
    CircuitPlayground.redLED(LOW);
  }

}