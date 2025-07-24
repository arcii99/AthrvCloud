//FormAI DATASET v1.0 Category: Sudoku solver ; Style: synchronous
#include <stdio.h>

// Function to check if the value can be inserted in x, y position
int canInsert(int puzzle[][9], int x, int y, int val) {
  int i, j;
  // Check if the value is already present in row or column
  for ( i = 0; i < 9; i++ )
  {
    if ( puzzle[x][i] == val || puzzle[i][y] == val )
      return 0;
  }
  // Check if the value is already present in the corresponding 3 x 3 grid
  int x0 = (x/3) * 3, y0 = (y/3) * 3;
  for ( i = x0; i < x0 + 3; i++ )
  {
    for ( j = y0; j < y0 + 3; j++ )
    {
      if ( puzzle[i][j] == val )
        return 0;
    }
  }
  return 1;
}

// Function to solve the Sudoku puzzle
int solveSudoku(int puzzle[][9]) {
  int row, col;
  for ( row = 0; row < 9; row++ )
  {
    for ( col = 0; col < 9; col++ )
    {
      // If the cell is empty, try all possible values
      if ( puzzle[row][col] == 0 )
      {
        int val;
        for ( val = 1; val <= 9; val++ )
        {
          if ( canInsert(puzzle, row, col, val) == 1 )
          {
            // Insert the value
            puzzle[row][col] = val;
            // Recursively try to solve the remaining puzzle
            if ( solveSudoku(puzzle) == 1 )
              return 1;
            // If the value doesn't work, backtrack and try another value
            puzzle[row][col] = 0;
          }
        }
        return 0;
      }
    }
  }
  return 1;
}

// Function to print the Sudoku puzzle
void printPuzzle(int puzzle[][9]) {
  int row, col;
  printf("\n-------------------------\n"); 
  for ( row = 0; row < 9; row++ )
  {
    printf("| ");
    for ( col = 0; col < 9; col++ )
    {
      printf("%d ",puzzle[row][col]);
      if ( (col + 1) % 3 == 0 ) printf("| ");
    }
    printf("\n");
    if ( (row + 1) % 3 == 0 ) printf("-------------------------\n");
  }
}

int main() {
  int puzzle[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                      {6, 0, 0, 1, 9, 5, 0, 0, 0},
                      {0, 9, 8, 0, 0, 0, 0, 6, 0},
                      {8, 0, 0, 0, 6, 0, 0, 0, 3},
                      {4, 0, 0, 8, 0, 3, 0, 0, 1},
                      {7, 0, 0, 0, 2, 0, 0, 0, 6},
                      {0, 6, 0, 0, 0, 0, 2, 8, 0},
                      {0, 0, 0, 4, 1, 9, 0, 0, 5},
                      {0, 0, 0, 0, 8, 0, 0, 7, 9}};
  
  printf("Sudoku Puzzle\n");
  printPuzzle(puzzle);
  if ( solveSudoku(puzzle) == 1 )
  {
    printf("\nSolution:\n");
    printPuzzle(puzzle);
  }
  else
    printf("\nNo solution exists.\n");

  return 0;
}