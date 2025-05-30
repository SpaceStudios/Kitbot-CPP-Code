// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc2/command/SubsystemBase.h>


#include <rev/SparkMax.h>
#include <math.h>
#include <frc/smartdashboard/SmartDashboard.h>

class Dispenser : public frc2::SubsystemBase {
 public:
  Dispenser();
  void setOutput(double output);

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  rev::spark::SparkMax dispenserSpark{11, rev::spark::SparkLowLevel::MotorType::kBrushless};
  rev::spark::SparkBaseConfig config;
};
