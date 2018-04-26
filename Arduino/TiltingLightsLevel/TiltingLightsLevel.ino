//Meghan Jimenez
//Intro Engineering
//Tilting Lights Level

#include <Adafruit_CircuitPlayground.h>

float x;
float y;
float z;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Tilting Lights Level!");
  
  CircuitPlayground.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
  x = CircuitPlayground.motionX();
  y = CircuitPlayground.motionY();
  z = CircuitPlayground.motionZ();
  Serial.println("X: "); 
  Serial.println(x);
  Serial.println("Y: "); 
  Serial.println(y);
  Serial.println("Z: "); 
  Serial.println(z);
  CircuitPlayground.clearPixels();
  if (x> 8.5 && x< 9.5){
    CircuitPlayground.setPixelColor(1, 0x00FF00);
    CircuitPlayground.setPixelColor(2, 0x00FF00);
    CircuitPlayground.setPixelColor(3, 0x00FF00);
  }
  else if ( y>0){
    CircuitPlayground.setPixelColor(2, 0xFF0000);
    CircuitPlayground.setPixelColor(3, 0xFF0000);
    CircuitPlayground.setPixelColor(4, 0xFF0000);
  }
  else{
    CircuitPlayground.setPixelColor(0, 0xFF0000);
    CircuitPlayground.setPixelColor(1, 0xFF0000);
    CircuitPlayground.setPixelColor(2, 0xFF0000);
  }
  delay(300);
}
