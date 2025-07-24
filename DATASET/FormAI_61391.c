//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size

int root(int i, int *id) {
  while (i != id[i]){
    i = id[i];
  }
  return i;
}

void union_find(int p, int q, int *id, int *sz) {
  int i = root(p, id);
  int j = root(q, id);

  if (i == j) return;

  if (sz[i] < sz[j]) {
    id[i] = j;
    sz[j] += sz[i];
  } else {
    id[j] = i;
    sz[i] += sz[j];
  }
}

int percolates(int *grid, int *id, int *sz) {
  for (int i = 0; i < N; i++) {
    if (grid[i] && grid[(N * N) - 1 - i]){
      if (root(i, id) == root((N * N) - 1 - i, id)){
        return 1;
      }
    }
  }
  return 0;
}

void shuffle(int *arr, int n) {
  for (int i = n - 1; i > 0; i--) {
    int j = rand() % (i + 1);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }
}

void print_grid(int *grid) {
  printf("\n");
  for (int i = 0; i < N * N; i++) {
    if (grid[i])
      printf("%c ", '#');
    else
      printf("%c ", ' ');
    if ((i + 1) % N == 0)
      printf("\n");
  }
}

int main() {
  int id[N * N], sz[N * N];
  int grid[N * N];

  for (int i = 0; i < N * N; i++) {
    id[i] = i;
    sz[i] = 1;
    grid[i] = 0;
  }

  srand(time(NULL));
  int arr[N * N];
  for (int i = 0; i < N * N; i++) {
    arr[i] = i;
  }
  
  // simulation variables
  int perc = 0;
  int opened = 0;
  int i = 0;

  // configure number of iterations and number of sites to open per iteration
  int iterations = 100;
  int sites_to_open = 5;

  while (perc == 0 && i < iterations) {
    shuffle(arr, N * N);
    int j = 0;
    while (opened < sites_to_open) {
      int site = arr[j];
      if (grid[site] == 0) {
        grid[site] = 1;
        opened++;
        if (site < N && N - site > 1 && grid[site + N]) {
          union_find(site, site + N, id, sz);
        }
        if (site >= (N * (N - 1)) && site + N - N * N < N * N && grid[site - N]) {
          union_find(site, site - N, id, sz);
        }
        if (site % N != N - 1 && site + 1 < N * N && grid[site + 1]) {
          union_find(site, site + 1, id, sz);
        }
        if (site % N != 0 && site - 1 >= 0 && grid[site - 1]){
          union_find(site, site - 1, id, sz);
        }
      }
      j++;
    }
    perc = percolates(grid, id, sz);
    print_grid(grid);
    printf("\nIteration %d, %d sites opened, percolates? %d\n\n", i+1, sites_to_open, perc);
    i++;
    opened = 0;
  }

  if (perc) {
    printf("\nPercolates after %d iterations\n", i);
  }
  else {
    printf("\nDoes Not Percolate after %d iterations\n", i);
  }

  return 0;
}