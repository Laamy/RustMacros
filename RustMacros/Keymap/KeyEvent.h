#pragma once

class KeyEvent {
public:
    int key;
    VKeyCodes vkey;

    KeyEvent(int v, VKeyCodes c) : key(v), vkey(c) {}
};