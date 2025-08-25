#include "cube.hpp"

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
