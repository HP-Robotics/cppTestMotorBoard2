#include "Button.h"

Button::Button(frc::Joystick j, int b) {
    joystick = j;
    button = b;
    held = false;
    changed = false;
    state = false;
    lastState = false;
}

Button::getState() {
    return state;
}

Button::update() {
    cbutton = joystick.GetRawButton(button);

    if (cbutton && (cbutton != lastState)) {
        state = !state;
        changed = true;
    } else {
        changed = false;
    }

    held = cbutton;
    lastState = cbutton;
}

Button::reset() {
    state = false;
    lastState = false;
    changed = false;
}

Button::toggleOff() {
    reset();
    update();
}

Button::toggleOn() {
    state = true;
}