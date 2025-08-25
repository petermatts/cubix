#ifndef CUBE_HPP
#define CUBE_HPP

#include <iostream>
#include <cstdint>
#include <string>
#include "common.hpp"

class Cube {
    public:
    Cube();
    Cube(const Cube &cube);
    ~Cube();

    Cube U();
    Cube D();
    Cube L();
    Cube R();
    Cube F();
    Cube B();

    Cube u();
    Cube d();
    Cube l();
    Cube r();
    Cube f();
    Cube b();

    Cube U_prime();
    Cube D_prime();
    Cube L_prime();
    Cube R_prime();
    Cube F_prime();
    Cube B_prime();

    Cube u_prime();
    Cube d_prime();
    Cube l_prime();
    Cube r_prime();
    Cube f_prime();
    Cube b_prime();

    Cube U2();
    Cube D2();
    Cube L2();
    Cube R2();
    Cube F2();
    Cube B2();

    Cube u2();
    Cube d2();
    Cube l2();
    Cube r2();
    Cube f2();
    Cube b2();

    Cube M();
    Cube E();
    Cube S();

    Cube M_prime();
    Cube E_prime();
    Cube S_prime();

    Cube M2();
    Cube E2();
    Cube S2();

    Cube X();
    Cube Y();
    Cube Z();

    Cube X_prime();
    Cube Y_prime();
    Cube Z_prime();

    Cube X2();
    Cube Y2();
    Cube Z2();

    friend bool operator==(const Cube &cube1, const Cube &cube2);
    friend bool operator!=(const Cube &cube1, const Cube &cube2);

    bool isSolved();
    std::string toString();
    std::string __str__();
    std::string __repr__(); //? add more special python support
    bool __eq__(const Cube &other);
    bool __ne__(const Cube &other);

    private:
    uint32_t top;
    uint32_t front;
    uint32_t left;
    uint32_t right;
    uint32_t back;
    uint32_t bottom;
};

#endif // CUBE_HPP
