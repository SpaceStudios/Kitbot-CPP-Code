// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/drivetrain/commands/Drive.h"


Drive::Drive(Drivetrain kDrivetrain, double drive, double steer, double deadband) {
  // Use addRequirements() here to declare subsystem dependencies.
  AddRequirements(&kDrivetrain);
  this->drivetrain = &kDrivetrain;
  this->drive = drive;
  this->steer = steer;
  this->deadband = deadband;
}

// Called when the command is initially scheduled.
void Drive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
  (*drivetrain).Drive(drive, steer);
}

// Called once the command ends or is interrupted.
void Drive::End(bool interrupted) {
  (*drivetrain).Drive(0,0);
}

// Returns true when the command should end.
bool Drive::IsFinished() {
  return false;
}
