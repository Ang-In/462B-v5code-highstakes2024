using namespace vex;

extern brain Brain;

// VEXcode device constructors
extern motor leftF;
extern motor leftM;
extern motor leftR;
extern motor_group left;

extern motor rightF;
extern motor rightM;
extern motor rightR;
extern motor_group right;

extern motor intakeB;
extern motor intakeA;
extern inertial iner;
extern digital_out pneums;
extern controller Controller1;
extern digital_out pneums2;
extern digital_out sweepPneum;

// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */

void  vexcodeInit( void );