//FormAI DATASET v1.0 Category: Game of Life ; Style: Ada Lovelace
/*
  "The universe is infinite, as our imaginations." - Ada Lovelace
  Game of Life: A simulation of cellular automaton.

  Rules of the Game:
  1. Any live cell with fewer than two live neighbours dies, as if by underpopulation.
  2. Any live cell with two or three live neighbours lives on to the next generation.
  3. Any live cell with more than three live neighbours dies, as if by overpopulation.
  4. Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.

  Let's start the game of life!
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define ROWS 20
#define COLS 20
#define GENERATIONS 100

// Function Prototype
void printBoard(int board[ROWS][COLS]);
int countNeighbors(int board[ROWS][COLS], int row, int col);

int main() {
  srand(time(NULL)); // initialize random seed
  int board[ROWS][COLS]; // initialize game board

  // randomly fill the game board
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      board[r][c] = rand() % 2;
    }
  }

  // run the game for GENERATIONS
  for (int g = 0; g < GENERATIONS; g++) {
    printf("Generation %d:\n", g);

    // print the game board
    printBoard(board);

    // create a new board for the next generation
    int newBoard[ROWS][COLS];

    // iterate through each cell and apply the rules of the game
    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        int neighbors = countNeighbors(board, r, c);

        if (board[r][c] == 1) { // live cell
          if (neighbors < 2 || neighbors > 3) {
            newBoard[r][c] = 0; // cell dies
          } else {
            newBoard[r][c] = 1; // cell lives
          }
        } else { // dead cell
          if (neighbors == 3) {
            newBoard[r][c] = 1; // cell lives
          } else {
            newBoard[r][c] = 0; // cell remains dead
          }
        }
      }
    }

    // copy the new board to the game board
    for (int r = 0; r < ROWS; r++) {
      for (int c = 0; c < COLS; c++) {
        board[r][c] = newBoard[r][c];
      }
    }
  }

  return 0;
}

// Function Definition
void printBoard(int board[ROWS][COLS]) {
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (board[r][c] == 1) {
        printf("* ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf("--------------------\n");
}

int countNeighbors(int board[ROWS][COLS], int row, int col) {
  int count = 0;

  // check the eight neighboring cells
  if (row > 0) { // top
    count += board[row-1][col];
    if (col > 0) { // top left
      count += board[row-1][col-1];
    }
    if (col < COLS-1) { // top right
      count += board[row-1][col+1];
    }
  }
  if (row < ROWS-1) { // bottom
    count += board[row+1][col];
    if (col > 0) { // bottom left
      count += board[row+1][col-1];
    }
    if (col < COLS-1) { // bottom right
      count += board[row+1][col+1];
    }
  }
  if (col > 0) { // left
    count += board[row][col-1];
  }
  if (col < COLS-1) { // right
    count += board[row][col+1];
  }

  return count;
}