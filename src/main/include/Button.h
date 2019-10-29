#include <frc/Joystick.h>

class Button {
    public:
        Button(*frc::Joystick, int);
        bool getState();
        void update();
        void reset();
        void toggleOff();
        void toggleOn();

    private:
        bool state;
        bool lastState;
        bool held;
        bool changed;
        bool cbutton;
        frc::Joystick *joystick;
}