#include "Keymap.h"

void Log(const char* message);

Keymap::Keymap()
{
    for (unsigned char c = 0; c < 0xFF; c++)
        prevBuff[c] = false;
}

bool Keymap::GetDown(int key)
{
    return prevBuff[key];
}

void Keymap::Tick()
{
    for (unsigned char c = 0; c < 0xFF; c++) {
        if (OnKeyEvent != nullptr) {
            bool held = GetAsyncKeyState(c);

            if (held && !prevBuff[c]) OnKeyEvent(KeyEvent(c, VKeyCodes::KeyDown));
            else if (held && prevBuff[c]) OnKeyEvent(KeyEvent(c, VKeyCodes::KeyHeld));
            else if (!held && prevBuff[c]) OnKeyEvent(KeyEvent(c, VKeyCodes::KeyUp));

            prevBuff[c] = held;
        }
        else {
            //Log("No event bound");
        }
    }
}

void Keymap::SimulateRelease(unsigned short keyCode)
{
    INPUT inputs[1] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = keyCode;
    inputs[0].ki.dwFlags = KEYEVENTF_KEYUP;

    SendInput(1, inputs, sizeof(INPUT));
}

void Keymap::SimulatePress(unsigned short keyCode)
{
    INPUT inputs[1] = {};
    inputs[0].type = INPUT_KEYBOARD;
    inputs[0].ki.wVk = keyCode;

    SendInput(1, inputs, sizeof(INPUT));
}