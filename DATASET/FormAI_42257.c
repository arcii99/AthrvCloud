//FormAI DATASET v1.0 Category: Sudoku solver ; Style: expert-level
#include <stdio.h>

#define N 9
#define UNASSIGNED 0

int sudoku[N][N] = {
   {5, 3, 0, 0, 7, 0, 0, 0, 0},
   {6, 0, 0, 1, 9, 5, 0, 0, 0},
   {0, 9, 8, 0, 0, 0, 0, 6, 0},
   {8, 0, 0, 0, 6, 0, 0, 0, 3},
   {4, 0, 0, 8, 0, 3, 0, 0, 1},
   {7, 0, 0, 0, 2, 0, 0, 0, 6},
   {0, 6, 0, 0, 0, 0, 2, 8, 0},
   {0, 0, 0, 4, 1, 9, 0, 0, 5},
   {0, 0, 0, 0, 8, 0, 0, 7, 9}
};

void printSudoku() {
   int i, j;
   for (i = 0; i < N; i++) {
      for (j = 0; j < N; j++) {
         printf("%d ", sudoku[i][j]);
      }
      printf("\n");
   }
   printf("\n");
}

int isSafe(int row, int col, int num) {
   int i, j;
   
   // Check row for number
   for (i = 0; i < N; i++) {
      if (sudoku[row][i] == num) {
         return 0;
      }
   }
   
   // Check column for number
   for (i = 0; i < N; i++) {
      if (sudoku[i][col] == num) {
         return 0;
      }
   }
   
   // Check 3x3 box for number
   int boxRow = row - row % 3;
   int boxCol = col - col % 3;
   for (i = boxRow; i < boxRow + 3; i++) {
      for (j = boxCol; j < boxCol + 3; j++) {
         if (sudoku[i][j] == num) {
            return 0;
         }
      }
   }
   
   return 1;
}

int solveSudoku(int row, int col) {
   if (row == N - 1 && col == N) {
      return 1;
   }
   
   if (col == N) {
      row++;
      col = 0;
   }
   
   if (sudoku[row][col] > 0) {
      return solveSudoku(row, col + 1);
   }
   
   int num;
   for (num = 1; num <= N; num++) {
      if (isSafe(row, col, num)) {
         sudoku[row][col] = num;
         if (solveSudoku(row, col + 1)) {
            return 1;
         }
         sudoku[row][col] = UNASSIGNED;
      }
   }
   
   return 0;
}

int main() {
   if (solveSudoku(0, 0)) {
      printSudoku();
   } else {
      printf("No solution found.\n");
   }
   
   return 0;
}