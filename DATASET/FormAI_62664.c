//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define BLOCKED 0
#define OPEN 1

int grid[N][N];
int openSites = 0;

void initialize() {
  srand((unsigned)time(NULL));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      grid[i][j] = BLOCKED;
    }
  }
}

void open(int row, int col) {
  if (grid[row][col] == BLOCKED) {
    grid[row][col] = OPEN;
    openSites += 1;
  }
}

int isOpen(int row, int col) {
  return grid[row][col] == OPEN;
}

int percolates() {
  // Check if there is any open cell in the bottom row of the grid
  for (int j = 0; j < N; j++) {
    if (isOpen(N - 1, j)) {
      return 1;
    }
  }
  return 0;
}

int main() {
  initialize();

  while (!percolates()) {
    int row = rand() % N;
    int col = rand() % N;

    open(row, col);
  }

  printf("Percolation occurred after %d open sites\n", openSites);

  return 0;
}