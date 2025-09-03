#include "cube.hpp"
#include "moves.hpp"

#include <array>
#include <vector>
#include <algorithm>
#include <functional>
#include <unordered_map>

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

Cube Cube::apply_moves(const vector<string> &moves) {
    Cube newCube = *this;

    static const std::unordered_map<std::string, std::function<Cube(const Cube&)>> move_options = {
        {moves::U, [](const Cube &c) { return c.U(); }},
        {moves::D, [](const Cube &c) { return c.D(); }},
        {moves::L, [](const Cube &c) { return c.L(); }},
        {moves::R, [](const Cube &c) { return c.R(); }},
        {moves::F, [](const Cube &c) { return c.F(); }},
        {moves::B, [](const Cube &c) { return c.B(); }},
        {moves::U_prime, [](const Cube &c) { return c.U_prime(); }},
        {moves::D_prime, [](const Cube &c) { return c.D_prime(); }},
        {moves::L_prime, [](const Cube &c) { return c.L_prime(); }},
        {moves::R_prime, [](const Cube &c) { return c.R_prime(); }},
        {moves::F_prime, [](const Cube &c) { return c.F_prime(); }},
        {moves::B_prime, [](const Cube &c) { return c.B_prime(); }},
        {moves::U2, [](const Cube &c) { return c.U2(); }},
        {moves::D2, [](const Cube &c) { return c.D2(); }},
        {moves::L2, [](const Cube &c) { return c.L2(); }},
        {moves::R2, [](const Cube &c) { return c.R2(); }},
        {moves::F2, [](const Cube &c) { return c.F2(); }},
        {moves::B2, [](const Cube &c) { return c.B2(); }},
        {moves::u, [](const Cube &c) { return c.u(); }},
        {moves::d, [](const Cube &c) { return c.d(); }},
        {moves::l, [](const Cube &c) { return c.l(); }},
        {moves::r, [](const Cube &c) { return c.r(); }},
        {moves::f, [](const Cube &c) { return c.f(); }},
        {moves::b, [](const Cube &c) { return c.b(); }},
        {moves::u_prime, [](const Cube &c) { return c.u_prime(); }},
        {moves::d_prime, [](const Cube &c) { return c.d_prime(); }},
        {moves::l_prime, [](const Cube &c) { return c.l_prime(); }},
        {moves::r_prime, [](const Cube &c) { return c.r_prime(); }},
        {moves::f_prime, [](const Cube &c) { return c.f_prime(); }},
        {moves::b_prime, [](const Cube &c) { return c.b_prime(); }},
        {moves::u2, [](const Cube &c) { return c.u2(); }},
        {moves::d2, [](const Cube &c) { return c.d2(); }},
        {moves::l2, [](const Cube &c) { return c.l2(); }},
        {moves::r2, [](const Cube &c) { return c.r2(); }},
        {moves::f2, [](const Cube &c) { return c.f2(); }},
        {moves::b2, [](const Cube &c) { return c.b2(); }},
        {moves::M, [](const Cube &c) { return c.M(); }},
        {moves::E, [](const Cube &c) { return c.E(); }},
        {moves::S, [](const Cube &c) { return c.S(); }},
        {moves::M_prime, [](const Cube &c) { return c.M_prime(); }},
        {moves::E_prime, [](const Cube &c) { return c.E_prime(); }},
        {moves::S_prime, [](const Cube &c) { return c.S_prime(); }},
        {moves::M2, [](const Cube &c) { return c.M2(); }},
        {moves::E2, [](const Cube &c) { return c.E2(); }},
        {moves::S2, [](const Cube &c) { return c.S2(); }},
        {moves::X, [](const Cube &c) { return c.X(); }},
        {moves::Y, [](const Cube &c) { return c.Y(); }},
        {moves::Z, [](const Cube &c) { return c.Z(); }},
        {moves::X_prime, [](const Cube &c) { return c.X_prime(); }},
        {moves::Y_prime, [](const Cube &c) { return c.Y_prime(); }},
        {moves::Z_prime, [](const Cube &c) { return c.Z_prime(); }},
        {moves::X2, [](const Cube &c) { return c.X2(); }},
        {moves::Y2, [](const Cube &c) { return c.Y2(); }},
        {moves::Z2, [](const Cube &c) { return c.Z2(); }}
    };

    for(const string &m : moves) {
        newCube = move_options.at(m)(newCube);
    }

    return newCube;
}
