//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 // grid size
#define P 0.5 // probability of site being open

int uf[N*N]; // create a 1D array for the grid

// function to find the root of the cluster
int root(int i) {
    while (i != uf[i]) {
        uf[i] = uf[uf[i]]; // path compression
        i = uf[i];
    }
    return i;
}

// function to join two clusters
void join(int p, int q) {
    int rootp = root(p);
    int rootq = root(q);
    uf[rootp] = rootq;
}

// function to check if two sites are connected
int connected(int p, int q) {
    return root(p) == root(q);
}

int main() {
    // initialize grid
    int i, j, site;
    srand(time(0));
    for (i = 0; i < N*N; i++) {
        uf[i] = i;
    }
    // open sites with given probability
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            site = i*N + j;
            if ((double) rand()/RAND_MAX < P) {
                uf[site] = -1;
            }
        }
    }
    // connect open sites
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            site = i*N + j;
            if (uf[site] == -1) { // site is open
                if (i > 0 && uf[site-N] == -1) // top neighbor
                    join(site, site-N);
                if (j < N-1 && uf[site+1] == -1) // right neighbor
                    join(site, site+1);
                if (i < N-1 && uf[site+N] == -1) // bottom neighbor
                    join(site, site+N);
                if (j > 0 && uf[site-1] == -1) // left neighbor
                    join(site, site-1);
            }
        }
    }
    // check if top and bottom are connected
    int top, bottom, connected_flag = 0;
    top = N*N; // virtual top site
    bottom = N*N+1; // virtual bottom site
    for (i = 0; i < N; i++) {
        site = i*N;
        if (uf[site] == -1) {
            join(top, site);
        }
        site = i*N + N-1;
        if (uf[site] == -1) {
            join(bottom, site);
        }
    }
    if (connected(top, bottom)) {
        connected_flag = 1;
    }
    // print statement
    if (connected_flag) {
        printf("Percolation has occurred!\n");
    }
    else {
        printf("Percolation has not occurred.\n");
    }
    // end program
    return 0;
}