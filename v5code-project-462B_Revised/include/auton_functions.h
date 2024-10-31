#include <vex.h>
#include "chassis_control.h"
using namespace vex;

int station = 1;
int l1 = 0;
//select auton: 1 = red+, 2 = red-, 3 = blue+, 4/0 = blue-

void choose(){
  //change selected auton
  if(Controller1.ButtonUp.pressing()){
    while(Controller1.ButtonUp.pressing()){
      wait(5, msec);
    }
    station += 1;
  }

  Controller1.Screen.setCursor(1, 1);
  Controller1.Screen.print("Inertil=%.2f", iner.rotation());

  if(station % 4 == 1){
    Controller1.Screen.setCursor(1, 13);
    Controller1.Screen.print("RED+");
    
  } else if(station % 4 == 2){
    Controller1.Screen.setCursor(1, 13);
    Controller1.Screen.print("RED-");

  } else if(station % 4 == 3){
    Controller1.Screen.setCursor(1, 13);
    Controller1.Screen.print("BLUE+");
    
  } else {
    Controller1.Screen.setCursor(1, 13);
    Controller1.Screen.print("BLUE-");
    
  }
}

void autonChoose(){
  float tempei;
  tempei = iner.rotation(degrees);
  if(station % 4 == 1){
    //auton for red+ here
    turnAngle(90);
    driveLine(50, 90, 20, true);
    turnAngle(0);
    driveLine(-50, 90, 20, false); //going backwards
    l1 = 1;
  } else if(station % 4 == 2){
    //auton for red- here
  } else if(station % 4 == 3){
    //auton for blue+ here
  } else {
    //auton for blue- here
  }
}

int intakeControl(void){
  while(1){
    if(l1 == 1){
      intakeB.setVelocity(100, percent);
      //intakeT.setVelocity(100, percent);
    } else if(l1 == 2){
      intakeB.setVelocity(-100, percent);
      //intakeT.setVelocity(-100, percent);
    } else {
      intakeB.setVelocity(0, percent);
      //intakeT.setVelocity(0, percent);
    }
  }
}
