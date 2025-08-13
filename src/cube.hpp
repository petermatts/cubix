#include <iostream>
#include <cstdint>
#include <string>

#include "common.h"

#ifndef CUBE_H
#define CUBE_H

class Cube {
    public:
    Cube();
    Cube(const Cube &cube);
    ~Cube();

    Cube& U();
    Cube& D();
    Cube& L();
    Cube& R();
    // Cube& F();
    // Cube& B();

    // Cube& U_prime();
    // Cube& D_prime();
    Cube& L_prime();
    Cube& R_prime();
    // Cube& F_prime();
    // Cube& B_prime();

    // Cube& U2();
    // Cube& D2();
    // Cube& L2();
    // Cube& R2();
    // Cube& F2();
    // Cube& B2();

    // Cube& M();
    // Cube& E();
    // Cube& S();

    // Cube& M_prime();
    // Cube& E_prime();
    // Cube& S_prime();

    // Cube& M2();
    // Cube& E2();
    // Cube& S2();

    // Cube& X();
    // Cube& Y();
    // Cube& Z();

    // Cube& X_prime();
    // Cube& Y_prime();
    // Cube& Z_prime();

    // Cube& X2();
    // Cube& Y2();
    // Cube& Z2();

    bool isSolved();
    std::string toString();

    private:
    uint32_t top;
    uint32_t front;
    uint32_t left;
    uint32_t right;
    uint32_t back;
    uint32_t bottom;
}

std::string getColor(uint32_t num);

#endif