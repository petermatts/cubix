#include "cube.hpp"

#include <vector>
#include <algorithm>

using namespace std;

Cube::Cube() {
    top = WHITE_FACE;
    bottom = YELLOW_FACE;
    front = GREEN_FACE;
    back = BLUE_FACE;
    left = ORANGE_FACE;
    right = RED_FACE;
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

bool Cube::isSolved() {
    vector<uint32_t> solved_faces = {WHITE_FACE, YELLOW_FACE, GREEN_FACE, BLUE_FACE, RED_FACE, ORANGE_FACE};
    vector<uint32_t> faces = {top, bottom, left, right, front, back};
    sort(solved_faces.begin(), solved_faces.end());
    sort(faces.begin(), faces.end());

    return solved_faces == faces;
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

string Cube::__str__() {
    return toString();
}

string Cube::__repr__() {
    return toString();
}
