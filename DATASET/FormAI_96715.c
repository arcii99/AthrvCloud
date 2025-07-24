//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // size of grid
#define p 0.6 // probability for each site to be open

void print_grid(int grid[N][N]); // prints the grid
int percolates(int grid[N][N]); // return 1 if the system percolates
int find_root(int i, int j, int root[N*N]); // returns the root of the cluster
void merge_clusters(int root[N*N], int i1, int j1, int i2, int j2); // merges two clusters
int is_valid(int i, int j); // return 1 if the coordinates are valid
void populate_grid(int grid[N][N], int root[N*N]); // initialize the grid and the roots

int main() {
    int grid[N][N];
    int root[N*N];
    int i, j, x, y;

    populate_grid(grid, root);
    while (!percolates(grid)) { // run until the system percolates
        x = rand() % N; // generate random coordinates
        y = rand() % N;
        if (!grid[x][y]) { // if the site is not open
            grid[x][y] = 1; // open the site
            if (is_valid(x-1, y) && grid[x-1][y]) merge_clusters(root, x, y, x-1, y); // connect the site to its neighbors
            if (is_valid(x+1, y) && grid[x+1][y]) merge_clusters(root, x, y, x+1, y);
            if (is_valid(x, y-1) && grid[x][y-1]) merge_clusters(root, x, y, x, y-1);
            if (is_valid(x, y+1) && grid[x][y+1]) merge_clusters(root, x, y, x, y+1);
        }
    }
    print_grid(grid);
}

void populate_grid(int grid[N][N], int root[N*N]) {
    int i, j;
    srand(time(0));
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            grid[i][j] = (rand() / (float)RAND_MAX < p) ? 1 : 0; // open with probability p
            root[i*N+j] = i*N+j; // each site starts as its own cluster
        }
    }
}

int is_valid(int i, int j) {
    return (i>=0 && i<N && j>=0 && j<N);
}

int find_root(int i, int j, int root[N*N]) {
    int id = i*N+j;
    while (root[id] != id) id = root[id];
    return id;
}

void merge_clusters(int root[N*N], int i1, int j1, int i2, int j2) {
    int r1 = find_root(i1, j1, root);
    int r2 = find_root(i2, j2, root);
    if (r1 != r2) root[r2] = r1;
}

int percolates(int grid[N][N]) {
    int root[N*N];
    int i, j, r1, r2;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            root[i*N+j] = (i == 0) ? -1 : i*N+j; // top row is marked for connectivity check
        }
    }
    for (i=0; i<N; i++) { // connect all open sites in the top row
        if (grid[0][i]) merge_clusters(root, 0, i, 0, i);
    }
    for (i=1; i<N; i++) { // propagate the connectivity check down
        for (j=0; j<N; j++) {
            if (grid[i][j]) {
                r1 = find_root(i, j, root);
                if (r1 == -1) return 1; // if an open site is found in the bottom row, the system percolates
                if (is_valid(i-1, j) && grid[i-1][j]) {
                    r2 = find_root(i-1, j, root);
                    if (r1 != r2) root[r2] = r1;
                }
                if (is_valid(i, j-1) && grid[i][j-1]) {
                    r2 = find_root(i, j-1, root);
                    if (r1 != r2) root[r2] = r1;
                }
                if (is_valid(i, j+1) && grid[i][j+1]) {
                    r2 = find_root(i, j+1, root);
                    if (r1 != r2) root[r2] = r1;
                }
            }
        }
    }
    return 0;
}

void print_grid(int grid[N][N]) {
    int i, j;
    for (i=0; i<N; i++) {
        for (j=0; j<N; j++) {
            if (grid[i][j]) printf("0"); // open site
            else printf("*"); // blocked site
        }
        printf("\n");
    }
}