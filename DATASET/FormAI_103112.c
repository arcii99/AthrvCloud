//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // dimension of the grid
#define p 0.5 // probability of site being open

int grid[N][N];
int visited[N][N];
int clusters[N*N];
int cluster_count = 0;

void initialize_grid() {
  int i, j;
  srand(time(NULL));
  
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      double r = (double)rand() / RAND_MAX;
      if (r > p)
        grid[i][j] = 1;
      else
        grid[i][j] = 0;
    }
  }
}

void print_grid() {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (grid[i][j])
        printf("O ");
      else
        printf(". ");
    }
    printf("\n");
  }
}

int in_bounds(int i, int j) {
  return (i >= 0 && i < N && j >= 0 && j < N);
}

void dfs(int i, int j, int cluster) {
  if (!in_bounds(i, j))
    return;
  if (visited[i][j])
    return;
  if (!grid[i][j])
    return;
  
  visited[i][j] = 1;
  clusters[cluster]++;
  
  dfs(i-1, j, cluster);
  dfs(i+1, j, cluster);
  dfs(i, j-1, cluster);
  dfs(i, j+1, cluster);
}

void find_clusters() {
  int i, j;
  
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (!visited[i][j] && grid[i][j]) {
        cluster_count++;
        dfs(i, j, cluster_count);
      }
    }
  }
}

void print_clusters() {
  int i;
  
  for (i = 0; i < cluster_count; i++) {
    printf("Cluster %d: %d sites\n", i+1, clusters[i+1]);
  }
}

int main() {
  initialize_grid();
  printf("Initial grid:\n");
  print_grid();
  
  find_clusters();
  printf("Clusters:\n");
  print_clusters();
  
  return 0;
}