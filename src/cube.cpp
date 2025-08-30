#include "cube.hpp"

#include <array>
#include <vector>
#include <algorithm>

using namespace std;

Cube::Cube() {
    top = WHITE_FACE; // 0
    bottom = YELLOW_FACE; // 19173961
    front = GREEN_FACE; // 38347922
    back = BLUE_FACE; // 57521883
    left = ORANGE_FACE; // 95869805
    right = RED_FACE; // 76695844
}

Cube::Cube(const Cube &cube) {
    top = cube.top;
    front = cube.front;
    left = cube.left;
    right = cube.right;
    back = cube.back;
    bottom = cube.bottom;
}

Cube::~Cube() = default;

array<uint32_t, 6> Cube::__get_state() {
    array<uint32_t, 6> state = {
        top,
        front,
        left,
        right,
        back,
        bottom
    };
    
    return state;
}

bool Cube::isSolved() {
    return *this == Cube();
}

string Cube::toString() {
    const string square_space = "      ";
    const char* space = __USE_EMOJI ? "" : " ";
    string msg = "\n";

    // top
    msg += square_space;
    msg += getColor((top << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((top << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((top << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((top << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((top << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((top << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((top << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((top << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((top << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n";

    // left front right back
    msg += getColor((left << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((left << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((left << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((front << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((right << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((back << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += "\n";
    msg += getColor((left << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((left << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((left << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((front << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((right << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((back << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += "\n";
    msg += getColor((left << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((left << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((left << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((front << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((front << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((right << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((right << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((back << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((back << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += "\n";

    // bottom
    msg += square_space;
    msg += getColor((bottom << CLEAR_TOP_LEFT) >> CLEAR) + space;
    msg += getColor((bottom << CLEAR_TOP_MIDDLE) >> CLEAR) + space;
    msg += getColor((bottom << CLEAR_TOP_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((bottom << CLEAR_MIDDLE_LEFT) >> CLEAR) + space;
    msg += getColor((bottom << CLEAR_CENTER) >> CLEAR) + space;
    msg += getColor((bottom << CLEAR_MIDDLE_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n" + square_space;
    msg += getColor((bottom << CLEAR_BOTTOM_LEFT) >> CLEAR) + space;
    msg += getColor((bottom << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + space;
    msg += getColor((bottom << CLEAR_BOTTOM_RIGHT) >> CLEAR) + space;
    msg += square_space + square_space + "\n";

    return msg;
}

bool operator==(const Cube &cube1, const Cube &cube2) {
    vector<uint32_t> faces1 = {cube1.top, cube1.bottom, cube1.left, cube1.right, cube1.front, cube1.back};
    vector<uint32_t> faces2 = {cube2.top, cube2.bottom, cube2.left, cube2.right, cube2.front, cube2.back};
    sort(faces1.begin(), faces1.end());
    sort(faces2.begin(), faces2.end());

    return faces1 == faces2;
}

bool operator!=(const Cube &cube1, const Cube &cube2) {
    return !(cube1 == cube2);
}

string Cube::__str__() {
    return toString();
}

string Cube::__repr__() {
    return toString();
}

bool Cube::__eq__(const Cube &other) {
    return *this == other;
}

bool Cube::__ne__(const Cube &other) {
    return *this != other;
}
