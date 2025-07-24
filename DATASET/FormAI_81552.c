//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

int grid[N*N];
int virtual[N*N];
int open_sites = 0;

void initialize_grid() {
    for(int i = 0; i < N*N; i++) {
        grid[i] = 0;
        virtual[i] = i;
    }
}

int root(int i) {
    while(i != virtual[i]) {
        virtual[i] = virtual[virtual[i]];
        i = virtual[i];
    }
    return i;
}

void union_sites(int p, int q) {
    int root_p = root(p);
    int root_q = root(q);
    virtual[root_p] = root_q;
}

int is_connected(int p, int q) {
    return root(p) == root(q);
}

void open_site(int i, int j) {
    int index = (i*N) + j;
    grid[index] = 1;
    open_sites++;

    // connecting to adjacent open sites
    if(i > 0 && grid[index - N]) { // up
        union_sites(index, index - N);
    }
    if(i < N-1 && grid[index + N]) { // down
        union_sites(index, index + N);
    }
    if(j > 0 && grid[index - 1]) { // left
        union_sites(index, index - 1);
    }
    if(j < N-1 && grid[index + 1]) { // right
        union_sites(index, index + 1);
    }
}

int percolates() {
    for(int i = 0; i < N; i++) {
        if(is_connected(i, N*(N-1))) {
            return 1;
        }
    }
    return 0;
}

void print_grid() {
    for(int i = 0; i < N*N; i++) {
        if(i%N == 0) {
            printf("\n");
        }
        if(grid[i]) {
            printf("O ");
        } else {
            printf("- ");
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL)); // seed the random number generator

    initialize_grid();

    while(!percolates()) {
        // choose a random site to open
        int site = rand() % (N*N);
        int row = site / N;
        int col = site % N;
        if(!grid[site]) {
            open_site(row, col);
        }
    }

    printf("Percolation threshold: %.2f\n", (float)open_sites / (N*N));

    print_grid();

    return 0;
}