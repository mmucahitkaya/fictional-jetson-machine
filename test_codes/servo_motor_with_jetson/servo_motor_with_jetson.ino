#include <Servo.h>


Servo myservo;  // create servo object to control a servo

int val;    // variable to read the value from the analog pin

void setup() {
  SerialUSB.begin(115200);
  Serial1.begin(115200); // Initialize hardware serial port, pins 0/1
  myservo.attach(5);  // attaches the servo on pin 9 to the servo object
}

void loop() {
    if (Serial1.available() > 0) {
    val = Serial1.parseInt();
    myservo.write(val);  
    SerialUSB.println(val);
    delay(15);
  }
}
