#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor leftF = motor(PORT11, ratio6_1, true);
motor leftM = motor(PORT15, ratio6_1, true);
motor leftR = motor(PORT20, ratio6_1, true);
motor_group left = motor_group(leftF, leftM, leftR);

motor rightF = motor(PORT1, ratio6_1, false);
motor rightM = motor(PORT4, ratio6_1, false);
motor rightR = motor(PORT10, ratio6_1, false);
motor_group right = motor_group(rightF, rightM, rightR);

motor intakeB = motor(PORT18, ratio6_1, false);
//motor intakeT = motor(PORT8, ratio6_1, false);
inertial iner = inertial(PORT19);
digital_out pneums = digital_out(Brain.ThreeWirePort.A);
controller Controller1 = controller(primary);

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}