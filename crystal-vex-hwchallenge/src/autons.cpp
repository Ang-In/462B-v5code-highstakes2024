#include "vex.h"

void default_constants(){
  chassis.set_drive_constants(12, 0.7, 0, 0, 0);
  chassis.set_heading_constants(6, .4, 0, 1, 0);
  chassis.set_turn_constants(12, .4, .03, 3, 15);
  chassis.set_swing_constants(12, .3, .001, 2, 15);
  chassis.set_drive_exit_conditions(1.5, 300, 5000);
  chassis.set_turn_exit_conditions(1, 300, 3000);
  chassis.set_swing_exit_conditions(1, 300, 3000);
}

void odom_constants(){
  default_constants();
  chassis.drive_max_voltage = 8;
  chassis.drive_settle_error = 3;
}

void skills_462B(){
  //right side
  //first mobile goal
  chassis.drive_distance(15, 0, 9, 0);
  chassis.turn_to_angle(-87);
  pneums.set(true);
  chassis.drive_distance(-23, 0, 5, 0);
  pneums.set(false);
  chassis.drive_distance(0, 0, 8, 0);
  wait(0.5, sec);
  
  //intake and score rightward ringss
  chassis.turn_to_angle(-2);
  intakeA.spin(fwd, 12, volt);
  intakeB.spin(reverse, 11.6, volt);
  chassis.drive_distance(22.5, 0, 9, 0);
  wait(0.5, sec);

  //turn to take in right corner rings
  chassis.turn_to_angle(90);
  chassis.drive_distance(23, 0, 9, 0);
  wait(0.5, sec);
  
  //Get two set of rings in a row
  chassis.turn_to_angle(180);
  chassis.drive_distance(20, 0, 8, 0);
  wait(1, sec);
  chassis.drive_distance(14, 0, 6, 0);
  wait(0.5, sec);
  
  chassis.drive_distance(-20, 0, 9, 0);
  chassis.turn_to_angle(120);
  chassis.drive_distance(15, 0, 8, 0);
  chassis.drive_distance(-5, 0, 8, 0);
  chassis.turn_to_angle(-20);
  pneums.set(true);
  chassis.drive_distance(-12, 0, 8, 0);
  chassis.drive_distance(9.5, 0, 9, 0);
  chassis.turn_to_angle(91.5);
  chassis.drive_distance(-80, 0, 6, 0);
  pneums.set(false);
  /*chassis.set_coordinates(12, 72, -91.5);
  /*
  Keep adding resets 
  */

  //left side
  chassis.drive_distance(0, 0, 8, 0);
  wait(0.5,sec);
  
  //intake and score leftward ringss
  chassis.turn_to_angle(2);
  intakeA.spin(fwd, 12, volt);
  intakeB.spin(reverse, 11.6, volt);
  chassis.drive_distance(22.5, 0, 9, 0);
  wait(0.5, sec);

  //turn to take in left corner rings
  chassis.turn_to_angle(-91);
  chassis.drive_distance(23, 0, 9, 0);

  wait(0.5, sec);
  chassis.turn_to_angle(-180);
  chassis.drive_distance(20, 0, 8, 0);
  wait(1, sec);
  chassis.drive_distance(14, 0, 8, 0);
  wait(0.5, sec);
  chassis.drive_distance(-20, 0, 9, 0);
  chassis.turn_to_angle(-120);
  chassis.drive_distance(15, 0, 8, 0);
  chassis.drive_distance(-5, 0, 8, 0);
  chassis.turn_to_angle(20);
  pneums.set(true);
  wait(0.5, sec);

  chassis.drive_distance(-15, 0, 8, 0);
  chassis.drive_distance(9.5, 0, 9, 0);
  chassis.turn_to_angle(-91.5);
  chassis.drive_distance(-36, 0, 9, 0);

}

void right_auton_462B(){
  //grab goal
  pneums.set(true);
  chassis.drive_distance(-23, 0, 8, 0);
  chassis.turn_to_angle(-28);
  chassis.drive_distance(-12, -42, 8, 0);
  pneums.set(false);

  //start scoring
  chassis.drive_distance(-2, -42, 8, 0);
  chassis.turn_to_angle(-45);
  intakeB.spin(reverse, 11.6, volt);
  intakeA.spin(fwd, 12, volt);
  wait(1, sec);

  //intake more rings
  chassis.turn_to_angle(-95);
  chassis.drive_distance(14, 0, 8, 0);
  wait(1, sec);

  //touch the ladder - may rework
  chassis.turn_to_angle(75);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(20);
}

//specialized auton - no use case (yet)
void matchauton(){
  pneums.set(true);
  chassis.drive_distance(-23, 0, 8, 0);
  chassis.turn_to_angle(35);
  chassis.drive_distance(-12, 42, 8, 0);
  pneums.set(false);
  chassis.drive_distance(-2, 42, 8, 0);
  chassis.turn_to_angle(45);
  intakeB.spin(reverse, 11.6, volt);
  intakeA.spin(fwd, 12, volt);
  wait(1, sec);
  chassis.turn_to_angle(95);
  chassis.drive_distance(14, 0, 8, 0);
  wait(1, sec);
  /*chassis.drive_distance(-4, 0, 12, 0);*/
  chassis.turn_to_angle(-160);
  /*chassis.drive_distance(22, 0, 6, 0);
  wait(0.5, sec);
  chassis.drive_distance(-8, 0, 12, 0);
  chassis.turn_to_angle(-90);
  chassis.drive_distance(7, 0, 12, 0);
  chassis.turn_to_angle(180);
  chassis.drive_distance(8, 0, 6, 0);
  */
}

void left_auton_462B(){
  //grab goal
  pneums.set(true);
  chassis.drive_distance(-23, 0, 8, 0);
  chassis.turn_to_angle(35);
  chassis.drive_distance(-12, 42, 8, 0);
  pneums.set(false);

  //start scoring
  chassis.drive_distance(-2, 42, 8, 0);
  chassis.turn_to_angle(45);
  intakeB.spin(reverse, 11.6, volt);
  intakeA.spin(fwd, 12, volt);
  wait(1, sec);

  //intake more rings
  chassis.turn_to_angle(95);
  chassis.drive_distance(14, 0, 8, 0);
  wait(1, sec);

  //touch the goal
  chassis.turn_to_angle(-75);
  chassis.drive_distance(27);

}
  
/*
  intakeA.spin(fwd, 12, volt);
  intakeB.spin(reverse, 12, volt);
  wait(0.01, sec);
  intakeA.stop();
  intakeB.stop();
  chassis.drive_distance(5, 0, 8, 0);
  chassis.turn_to_angle(90);
*/

void drive_test(){
  chassis.drive_distance(24);
  //chassis.drive_distance(-18);
}

void turn_test(){
  chassis.turn_to_angle(90);
  //chassis.turn_to_angle(0);
}

void swing_test(){
  chassis.left_swing_to_angle(90);
  chassis.right_swing_to_angle(0);
}

void full_test(){
  chassis.drive_distance(24);
  chassis.turn_to_angle(-45);
  chassis.drive_distance(-36);
  chassis.right_swing_to_angle(-90);
  chassis.drive_distance(24);
  chassis.turn_to_angle(0);
}

/*void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}*/
