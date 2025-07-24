//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Claude Shannon
#include <stdio.h>
#include <stdbool.h>

bool usedInRow(int grid[9][9], int row, int num) {
   for (int col = 0; col < 9; col++) {
      if (grid[row][col] == num) {
         return true;
      }
   }
   return false;
}

bool usedInCol(int grid[9][9], int col, int num) {
   for (int row = 0; row < 9; row++) {
      if (grid[row][col] == num) {
         return true;
      }
   }
   return false;
}

bool usedInBox(int grid[9][9], int boxStartRow, int boxStartCol, int num) {
   for (int row = 0; row < 3; row++) {
      for (int col = 0; col < 3; col++) {
         if (grid[row + boxStartRow][col + boxStartCol] == num) {
            return true;
         }
      }
   }
   return false;
}

bool isSafe(int grid[9][9], int row, int col, int num) {
   return !usedInRow(grid, row, num)
         && !usedInCol(grid, col, num)
         && !usedInBox(grid, row - row % 3, col - col % 3, num);
}

bool findUnassigned(int grid[9][9], int *row, int *col) {
   for (*row = 0; *row < 9; (*row)++) {
      for (*col = 0; *col < 9; (*col)++) {
         if (grid[*row][*col] == 0) {
            return true;
         }
      }
   }
   return false;
}

bool solveSudoku(int grid[9][9]) {
   int row, col;
   if (!findUnassigned(grid, &row, &col)) {
      return true;
   }
   for (int num = 1; num <= 9; num++) {
      if (isSafe(grid, row, col, num)) {
         grid[row][col] = num;
         if (solveSudoku(grid)) {
            return true;
         }
         grid[row][col] = 0;
      }
   }
   return false;
}

void printSudoku(int grid[9][9]) {
   printf("\n");
   for (int row = 0; row < 9; row++) {
      for (int col = 0; col < 9; col++) {
         printf("%d ", grid[row][col]);
      }
      printf("\n");
   }
}

int main() {
   int grid[9][9] = {
   {3, 0, 6, 5, 0, 8, 4, 0, 0},
   {5, 2, 0, 0, 0, 0, 0, 0, 0},
   {0, 8, 7, 0, 0, 0, 0, 3, 1},
   {0, 0, 3, 0, 0, 0, 0, 2, 0},
   {9, 0, 0, 8, 0, 0, 0, 0, 5},
   {0, 5, 0, 0, 0, 0, 6, 0, 0},
   {1, 3, 0, 0, 0, 0, 2, 5, 0},
   {0, 0, 0, 0, 0, 0, 0, 7, 4},
   {0, 0, 5, 2, 0, 6, 3, 0, 0}
   };
   if (solveSudoku(grid)) {
      printSudoku(grid);
   } else {
      printf("\nNo solution exists.\n");
   }
   return 0;
}