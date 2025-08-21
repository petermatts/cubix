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

Cube Cube::U() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, get(newCube.top, TOP_RIGHT));
    set(newCube.top, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edge
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, MIDDLE_LEFT));
    set(newCube.top, MIDDLE_LEFT, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    return newCube;
}

Cube Cube::D() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    return newCube;
}

Cube Cube::L() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::R() {
    uint32_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::F() {
    uint32_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edge
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::B() {
    uint32_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::U_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, TOP_RIGHT));
    set(newCube.top, TOP_RIGHT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    // edge
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.top, MIDDLE_LEFT));
    set(newCube.top, MIDDLE_LEFT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    return newCube;
}

Cube Cube::D_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    return newCube;
}

Cube Cube::L_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::R_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::F_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    // edge
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::B_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;
    
    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::M() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, temp);

    return newCube;
}

Cube Cube::E() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::S() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::M_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::E_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::S_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::U2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    return newCube;
}

Cube Cube::D2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.bottom, TOP_RIGHT);
    set(newCube.bottom, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    // edges
    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.bottom, MIDDLE_LEFT);
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    return newCube;
}

Cube Cube::L2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::R2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.right, TOP_RIGHT);
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edges
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.right, MIDDLE_LEFT);
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::F2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edges
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    return newCube;
}

Cube Cube::B2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.back, MIDDLE_LEFT);
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    return newCube;
}

Cube Cube::M2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::E2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::S2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // edges
    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::X() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::Y() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, get(newCube.top, TOP_RIGHT));
    set(newCube.top, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, MIDDLE_LEFT));
    set(newCube.top, MIDDLE_LEFT, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::Z() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::X_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    // edges
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, temp);

    return newCube;
}

Cube Cube::Y_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, TOP_RIGHT));
    set(newCube.top, TOP_RIGHT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.top, MIDDLE_LEFT));
    set(newCube.top, MIDDLE_LEFT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::Z_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edges
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}


Cube Cube::X2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.right, TOP_RIGHT);
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edges
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.right, MIDDLE_LEFT);
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::Y2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.bottom, TOP_RIGHT);
    set(newCube.bottom, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.bottom, MIDDLE_LEFT);
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::Z2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.back, MIDDLE_LEFT);
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::u() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, get(newCube.top, TOP_RIGHT));
    set(newCube.top, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edge
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, MIDDLE_LEFT));
    set(newCube.top, MIDDLE_LEFT, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::d() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::l() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, temp);

    return newCube;
}

Cube Cube::r() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::f() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edge
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::b() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::u_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, TOP_RIGHT));
    set(newCube.top, TOP_RIGHT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, temp);

    // edge
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.top, MIDDLE_LEFT));
    set(newCube.top, MIDDLE_LEFT, temp);

    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::d_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.back, BOTTOM_RIGHT);
    set(newCube.back, BOTTOM_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, BOTTOM_LEFT);
    set(newCube.back, BOTTOM_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    // edge
    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.back, BOTTOM_MIDDLE);
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::l_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.front, TOP_LEFT));
    set(newCube.front, TOP_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::r_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    // edge
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.front, TOP_MIDDLE));
    set(newCube.front, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.front, CENTER));
    set(newCube.front, CENTER, temp);

    return newCube;
}

Cube Cube::f_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, TOP_RIGHT));
    set(newCube.front, TOP_RIGHT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, get(newCube.left, TOP_RIGHT));
    set(newCube.left, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    // edge
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.front, MIDDLE_LEFT));
    set(newCube.front, MIDDLE_LEFT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, temp);

    return newCube;
}

Cube Cube::b_prime() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corner
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.left, TOP_LEFT));
    set(newCube.left, TOP_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edge
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.left, MIDDLE_LEFT));
    set(newCube.left, MIDDLE_LEFT, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.left, TOP_MIDDLE));
    set(newCube.left, TOP_MIDDLE, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.left, CENTER));
    set(newCube.left, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::u2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.top, BOTTOM_RIGHT));
    set(newCube.top, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.top, BOTTOM_LEFT));
    set(newCube.top, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.top, BOTTOM_MIDDLE));
    set(newCube.top, BOTTOM_MIDDLE, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.top, MIDDLE_RIGHT));
    set(newCube.top, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::d2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.bottom, TOP_LEFT);
    set(newCube.bottom, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.bottom, TOP_RIGHT);
    set(newCube.bottom, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    // edges
    temp = get(newCube.bottom, TOP_MIDDLE);
    set(newCube.bottom, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.bottom, MIDDLE_LEFT);
    set(newCube.bottom, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    // centers
    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::l2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.left, BOTTOM_RIGHT));
    set(newCube.left, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.left, BOTTOM_LEFT));
    set(newCube.left, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, BOTTOM_LEFT);
    set(newCube.front, BOTTOM_LEFT, get(newCube.back, TOP_RIGHT));
    set(newCube.back, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.left, BOTTOM_MIDDLE));
    set(newCube.left, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.left, MIDDLE_RIGHT));
    set(newCube.left, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::r2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.right, TOP_LEFT);
    set(newCube.right, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.right, TOP_RIGHT);
    set(newCube.right, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.front, BOTTOM_RIGHT);
    set(newCube.front, BOTTOM_RIGHT, get(newCube.back, TOP_LEFT));
    set(newCube.back, TOP_LEFT, temp);

    // edges
    temp = get(newCube.right, TOP_MIDDLE);
    set(newCube.right, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.right, MIDDLE_LEFT);
    set(newCube.right, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.front, MIDDLE_RIGHT);
    set(newCube.front, MIDDLE_RIGHT, get(newCube.back, MIDDLE_LEFT));
    set(newCube.back, MIDDLE_LEFT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, BOTTOM_MIDDLE);
    set(newCube.front, BOTTOM_MIDDLE, get(newCube.back, TOP_MIDDLE));
    set(newCube.back, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.front, CENTER);
    set(newCube.front, CENTER, get(newCube.back, CENTER));
    set(newCube.back, CENTER, temp);

    return newCube;
}

Cube Cube::f2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.front, TOP_LEFT);
    set(newCube.front, TOP_LEFT, get(newCube.front, BOTTOM_RIGHT));
    set(newCube.front, BOTTOM_RIGHT, temp);

    temp = get(newCube.front, TOP_RIGHT);
    set(newCube.front, TOP_RIGHT, get(newCube.front, BOTTOM_LEFT));
    set(newCube.front, BOTTOM_LEFT, temp);

    temp = get(newCube.top, BOTTOM_LEFT);
    set(newCube.top, BOTTOM_LEFT, get(newCube.bottom, TOP_RIGHT));
    set(newCube.bottom, TOP_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_RIGHT);
    set(newCube.top, BOTTOM_RIGHT, get(newCube.bottom, TOP_LEFT));
    set(newCube.bottom, TOP_LEFT, temp);

    temp = get(newCube.left, TOP_RIGHT);
    set(newCube.left, TOP_RIGHT, get(newCube.right, BOTTOM_LEFT));
    set(newCube.right, BOTTOM_LEFT, temp);

    temp = get(newCube.left, BOTTOM_RIGHT);
    set(newCube.left, BOTTOM_RIGHT, get(newCube.right, TOP_LEFT));
    set(newCube.right, TOP_LEFT, temp);

    // edges
    temp = get(newCube.front, TOP_MIDDLE);
    set(newCube.front, TOP_MIDDLE, get(newCube.front, BOTTOM_MIDDLE));
    set(newCube.front, BOTTOM_MIDDLE, temp);

    temp = get(newCube.front, MIDDLE_LEFT);
    set(newCube.front, MIDDLE_LEFT, get(newCube.front, MIDDLE_RIGHT));
    set(newCube.front, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, BOTTOM_MIDDLE);
    set(newCube.top, BOTTOM_MIDDLE, get(newCube.bottom, TOP_MIDDLE));
    set(newCube.bottom, TOP_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_RIGHT);
    set(newCube.left, MIDDLE_RIGHT, get(newCube.right, MIDDLE_LEFT));
    set(newCube.right, MIDDLE_LEFT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}

Cube Cube::b2() {
    uint32_t temp = 0;
    Cube newCube = *this;

    // corners
    temp = get(newCube.back, TOP_LEFT);
    set(newCube.back, TOP_LEFT, get(newCube.back, BOTTOM_RIGHT));
    set(newCube.back, BOTTOM_RIGHT, temp);

    temp = get(newCube.back, TOP_RIGHT);
    set(newCube.back, TOP_RIGHT, get(newCube.back, BOTTOM_LEFT));
    set(newCube.back, BOTTOM_LEFT, temp);

    temp = get(newCube.top, TOP_LEFT);
    set(newCube.top, TOP_LEFT, get(newCube.bottom, BOTTOM_RIGHT));
    set(newCube.bottom, BOTTOM_RIGHT, temp);

    temp = get(newCube.top, TOP_RIGHT);
    set(newCube.top, TOP_RIGHT, get(newCube.bottom, BOTTOM_LEFT));
    set(newCube.bottom, BOTTOM_LEFT, temp);

    temp = get(newCube.left, TOP_LEFT);
    set(newCube.left, TOP_LEFT, get(newCube.right, BOTTOM_RIGHT));
    set(newCube.right, BOTTOM_RIGHT, temp);

    temp = get(newCube.left, BOTTOM_LEFT);
    set(newCube.left, BOTTOM_LEFT, get(newCube.right, TOP_RIGHT));
    set(newCube.right, TOP_RIGHT, temp);

    // edges
    temp = get(newCube.back, TOP_MIDDLE);
    set(newCube.back, TOP_MIDDLE, get(newCube.back, BOTTOM_MIDDLE));
    set(newCube.back, BOTTOM_MIDDLE, temp);

    temp = get(newCube.back, MIDDLE_LEFT);
    set(newCube.back, MIDDLE_LEFT, get(newCube.back, MIDDLE_RIGHT));
    set(newCube.back, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, TOP_MIDDLE);
    set(newCube.top, TOP_MIDDLE, get(newCube.bottom, BOTTOM_MIDDLE));
    set(newCube.bottom, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, MIDDLE_LEFT);
    set(newCube.left, MIDDLE_LEFT, get(newCube.right, MIDDLE_RIGHT));
    set(newCube.right, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_LEFT);
    set(newCube.top, MIDDLE_LEFT, get(newCube.bottom, MIDDLE_RIGHT));
    set(newCube.bottom, MIDDLE_RIGHT, temp);

    temp = get(newCube.top, MIDDLE_RIGHT);
    set(newCube.top, MIDDLE_RIGHT, get(newCube.bottom, MIDDLE_LEFT));
    set(newCube.bottom, MIDDLE_LEFT, temp);

    temp = get(newCube.left, TOP_MIDDLE);
    set(newCube.left, TOP_MIDDLE, get(newCube.right, BOTTOM_MIDDLE));
    set(newCube.right, BOTTOM_MIDDLE, temp);

    temp = get(newCube.left, BOTTOM_MIDDLE);
    set(newCube.left, BOTTOM_MIDDLE, get(newCube.right, TOP_MIDDLE));
    set(newCube.right, TOP_MIDDLE, temp);

    // centers
    temp = get(newCube.top, CENTER);
    set(newCube.top, CENTER, get(newCube.bottom, CENTER));
    set(newCube.bottom, CENTER, temp);

    temp = get(newCube.left, CENTER);
    set(newCube.left, CENTER, get(newCube.right, CENTER));
    set(newCube.right, CENTER, temp);

    return newCube;
}
