// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <optional>

#include <frc/TimedRobot.h>
#include <frc2/command/CommandPtr.h>
#include <frc/MathUtil.h>
#include <frc/smartdashboard/SmartDashboard.h>

#include "RobotContainer.h"

#include "subsystems/drivetrain/Drivetrain.h"
#include "subsystems/dispenser/Dispenser.h"
#include "subsystems/dispenser/commands/setOutputDispenser.h"

class Robot : public frc::TimedRobot {
 public:
  Robot();
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void DisabledExit() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void AutonomousExit() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TeleopExit() override;
  void TestInit() override;
  void TestPeriodic() override;
  void TestExit() override;

 private:
  std::optional<frc2::CommandPtr> m_autonomousCommand;
  RobotContainer m_container;
  Drivetrain drivetrain;
  frc2::CommandXboxController driveController{0};
  Dispenser dispenser;
  setOutputDispenser dispenserCommand{&dispenser, 0.5};
};
