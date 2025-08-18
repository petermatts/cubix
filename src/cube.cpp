#include <vector>
#include <algorithm>

// #ifdef _WIN32
// #include <windows.h>
// #endif

#include "cube.hpp"

using namespace std;

string getColor(uint32_t num) {
    // #ifdef _WIN32
    // SetConsoleOutputCP(CP_UTF8);
    // #endif

    if (num == WHITE)
        // return "⬜";
        return "W";
    else if (num == YELLOW)
        // return "🟨";
        return "Y";
    else if (num == GREEN)
        // return "🟩";
        return "G";
    else if (num == BLUE)
        // return "🟦";
        return "B";
    else if (num == RED)
        // return "🟥";
        return "R";
    else if (num == ORANGE)
        // return "🟧";
        return "O";
    else
        // cout << num << endl;
        return "?";
}

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
    string space = "      ";
    string msg = "";

    // top
    msg += space;
    msg += getColor((top << CLEAR_TOP_LEFT) >> CLEAR) + " ";
    msg += getColor((top << CLEAR_TOP_MIDDLE) >> CLEAR) + " ";
    msg += getColor((top << CLEAR_TOP_RIGHT) >> CLEAR) + " ";
    msg += space + space + "\n" + space;
    msg += getColor((top << CLEAR_MIDDLE_LEFT) >> CLEAR) + " ";
    msg += getColor((top << CLEAR_CENTER) >> CLEAR) + " ";
    msg += getColor((top << CLEAR_MIDDLE_RIGHT) >> CLEAR) + " ";
    msg += space + space + "\n" + space;
    msg += getColor((top << CLEAR_BOTTOM_LEFT) >> CLEAR) + " ";
    msg += getColor((top << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + " ";
    msg += getColor((top << CLEAR_BOTTOM_RIGHT) >> CLEAR) + " ";
    msg += space + space + "\n";

    // left front right back
    msg += getColor((left << CLEAR_TOP_LEFT) >> CLEAR) + " ";
    msg += getColor((left << CLEAR_TOP_MIDDLE) >> CLEAR) + " ";
    msg += getColor((left << CLEAR_TOP_RIGHT) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_TOP_LEFT) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_TOP_MIDDLE) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_TOP_RIGHT) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_TOP_LEFT) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_TOP_MIDDLE) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_TOP_RIGHT) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_TOP_LEFT) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_TOP_MIDDLE) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_TOP_RIGHT) >> CLEAR) + " ";
    msg += "\n";
    msg += getColor((left << CLEAR_MIDDLE_LEFT) >> CLEAR) + " ";
    msg += getColor((left << CLEAR_CENTER) >> CLEAR) + " ";
    msg += getColor((left << CLEAR_MIDDLE_RIGHT) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_MIDDLE_LEFT) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_CENTER) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_MIDDLE_RIGHT) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_MIDDLE_LEFT) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_CENTER) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_MIDDLE_RIGHT) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_MIDDLE_LEFT) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_CENTER) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_MIDDLE_RIGHT) >> CLEAR) + " ";
    msg += "\n";
    msg += getColor((left << CLEAR_BOTTOM_LEFT) >> CLEAR) + " ";
    msg += getColor((left << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + " ";
    msg += getColor((left << CLEAR_BOTTOM_RIGHT) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_BOTTOM_LEFT) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + " ";
    msg += getColor((front << CLEAR_BOTTOM_RIGHT) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_BOTTOM_LEFT) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + " ";
    msg += getColor((right << CLEAR_BOTTOM_RIGHT) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_BOTTOM_LEFT) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + " ";
    msg += getColor((back << CLEAR_BOTTOM_RIGHT) >> CLEAR) + " ";
    msg += "\n";

    // bottom
    msg += space;
    msg += getColor((bottom << CLEAR_TOP_LEFT) >> CLEAR) + " ";
    msg += getColor((bottom << CLEAR_TOP_MIDDLE) >> CLEAR) + " ";
    msg += getColor((bottom << CLEAR_TOP_RIGHT) >> CLEAR) + " ";
    msg += space + space + "\n" + space;
    msg += getColor((bottom << CLEAR_MIDDLE_LEFT) >> CLEAR) + " ";
    msg += getColor((bottom << CLEAR_CENTER) >> CLEAR) + " ";
    msg += getColor((bottom << CLEAR_MIDDLE_RIGHT) >> CLEAR) + " ";
    msg += space + space + "\n" + space;
    msg += getColor((bottom << CLEAR_BOTTOM_LEFT) >> CLEAR) + " ";
    msg += getColor((bottom << CLEAR_BOTTOM_MIDDLE) >> CLEAR) + " ";
    msg += getColor((bottom << CLEAR_BOTTOM_RIGHT) >> CLEAR) + " ";
    msg += space + space + "\n";

    return msg;
}

string Cube::__str__() {
    return toString();
}

string Cube::__repr__() {
    return toString();
}
