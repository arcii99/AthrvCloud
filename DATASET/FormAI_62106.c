//FormAI DATASET v1.0 Category: Game of Life ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void print_board(int board[ROWS][COLS]) {
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      printf("%c", board[i][j] ? '#' : '-');
    }
    printf("\n");
  }
  printf("\n");
}

int count_neighbors(int board[ROWS][COLS], int row, int col) {
  int count = 0;
  for(int i = -1; i <= 1; i++) {
    for(int j = -1; j <= 1; j++) {
      if(i == 0 && j == 0) continue;
      int r = row + i;
      int c = col + j;
      if(r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;
      count += board[r][c];
    }
  }
  return count;
}

void update_board(int board[ROWS][COLS]) {
  int new_board[ROWS][COLS];
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      int neighbors = count_neighbors(board, i, j);
      if(board[i][j]) {
        if(neighbors == 2 || neighbors == 3)
          new_board[i][j] = 1;
        else
          new_board[i][j] = 0;
      } else {
        if(neighbors == 3)
          new_board[i][j] = 1;
        else
          new_board[i][j] = 0;
      }
    }
  }
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      board[i][j] = new_board[i][j];
    }
  }
}

int main() {
  srand(time(NULL));
  int board[ROWS][COLS];
  for(int i = 0; i < ROWS; i++) {
    for(int j = 0; j < COLS; j++) {
      board[i][j] = rand() % 2;
    }
  }
  for(int i = 0; i < 100; i++) {
    print_board(board);
    update_board(board);
    usleep(100000);
  }
  return 0;
}