#include <vex.h>
#include "auton_functions.h"

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// leftF                motor         1               
// leftM                motor         4               
// leftR                motor         10              
// rightF               motor         11              
// rightM               motor         15              
// rightR               motor         20              
// intakeB              motor         18      
// intakeT              motor         9
// iner                 inertial      19              
// pneums               digital_out   A               
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----

using namespace vex;
competition Competition;

void pre_auton() {
  // Initializing Robot Config
  vexcodeInit();

  wait(20, msec);
}

//Auton function, which runs the selected auton.

void autonomous(void) {
  choose();
  autonChoose();
}

void usercontrol(void) {
  // User control code here, inside the loop
  float a, d;
  bool pneumStats = false; 
  int l1 = 0;
  bool intakeButtonPress = false;

  while (1) {
    //Choosing Auton:
    //choose(); why is this in the user control???
    //Chassis:
    a = Controller1.Axis3.position(percent);
    d = Controller1.Axis2.position(percent);
    leftF.spin(fwd, a, percent);
    leftM.spin(fwd, a, percent);
    leftR.spin(fwd, a, percent);
    rightF.spin(fwd, d, percent);
    rightM.spin(fwd, d, percent);
    rightR.spin(fwd, d, percent);
    //Intake:
    if(Controller1.ButtonL1.pressing()){
      intakeB.setVelocity(100, percent);
      //intakeT.setVelocity(100, percent);
    } else if(Controller1.ButtonL2.pressing()){
      intakeB.setVelocity(-100, percent);
      //intakeT.setVelocity(-100, percent);
    } else {
      intakeB.setVelocity(0, percent);
      //intakeT.setVelocity(0, percent);
    }
    //Pneumatics:
    if(Controller1.ButtonA.pressing() && pneumStats == false){ //change to when state changes, WIP
      pneumStats = true;
    }
    pneums.set(pneumStats);

    wait(10, msec); 
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
