#include "cube.hpp"

Cube Cube::B() const {
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

Cube Cube::B_prime() const {
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

Cube Cube::B2() const {
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

Cube Cube::b() const {
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

Cube Cube::b_prime() const {
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

Cube Cube::b2() const {
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
