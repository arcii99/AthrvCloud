//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid
#define P 0.5 // Probability of a site being open
#define SEED time(0) // Seed for random number generator

// Structure for a site on the grid
typedef struct {
  int x;
  int y;
  int open;
  int full;
} site;

// Function to initialize the grid
void init(site grid[][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      grid[i][j].x = i;
      grid[i][j].y = j;
      grid[i][j].open = ((double) rand() / (RAND_MAX)) < P;
      grid[i][j].full = 0;
    }
  }
}

// Function to print the grid
void print(site grid[][N]) {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (grid[i][j].open) {
        printf(" ");
      } else {
        printf("X");
      }
    }
    printf("\n");
  }
  printf("\n");
}

// Recursive function to check if a site is full
void fill(site grid[][N], int i, int j) {
  if (i < 0 || i >= N || j < 0 || j >= N) {
    return;
  }
  if (!grid[i][j].open || grid[i][j].full) {
    return;
  }
  grid[i][j].full = 1;
  fill(grid, i - 1, j);
  fill(grid, i + 1, j);
  fill(grid, i, j - 1);
  fill(grid, i, j + 1);
}

int main() {
  srand(SEED);
  site grid[N][N];
  init(grid);
  print(grid);

  int i, j;
  for (i = 0; i < N; i++) {
    if (grid[0][i].open) {
      fill(grid, 0, i);
    }
  }
  print(grid);

  for (i = 0; i < N; i++) {
    if (grid[N-1][i].full) {
      printf("Percolates!\n");
      return 0;
    }
  }
  printf("Does not percolate\n");
  return 0;
}