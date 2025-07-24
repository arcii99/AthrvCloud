//FormAI DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

int matrix[ROWS][COLS];

void init_matrix() {
  int i, j;
  for (i=0; i<ROWS; i++) {
    for (j=0; j<COLS; j++) {
      matrix[i][j] = rand() % 2;
    }
  }
}

void print_matrix() {
  int i, j;
  for (i=0; i<ROWS; i++) {
    for (j=0; j<COLS; j++) {
      if (matrix[i][j] == 0) {
        printf(".");
      }
      else {
        printf("*");
      }
    }
    printf("\n");
  }
}

int count_neighbors(int row, int col) {
  int count = 0;
  int i, j;

  for (i=-1; i<=1; i++) {
    for (j=-1; j<=1; j++) {
      if (i==0 && j==0) continue;
      int neighbor_row = (row+i+ROWS) % ROWS;
      int neighbor_col = (col+j+COLS) % COLS;
      count += matrix[neighbor_row][neighbor_col];
    }
  }

  return count;
}

void iterate_matrix() {
  int i, j;
  int new_matrix[ROWS][COLS];

  for (i=0; i<ROWS; i++) {
    for (j=0; j<COLS; j++) {
      int neighbors = count_neighbors(i, j);
      if (matrix[i][j] == 1) {
        if (neighbors < 2 || neighbors > 3) {
          new_matrix[i][j] = 0;
        }
        else {
          new_matrix[i][j] = 1;
        }
      }
      else {
        if (neighbors == 3) {
          new_matrix[i][j] = 1;
        }
        else {
          new_matrix[i][j] = 0;
        }
      }
    }
  }

  for (i=0; i<ROWS; i++) {
    for (j=0; j<COLS; j++) {
      matrix[i][j] = new_matrix[i][j];
    }
  }
}

int main() {
  srand(time(NULL));
  init_matrix();
  while (1) {
    system("clear"); // Clear the console
    print_matrix();
    iterate_matrix();
    usleep(100000); // Sleep for 100ms
  }
  return 0;
}