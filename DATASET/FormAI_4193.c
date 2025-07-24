//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Grid size

int grid[N][N];
int visited[N][N];

void initialize_grid() {
  // Randomly initializes grid with 0s and 1s
  int i, j;
  srand(time(NULL));
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      grid[i][j] = rand() % 2;
    }
  }
}

void print_grid() {
  // Prints grid to terminal
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
}

void dfs(int x, int y) {
  // Depth-First Search algorithm to mark percolated cells
  int i, dx, dy;
  int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  visited[x][y] = 1;
  for (i = 0; i < 4; i++) {
    dx = directions[i][0];
    dy = directions[i][1];
    if (x+dx >= 0 && x+dx < N && y+dy >= 0 && y+dy < N && !visited[x+dx][y+dy] && grid[x+dx][y+dy]) {
      dfs(x+dx, y+dy);
    }
  }
}

int percolates() {
  // Returns 1 if there is a percolated path in the grid
  int i;
  for (i = 0; i < N; i++) visited[0][i] = 0; // resetting visited matrix
  for (i = 0; i < N; i++) {
    if (grid[0][i] && !visited[0][i]) dfs(0, i);
  }
  for (i = 0; i < N; i++) {
    if (visited[N-1][i]) return 1;
  }
  return 0;
}

int main() {
  initialize_grid();
  printf("Initial grid:\n");
  print_grid();
  if (percolates()) {
    printf("\nThe grid percolates.\n");
  } else {
    printf("\nThe grid does not percolate.\n");
  }
  return 0;
}