//FormAI DATASET v1.0 Category: Game of Life ; Style: surprised
#include <stdio.h>

int main() {
  printf("Gasp! I never thought my Game of Life program will work!\n");

  int grid[20][20] = {0};
  int nextGen[20][20] = {0};
  int i, j;

  // Set initial grid
  grid[4][6] = 1;
  grid[4][7] = 1;
  grid[4][8] = 1;
  grid[5][6] = 1;
  grid[5][7] = 0;
  grid[5][8] = 1;
  grid[6][6] = 0;
  grid[6][7] = 1;
  grid[6][8] = 0;

  // Print the initial grid
  printf("Initial Grid:\n");
  for (i = 0; i < 20; i++) {
      for (j = 0; j < 20; j++) {
          printf("%d ", grid[i][j]);
      }
      printf("\n");
  }

  // Iterate 10 generations
  int generation;
  for (generation = 1; generation <= 10; generation++) {
    printf("Generation %d\n", generation);

    // Calculate next generation
    for (i = 0; i < 20; i++) {
      for (j = 0; j < 20; j++) {
        // Count live neighbors
        int neighbors = 0;
        if (i - 1 >= 0 && j - 1 >= 0 && grid[i-1][j-1] == 1) {
          neighbors++;
        }
        if (i - 1 >= 0 && grid[i-1][j] == 1) {
          neighbors++;
        }
        if (i - 1 >= 0 && j + 1 < 20 && grid[i-1][j+1] == 1) {
          neighbors++;
        }
        if (j - 1 >= 0 && grid[i][j-1] == 1) {
          neighbors++;
        }
        if (j + 1 < 20 && grid[i][j+1] == 1) {
          neighbors++;
        }
        if (i + 1 < 20 && j - 1 >= 0 && grid[i+1][j-1] == 1) {
          neighbors++;
        }
        if (i + 1 < 20 && grid[i+1][j] == 1) {
          neighbors++;
        }
        if (i + 1 < 20 && j + 1 < 20 && grid[i+1][j+1] == 1) {
          neighbors++;
        }

        // Apply Game of Life rules
        if (grid[i][j] == 1 && neighbors < 2) {
          nextGen[i][j] = 0;
        }
        else if (grid[i][j] == 1 && (neighbors == 2 || neighbors == 3)) {
          nextGen[i][j] = 1;
        }
        else if (grid[i][j] == 1 && neighbors > 3) {
          nextGen[i][j] = 0;
        }
        else if (grid[i][j] == 0 && neighbors == 3) {
          nextGen[i][j] = 1;
        }
        else {
          nextGen[i][j] = grid[i][j];
        }
      }
    }

    // Copy next generation to current grid
    for (i = 0; i < 20; i++) {
      for (j = 0; j < 20; j++) {
        grid[i][j] = nextGen[i][j];
      }
    }

    // Print the generation
    for (i = 0; i < 20; i++) {
      for (j = 0; j < 20; j++) {
        printf("%d ", grid[i][j]);
      }
      printf("\n");
    }

  }

  printf("I'm so amazed that it works! Thanks for watching!\n");

  return 0;
}