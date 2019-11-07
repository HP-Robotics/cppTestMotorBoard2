#include <frc/Joystick.h>

class Button {
    public:
        Button(frc::Joystick *j, int b);
        bool getState();
        void update();
        void reset();
        void toggleOff();
        void toggleOn();
        bool isChanged();

    private:
        bool state;
        bool lastState;
        bool held;
        bool changed;
        bool cbutton;
        int button;
        frc::Joystick *joystick;
};