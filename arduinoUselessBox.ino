#include <Servo.h>

//Pin Constants
int uselessSwitch = 2; // Declares pin ID for the switch.

int armPin = 3; // Declares pin ID for the arm.
int lidPin = 4; // Declares pin ID for the lid.

// Servo Constants
Servo armServo; // Declares Servo Motor for Arm
Servo lidServo; // Declares Servo Motor for Lid

int rotationDegreestoLid = 180; // Preset constant for openning the lid.
int rotationDegreesToArm = -180; // Preset constant for using the arm.

// Executed Code
void setup() {
  pinMode(uselessSwitch, INPUT); // Sets the switch pin to take input.
  armServo.attach(armPin); //Sets the Arm servo to take input from the Arm Pin
  armServo.write(90); // Zeroes the servo
  lidServo.attach(lidPin); //Sets the Lud servo to take input from the Lid Pin
  lidServo.write(90);
}

void loop() {
  bool futileActionTaken = digitalRead(uselessSwitch); // Reads switch input
  if (futileActionTaken){ // Checks if switch pressed
    lidServo.write(rotationDegreestoLid); // Open Lid
    armServo.write(rotationDegreesToArm); // Deploy Arm
    armServo.write(-rotationDegreesToArm); // Retract Arm
    lidServo.write(-rotationDegreestoLid); // Close Lid
  }
}
