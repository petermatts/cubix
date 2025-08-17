#include "cube.hpp"

using namespace std;

void solvedMsg(Cube cube) {
    if(cube.isSolved()) {
        cout << "Cube is solved :)" << endl << endl;
    } else {
        cout << "Cube is not solved :(" << endl << endl;
    }
}

int main() {
    Cube cube = Cube();
    Cube c = Cube();
    cout << cube.toString();
    solvedMsg(cube);

    // cout << WHITE_FACE << endl << YELLOW_FACE << endl << GREEN_FACE << endl
    //      << BLUE_FACE << endl << RED_FACE << endl << ORANGE_FACE << endl;

    // cout << "Performing R turn" << endl;
    // c = cube.R();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing R' turn" << endl;
    // c = cube.R_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing L turn" << endl;
    // c = cube.L();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing L' turn" << endl;
    // c = cube.L_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing U turn" << endl;
    // c = cube.U();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing U' turn" << endl;
    // c = cube.U_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing D turn" << endl;
    // c = cube.D();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing D' turn" << endl;
    // c = cube.D_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing F turn" << endl;
    // c = cube.F();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing F' turn" << endl;
    // c = cube.F_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing B turn" << endl;
    // c = cube.B();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing B' turn" << endl;
    // c = cube.B_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing M turn" << endl;
    // c = cube.M();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing M' turn" << endl;
    // c = cube.M_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing E turn" << endl;
    // c = cube.E();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing E' turn" << endl;
    // c = cube.E_prime();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing S turn" << endl;
    // c = cube.S();
    // cout << c.toString();
    // solvedMsg(c);

    // cout << "Performing S' turn" << endl;
    // c = cube.S_prime();
    // cout << c.toString();
    // solvedMsg(c);
}