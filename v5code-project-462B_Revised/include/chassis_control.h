#include <vex.h>
using namespace vex;

void robotInit(){
  //testing for function
  leftF.spin(fwd);
  leftM.spin(fwd);
  leftR.spin(fwd);
  rightF.spin(fwd);
  rightM.spin(fwd);
  rightR.spin(fwd);

  intakeB.spin(fwd);
  //intakeT.spin(forward);

  //setting vals
  leftF.setStopping(brake);
  leftM.setStopping(brake);
  leftR.setStopping(brake);
  rightF.setStopping(brake);
  rightM.setStopping(brake);
  rightR.setStopping(brake);

  intakeB.setStopping(brake);
  //intakeT.setStopping(brake);

  pneums.set(false);
  iner.calibrate();
  wait(1, seconds);
}

void drive(int lPower, int rPower){
  //motor automation
  leftF.spin(fwd, lPower, percent);
  leftM.spin(fwd, lPower, percent);
  leftR.spin(fwd, lPower, percent);
  rightF.spin(fwd, rPower, percent);
  rightM.spin(fwd, rPower, percent);
  rightR.spin(fwd, rPower, percent);
}

void moveStop(){
  //freeze everything
  leftF.stop(brake);
  leftM.stop(brake);
  leftR.stop(brake);
  rightF.stop(brake);
  rightM.stop(brake);
  rightR.stop(brake);
}

//go straight in a line; prams speed, direction, distance, & clamp a goal or not
void driveLine(float speed, float deg, float goalDist, bool flagGet){
  //init vals
  float accel, deaccel, dist, runSpeed;
  
  //inital positions
  float leftInit = leftF.position(degrees);
  float rightInit = rightF.position(degrees);

  //current positions
  float leftCur = leftF.position(degrees);
  float rightCur = rightF.position(degrees);

  //Calc distance: absolute values
  dist = abs(leftCur - leftInit) + abs(rightCur - rightInit); //) / 115; idk what this part is for, add back later when I understand
  
  accel = speed/100 * 5; //edit speed rate as needed
  
  while(dist < goalDist){
    //update req. vals
    float leftCur = leftF.position(degrees);
    float rightCur = rightF.position(degrees);
    dist = (abs(leftCur - leftInit) + abs(rightCur - rightInit)); // / 115;
    
    if(dist < accel){
      //Accel
      runSpeed = (dist/accel) * speed + 10;
      if(runSpeed > speed) runSpeed = speed;
    } else if(dist > accel){
      //Deaccel
      runSpeed = speed*(goalDist - dist)/accel + 10;
    } else {
      runSpeed = speed;
    }

    clamp(flagGet);

    //Set motor speed
    drive(runSpeed, runSpeed);

    wait(10, msec);
  }
  moveStop();
}

//PID Setup! Because I still need to figure my life out!

float getLeft() {
  return ((leftF.position(deg) + leftM.position(deg) + leftR.position(deg))/3);
}

float getRight() {
  return ((rightF.position(deg) + rightM.position(deg) + rightR.position(deg))/3);
}

float getDrive() {
  return ((getLeft() + getRight())/2);
}

void properPID(){
  //PID V2! This one should actually make sense!

  float errorG, turnV, sumE = 0, head, kp;
  

}

void clamp(bool boolClamp){
  if(boolClamp){ //-4 to clamp with proper distance; mods allowed
    pneums.set(true);
  } else {
    pneums.set(false);
  }
}
void turnAngle(float deg /*, int falgm*/){
  float gyroVel, lastGyro, s = 0, gyroRead, runSpeed;

  while(abs(iner.rotation() - deg)){
    //PID alg for rotation

    gyroRead = iner.rotation();
    s += 1;
    wait(10, msec);
    if(s == 8){
      s = 0;
      lastGyro = iner.rotation();
      gyroVel = lastGyro - gyroRead;
    }

    //falgm = 0: turn left & right motors (turn in place)
    /*if(falgm == 0) {*/
      runSpeed = (gyroRead - deg) * 0.6; //+ gyroVel * 5;
      if(runSpeed > -15 && runSpeed < 0) runSpeed = -15;
      else if(runSpeed < 15 && runSpeed > 0) runSpeed = 15;

      drive(-runSpeed, runSpeed);

    /*}*/
    
    //Deal with pivoting later???
    /** else if(falgm == 1) {
      //falgm = 1: turn right motors only (pivot on left)
      runSpeed = (gyroRead - deg) * 0.9; //+ gyroVel * 5;
      if(runSpeed > -15 && runSpeed < 0) runSpeed = -15;
      else if(runSpeed < 15 && runSpeed > 0) runSpeed = 15;

      drive(0, runSpeed);

    } else if(falgm == 2) {
      //falgm = 2: turn left motors only (pivot on right)
      runSpeed = (gyroRead - deg) * 0.9; //+ gyroVel * 5;
      if(runSpeed > -15 && runSpeed < 0) runSpeed = -15;
      else if(runSpeed < 15 && runSpeed > 0) runSpeed = 15;

      drive(runSpeed, 0);
    } */
  }
  moveStop();
  wait(10, msec);
}

