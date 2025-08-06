#include <cassert>
#include <iostream>
#include "cube.hpp"

using namespace std;

void move(uint32_t num, int from, int to) {
    // ~(7 << to) clears the destination bits that are to be set
    // (((num << (32 - from - 3)) >> CLEAR) << to) extracts the bits from source and shifts them to destination
    num &= ~(7 << to) | (((num << (32 - from - 3)) >> CLEAR) << to);
}

uint32_t get(uint32_t num, int from) {
    return (num << (32-from-3)) >> CLEAR; 
}

void set(uint32_t &num, int to, uint32_t set_val) {
    assert(set_val < 8);
    num &= ~(7 << to) | (set_val << to);
}

// Cube& Cube::U() {};
// Cube& Cube::D() {};
// Cube& Cube::L() {};

Cube& Cube::R() {
    uint32_t temp = 0;
    
    // corner
    temp = get(right, TOP_LEFT);
    set(right, TOP_LEFT, get(right, BOTTOM_LEFT));
    set(right, BOTTOM_LEFT, get(right, BOTTOM_RIGHT));
    set(right, BOTTOM_RIGHT, get(right, TOP_RIGHT));
    set(right, TOP_RIGHT, temp);

    // todo finish the corner swaps

    // edge
    temp = get(right, TOP_MIDDLE);
    set(right, TOP_MIDDLE, get(right, MIDDLE_LEFT));
    set(right, MIDDLE_LEFT, get(right, BOTTOM_MIDDLE));
    set(right, BOTTOM_MIDDLE, get(right, MIDDLE_RIGHT));
    set(right, MIDDLE_RIGHT, temp);

    //! something is broken here
    temp = get(top, MIDDLE_RIGHT);
    set(top, MIDDLE_RIGHT, get(front, MIDDLE_RIGHT)); //! does nothing
    set(front, MIDDLE_RIGHT, get(bottom, MIDDLE_RIGHT)); //? sets wrong value
    set(bottom, MIDDLE_RIGHT, get(back, MIDDLE_LEFT)); //! does nothing
    set(back, MIDDLE_LEFT, temp);
    
    cout << getColor(get(bottom, MIDDLE_RIGHT)) << endl;
    cout << right << endl;

    return *this;
};

// Cube& Cube::F() {};
// Cube& Cube::B() {};
