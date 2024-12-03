#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
motor leftF = motor(PORT1, ratio6_1, true);
motor leftM = motor(PORT4, ratio6_1, true);
motor leftR = motor(PORT10, ratio6_1, true);
motor_group left = motor_group(leftF, leftM, leftR);

motor rightF = motor(PORT11, ratio6_1, false);
motor rightM = motor(PORT16, ratio6_1, false);
motor rightR = motor(PORT20, ratio6_1, false);
motor_group right = motor_group(rightF, rightM, rightR);

motor intakeB = motor(PORT18, ratio6_1, true);
motor intakeA = motor(PORT6, ratio6_1, true);
inertial iner = inertial(PORT13);
digital_out pneums = digital_out(Brain.ThreeWirePort.H);
digital_out pneums2 = digital_out(Brain.ThreeWirePort.F);
digital_out sweepPneum = digital_out(Brain.ThreeWirePort.E);
controller Controller1 = controller(primary);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void)
{
  // nothing to initialize
}