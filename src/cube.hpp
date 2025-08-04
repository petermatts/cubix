#include <iostream>
#include <cstdint>
#include <string>

#include "common.h"

#ifndef CUBE_H
#define CUBE_H

class Cube {
    public:
    Cube();
    ~Cube();

    void U();
    void D();
    void L();
    void R();
    void F();
    void B();

    void U_prime();
    void D_prime();
    void L_prime();
    void R_prime();
    void F_prime();
    void B_prime();

    void U2();
    void D2();
    void L2();
    void R2();
    void F2();
    void B2();

    void M();
    void E();
    void S();

    void M_prime();
    void E_prime();
    void S_prime();

    void M2();
    void E2();
    void S2();

    void X();
    void Y();
    void Z();

    void X_prime();
    void Y_prime();
    void Z_prime();

    void X2();
    void Y2();
    void Z2();

    bool isSolved();
    std::string toString();

    private:
    uint32_t top;
    uint32_t front;
    uint32_t left;
    uint32_t right;
    uint32_t back;
    uint32_t bottom;
};

#endif