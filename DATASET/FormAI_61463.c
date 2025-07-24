//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10
// N is the grid size
// In this example, we will use 10x10 grid

char grid[N][N]; // initialize the grid
int parent[N*N]; // initialize the parent array
int size[N*N]; // initialize the size array
int open_count = 0; // initialize the open_count variable

// find the root of the given element using weighted quick-union algorithm
int root(int i) {
    while (i != parent[i]) {
        parent[i] = parent[parent[i]];
        i = parent[i];
    }
    return i;
}

// checks if two elements are connected or not
int connected(int p, int q) {
    return root(p) == root(q);
}

// connect two elements by changing their root
void union_elements(int p, int q) {
    int root_p = root(p);
    int root_q = root(q);

    if (root_p == root_q)
        return;

    if (size[root_p] > size[root_q]) {
        parent[root_q] = root_p;
        size[root_p] += size[root_q];
    } else {
        parent[root_p] = root_q;
        size[root_q] += size[root_p];
    }
}

// open a site on the grid and connect it with its neighbors
void open_site(int i, int j) {
    int site = i*N + j;

    if (grid[i][j] == 'O')
        return;

    grid[i][j] = 'O';
    open_count++;

    if (i == 0)
        union_elements(site, N*N);

    if (i == N-1)
        union_elements(site, N*N+1);

    if (i > 0 && grid[i-1][j] == 'O')
        union_elements(site, site-N);

    if (i < N-1 && grid[i+1][j] == 'O')
        union_elements(site, site+N);

    if (j > 0 && grid[i][j-1] == 'O')
        union_elements(site, site-1);

    if (j < N-1 && grid[i][j+1] == 'O')
        union_elements(site, site+1);
}


// check if the system percolated or not
int percolates() {
    return connected(N*N, N*N+1);
}

// print the current state of the grid
void print_grid() {
    printf("\n");
    for (int i=0; i<N; i++) {
        for (int j=0; j<N; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    // initialize the parent array
    for (int i=0; i<N*N; i++) {
        parent[i] = i;
        size[i] = 1;
    }

    while (!percolates()) {
        int i = rand() % N;
        int j = rand() % N;
        open_site(i, j);
        print_grid();
    }

    printf("Percolation reached! Total sites opened: %d\n", open_count);
    return 0;
}