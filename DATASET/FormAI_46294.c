//FormAI DATASET v1.0 Category: Sudoku solver ; Style: real-life
#include <stdio.h>

// Function to check if value is valid in Sudoku board
int isValid(int board[][9], int row, int col, int val) {
   // check in row
   for(int i=0;i<9;i++) { 
      if(board[row][i]==val)
         return 0;
   }
   // check in column
   for(int i=0;i<9;i++) {
      if(board[i][col]==val)
         return 0;
   }
   // check in box
   int boxRow = row - row%3;
   int boxCol = col - col%3;
   for(int i=0;i<3;i++) {
      for(int j=0;j<3;j++) {
         if(board[boxRow+i][boxCol+j] == val)
            return 0;
      }
   }
   return 1;
}

// Function to print the Sudoku Board
void printBoard(int board[][9]) {
   printf("-------------------------\n");
   for(int i=0;i<9;i++) {
      printf("| ");
      for(int j=0;j<9;j++) {
         printf("%d ", board[i][j]);
         if(j%3 == 2)
            printf("| ");
      }
      printf("\n");
      if(i%3 == 2)
         printf("-------------------------\n");
   }
}

// Function to solve Sudoku
int solveSudoku(int board[][9], int row, int col) {
   // if we reached the last row with the last col, we filled up the whole board
   if(row == 8 && col == 9)
      return 1;
   // if we reached the last column, move to next row
   if(col == 9) {
      row++;
      col = 0;
   }
   // if the current value is not empty, move ahead
   if(board[row][col] != 0)
      return solveSudoku(board, row, col+1);
   // fill empty cells with all possible values
   for(int i=1; i<=9; i++) {
      // if current value is valid, continue
      if(isValid(board, row, col, i)) {
         board[row][col] = i;
         // move to next cell
         if(solveSudoku(board, row, col+1))
            return 1;
         // backtrack if failed
         board[row][col] = 0;
      }
   }
   return 0;
}

// Driver function
int main() {
   int board[9][9] = {
      {0, 0, 3, 0, 2, 0, 6, 0, 0},
      {9, 0, 0, 3, 0, 5, 0, 0, 1},
      {0, 0, 1, 8, 0, 6, 4, 0, 0},
      {0, 0, 8, 1, 0, 2, 9, 0, 0},
      {7, 0, 0, 0, 0, 0, 0, 0, 8},
      {0, 0, 6, 7, 0, 8, 2, 0, 0},
      {0, 0, 2, 6, 0, 9, 5, 0, 0},
      {8, 0, 0, 2, 0, 3, 0, 0, 9},
      {0, 0, 5, 0, 1, 0, 3, 0, 0}
   };
   printf("Sudoku Board:\n");
   printBoard(board);
   printf("\n");

   if(solveSudoku(board, 0, 0)) {
      printf("Solution:\n");
      printBoard(board);
   } else {
      printf("No solution exists");
   }
   return 0;
}