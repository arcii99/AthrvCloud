//FormAI DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 9

// Function to print the board
void printBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  printf("\n -------------------------\n");
   for (int i = 0; i < BOARD_SIZE; i++) {
      for (int j = 0; j < BOARD_SIZE; j++) {
          printf(" %d", board[i][j]);
      }
      printf(" |");
      printf("\n");
      if ((i + 1) % 3 == 0) {
          printf(" -------------------------\n");
      }
   }
}

// Function to check if the value is already in the row
bool isInRow(int row, int value, int board[BOARD_SIZE][BOARD_SIZE]) {
   for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[row][i] == value) {
            return true;
        }
   }
   return false;
}

// Function to check if the value is already in the column
bool isInCol(int col, int value, int board[BOARD_SIZE][BOARD_SIZE]) {
   for (int i = 0; i < BOARD_SIZE; i++) {
      if (board[i][col] == value) {
         return true;
      }
   }
   return false;
}

// Function to check if the value is already in the 3x3 box
bool isInBox(int row, int col, int value, int board[BOARD_SIZE][BOARD_SIZE]) {
   int r = row - row % 3;
   int c = col - col % 3;
   for (int i = r; i < r + 3; i++) {
      for (int j = c; j < c + 3; j++) {
         if (board[i][j] == value) {
            return true;
         }
      }
   }
   return false;
}

// Function to check if the value is a valid move
bool isValidMove(int row, int col, int value, int board[BOARD_SIZE][BOARD_SIZE]) {
  return !isInRow(row, value, board) && !isInCol(col, value, board) && !isInBox(row, col, value, board);
}

// Function to solve the sudoku board
bool solveBoard(int board[BOARD_SIZE][BOARD_SIZE]) {
  // Find the next empty cell to fill
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (board[row][col] == 0) {
        // We found an empty cell. Try to fill it with a value between 1-9
        for (int value = 1; value <= BOARD_SIZE; value++) {
          if (isValidMove(row, col, value, board)) {
            // This value is a valid move, try to solve the board with this value
            board[row][col] = value;

            // Recursively solve the board
            if (solveBoard(board)) {
              return true;
            }

            // We could not solve the board with this value, undo the move and try again
            board[row][col] = 0;
          }
        }
        // We could not solve the board with any value, backtrack
        return false;
      }
    }
  }
  // If we reach here, the board is solved
  return true;
}

int main() {
  int board[BOARD_SIZE][BOARD_SIZE] = {
    {8,0,0,  0,0,0,  0,0,0},
    {0,0,3,  6,0,0,  0,0,0},
    {0,7,0,  0,9,0,  2,0,0},

    {0,5,0,  0,0,7,  0,0,0},
    {0,0,0,  0,4,5,  7,0,0},
    {0,0,0,  1,0,0,  0,3,0},

    {0,0,1,  0,0,0,  0,6,8},
    {0,0,8,  5,0,0,  0,1,0},
    {0,9,0,  0,0,0,  4,0,0}
  }; // Example board to solve

  printf("Before solving:\n");
  printBoard(board);

  if (solveBoard(board)) {
    printf("After solving:\n");
    printBoard(board);
  } else {
    printf("Could not find a solution.\n");
  }
  
  return 0;
}