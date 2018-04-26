#include <Adafruit_CircuitPlayground.h>

int count = 0;
int cap = 4;
int colors[4];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Simon Says!");
  
  CircuitPlayground.begin();
}

void loop() {
  chooseColor();
  // put your main code here, to run repeatedly:
//  if (CircuitPlayground.leftButton()){
//    newGame();
//    playGame();
//    }
  

}

void newGame(){
  Serial.println("New game");
  CircuitPlayground.setPixelColor(1, CircuitPlayground.colorWheel(25));
  delay(500);
  CircuitPlayground.clearPixels();
  delay(500);
  CircuitPlayground.setPixelColor(1, CircuitPlayground.colorWheel(25));
  delay(500);
  CircuitPlayground.clearPixels();
}

void playGame(){
  
}

void chooseColor(){
  colors[count] = random(0,4);
  Serial.println(colors[count]);
  if (colors[count] == 0){
    red();
  }
  else if (colors[count] == 1){
    yellow();
  }
  else if (colors[count] == 2){
    green();
  }
  else{
    blue();
  }
  cap = 4;
  while (cap == 4){
      cap = checkCaps();
      Serial.println(cap);
      Serial.println(colors[count]);
    }
    if (cap == colors[count]){
      count++;
      Serial.println("You picked the right thing!");
    }
    else if (cap != colors[count] && cap != 4){
      CircuitPlayground.clearPixels();
      Serial.println("You lose");
      stahp();
    }
    else{
      
    }
  delay(1000);
  CircuitPlayground.clearPixels();
}

void stahp(){
  delay(999999999999999999999999999999);
}

void readCaps(){
  Serial.print("Capsense #3: "); Serial.println(CircuitPlayground.readCap(3)); //reads the 8 capacative touch sensors
  Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2)); //and outputs the result to the serial 
  Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0)); //monitor
  Serial.print("Capsense #1: "); Serial.println(CircuitPlayground.readCap(1));
  Serial.print("Capsense #12: "); Serial.println(CircuitPlayground.readCap(12));
  Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
  Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));
  delay(500);
}

int checkCaps(){
  if (CircuitPlayground.readCap(2) == 0){
    return 0;
  }
  else if (CircuitPlayground.readCap(1) > 500){
    return 1;
  }
  else if (CircuitPlayground.readCap(6) > 500){
    return 2;
  }
  else if (CircuitPlayground.readCap(9) == 0){
    return 3;
  }
  else{
    return 4;
  }
}

void red(){
  CircuitPlayground.setPixelColor(0, 0xFF0000);
  CircuitPlayground.setPixelColor(1, 0xFF0000);
  CircuitPlayground.setPixelColor(2, 0xFF0000);
  //CircuitPlayground.playTone(1200, 250);
}

void yellow(){
  CircuitPlayground.setPixelColor(2, 0xFFFF00);
  CircuitPlayground.setPixelColor(3, 0xFFFF00);
  CircuitPlayground.setPixelColor(4, 0xFFFF00);
  //CircuitPlayground.playTone(1400, 250);
}

void green(){
  CircuitPlayground.setPixelColor(5, 0x00FF00);
  CircuitPlayground.setPixelColor(6, 0x00FF00);
  CircuitPlayground.setPixelColor(7, 0x00FF00);
  //CircuitPlayground.playTone(1600, 250);
}

void blue(){
  CircuitPlayground.setPixelColor(7, 0x0000FF);
  CircuitPlayground.setPixelColor(8, 0x0000FF);
  CircuitPlayground.setPixelColor(9, 0x0000FF);
  //CircuitPlayground.playTone(1800, 250);
}

void testColors(){
  red();
  delay(500);
  CircuitPlayground.clearPixels();
  yellow();
  delay(500);
  CircuitPlayground.clearPixels();
  green();
  delay(500);
  CircuitPlayground.clearPixels();
  blue();
  delay(500);
  CircuitPlayground.clearPixels();
}

