//FormAI DATASET v1.0 Category: Sudoku solver ; Style: statistical
/* 
  A unique C Sudoku solver using statistical methods
  Author: [Your Name]
*/

#include <stdio.h>
#include <stdbool.h>

// Function declarations
void printSudoku(int sudoku[9][9]);
bool solveSudoku(int sudoku[9][9], int row, int column);
bool isNumberValid(int sudoku[9][9], int row, int column, int number);
void getGaps(int sudoku[9][9], bool gaps[9][9], int *numberOfGaps);
int getNextGuess(int sudoku[9][9], bool gaps[9][9], int row, int column, int currentValue);
int getMostRestrictiveGap(int sudoku[9][9], bool gaps[9][9], int *numberOfGaps);
bool isValidSudoku(int sudoku[9][9]);

// Main Sudoku Solver function
void sudokuSolver(int sudoku[9][9]) {
  bool gaps[9][9];
  int numberOfGaps;

  // Get gaps in the Sudoku
  getGaps(sudoku, gaps, &numberOfGaps);

  // Solve the Sudoku using backtrack and statistical methods
  int guess = 0;
  int row = 0, column = 0;

  while (true) {
    if (isNumberValid(sudoku, row, column, guess)) {
      sudoku[row][column] = guess;

      if (solveSudoku(sudoku, row, column)) {
        return;
      }

      sudoku[row][column] = 0;
    }

    guess = getNextGuess(sudoku, gaps, row, column, guess);

    if (guess == 0) {
      break;
    }
  }
}

// Print the Sudoku
void printSudoku(int sudoku[9][9]) {
  printf("\n");
  for (int row = 0; row < 9; row++) {
    for (int column = 0; column < 9; column++) {
      printf("%d\t", sudoku[row][column]);
    }
    printf("\n");
  }
}

// Get the gaps in the Sudoku
void getGaps(int sudoku[9][9], bool gaps[9][9], int *numberOfGaps) {
  *numberOfGaps = 0;

  for (int row = 0; row < 9; row++) {
    for (int column = 0; column < 9; column++) {
      if (sudoku[row][column] == 0) {
        gaps[row][column] = true;
        (*numberOfGaps)++;
      } else {
        gaps[row][column] = false;
      }
    }
  }
}

// Check if the given number is valid at the given coordinate
bool isNumberValid(int sudoku[9][9], int row, int column, int number) {
  // Check the row
  for (int i = 0; i < 9; i++) {
    if (sudoku[row][i] == number) {
      return false;
    }
  }

  // Check the column
  for (int i = 0; i < 9; i++) {
    if (sudoku[i][column] == number) {
      return false;
    }
  }

  // Check the 3x3 grid
  int gridRow = (row / 3) * 3;
  int gridColumn = (column / 3) * 3;

  for (int i = gridRow; i < gridRow+3; i++) {
    for (int j = gridColumn; j < gridColumn+3; j++) {
      if (sudoku[i][j] == number) {
        return false;
      }
    }
  }

  return true;
}

// Get the next guess for the Sudoku
int getNextGuess(int sudoku[9][9], bool gaps[9][9], int row, int column, int currentValue) {
  int valueCount[10] = {};

  for (int i = currentValue+1; i <= 9; i++) {
    if (isNumberValid(sudoku, row, column, i)) {
      valueCount[i]++;
    }
  }

  int mostRestrictiveGap = getMostRestrictiveGap(sudoku, gaps, NULL);

  for (int i = 1; i <= 9; i++) {
    if (valueCount[i] > 0 && isNumberValid(sudoku, mostRestrictiveGap/9, mostRestrictiveGap%9, i)) {
      return i;
    }
  }

  return 0;
}

// Get the most restrictive gap in the Sudoku
int getMostRestrictiveGap(int sudoku[9][9], bool gaps[9][9], int *numberOfGaps) {
  int gapCount[9][9] = {};

  for (int row = 0; row < 9; row++) {
    for (int column = 0; column < 9; column++) {
      // Only consider gaps
      if (gaps[row][column]) {

        // Count the number of gaps in the row
        for (int i = 0; i < 9; i++) {
          if (gaps[row][i]) {
            gapCount[row][column]++;
          }
        }

        // Count the number of gaps in the column
        for (int i = 0; i < 9; i++) {
          if (gaps[i][column]) {
            gapCount[row][column]++;
          }
        }

        // Count the number of gaps in the 3x3 grid
        int gridRow = (row / 3) * 3;
        int gridColumn = (column / 3) * 3;

        for (int i = gridRow; i < gridRow+3; i++) {
          for (int j = gridColumn; j < gridColumn+3; j++) {
            if (gaps[i][j]) {
              gapCount[row][column]++;
            }
          }
        }
      }
    }
  }

  // Find the gap with the lowest count
  int mostRestrictiveGap = -1;
  int lowestCount = 10;

  for (int row = 0; row < 9; row++) {
    for (int column = 0; column < 9; column++) {
      if (gaps[row][column] && gapCount[row][column] < lowestCount) {
        lowestCount = gapCount[row][column];
        mostRestrictiveGap = row * 9 + column;
      }
    }
  }

  if (numberOfGaps != NULL) {
    *numberOfGaps = lowestCount;
  }

  return mostRestrictiveGap;
}

// Solve the Sudoku using backtrack and statistical methods
bool solveSudoku(int sudoku[9][9], int row, int column) {
  bool gaps[9][9];
  int numberOfGaps;

  // Get gaps in the Sudoku
  getGaps(sudoku, gaps, &numberOfGaps);

  // If there are no more gaps, the Sudoku is solved
  if (numberOfGaps == 0) {
    return true;
  }

  // Get the next gap to solve
  int gap = getMostRestrictiveGap(sudoku, gaps, NULL);
  int rowToSolve = gap / 9;
  int columnToSolve = gap % 9;

  // Try each possible value for the gap
  for (int i = 1; i <= 9; i++) {
    if (isNumberValid(sudoku, rowToSolve, columnToSolve, i)) {
      sudoku[rowToSolve][columnToSolve] = i;

      if (solveSudoku(sudoku, rowToSolve, columnToSolve)) {
        return true;
      }

      // Undo the guess
      sudoku[rowToSolve][columnToSolve] = 0;
    }
  }

  return false;
}

// Main function
int main() {
  int sudoku[9][9] = {
    {0, 0, 0, 0, 0, 7, 1, 5, 0},
    {9, 0, 0, 5, 0, 0, 0, 7, 0},
    {0, 2, 0, 1, 0, 0, 0, 0, 8},
    {0, 1, 3, 4, 0, 0, 9, 0, 5},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {8, 0, 4, 0, 0, 9, 2, 1, 0},
    {2, 0, 0, 0, 0, 5, 0, 8, 0},
    {0, 4, 0, 0, 0, 3, 0, 0, 6},
    {0, 7, 8, 6, 0, 0, 0, 0, 0}
  };

  // Print the unsolved Sudoku
  printf("Unsolved Sudoku:\n");
  printSudoku(sudoku);

  // Solve the Sudoku
  sudokuSolver(sudoku);

  if (isValidSudoku(sudoku)) {
    // Print the solved Sudoku
    printf("Solved Sudoku:\n");
    printSudoku(sudoku);
  } else {
    // If the Sudoku is not valid, print an error message
    printf("Error: Invalid Sudoku\n");
  }

  return 0;
}

// Check if the Sudoku is valid
bool isValidSudoku(int sudoku[9][9]) {
  // Check the rows and columns
  for (int i = 0; i < 9; i++) {
    int rowNumbers[10] = {};
    int columnNumbers[10] = {};

    for (int j = 0; j < 9; j++) {
      // Check the row
      if (rowNumbers[sudoku[i][j]] != 0) {
        return false;
      } else {
        rowNumbers[sudoku[i][j]] = 1;
      }

      // Check the column
      if (columnNumbers[sudoku[j][i]] != 0) {
        return false;
      } else {
        columnNumbers[sudoku[j][i]] = 1;
      }
    }
  }

  // Check the 3x3 grids
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      int gridNumbers[10] = {};

      for (int k = i*3; k < i*3+3; k++) {
        for (int l = j*3; l < j*3+3; l++) {
          // Check the 3x3 grid
          if (gridNumbers[sudoku[k][l]] != 0) {
            return false;
          } else {
            gridNumbers[sudoku[k][l]] = 1;
          }
        }
      }
    }
  }

  return true;
}