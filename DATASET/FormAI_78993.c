//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // Size of grid
#define P 0.4 // Probability of site being open

// Union-find data structure
int parent[N*N];
int size[N*N];

// Initialize union-find data structure
void init() {
    for (int i = 0; i < N*N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

// Find root of i using path compression
int find(int i) {
    while (i != parent[i]) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

// Connect sites i and j using weighted quick-union
void connect(int i, int j) {
    int root_i = find(i);
    int root_j = find(j);
    if (root_i == root_j) return;
    if (size[root_i] < size[root_j]) {
        parent[root_i] = root_j;
        size[root_j] += size[root_i];
    } else {
        parent[root_j] = root_i;
        size[root_i] += size[root_j];
    }
}

// Check if site i is open
int is_open(int i, int* grid) {
    return grid[i] == 1;
}

// Generate random grid using p as probability
void generate_grid(int* grid) {
    srand(time(NULL));
    for (int i = 0; i < N*N; i++) {
        double r = (double) rand() / RAND_MAX;
        if (r < P) grid[i] = 1; // open
        else grid[i] = 0; // closed
    }
}

// Print grid to console
void print_grid(int* grid) {
    printf(" ");
    for (int i = 0; i < N; i++) {
        printf("_ ");
    }
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("|");
        for (int j = 0; j < N; j++) {
            if (is_open(i*N+j, grid)) printf(" ");
            else printf("_");
            if (j == N-1) printf("|");
            else printf(" ");
        }
        printf("\n");
    }
    printf(" ");
    for (int i = 0; i < N; i++) {
        printf("__");
    }
    printf("\n");
}

// Check if system percolates
int percolates() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int k = i*N + j;
            if (i == 0 && is_open(k, parent)) {
                connect(k, N*N);
            }
            if (i == N-1 && is_open(k, parent)) {
                connect(k, N*N+1);
            }
            if (i > 0 && is_open(k-N, parent)) {
                connect(k, k-N);
            }
            if (i < N-1 && is_open(k+N, parent)) {
                connect(k, k+N);
            }
            if (j > 0 && is_open(k-1, parent)) {
                connect(k, k-1);
            }
            if (j < N-1 && is_open(k+1, parent)) {
                connect(k, k+1);
            }
        }
    }
    return find(N*N) == find(N*N+1);
}

int main() {
    int grid[N*N];
    init();
    generate_grid(grid);
    printf("Initial Grid:\n");
    print_grid(grid);
    while (!percolates()) {
        generate_grid(grid);
        init();
        printf("New Grid:\n");
        print_grid(grid);
    }
    printf("Percolation achieved on Grid:\n");
    print_grid(grid);
    return 0;
}