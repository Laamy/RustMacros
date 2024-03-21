#include <iostream>
#include <windows.h>

#include "Keymap/Keymap.h"
#include "Stopwatch/Stopwatch.h"

Keymap keymap;
Stopwatch watch;

void SendKey(int key)
{
    keymap.SimulatePress(key);
    Sleep(200);
    keymap.SimulateRelease(key);
}

bool active = false;

void OnKeyPress(KeyEvent key)
{
    //std::cout << "Key: " << key.key << " VKey: " << key.vkey << std::endl;

    // detect if W is held down
    if (key.key == 87 && key.vkey == VKeyCodes::KeyHeld && active)
    {
        std::cout << watch.ElapsedMilliseconds() << std::endl;
        // check if stopwatch is over 500ms
        if (watch.ElapsedMilliseconds() > 200)
        {
			// send W key
			SendKey(VK_CONTROL);

			// restart stopwatch
			watch.Reset();
            watch.Start();

            //std::cout << "W held for 500ms" << std::endl;
		}
	}

    // keybind to toggle active state
    if (key.key == VK_F2 && key.vkey == VKeyCodes::KeyDown)
    {
		active = !active;
		std::cout << "Active: " << active << std::endl;
	}
}

int main()
{
    keymap.OnKeyEvent = OnKeyPress;
    watch.Start();

    while (true)
    {
        keymap.Tick();
        Sleep(1);
    }
}