#include <frc/Joystick.h>

class Button {
    public:
        Button(frc::Joystick j);
        Boolean GetState();
    private:
        Boolean output;
}