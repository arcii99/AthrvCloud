//FormAI DATASET v1.0 Category: Game of Life ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLUMNS 20

// Initialize the game board randomly
void initializeBoard(int board[ROWS][COLUMNS]) {
  srand(time(NULL));
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      board[i][j] = rand() % 2;
    }
  }
}

// Print the current state of the game board
void printBoard(int board[ROWS][COLUMNS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      if (board[i][j] == 0) {
        printf(".");
      } else {
        printf("*");
      }
    }
    printf("\n");
  }
}

// Count the number of neighbors for a given cell
int countNeighbors(int board[ROWS][COLUMNS], int row, int column) {
  int count = 0;
  int neighborRow, neighborColumn;
  
  // Loop through all the neighbors of the cell
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      // Calculate the row and column of the neighbor
      neighborRow = row + i;
      neighborColumn = column + j;
      
      // Check if the neighbor is within the bounds of the board and is not the cell itself
      if (neighborRow >= 0 && neighborRow < ROWS && neighborColumn >= 0 && neighborColumn < COLUMNS && (i != 0 || j != 0)) {
        count += board[neighborRow][neighborColumn];
      }
    }
  }
  
  return count;
}

// Update the game board based on the rules of the Game of Life
void updateBoard(int board[ROWS][COLUMNS]) {
  int neighbors;
  int newBoard[ROWS][COLUMNS];

  // Loop through all the cells in the board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      neighbors = countNeighbors(board, i, j);
      
      // Apply the rules of the Game of Life
      if (board[i][j] == 1 && neighbors < 2) { // Underpopulation
        newBoard[i][j] = 0;
      } else if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3)) { // Survival
        newBoard[i][j] = 1;
      } else if (board[i][j] == 1 && neighbors > 3) { // Overpopulation
        newBoard[i][j] = 0;
      } else if (board[i][j] == 0 && neighbors == 3) { // Reproduction
        newBoard[i][j] = 1;
      } else {
        newBoard[i][j] = board[i][j];
      }
    }
  }

  // Copy the new board to the original board
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLUMNS; j++) {
      board[i][j] = newBoard[i][j];
    }
  }
}

int main() {
  int board[ROWS][COLUMNS];

  initializeBoard(board);
  printf("Initial state:\n");
  printBoard(board);
  
  for (int i = 0; i < 5; i++) {
    updateBoard(board);
    printf("State after %d generations:\n", i+1);
    printBoard(board);
  }

  return 0;
}