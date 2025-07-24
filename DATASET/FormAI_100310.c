//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size
#define P 0.6 // probability of a site being open

void union_find(int i, int j, int *id, int *sz);
int find_root(int i, int *id);
int is_percolating(int *id);

int main() {
    srand(time(NULL));
    int open[N][N] = {0};
    int id[N*N], sz[N*N];
    int i, j, k, x, y;

    // initialize id and sz arrays for union-find algorithm
    for (i = 0; i < N*N; i++) {
        id[i] = i;
        sz[i] = 1;
    }

    // randomly open sites with probability P
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if ((float) rand() / (float) RAND_MAX < P) {
                open[i][j] = 1;
            }
        }
    }

    // union neighboring open sites
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            if (open[i][j]) {
                k = i*N + j;
                if (i > 0 && open[i-1][j]) {
                    union_find(k, k-N, id, sz);
                }
                if (i < N-1 && open[i+1][j]) {
                    union_find(k, k+N, id, sz);
                }
                if (j > 0 && open[i][j-1]) {
                    union_find(k, k-1, id, sz);
                }
                if (j < N-1 && open[i][j+1]) {
                    union_find(k, k+1, id, sz);
                }
            }
        }
    }

    // check if there is a percolating path
    if (is_percolating(id)) {
        printf("There is a percolating path!\n");
    } else {
        printf("There is no percolating path.\n");
    }

    return 0;
}

// union-find algorithm with path compression and weighted quick-union
void union_find(int i, int j, int *id, int *sz) {
    int root_i = find_root(i, id);
    int root_j = find_root(j, id);
    if (root_i == root_j) {
        return;
    }
    if (sz[root_i] > sz[root_j]) {
        id[root_j] = root_i;
        sz[root_i] += sz[root_j];
    } else {
        id[root_i] = root_j;
        sz[root_j] += sz[root_i];
    }
}

// find the root of a site's component
int find_root(int i, int *id) {
    while (i != id[i]) {
        id[i] = id[id[i]]; // path compression
        i = id[i];
    }
    return i;
}

// check if the top and bottom rows are in the same component
int is_percolating(int *id) {
    int i, j;
    for (j = 0; j < N; j++) {
        if (id[j] == find_root(N*N-N+j, id)) {
            return 1;
        }
    }
    return 0;
}