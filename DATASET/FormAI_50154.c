//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // system size
#define p 0.5 // percolation threshold
#define SEED time(NULL)

int P[N][N], Q[N][N], cluster_count = 0;

int rand_int(int min, int max) {
  return rand() % (max - min + 1) + min;
}

void print_lattice() {
  int i, j;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      printf("%3d", P[i][j]);
    }
    printf("\n");
  }
}

void bond_percolation() {
  int i, j;

  // initialize lattice with bonds
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (rand() / (double)RAND_MAX < p) {
        P[i][j] = 1;
      } else {
        P[i][j] = 0;
      }
      Q[i][j] = 0;
    }
  }

  // find clusters
  int cluster_size;
  for (i = 0; i < N; i++) {
    for (j = 0; j < N; j++) {
      if (Q[i][j] == 0 && P[i][j] == 1) { // unvisited part of cluster
        cluster_count++;
        cluster_size = 0;
        dfs(i, j, cluster_size); // depth-first search
      }
    }
  }
}

void dfs(int i, int j, int cluster_size) {
  cluster_size++;
  Q[i][j] = cluster_count;

  // check neighbors
  if (i > 0 && P[i-1][j] == 1 && Q[i-1][j] == 0) { dfs(i-1, j, cluster_size); }
  if (i < N-1 && P[i+1][j] == 1 && Q[i+1][j] == 0) { dfs(i+1, j, cluster_size); }
  if (j > 0 && P[i][j-1] == 1 && Q[i][j-1] == 0) { dfs(i, j-1, cluster_size); }
  if (j < N-1 && P[i][j+1] == 1 && Q[i][j+1] == 0) { dfs(i, j+1, cluster_size); }
}

int main() {
  srand(SEED);

  bond_percolation();

  printf("Lattice with bonds:\n");
  print_lattice();

  printf("\nNumber of clusters: %d\n", cluster_count);

  return 0;
}