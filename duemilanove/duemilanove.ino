#include <SoftwareSerial.h>
#include <Stepper.h>

#define STEPS_PER_MOTOR_REVOLUTION 32
#define STEPS_PER_OUTPUT_REVOLUTION 32*64

Stepper stepper(STEPS_PER_MOTOR_REVOLUTION, 6, 8, 7, 9);
int stepsToTake;

SoftwareSerial XBee(10, 11);
void setup() {
    XBee.begin(9600);
    Serial.begin(9600);
    while (!Serial) {
      // wait  
    }
}
void loop() {
 /* stepper.setSpeed(1);
  stepsToTake = 4;
  stepper.step(stepsToTake);
  delay(2000);
*/
  stepsToTake = STEPS_PER_OUTPUT_REVOLUTION / 2;
  stepper.setSpeed(500);
  stepper.step(stepsToTake);
  delay(2000);
/*
  stepsToTake = - STEPS_PER_OUTPUT_REVOLUTION / 2;
  stepper.setSpeed(500);
  stepper.step(stepsToTake);
  delay(10000);
  */
  if (Serial.available()) {
      XBee.write(Serial.read());
  }
  if (XBee.available()) {
    Serial.write(XBee.read()); 
   }
      //char c = XBee.read();
      //Serial.write(c);
  //}
}
