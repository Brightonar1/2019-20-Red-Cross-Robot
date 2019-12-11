/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Wed Sep 25 2019                                           */
/*    Description:  Tank Drive                                                */
/*    This sample allows you to control the V5 Clawbot using the both         */
/*    joystick. Adjust the deadband value for more accurate movements.        */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Controller1          controller
// LeftMotor            motor         1
// RightMotor           motor         10
// ClawMotor            motor         3
// ArmMotor             motor         8
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"
using namespace vex;

// Setting the arm button up
void whenControllerL1Pressed() {
  vexcodeInit();
  // Take the current position of the Arm as zero
  ArmMotor.setPosition(0, degrees);
  ArmMotor2.setPosition(0, degrees);
  // Move the Arm up and hold the position for 2 seconds
  ArmMotor.spinFor(90, degrees);
  ArmMotor2.spinFor(-90, degrees);
  wait(2, seconds);
  ArmMotor.stop();
  ArmMotor2.stop();
}

// Setting the arm button down
void whenControllerR1Pressed() {
  vexcodeInit();
 // Take the current position of the Arm as zero
  ArmMotor.setPosition(0, degrees);
  ArmMotor2.setPosition(0, degrees);
  // Move the Arm up and hold the position for 2 seconds
  ArmMotor.spinFor(-90, degrees);
  ArmMotor2.spinFor(90, degrees);
  wait(2, seconds);
  ArmMotor.stop();
  ArmMotor2.stop();
}



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // Deadband stops the motors when Axis values are close to zero.
  int deadband = 5;

  while (true) {
    // Get the velocity percentage of the left motor. (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // Get the velocity percentage of the right motor. (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();

    // Set the speed of the left motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(leftMotorSpeed) < deadband) {
      // Set the speed to zero.
      LeftMotor.setVelocity(0, percent);
    } else {
      // Set the speed to leftMotorSpeed
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    // Set the speed of the right motor. If the value is less than the deadband,
    // set it to zero.
    if (abs(rightMotorSpeed) < deadband) {
      // Set the speed to zero
      RightMotor.setVelocity(0, percent);
    } else {
      // Set the speed to rightMotorSpeed
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }

    // Spin both motors in the forward direction.
    LeftMotor.spin(forward);
    RightMotor.spin(forward);

    wait(25, msec); //wait for 25 milliseconds

  }


  // Set motor's brake mode and velocity
  ArmMotor.setStopping(hold);
  ArmMotor.setVelocity(90, percent);
  ArmMotor2.setStopping(hold);
  ArmMotor2.setVelocity(90, percent);
  // Register callbacks to controller button 'pressed' events.
  Controller1.ButtonL1.pressed(whenControllerL1Pressed);
  Controller1.ButtonR1.pressed(whenControllerR1Pressed);
  //// Use a 'forever loop' to constantly check the controller's values.
  while (true) {
    if (Controller1.ButtonL1.pressing()) {
      ArmMotor.spin(forward);
      ArmMotor2.spin(forward);
    } else {
      ArmMotor.stop();
      ArmMotor2.stop();
    }
    wait(25, msec);
  }
  //// Use a 'forever loop' to constantly check the controller's values.
  while (true) {
    if (Controller1.ButtonR1.pressing()) {
      ArmMotor.spin(forward);
      ArmMotor2.spin(forward);
    } else {
      ArmMotor.stop();
      ArmMotor2.stop();
    }
    wait(25, msec);
  }

}
