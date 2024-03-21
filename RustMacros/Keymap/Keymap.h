#pragma once

#include "VKeyCodes.h"
#include "KeyEvent.h"

#include <unordered_map>
#include <functional>
#include <Windows.h>

class Keymap {
private: // prev key buffer
    std::unordered_map<char, bool> prevBuff;

public: // events
    std::function<void(KeyEvent)> OnKeyEvent;

public: // methods
    Keymap();

    bool GetDown(int key);

    void Tick();

    void SimulateRelease(unsigned short keyCode);
    void SimulatePress(unsigned short keyCode);
};