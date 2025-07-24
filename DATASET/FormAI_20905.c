//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: sophisticated
/* C Percolation Simulator */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10         // size of grid
#define PROBABILITY 0.6 // probability of filling a site

typedef enum {false, true} bool;  // define boolean variable

bool grid[SIZE][SIZE]; // boolean array to store whether a site is filled or empty

int uf[SIZE*SIZE+2];   // array to represent the union-find data structure
int size[SIZE*SIZE+2]; // array to store size of component

int find(int i) {
    while (i != uf[i]) {
        uf[i] = uf[uf[i]]; // improve path compression
        i = uf[i];
    }
    return i;
}

void union_set(int p, int q) {
    int i = find(p);
    int j = find(q);
    if (i == j) return; // if already in same component, no need to union
    if (size[i] < size[j]) {
        uf[i] = j;
        size[j] += size[i];
    }
    else {
        uf[j] = i;
        size[i] += size[j];
    }
}

int main() {
    srand(time(NULL));  // seed random number generator
    int i, j, site, count = 0;
    float r;
    for (i = 0; i < SIZE*SIZE+2; i++) {
        uf[i] = i;
        size[i] = 1;
    }
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            r = (float)rand()/(float)RAND_MAX;
            if (r <= PROBABILITY) {
                grid[i][j] = true; // fill site
                site = i*SIZE+j+1; // convert 2D coordinates to 1D index
                if (i == 0) union_set(site, 0); // connect topmost sites to an imaginary site 0
                if (i == SIZE-1) union_set(site, SIZE*SIZE+1); // connect bottommost sites to an imaginary site N+1
                if (i > 0 && grid[i-1][j] == true) union_set(site, site-SIZE); // union with neighboring sites
                if (j > 0 && grid[i][j-1] == true) union_set(site, site-1);
                count++;
            }
            else grid[i][j] = false; // leave site empty
        }
    }
    printf("Percolation threshold: %f\n",(float)count/(float)(SIZE*SIZE));
    if (find(0) == find(SIZE*SIZE+1)) printf("The system percolates!\n");
    else printf("The system does not percolate.\n");
    return 0;
}