#include <Servo.h>
Servo ESC;     // create servo object to control the ESC
int potValue;  // value from the analog pin

void setup() {
  Serial.begin(115200);
  // Attach the ESC on pin 9
  ESC.attach(5,1000,2000); // (pin, min pulse width, max pulse width in microseconds)
  ESC.write(0);    // Send the signal to the ESC 
  delay(100);
}

void loop() {
  
  potValue = analogRead(A0);   // reads the value of the potentiometer (value between 0 and 1023)
  potValue = map(potValue, 0, 1023, 0, 180);   // scale it to use it with the servo library (value between 0 and 180)
  ESC.write(potValue);
  Serial.println(potValue);
  
  
}
