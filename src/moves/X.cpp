#include "cube.hpp"

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
