//FormAI DATASET v1.0 Category: Game of Life ; Style: optimized
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define BOARD_SIZE 50

void printBoard(int board[][BOARD_SIZE]) {
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      printf(board[i][j] ? "x " : "- ");
    }
    printf("\n");
  }
}

int main() {
  srand(time(NULL)); // initialize random seed

  // Initialize board with random values
  int board[BOARD_SIZE][BOARD_SIZE];
  for (int i = 0; i < BOARD_SIZE; i++) {
    for (int j = 0; j < BOARD_SIZE; j++) {
      int randomValue = rand() % 2; // get random value (either 0 or 1)
      board[i][j] = randomValue;
    }
  }

  // Print initial board
  printf("Initial Board:\n");
  printBoard(board);

  int generations = 10; // number of generations to simulate
  for (int i = 0; i < generations; i++) {
    // Create temporary board to hold new values
    int tempBoard[BOARD_SIZE][BOARD_SIZE];

    // Calculate new values for each cell using Game of Life rules
    for (int x = 0; x < BOARD_SIZE; x++) {
      for (int y = 0; y < BOARD_SIZE; y++) {
        int aliveNeighbors = 0;

        // Check neighbors
        for (int dx = -1; dx <= 1; dx++) {
          for (int dy = -1; dy <= 1; dy++) {
            int nx = x + dx;
            int ny = y + dy;

            if (nx < 0 || nx >= BOARD_SIZE || ny < 0 || ny >= BOARD_SIZE) {
              continue; // out of bounds, skip
            }

            if (dx == 0 && dy == 0) {
              continue; // current cell, skip
            }

            if (board[nx][ny]) {
              aliveNeighbors++;
            }
          }
        }

        // Apply rules
        if (board[x][y]) {
          // Cell is alive
          if (aliveNeighbors < 2 || aliveNeighbors > 3) {
            tempBoard[x][y] = 0; // dies
          } else {
            tempBoard[x][y] = 1; // lives
          }
        } else {
          // Cell is dead
          if (aliveNeighbors == 3) {
            tempBoard[x][y] = 1; // revives
          } else {
            tempBoard[x][y] = 0; // stays dead
          }
        }
      }
    }

    // Copy new values from temporary board to main board
    for (int x = 0; x < BOARD_SIZE; x++) {
      for (int y = 0; y < BOARD_SIZE; y++) {
        board[x][y] = tempBoard[x][y];
      }
    }

    // Print new board
    printf("Generation %d:\n", i + 1);
    printBoard(board);
  }

  return 0;
}