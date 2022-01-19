/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 3, 2, 4, 9
// FrontLift            motor         5
// BackLift             motor         8
// Inertial10           inertial      10
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/
double a = 0;
double b = 0;
double c = 0;
double d = 0;
double e = 0;
int hector = 0;
double lol = 0;
void autonomous(void) {

  Brain.resetTimer();

  ////Picks up blue goal out of ramp
  // Lowers front lift
  FrontLift.spinFor(reverse, 565, deg, 100, rpm);
  // hold front lift
  FrontLift.setStopping(brakeType::hold);
  // move forward to ramp
  Drivetrain.driveFor(forward, 20, inches, 170, rpm);
  // Lifts up goal
  FrontLift.spinFor(forward, 290, deg);

  // turn to right position
  Drivetrain.turnFor(left, 87, deg, 200, rpm);
  
  // Push goal to other side
  Drivetrain.driveFor(forward, 100, inches, 150, rpm);
  wait(1, sec);

  // Back up from neutral goal a little
  Drivetrain.driveFor(reverse, 10, inches, 100, rpm);
  // TURN 90 dEGREES TO tHErIGHT
  Drivetrain.turnFor(right, 90, degrees);
  Drivetrain.driveFor(fwd, 9, inches, 100, rpm);
  // Lowers blue goal down
  FrontLift.spinFor(reverse, 295, deg, 100, rpm);
  
  // Lowers back lift
  BackLift.spinFor(reverse, 635, deg, 100, rpm);
  wait(0, sec);
  // Drive back more
  Drivetrain.driveFor(reverse, 20, inches, 150, rpm);
  
  // Fully lifts back lift to store red goal
  BackLift.spinFor(forward, 699, deg, 100, rpm);
  wait(0.5, sec);
  BackLift.setStopping(brakeType::hold);
  // Wiggle to get red goal in, incase its not
  Drivetrain.driveFor(forward, 3, inches, 200, rpm);
  Drivetrain.driveFor(reverse, 2, inches, 200, rpm);

  // Turns a little to face tall branch
  Drivetrain.turnFor(right, 32, deg, 100, rpm);
  // Move forward to tall branch
  Drivetrain.driveFor(49.5, inches, 100, rpm);
  Drivetrain.driveFor(9, inches, 50, rpm);
  wait(0.7, sec);
  // Lifts high branch
  FrontLift.spinFor(forward, 260, degrees, 75, rpm);
  // Lowers back lift
  BackLift.spinFor(reverse, 675, deg, 100, rpm);

  // Turn so backlift faces the neutral goal
  Drivetrain.turnFor(136, degrees, 100, rpm);
  // Drive backwards to intake goal
  Drivetrain.driveFor(reverse, 27, inches, 200, rpm);
  Drivetrain.driveFor(reverse, 10, inches, 180, rpm);
  Drivetrain.driveFor(reverse, 2, inches, 100, rpm);;
  // BackLift lifts up goal
  BackLift.spinFor(forward, 350, degrees, 100, rpm);
  // Turn so back faces the platform wall
  Drivetrain.turnFor(right, 90, deg, 100, rpm);
  // Drives backwards to platform wall
  Drivetrain.driveFor(reverse, 48, inches, 100, rpm);
  Drivetrain.driveFor(reverse, 2, inches, 100, rpm, false);
  wait(0.4, sec);

  FrontLift.setStopping(hold);
  BackLift.setStopping(hold);
  // Turn to calibrate
  Drivetrain.turnFor(left, 65, deg, 100, rpm);
  // Drive to corner
  Drivetrain.driveFor(reverse, 11, inches, 100, rpm);
  Drivetrain.driveFor(reverse, 2, inches, 100, rpm, false);
  wait(0.4, sec);
  // Turn to corner

  Drivetrain.turnFor(left, 43, degrees, 100, rpm);
  // Drive to ramp
  Drivetrain.driveFor(forward, 5, inches, 100, rpm);
  // turn to face platform
  Drivetrain.turnFor(right, 15, degrees, 100, rpm);
  // drive to platform
  Drivetrain.driveFor(forward, 9, inches, 100, rpm);

  // reset inertial
  DrivetrainInertial.resetRotation();
  BackLift.setStopping(hold);
  // push down the ramp
  FrontLift.spinFor(reverse, 240, degrees, 25, rpm);
  // drive up ramp
  Drivetrain.drive(forward);
  wait(3.2, sec);
  Drivetrain.stop(hold);
  // lift up frontlift
  FrontLift.spinFor(forward, 270, degrees, 100, rpm);
  // get on ramp
  while (true) {
    Brain.Screen.clearScreen();
    Brain.Screen.newLine();
    Brain.Screen.print(DrivetrainInertial.roll());
    // ...............................................
    if (DrivetrainInertial.roll() > -22.2) {
      Drivetrain.drive(forward);
      wait(2, msec);
    } else {
      break;
    }
  }

  // drive up ramp
  while (true) {
    while (DrivetrainInertial.roll() > 22.22 ||
           DrivetrainInertial.roll() < -22.22) {
      Brain.Screen.clearScreen();
      Brain.Screen.newLine();
      Brain.Screen.print(DrivetrainInertial.roll());
      wait(1, msec);
      Drivetrain.drive(forward, 50, rpm);
    }

    Drivetrain.driveFor(reverse, 4.4, inches, 100, rpm);

    Drivetrain.stop(hold);
    if (DrivetrainInertial.roll() < 2.5 || DrivetrainInertial.roll() > -2.5) {
      break;
    }
  }

  Brain.Screen.clearScreen();
  Brain.Screen.newLine();
  Brain.Screen.print(DrivetrainInertial.roll());

  // cool down time
  wait(20, msec);
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
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
