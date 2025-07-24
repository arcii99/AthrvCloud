//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

int grid[ROWS][COLS];
int open[ROWS][COLS];

void print_grid() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (grid[i][j] == 1) {
        printf("#");
      } else if (open[i][j] == 1) {
        printf(" ");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
}

void initialize_grid() {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = 1;
      open[i][j] = 0;
    }
  }
}

int percolates() {
  for (int j = 0; j < COLS; j++) {
    if (open[0][j] == 1 && open[ROWS-1][j] == 1) {
      return 1;
    }
  }
  return 0;
}

void percolate() {
  initialize_grid();

  int row, col;
  while (1) {
    do {
      row = rand() % ROWS;
      col = rand() % COLS;
    } while (open[row][col] == 1);

    open[row][col] = 1;
    grid[row][col] = 0;

    if (percolates()) {
      print_grid();
      printf("Percolates!\n");
      break;
    }
  }
}

int main() {
  srand(time(NULL));
  percolate();
  return 0;
}