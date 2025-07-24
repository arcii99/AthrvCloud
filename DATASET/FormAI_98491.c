//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
#define OPEN 0
#define CLOSED 1
#define FULL 2

int grid[N][N];
int parent[N*N];
int size[N*N];

int find(int p) {
    while (p != parent[p]) {
        p = parent[p];
    }
    return p;
}

void union_sets(int p, int q) {
    int root1 = find(p);
    int root2 = find(q);
    if (root1 == root2) return;
    if (size[root1] < size[root2]) {
        parent[root1] = root2;
        size[root2] += size[root1];
    } else {
        parent[root2] = root1;
        size[root1] += size[root2];
    }
}

void initialize() {
    for (int i = 0; i < N*N; i++) {
        parent[i] = i;
        size[i] = 1;
    }
}

void print_grid() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == OPEN) {
                printf(" ");
            } else if (grid[i][j] == CLOSED) {
                printf("#");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    initialize();
    for (int i = 0; i < N*N/2; i++) {
        int p = rand() % (N*N);
        grid[p/N][p%N] = CLOSED;
    }
    int count = 0;
    while (find(0) != find(N*N-1)) {
        int p = rand() % (N*N);
        int i = p/N;
        int j = p%N;
        if (grid[i][j] != CLOSED) {
            grid[i][j] = FULL;
            if (i > 0 && grid[i-1][j] == FULL) {
                union_sets(p, (i-1)*N+j);
            }
            if (i < N-1 && grid[i+1][j] == FULL) {
                union_sets(p, (i+1)*N+j);
            }
            if (j > 0 && grid[i][j-1] == FULL) {
                union_sets(p, i*N+(j-1));
            }
            if (j < N-1 && grid[i][j+1] == FULL) {
                union_sets(p, i*N+(j+1));
            }
            count++;
        }
    }
    print_grid();
    printf("Number of open sites: %d\n", count);
    return 0;
}