//FormAI DATASET v1.0 Category: Game of Life ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 50
#define GENERATIONS 100

void print_board(int board[ROWS][COLS]) {
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      printf("%c", board[row][col] ? '#' : '.');
    }
    printf("\n");
  }
  printf("\n");
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
  int count = 0;
  for (int i = -1; i <= 1; i++) {
    for (int j = -1; j <= 1; j++) {
      if (i == 0 && j == 0) {
        continue;
      }
      int r = (row + i + ROWS) % ROWS;
      int c = (col + j + COLS) % COLS;
      count += board[r][c];
    }
  }
  return count;
}

void next_generation(int board[ROWS][COLS]) {
  int new_board[ROWS][COLS] = {{0}};
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      int count = count_neighbors(board, row, col);
      if (board[row][col]) {
        new_board[row][col] = (count == 2 || count == 3);
      } else {
        new_board[row][col] = (count == 3);
      }
    }
  }
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      board[row][col] = new_board[row][col];
    }
  }
}

int main() {
  int board[ROWS][COLS] = {{0}};
  srand(time(NULL));
  for (int row = 0; row < ROWS; row++) {
    for (int col = 0; col < COLS; col++) {
      board[row][col] = (rand() % 2);
    }
  }
  for (int i = 0; i < GENERATIONS; i++) {
    printf("Generation %d:\n", i + 1);
    print_board(board);
    next_generation(board);
  }
  return 0;
}