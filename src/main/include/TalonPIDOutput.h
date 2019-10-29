#include <frc/PIDOutput.h>
#include <ctre/Phoenix.h>

class TalonPIDOutput : public frc::PIDOutput {
    public:
        TalonPIDOutput(TalonSRX *m);
        void PIDWrite(double i);
    
    private:
        TalonSRX *m_motor;
};