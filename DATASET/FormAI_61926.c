//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void print_grid(char grid[SIZE][SIZE]) {
  printf("+");
  for (int i = 0; i < SIZE; i++) {
    printf("--");
  }
  printf("+\n");
  for (int i = 0; i < SIZE; i++) {
    printf("|");
    for (int j = 0; j < SIZE; j++) {
      printf("%c ", grid[i][j]);
    }
    printf("|\n");
  }
  printf("+");
  for (int i = 0; i < SIZE; i++) {
    printf("--");
  }
  printf("+\n");
}

int main() {
  char grid[SIZE][SIZE];
  int percolates = 0;

  // Initialize the grid
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      grid[i][j] = '.';
    }
  }

  // Set random sites to be open
  srand(time(NULL));
  for (int i = 0; i < SIZE; i++) {
    int rand_i = rand() % SIZE;
    int rand_j = rand() % SIZE;
    grid[rand_i][rand_j] = ' ';
  }

  // Simulation loop
  while (!percolates) {
    print_grid(grid);

    // Check if the system percolates
    for (int j = 0; j < SIZE; j++) {
      if (grid[0][j] == ' ') {
        percolates = 1;
        break;
      }
    }

    // Fill any open sites connected to the top row
    for (int j = 0; j < SIZE; j++) {
      if (grid[0][j] == ' ') {
        grid[0][j] = '1';
        if (j > 0 && grid[0][j-1] == ' ') {
          grid[0][j-1] = '1';
        }
        if (j < SIZE-1 && grid[0][j+1] == ' ') {
          grid[0][j+1] = '1';
        }
        if (grid[1][j] == ' ') {
          grid[1][j] = '1';
        }
      }
    }

    // Fill any open sites connected to neighboring filled sites
    for (int i = 1; i < SIZE; i++) {
      for (int j = 0; j < SIZE; j++) {
        if (grid[i][j] == ' ') {
          if (j > 0 && grid[i][j-1] == '1') {
            grid[i][j] = '1';
          }
          if (j < SIZE-1 && grid[i][j+1] == '1') {
            grid[i][j] = '1';
          }
          if (i < SIZE-1 && grid[i+1][j] == '1') {
            grid[i][j] = '1';
          }
        }
      }
    }
  }

  print_grid(grid);

  return 0;
}