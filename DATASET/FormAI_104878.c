//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10
#define THRESHOLD 0.6

int uf_find(int parent[], int i) {
  while (i != parent[i]) {
    parent[i] = parent[parent[i]];
    i = parent[i];
  }
  return i;
}

void uf_union(int parent[], int size[], int a, int b) {
  int root_a = uf_find(parent, a);
  int root_b = uf_find(parent, b);

  if (root_a == root_b) return;

  if (size[root_a] < size[root_b]) {
    parent[root_a] = root_b;
    size[root_b] += size[root_a];
  } else {
    parent[root_b] = root_a;
    size[root_a] += size[root_b];
  }
}

int main() {
  // initialize random seed
  srand(time(NULL));

  int i, j;
  float random_number;
  int grid[GRID_SIZE + 1][GRID_SIZE + 1];
  int parent[(GRID_SIZE + 1) * (GRID_SIZE + 1)];
  int size[(GRID_SIZE + 1) * (GRID_SIZE + 1)];

  // initialize grid and disjoint set
  for (i = 0; i <= GRID_SIZE; i++) {
    for (j = 0; j <= GRID_SIZE; j++) {
      grid[i][j] = 0;
      parent[i * GRID_SIZE + j] = i * GRID_SIZE + j;
      size[i * GRID_SIZE + j] = 1;
    }
  }

  // simulate percolation
  for (i = 1; i <= GRID_SIZE; i++) {
    for (j = 1; j <= GRID_SIZE; j++) {
      random_number = (float)rand() / (float)RAND_MAX;

      if (random_number < THRESHOLD) {
        grid[i][j] = 1;

        // union with neighboring cells
        if (grid[i - 1][j]) uf_union(parent, size, i * GRID_SIZE + j, (i - 1) * GRID_SIZE + j);
        if (grid[i][j - 1]) uf_union(parent, size, i * GRID_SIZE + j, i * GRID_SIZE + j - 1);
        if (grid[i + 1][j]) uf_union(parent, size, i * GRID_SIZE + j, (i + 1) * GRID_SIZE + j);
        if (grid[i][j + 1]) uf_union(parent, size, i * GRID_SIZE + j, i * GRID_SIZE + j + 1);
      }
    }
  }

  // check if top and bottom cells are connected
  int top_root = uf_find(parent, 0);
  int bottom_root = uf_find(parent, GRID_SIZE * (GRID_SIZE + 1));

  if (top_root == bottom_root) {
    printf("Percolation occurred!\n");
  } else {
    printf("Percolation did not occur.\n");
  }

  return 0;
}