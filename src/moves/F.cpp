#include "cube.hpp"

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
