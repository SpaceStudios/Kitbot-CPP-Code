// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/drivetrain/Drivetrain.h"

Drivetrain::Drivetrain() {
    
};

void Drivetrain::Drive(double drive, double steer) {
    frc::DifferentialDrive::WheelSpeeds speeds = frc::DifferentialDrive::ArcadeDriveIK(drive, steer, true);
    flDrive.Set(speeds.left);
    frDrive.Set(speeds.right);
    blDrive.Set(speeds.left);
    brDrive.Set(speeds.left);
};

// This method will be called once per scheduler run
void Drivetrain::Periodic() {
    
}
