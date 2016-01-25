#include <HX711.h>

#include <SoftwareSerial.h>
#include <Stepper.h>


#define STEPS_PER_MOTOR_REVOLUTION 32
#define STEPS_PER_OUTPUT_REVOLUTION 32*64

#define DOUT  3
#define CLK  2

Stepper stepper(STEPS_PER_MOTOR_REVOLUTION, 6, 8, 7, 9);
int stepsToTake;

SoftwareSerial XBee(10, 11);

float calibration_factor = -7050;
HX711 scale(DOUT, CLK);

void setup() {
    XBee.begin(9600);
    Serial.begin(9600);
    while (!Serial) {
      // wait  
    }

    scale.set_scale(calibration_factor);
    scale.tare();
}
void loop() {
 /* stepper.setSpeed(1);
  stepsToTake = 4;
  stepper.step(stepsToTake);
  delay(2000);
*/

    // scale:
  Serial.print("scale: ");
  Serial.print(scale.read_average(), 5);
  Serial.println();

  stepsToTake = STEPS_PER_OUTPUT_REVOLUTION / 2;
  stepper.setSpeed(500);
  stepper.step(stepsToTake);
  //delay(500);
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
