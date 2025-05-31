// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <units/voltage.h>

#include "subsystems/dispenser/Dispenser.h"

Dispenser::Dispenser() {
    config.SmartCurrentLimit(40);
    config.SecondaryCurrentLimit(60);
    dispenserSpark.Configure(config, rev::spark::SparkBase::ResetMode::kResetSafeParameters, rev::spark::SparkBase::PersistMode::kPersistParameters);
};

void Dispenser::setOutput(double output) {
    dispenserSpark.Set(std::clamp(output, -1.0, 1.0));
}

// This method will be called once per scheduler run
void Dispenser::Periodic() {
    frc::SmartDashboard::PutNumber("Dispenser/Output",dispenserSpark.Get());
    frc::SmartDashboard::PutNumber("Dispenser/Current",dispenserSpark.GetOutputCurrent());
    frc::SmartDashboard::PutNumber("Dispenser/Temperature",dispenserSpark.GetMotorTemperature());
    frc::SmartDashboard::PutNumber("Dispenser/Bus Voltage",dispenserSpark.GetBusVoltage());
}
