#include <cassert>
#include <iostream>
#include "cube.hpp"

using namespace std;

uint32_t get(uint32_t num, int from) {
    return (num << (32-from-3)) >> CLEAR; 
}

void set(uint32_t &num, int to, uint32_t set_val) {
    assert(set_val < 8);
    num &= ~(7 << to);
    num |= (set_val << to);
}

// Cube& Cube::U() {};

// Cube& Cube::D() {};

Cube& Cube::L() {
    uint32_t temp = 0;
    
    // corner
    temp = get(left, TOP_LEFT);
    set(left, TOP_LEFT, get(left, BOTTOM_LEFT));
    set(left, BOTTOM_LEFT, get(left, BOTTOM_RIGHT));
    set(left, BOTTOM_RIGHT, get(left, TOP_RIGHT));
    set(left, TOP_RIGHT, temp);

    temp = get(top, TOP_LEFT);
    set(top, TOP_LEFT, get(back, BOTTOM_RIGHT));
    set(back, BOTTOM_RIGHT, get(bottom, TOP_LEFT));
    set(bottom, TOP_LEFT, get(front, TOP_LEFT));
    set(front, TOP_LEFT, temp);

    temp = get(top, BOTTOM_LEFT);
    set(top, BOTTOM_LEFT, get(back, TOP_RIGHT));
    set(back, TOP_RIGHT, get(bottom, BOTTOM_LEFT));
    set(bottom, BOTTOM_LEFT, get(front, BOTTOM_LEFT));
    set(front, BOTTOM_LEFT, temp);

    // edge
    temp = get(left, TOP_MIDDLE);
    set(left, TOP_MIDDLE, get(left, MIDDLE_LEFT));
    set(left, MIDDLE_LEFT, get(left, BOTTOM_MIDDLE));
    set(left, BOTTOM_MIDDLE, get(left, MIDDLE_RIGHT));
    set(left, MIDDLE_RIGHT, temp);

    temp = get(top, MIDDLE_LEFT);
    set(top, MIDDLE_LEFT, get(back, MIDDLE_RIGHT));
    set(back, MIDDLE_RIGHT, get(bottom, MIDDLE_LEFT));
    set(bottom, MIDDLE_LEFT, get(front, MIDDLE_LEFT));
    set(front, MIDDLE_LEFT, temp);

    return *this;
};

Cube& Cube::R() {
    uint32_t temp = 0;
    
    // corner
    temp = get(right, TOP_LEFT);
    set(right, TOP_LEFT, get(right, BOTTOM_LEFT));
    set(right, BOTTOM_LEFT, get(right, BOTTOM_RIGHT));
    set(right, BOTTOM_RIGHT, get(right, TOP_RIGHT));
    set(right, TOP_RIGHT, temp);

    temp = get(top, TOP_RIGHT);
    set(top,TOP_RIGHT, get(front, TOP_RIGHT));
    set(front, TOP_RIGHT, get(bottom, TOP_RIGHT));
    set(bottom, TOP_RIGHT, get(back, BOTTOM_LEFT));
    set(back, BOTTOM_LEFT, temp);

    temp = get(top, BOTTOM_RIGHT);
    set(top,BOTTOM_RIGHT, get(front, BOTTOM_RIGHT));
    set(front, BOTTOM_RIGHT, get(bottom, BOTTOM_RIGHT));
    set(bottom, BOTTOM_RIGHT, get(back, TOP_LEFT));
    set(back, TOP_LEFT, temp);

    // edge
    temp = get(right, TOP_MIDDLE);
    set(right, TOP_MIDDLE, get(right, MIDDLE_LEFT));
    set(right, MIDDLE_LEFT, get(right, BOTTOM_MIDDLE));
    set(right, BOTTOM_MIDDLE, get(right, MIDDLE_RIGHT));
    set(right, MIDDLE_RIGHT, temp);

    temp = get(top, MIDDLE_RIGHT);
    set(top, MIDDLE_RIGHT, get(front, MIDDLE_RIGHT));
    set(front, MIDDLE_RIGHT, get(bottom, MIDDLE_RIGHT));
    set(bottom, MIDDLE_RIGHT, get(back, MIDDLE_LEFT));
    set(back, MIDDLE_LEFT, temp);

    return *this;
};

// Cube& Cube::F() {};

// Cube& Cube::B() {};

// Cube& Cube::U_prime() {};

// Cube& Cube::D_prime() {};

Cube & Cube::L_prime() {
    uint32_t temp = 0;
    
    // corner
    temp = get(left, TOP_LEFT);
    set(left, TOP_LEFT, get(left, TOP_RIGHT));
    set(left, TOP_RIGHT, get(left, BOTTOM_RIGHT));
    set(left, BOTTOM_RIGHT, get(left, BOTTOM_LEFT));
    set(left, BOTTOM_LEFT, temp);

    temp = get(top, TOP_LEFT);
    set(top, TOP_LEFT, get(front, TOP_LEFT));
    set(front, TOP_LEFT, get(bottom, TOP_LEFT));
    set(bottom, TOP_LEFT, get(back, BOTTOM_RIGHT));
    set(back, BOTTOM_RIGHT, temp);

    temp = get(top, BOTTOM_LEFT);
    set(top, BOTTOM_LEFT, get(front, BOTTOM_LEFT));
    set(front, BOTTOM_LEFT, get(bottom, BOTTOM_LEFT));
    set(bottom, BOTTOM_LEFT, get(back, TOP_RIGHT));
    set(back, TOP_RIGHT, temp);

    // edge
    temp = get(left, TOP_MIDDLE);
    set(left, TOP_MIDDLE, get(left, MIDDLE_RIGHT));
    set(left, MIDDLE_RIGHT, get(left, BOTTOM_MIDDLE));
    set(left, BOTTOM_MIDDLE, get(left, MIDDLE_LEFT));
    set(left, MIDDLE_LEFT, temp);

    temp = get(top, MIDDLE_LEFT);
    set(top, MIDDLE_LEFT, get(front, MIDDLE_LEFT));
    set(front, MIDDLE_LEFT, get(bottom, MIDDLE_LEFT));
    set(bottom, MIDDLE_LEFT, get(back, MIDDLE_RIGHT));
    set(back, MIDDLE_RIGHT, temp);

    return *this;
};

Cube& Cube::R_prime() {
    uint32_t temp = 0;

    // corner
    temp = get(right, TOP_LEFT);
    set(right, TOP_LEFT, get(right, TOP_RIGHT));
    set(right, TOP_RIGHT, get(right, BOTTOM_RIGHT));
    set(right, BOTTOM_RIGHT, get(right, BOTTOM_LEFT));
    set(right, BOTTOM_LEFT, temp);

    temp = get(top, TOP_RIGHT);
    set(top,TOP_RIGHT, get(back, BOTTOM_LEFT));
    set(back, BOTTOM_LEFT, get(bottom, TOP_RIGHT));
    set(bottom, TOP_RIGHT, get(front, TOP_RIGHT));
    set(front, TOP_RIGHT, temp);

    temp = get(top, BOTTOM_RIGHT);
    set(top,BOTTOM_RIGHT, get(back, TOP_LEFT));
    set(back, TOP_LEFT, get(bottom, BOTTOM_RIGHT));
    set(bottom, BOTTOM_RIGHT, get(front, BOTTOM_RIGHT));
    set(front, BOTTOM_RIGHT, temp);

    // edge
    temp = get(right, TOP_MIDDLE);
    set(right, TOP_MIDDLE, get(right, MIDDLE_LEFT));
    set(right, MIDDLE_LEFT, get(right, BOTTOM_MIDDLE));
    set(right, BOTTOM_MIDDLE, get(right, MIDDLE_RIGHT));
    set(right, MIDDLE_RIGHT, temp);

    temp = get(top, MIDDLE_RIGHT);
    set(top, MIDDLE_RIGHT, get(back, MIDDLE_LEFT));
    set(back, MIDDLE_LEFT, get(bottom, MIDDLE_RIGHT));
    set(bottom, MIDDLE_RIGHT, get(front, MIDDLE_RIGHT));
    set(front, MIDDLE_RIGHT, temp);

    return *this;
};

// Cube& Cube::F_prime() {};

// Cube& Cube::B_prime() {};
