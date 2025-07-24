//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define THRESHOLD 0.5

int grid[GRID_SIZE][GRID_SIZE];

void initialize_grid() {
  srand(time(NULL));

  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      float random_value = (float)rand() / RAND_MAX;

      if (random_value < THRESHOLD) {
        grid[i][j] = 1;
      } else {
        grid[i][j] = 0;
      }
    }
  }
}

void print_grid() {
  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j] == 1) {
        printf("#");
      } else {
        printf(" ");
      }
    }
    printf("\n");
  }
}

int dfs(int x, int y) {
  if (x < 0 || x >= GRID_SIZE || y < 0 || y >= GRID_SIZE) {
    return 0;
  }

  if (grid[x][y] == 0) {
    return 0;
  }

  grid[x][y] = 0;

  return 1 + dfs(x + 1, y) + dfs(x - 1, y) + dfs(x, y + 1) + dfs(x, y - 1);
}

int main() {
  initialize_grid();
  print_grid();

  int largest_cluster_size = 0;

  for (int i = 0; i < GRID_SIZE; i++) {
    for (int j = 0; j < GRID_SIZE; j++) {
      if (grid[i][j] == 1) {
        int cluster_size = dfs(i, j);

        if (cluster_size > largest_cluster_size) {
          largest_cluster_size = cluster_size;
        }
      }
    }
  }

  printf("The largest cluster size is %d\n", largest_cluster_size);

  return 0;
}