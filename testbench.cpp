#include <iostream>
#include "solver.h"
#include "testbench.h"

using namespace std;
int gridNoError[9][9] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 9, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int gridNoError2[9][9] = {
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 9, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0},
   {0, 0, 0, 0, 0, 0, 0, 0, 0}
};
int gridRowError[9][9] = {
   {1, 0, 0, 0, 0, 0, 0, 0, 2},
   {0, 0, 5, 0, 6, 0, 0, 3, 0},
   {0, 0, 4, 0, 0, 0, 9, 0, 0},
   {0, 0, 0, 1, 0, 2, 0, 0, 0},
   {0, 5, 0, 0, 3, 0, 0, 0, 0},
   {0, 0, 0, 9, 0, 4, 0, 0, 0},
   {0, 0, 2, 0, 0, 0, 1, 0, 0},
   {0, 3, 0, 0, 0, 0, 6, 0, 5},
   {9, 0, 0, 0, 0, 0, 0, 4, 4}
};
int gridColError[9][9] = {
   {1, 0, 0, 0, 0, 0, 0, 0, 2},
   {0, 0, 5, 0, 6, 0, 0, 3, 0},
   {0, 0, 4, 0, 0, 0, 9, 0, 0},
   {0, 0, 0, 1, 0, 2, 0, 0, 0},
   {0, 5, 0, 0, 3, 0, 0, 0, 0},
   {0, 0, 0, 9, 0, 4, 0, 0, 0},
   {0, 0, 2, 0, 0, 0, 1, 0, 0},
   {0, 3, 0, 0, 0, 0, 6, 0, 5},
   {9, 0, 0, 0, 0, 0, 0, 3, 4}
};
int gridBoxError[9][9] = {
   {1, 0, 0, 0, 0, 0, 0, 0, 2},
   {0, 0, 5, 0, 6, 0, 0, 3, 0},
   {0, 0, 4, 0, 0, 0, 9, 0, 0},
   {0, 0, 0, 1, 0, 2, 0, 0, 0},
   {0, 5, 0, 0, 3, 0, 0, 0, 0},
   {0, 0, 0, 9, 0, 4, 0, 0, 0},
   {0, 0, 2, 0, 0, 0, 1, 0, 0},
   {0, 3, 0, 0, 0, 0, 6, 4, 5},
   {9, 0, 0, 0, 0, 0, 0, 0, 4}
};

void runTestBench() {
    Solver sudokuSolverNoError = Solver(gridNoError);
    if (sudokuSolverNoError.startSolving() == true) {
        cout << "Test 1 'No Error' passed" << endl;
        sudokuSolverNoError.~Solver();
    } 
    else {
        cout << "Error in Test 1 'No Error Test' " << endl;
        return;
    }
    Solver sudokuSolverRowError = Solver(gridRowError);
    if (sudokuSolverRowError.startSolving() == false) {
        cout << "Test 2 'Row Error' passed" << endl;
        sudokuSolverRowError.~Solver();
    }
    else
    {
        cout << "Error while checking for same numbers in a row" << endl;
        return;
    }
    Solver sudokuSolverColError = Solver(gridColError);
    if (sudokuSolverColError.startSolving() == false) {
        cout << "Test 3 'Col Error' passed" << endl;
        sudokuSolverColError.~Solver();
    }
    else
    {
        cout << "Error while checking for same numbers in col" << endl;
        return;
    }
    Solver sudokuSolverBoxError = Solver(gridBoxError);
    if (sudokuSolverBoxError.startSolving() == false) {
        cout << "Test 4 'Box Error' passed" << endl;
        sudokuSolverBoxError.~Solver();
    }
    else {
        cout << "Error while checking for same numbers in 3x3 Box" << endl;
        return;
    }
    cout << "All Tests passed" << endl;
    cout << "=======================Test finished==================" << endl <<endl;
}