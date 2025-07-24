//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N][N];
int visited[N][N];

void print_grid() {
  printf("Current Grid:\n\n");
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      printf("%d ", grid[i][j]);
    }
    printf("\n");
  }
  printf("\n");
}

void dfs(int x, int y) {
  visited[x][y] = 1;
  grid[x][y] = 2;

  if (x+1 < N && !visited[x+1][y] && grid[x+1][y]) {
    dfs(x+1, y);
  }

  if (x-1 >= 0 && !visited[x-1][y] && grid[x-1][y]) {
    dfs(x-1, y);
  }

  if (y+1 < N && !visited[x][y+1] && grid[x][y+1]) {
    dfs(x, y+1);
  }

  if (y-1 >= 0 && !visited[x][y-1] && grid[x][y-1]) {
    dfs(x, y-1);
  }
}

int main() {
  srand(time(0));

  // Initialize the grid randomly
  for (int i=0; i<N; i++) {
    for (int j=0; j<N; j++) {
      grid[i][j] = rand() % 2;
    }
  }

  print_grid();

  // Run the flood fill algorithm on the top row to check if water can percolate
  for (int j=0; j<N; j++) {
    if (grid[0][j]) {
      dfs(0, j);
    }
  }

  // Check if water was able to reach the bottom row
  int percolates = 0;
  for (int j=0; j<N; j++) {
    if (grid[N-1][j] == 2) {
      percolates = 1;
      break;
    }
  }

  if (percolates) {
    printf("Water percolates through the grid.\n");
  } else {
    printf("Water does not percolate through the grid.\n");
  }

  print_grid();

  return 0;
}