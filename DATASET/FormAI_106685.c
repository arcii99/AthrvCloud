//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10

// quick-union algorithm
int parent[N*N], size[N*N];

void initialize(int n) {
  int i;
  for (i = 0; i < n*n; i++) {
    parent[i] = i;
    size[i] = 1;
  }
}

int find(int p) {
  while (p != parent[p])
    p = parent[p];
  return p;
}

void unite(int p, int q) {
  int i = find(p);
  int j = find(q); 
  if (i == j) return;
  if (size[i] < size[j]) { 
    parent[i] = j;
    size[j] += size[i];
  } else { 
    parent[j] = i;
    size[i] += size[j];
  }
}

bool connected(int p, int q) { return find(p) == find(q); }

int main() {
  srand(time(NULL));
  initialize(N);
  int openSites = 0;
  while (!connected(0,N*N-1)) {
    int i = rand() % N;
    int j = rand() % N;
    int idx = i*N+j;
    if (parent[idx] == idx) { 
      parent[idx] = N*N;
      openSites++;
    }
    // check up, down, left, and right
    if (i > 0 && parent[idx-N] != idx) unite(idx,idx-N); // up
    if (i < N-1 && parent[idx+N] != idx) unite(idx,idx+N); // down
    if (j > 0 && parent[idx-1] != idx) unite(idx,idx-1); // left
    if (j < N-1 && parent[idx+1] != idx) unite(idx,idx+1); // right
  }
  double p = (double)openSites / (N*N);
  printf("Percolation threshold: %f\n", p);
  return 0;
}