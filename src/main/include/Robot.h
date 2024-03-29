/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/Joystick.h>
#include "ctre/Phoenix.h"
#include <frc/Encoder.h>
#include <frc/PIDController.h>
#include <frc/DoubleSolenoid.h>
#include <frc/Compressor.h>
#include "TalonPIDOutput.h"
#include "Button.h"

class Robot : public frc::TimedRobot {

 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  frc::Joystick *joystick;
  
  frc::DoubleSolenoid *solenoid;
  bool hasPushed;

  Button *buttonPID;
  Button *buttonShoot;
  Button *buttonPush;

  frc::Compressor *compressor;

  TalonSRX *talon1;
  TalonSRX *talon2;
  
  frc::Encoder *encoder;
  frc::PIDController *pidController;
  TalonPIDOutput *pidOutput;
  bool enablePID;

  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
