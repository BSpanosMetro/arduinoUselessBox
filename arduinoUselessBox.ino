#include <Servo.h>
 
//Pin Constants
int uselessSwitch = 2; // Declares pin ID for the switch.

int armPin = 3; // Declares pin ID for the arm.
int armPin2 = 5; // See above
int lidPin = 4; // Declares pin ID for the lid.

// Servo Constants
Servo armServo; // Declares Servo Motor for Arm
Servo armServo2; // Declares Servo Motor for Arm Again
Servo lidServo; // Declares Servo Motor for Lid

.// Time constants, Edit for tuning purposes.
int timeToArm = 500;
int timeToLid = 500;

// Executed Code
void setup() {
  Serial.begin(9600);
  pinMode(uselessSwitch, INPUT); // Sets the switch pin to take input.
  armServo.attach(armPin); //Sets the Arm servo to take input from the Arm Pin
  armServo.write(90); // Zeroes the servo
  armServo2.attach(armPin2); //Sets the Arm servo to take input from the Arm Pin
  armServo2.write(90); // Zeroes the servo
  lidServo.attach(lidPin); //Sets the Lid servo to take input from the Lid Pin
  lidServo.write(90);

void loop() {
  bool futileActionTaken = digitalRead(uselessSwitch); // Reads switch input
  Serial.println(futileActionTaken);
  if (futileActionTaken) {
    lidServo.write(180);
    delay(timeToLid);
    lidServo.write(90);
    armServo.write(180);
    armServo2.write(1);
    delay(timeToArm);
    armServo.write(1);
    armServo2.write(180);
    delay(timeToArm);
    armServo.write(90);
    lidServo.write(1);
    delay(timeToLid);
    lidServo.write(90);
  }
}
