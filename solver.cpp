#include "Solver.h"
#include <iostream>

bool Solver::isAlreadyInCol(int col, int num)
{
    // Iterate through each row and check if num is present. If it is return true
    for (int row = 0; row < 9; row++) {
        if (this->grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Solver::isAlreadyInRow(int row, int num)
{
    // Iterate through each column in a row and check if num is present.
    for (int col = 0; col < 9; col++) {
        if (this->grid[row][col] == num) {
            return true;
        }
    }
    return false;
}

bool Solver::isAlreadyInGridBox(int boxStartRow, int boxStartCol, int num)
{
    // Check a 3 x 3 Box and check if a num is present.
    // Iterate through the rows in 3x3 Box
    for (int i = 0; i < 3; i++)
    {
        // Iterate through the columns in 3x3 Box
        for (int j = 0; j < 3; j++)
        {
            // We iterate from top left to bottom left, middle top -> middle bot(...)
            // If num is present then return true
            if (this->grid[boxStartRow + i][boxStartCol + j] == num)
                return true;
        }
    }
    return false;
}

// This function iterates through the whole grid. It searches for not solved rows and columns
bool Solver::findEmptyPlace(int& row, int& col)
{ 
    //get empty location and update row and column
    for (row = 0; row < 9; row++)
        for (col = 0; col < 9; col++)
            if (this->grid[row][col] == 0) //marked with 0 is empty
                return true;
    return false;
}

bool Solver::isValidPositionForNum(int row, int col, int num)
{
    // returns true when number not found in col, row and current 3x3 box
    if (this->isAlreadyInRow(row, num) == false && this->isAlreadyInCol(col, num) == false && this->isAlreadyInGridBox(row - row % 3, col - col % 3, num) == false) {
        return true;
    }
    return false;
}

Solver::Solver(int inputGrid[9][9])
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            this->grid[i][j] = inputGrid[i][j];
        }
    }
}

Solver::~Solver()
{
}

bool Solver::solveSudoku()
{
    int row, col;
    if (!this->findEmptyPlace(row, col))
        return true; //when all places are filled
    for (int num = 1; num <= 9; num++) { //valid numbers are 1 - 9
        if (this->isValidPositionForNum(row, col, num)) { //check validation, if yes, put the number in the grid
            this->grid[row][col] = num;
            if (this->solveSudoku())
                return true;
            this->grid[row][col] = 0; //reset if conditions are not met
        }
    }
    return false;
}

void Solver::printGrid()
{
    for (int row = 0; row < 9; row++) {
        for (int col = 0; col < 9; col++) {
            if (col == 3 || col == 6)
                std::cout << " | ";
            std::cout << this->grid[row][col] << " ";
        }
        if (row == 2 || row == 5) {
            std::cout << std::endl;
            for (int i = 0; i < 9; i++)
                std::cout << "---";
        }
        std::cout << std::endl;
    }
}

bool Solver::startSolving() {
    // First of all Check if the Grid contains duplicates in a row, col or box
    bool solvable = true;
    
    //Check the rows
    for (int row = 0; row < 9; row++) {
        for (int num = 1; num <= 9; num++) {
            int duplicateCounter = 0;
            for (int col = 0; col < 9; col++) {
                if (this->grid[row][col] == num) {
                    duplicateCounter++;
                    if (duplicateCounter > 1) {
                        solvable = false;
                    }
                }
            }
        }
    }

    //Check the Collumns
    for (int col = 0; col < 9; col++) {
        for (int num = 1; num <= 9; num++) {
            int duplicateCounter = 0;
            for (int row = 0; row < 9; row++) {
                if (this->grid[row][col] == num) {
                    duplicateCounter++;
                    if (duplicateCounter > 1) {
                        solvable = false;
                    }
                }
            }
        }
    }

    //Check the 3x3 Boxes
    for (int row = 0; row < 9; row ++) {
        for (int col = 0; col < 9; col++) {
            for (int num = 1; num <= 9; num++) {
                int duplicateCounter = 0;
                // iterate from top left to bottom left, middle top -> middle bot(...)
                // If num is present then return true
                for (int rowCrawler = 0; rowCrawler < 3; rowCrawler++) {
                    for (int colCrawler = 0; colCrawler < 3; colCrawler++) {
                        if (this->grid[row + rowCrawler][col + colCrawler] == num) {
                            duplicateCounter++;
                            if (duplicateCounter > 1) {
                                solvable = false;
                            }
                        }

                    }
                }
            }
        }
    }

    if (solvable == false) {
        //std::cout << "The given Sudoku is not solvable" << std::endl;
        return false;
    }
    if (this->solveSudoku() == true)
        this->printGrid();
    return true;
}
