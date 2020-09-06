#pragma once
class Solver
{
private:
	int grid[9][9];
	bool isAlreadyInCol(int col, int num);
	bool isAlreadyInRow(int row, int num);
	bool isAlreadyInGridBox(int boxStartRow, int boxStartCol, int num);
	bool findEmptyPlace(int& row, int& col);
	bool isValidPositionForNum(int row, int col, int num);
	bool solveSudoku();
public:
	Solver(int inputGrid[9][9]);
	~Solver();
	bool startSolving(); // Solve the grid returns false if not solvable. Automaticaly prints the solved sudoku
	void printGrid(); // Print the Sudoku grid
};

