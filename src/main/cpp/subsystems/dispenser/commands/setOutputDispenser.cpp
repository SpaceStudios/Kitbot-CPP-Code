// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/dispenser/commands/setOutputDispenser.h"

setOutputDispenser::setOutputDispenser(Dispenser *kDispenser, double kOutput) {
  // Use addRequirements() here to declare subsystem dependencies.
  dispenser = kDispenser;
  output = kOutput;
}

// Called when the command is initially scheduled.
void setOutputDispenser::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void setOutputDispenser::Execute() {
  (*dispenser).setOutput(output);
}

// Called once the command ends or is interrupted.
void setOutputDispenser::End(bool interrupted) {
  (*dispenser).setOutput(0.0);
}

// Returns true when the command should end.
bool setOutputDispenser::IsFinished() {
  return false;
}
