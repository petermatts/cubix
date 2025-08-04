#include "cube.hpp"

Cube::Cube() {
    top = (WHITE << TOP_LEFT) + (WHITE << TOP_MIDDLE) + (WHITE << TOP_RIGHT) +
          (WHITE << MIDDLE_LEFT) + (WHITE << CENTER) + (WHITE << MIDDLE_RIGHT) +
          (WHITE << BOTTOM_LEFT) + (WHITE << BOTTOM_MIDDLE) + (WHITE << BOTTOM_RIGHT);
    bottom = (YELLOW << TOP_LEFT) + (YELLOW << TOP_MIDDLE) + (YELLOW << TOP_RIGHT) +
             (YELLOW << MIDDLE_LEFT) + (YELLOW << CENTER) + (YELLOW << MIDDLE_RIGHT) +
             (YELLOW << BOTTOM_LEFT) + (YELLOW << BOTTOM_MIDDLE) + (YELLOW << BOTTOM_RIGHT);

    front = (GREEN << TOP_LEFT) + (GREEN << TOP_MIDDLE) + (GREEN << TOP_RIGHT) +
            (GREEN << MIDDLE_LEFT) + (GREEN << CENTER) + (GREEN << MIDDLE_RIGHT) +
            (GREEN << BOTTOM_LEFT) + (GREEN << BOTTOM_MIDDLE) + (GREEN << BOTTOM_RIGHT);
    back = (BLUE << TOP_LEFT) + (BLUE << TOP_MIDDLE) + (BLUE << TOP_RIGHT) +
           (BLUE << MIDDLE_LEFT) + (BLUE << CENTER) + (BLUE << MIDDLE_RIGHT) +
           (BLUE << BOTTOM_LEFT) + (BLUE << BOTTOM_MIDDLE) + (BLUE << BOTTOM_RIGHT);

    left = (ORANGE << TOP_LEFT) + (ORANGE << TOP_MIDDLE) + (ORANGE << TOP_RIGHT) +
           (ORANGE << MIDDLE_LEFT) + (ORANGE << CENTER) + (ORANGE << MIDDLE_RIGHT) +
           (ORANGE << BOTTOM_LEFT) + (ORANGE << BOTTOM_MIDDLE) + (ORANGE << BOTTOM_RIGHT);
    right = (RED << TOP_LEFT) + (RED << TOP_MIDDLE) + (RED << TOP_RIGHT) +
            (RED << MIDDLE_LEFT) + (RED << CENTER) + (RED << MIDDLE_RIGHT) +
            (RED << BOTTOM_LEFT) + (RED << BOTTOM_MIDDLE) + (RED << BOTTOM_RIGHT);

    // top = 0;
    // bottom = 19173961;
    // front = 38347922;
    // back = 57521883;
    // left = 95869805;
    // right = 76695844;
};
Cube::~Cube() {};

std::string getColor(uint32_t num) {
    if (num == WHITE)
        return "W";
    else if (num == YELLOW)
        return "Y";
    else if (num == GREEN)
        return "G";
    else if (num == BLUE)
        return "B";
    else if (num == RED)
        return "R";
    else if (num == ORANGE)
        return "O";
    else
        std::cout << num << std::endl;
        return "?";
}

std::string Cube::toString() {
    std::string space = "      ";
    std::string msg = "";

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
};

int main() {
    std::cout << "Hello world" << std::endl;
    Cube cube = Cube();
    std::cout << cube.toString();
}
