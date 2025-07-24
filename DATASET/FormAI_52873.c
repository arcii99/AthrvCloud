//FormAI DATASET v1.0 Category: Game of Life ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void print_grid(int grid[ROWS][COLS]);
void generate_next(int grid[ROWS][COLS]);

int main() {
  int grid[ROWS][COLS] = {0};

  // Seed random number generator
  srand(time(NULL));

  // Randomly set initial live cells
  for (int i = 0; i < 200; i++) {
    int row = rand() % ROWS;
    int col = rand() % COLS;
    grid[row][col] = 1;
  }

  // Run Game of Life for 100 iterations
  for (int i = 0; i < 100; i++) {
    printf("Iteration %d:\n", i + 1);
    print_grid(grid);
    generate_next(grid);
  }

  return 0;
}

void print_grid(int grid[ROWS][COLS]) {
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      if (grid[i][j]) {
        printf("X");
      } else {
        printf(".");
      }
    }
    printf("\n");
  }
  printf("\n");
}

void generate_next(int grid[ROWS][COLS]) {
  int next[ROWS][COLS] = {0};

  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      int neighbors = 0;

      // Check neighbors
      if (i > 0 && grid[i-1][j]) {
        neighbors++;
      }
      if (j > 0 && grid[i][j-1]) {
        neighbors++;
      }
      if (i < ROWS - 1 && grid[i+1][j]) {
        neighbors++;
      }
      if (j < COLS - 1 && grid[i][j+1]) {
        neighbors++;
      }
      if (i > 0 && j > 0 && grid[i-1][j-1]) {
        neighbors++;
      }
      if (i > 0 && j < COLS - 1 && grid[i-1][j+1]) {
        neighbors++;
      }
      if (i < ROWS - 1 && j > 0 && grid[i+1][j-1]) {
        neighbors++;
      }
      if (i < ROWS - 1 && j < COLS - 1 && grid[i+1][j+1]) {
        neighbors++;
      }

      // Apply Game of Life rules
      if (grid[i][j] && (neighbors == 2 || neighbors == 3)) {
        next[i][j] = 1;
      } else if (!grid[i][j] && neighbors == 3) {
        next[i][j] = 1;
      }
    }
  }

  // Copy next to grid
  for (int i = 0; i < ROWS; i++) {
    for (int j = 0; j < COLS; j++) {
      grid[i][j] = next[i][j];
    }
  }
}