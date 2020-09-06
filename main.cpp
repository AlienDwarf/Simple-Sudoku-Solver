#include <iostream>
#include <cstring>
#include "solver.h"
#include "testbench.h"

// Your sudoku grid here. Use '0' for empty places
int sudoku[9][9] = {
   {1, 0, 0, 0, 0, 0, 0, 0, 2},
   {0, 0, 5, 0, 6, 0, 0, 3, 0},
   {0, 0, 4, 0, 0, 0, 9, 0, 0},
   {0, 0, 0, 1, 0, 2, 0, 0, 0},
   {0, 5, 0, 0, 3, 0, 0, 0, 0},
   {0, 0, 0, 9, 0, 4, 0, 0, 0},
   {0, 0, 2, 0, 0, 0, 1, 0, 0},
   {0, 3, 0, 0, 0, 0, 6, 0, 5},
   {9, 0, 0, 0, 0, 0, 0, 0, 4}
};

int main(int argc, char* argv[]) {
    if(argc == 2) {
        if(strcmp(argv[1], "dbg") == 0) {
            runTestBench();
        }
    }
    Solver sudokuSolver = Solver(sudoku);
    // startSolving() automatically prints the solved sudoku to CL
    if (sudokuSolver.startSolving() == false) {
        std::cout << "The given Sudoku is not solvable." << std::endl;
        return -1;
    }
}