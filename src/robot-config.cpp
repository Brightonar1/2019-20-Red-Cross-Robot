#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LeftMotor = motor(PORT10, ratio18_1, false);
motor RightMotor = motor(PORT1, ratio18_1, true);

motor ClawMotor1 = motor(PORT3, ratio18_1, false);
motor ClawMotor2 = motor(PORT4, ratio18_1, false);

motor ArmMotor = motor(PORT11, ratio18_1, false);
motor ArmMotor2 = motor(PORT20, ratio18_1, false);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // nothing to initialize
}