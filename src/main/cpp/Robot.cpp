/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/smartdashboard/SmartDashboard.h>


void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  frc::SmartDashboard::PutNumber("P: ", 0.0);
  frc::SmartDashboard::PutNumber("I: ", 0.0);
  frc::SmartDashboard::PutNumber("realD: ", 0.0);
  frc::SmartDashboard::PutNumber("Setpoint: ", 0.0);

  joystick = new frc::Joystick(0);
  talon1 = new TalonSRX(31);
  talon2 = new TalonSRX(3);

  buttonPID = new Button(joystick, 2);
  buttonShoot = new Button(joystick, 1);

  encoder = new frc::Encoder(0, 1, false, frc::Encoder::EncodingType::k4X);
  pidOutput = new TalonPIDOutput(talon1);
  pidController = new frc::PIDController(0, 0, 0, encoder, pidOutput);
  pidController->SetSetpoint(0);
  bool enablePID = false;
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  //std::cout << "Vertical Joystick value: " << joystick->GetRawAxis(1) << " Encoder Value: " << encoder->GetRaw() << std::endl;
  //std::cout << "Horizontal Joystick value: " << joystick->GetRawAxis(0) << " No encoder." << std::endl;
  //std::cout << "Button Toggle Value: " << button->getState() << " Button Instantaneous Value: " << joystick->GetRawButton(1) << std::endl;

  buttonPID->update();
  buttonShoot->update();
  pidController->SetP(frc::SmartDashboard::GetNumber("P: ", 0.0));
  pidController->SetI(frc::SmartDashboard::GetNumber("I: ", 0.0));
  pidController->SetD(frc::SmartDashboard::GetNumber("realD: ", 0.0));

  std::cout << "PID Controller state: " << pidController->IsEnabled() << " Changed: " << buttonPID->isChanged() << " Button: " << buttonPID->getState() << std::endl;

  if(enablePID) {
    if(buttonPID->isChanged() && buttonPID->getState()) {

      pidController->Enable();
      std::cout << "PID Control enabled." << std::endl;

    }else if(buttonPID->isChanged() && !buttonPID->getState()) {

      pidController->Disable();
      std::cout << "PID Control disabled." << std::endl;

    }else if (!buttonPID->getState()) {

      talon1->Set(ControlMode::PercentOutput, joystick->GetRawAxis(1));
      //pidController->Disable();
    } else {
      
    }
  } else {
    std::cout << "Shooting mode enabled." << std::endl;
    if (buttonShoot->getState()){
      std::cout << "Firing." << std::endl;
      talon1->Set(ControlMode::PercentOutput, 1.0);
      talon2->Set(ControlMode::PercentOutput, -1.0);
    } else if (!buttonShoot->getState()){
      std::cout << "Fine control mode enabled." << std::endl;
      talon1->Set(ControlMode::PercentOutput, joystick->GetRawAxis(1));
      talon2->Set(ControlMode::PercentOutput, -joystick->GetRawAxis(1));
    }
  }
  

  //talon1->Set(ControlMode::PercentOutput, joystick->GetRawAxis(1));
  
}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
