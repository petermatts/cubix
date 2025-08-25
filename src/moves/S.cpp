#include "cube.hpp"

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
