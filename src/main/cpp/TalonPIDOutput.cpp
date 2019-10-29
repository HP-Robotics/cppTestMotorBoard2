#include "TalonPIDOutput.h"

TalonPIDOutput::TalonPIDOutput (TalonSRX *m) {
    m_motor = m;

}

void TalonPIDOutput::PIDWrite (double i) {
    m_motor->Set(ControlMode::PercentOutput, i);
}