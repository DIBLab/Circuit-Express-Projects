//Meghan Jimenez
//Intro Engineering
//Assignment 1

// Demo program for testing library and board - flip the switch to turn on/off buzzer

#include <Adafruit_CircuitPlayground.h> //imports libraries
#include <Wire.h>
#include <SPI.h>

// we light one pixel at a time, this is our counter
uint8_t pixeln = 0;

void setup() {
  //while (!Serial);
  Serial.begin(9600); //Start sending things to the serial monitor
  Serial.println("Circuit Playground test!"); //Write that sentence to the serial monitor

  CircuitPlayground.begin(); //Initializes (starts) the board
}


void loop() {
  delay(200);
  // test Red #13 LED
  CircuitPlayground.redLED(HIGH); //turns red LED on
  delay(100); //waits 100ms
  CircuitPlayground.redLED(LOW);//turns red LED off
  delay(100); //waits 100ms

  /************* TEST CAPTOUCH */
  Serial.print("Capsense #3: "); Serial.println(CircuitPlayground.readCap(3)); //reads the 8 capacative touch sensors
  Serial.print("Capsense #2: "); Serial.println(CircuitPlayground.readCap(2)); //and outputs the result to the serial 
  Serial.print("Capsense #0: "); Serial.println(CircuitPlayground.readCap(0)); //monitor
  Serial.print("Capsense #1: "); Serial.println(CircuitPlayground.readCap(1));
  Serial.print("Capsense #12: "); Serial.println(CircuitPlayground.readCap(12));
  Serial.print("Capsense #6: "); Serial.println(CircuitPlayground.readCap(6));
  Serial.print("Capsense #9: "); Serial.println(CircuitPlayground.readCap(9));
  Serial.print("Capsense #10: "); Serial.println(CircuitPlayground.readCap(10));
  
  /************* TEST SLIDE SWITCH */
  if (CircuitPlayground.slideSwitch()) {
    Serial.println("Slide to the left"); //When the switch moves to the left, print that
  } else {
    Serial.println("Slide to the right"); //when the switch moves right, print that and make sounds of 
    CircuitPlayground.playTone(500 + pixeln * 500, 250); //increasing pitch
  }

  /************* TEST 10 NEOPIXELS */

 /*
  * Increses pixeln by 1 every time through. The colorWheel part is used to make the color further down the
  * color wheel for each pixel by multiplying the pixel number by 25 to get the RGB value
  */
  CircuitPlayground.setPixelColor(pixeln++, CircuitPlayground.colorWheel(25 * pixeln));
  //reset the pixels once it has gone all the way around
  if (pixeln == 11) {
    pixeln = 0;
    CircuitPlayground.clearPixels();
  }

  /************* TEST BOTH BUTTONS */
  if (CircuitPlayground.leftButton()) {
    Serial.println("Left button pressed!"); //say that the left button has been pressed
  }
  if (CircuitPlayground.rightButton()) {
    Serial.println("Right button pressed!"); //say that the right button has been pressed
  }

  /************* TEST LIGHT SENSOR */
  Serial.print("Light sensor: ");
  Serial.println(CircuitPlayground.lightSensor()); //print the output of the light Sensor

  /************* TEST SOUND SENSOR */
  Serial.print("Sound sensor: ");
  Serial.println(CircuitPlayground.soundSensor()); //print the output of the sound sensor

  /************* TEST ACCEL */
  // Display the results (acceleration is measured in m/s*s)
  //Write out the accelerometer
  Serial.print("X: "); Serial.print(CircuitPlayground.motionX());
  Serial.print(" \tY: "); Serial.print(CircuitPlayground.motionY());
  Serial.print(" \tZ: "); Serial.print(CircuitPlayground.motionZ());
  Serial.println(" m/s^2");

  /************* TEST THERMISTOR */
  Serial.print("Temperature ");
  Serial.print(CircuitPlayground.temperature()); //print the outpt of the temperature sensor
  Serial.println(" *C");
}
