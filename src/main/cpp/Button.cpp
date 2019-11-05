#include "Button.h"

Button::Button(frc::Joystick *j, int b) {
    joystick = j;
    button = b;
    held = false;
    changed = false;
    state = false;
    lastState = false;
}

bool Button::getState() {
    return state;
}

void Button::update() {
    cbutton = joystick->GetRawButton(button);

    if (cbutton && (cbutton != lastState)) {
        state = !state;
        changed = true;
    } else {
        changed = false;
    }

    held = cbutton;
    lastState = cbutton;
}

void Button::reset() {
    state = false;
    lastState = false;
    changed = false;
}

void Button::toggleOff() {
    reset();
    update();
}

void Button::toggleOn() {
    state = true;
}