//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // Size of the grid
#define P 0.5 // Probability of site being open
#define CLOSED 0 // Value of blocked site
#define OPEN 1 // Value of open site
#define FULL 2 // Value of full site

int grid[N * N]; // Array to store grid
int uf[N * N]; // Array to create union-find data structure
int sz[N * N]; // Array to store size of each tree in union-find

// Function to initialize the grid
void initialize_grid() {
  srand(time(NULL)); // Seed for random number generator
  for (int i = 0; i < N * N; i++) {
    if ((double) rand() / (double) RAND_MAX < P) {
      grid[i] = OPEN; // Site is open with probability P
    } else {
      grid[i] = CLOSED; // Site is blocked otherwise
    }

    uf[i] = i; // Initialize union-find with each site as its own root
    sz[i] = 1; // Initialize size of each tree in union-find to 1
  }
}

// Function to find the root of a site in union-find
int find_root(int i) {
  while (i != uf[i]) {
    uf[i] = uf[uf[i]]; // Path compression
    i = uf[i];
  }
  return i;
}

// Function to perform union of sites in union-find
void union_sites(int p, int q) {
  int root_p = find_root(p);
  int root_q = find_root(q);
  if (root_p == root_q) return;
  if (sz[root_p] < sz[root_q]) {
    uf[root_p] = root_q;
    sz[root_q] += sz[root_p];
  } else {
    uf[root_q] = root_p;
    sz[root_p] += sz[root_q];
  }
}

// Function to check if grid site is connected to top
int is_connected_to_top(int i) {
  return find_root(i) < N;
}

// Function to check if grid site is connected to bottom
int is_connected_to_bottom(int i) {
  return find_root(i) >= N * (N - 1);
}

// Function to connect grid site to its neighboring open sites in union-find
void connect_to_neighbors(int i) {
  int row = i / N;
  int col = i % N;
  if (row > 0 && grid[(row - 1) * N + col] == OPEN) {
    union_sites(i, (row - 1) * N + col); // Connect to top neighbor
  }
  if (row < N - 1 && grid[(row + 1) * N + col] == OPEN) {
    union_sites(i, (row + 1) * N + col); // Connect to bottom neighbor
  }
  if (col > 0 && grid[row * N + (col - 1)] == OPEN) {
    union_sites(i, row * N + (col - 1)); // Connect to left neighbor
  }
  if (col < N - 1 && grid[row * N + (col + 1)] == OPEN) {
    union_sites(i, row * N + (col + 1)); // Connect to right neighbor
  }
}

// Function to perform percolation simulation
int percolates() {
  for (int i = 0; i < N * N; i++) {
    if (grid[i] == OPEN) {
      connect_to_neighbors(i); // Connect open site to its neighboring open sites
    }
  }
  for (int i = 0; i < N * N; i++) {
    if (grid[i] == OPEN && is_connected_to_top(i) && is_connected_to_bottom(i)) {
      return 1; // Grid percolates if there is a path from top to bottom
    }
  }
  return 0; // Grid does not percolate otherwise
}

// Function to print grid
void print_grid() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (grid[i * N + j] == CLOSED) {
        printf("# ");
      } else if (grid[i * N + j] == OPEN) {
        printf(". ");
      } else if (grid[i * N + j] == FULL) {
        printf("* ");
      }
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  initialize_grid(); // Initialize grid
  printf("Initial Grid:\n");
  print_grid(); // Print initial grid
  if (percolates()) {
    printf("Grid percolates!\n");
  } else {
    printf("Grid does not percolate.\n");
  }
  return 0;
}