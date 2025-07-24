//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define N 10 // Grid size
#define P 0.5 // Probability of opening a site
#define TOP 0 // Virtual top site index
#define BOTTOM N*N+1 // Virtual bottom site index

int id[N*N+2]; // id[i] = component identifier of i
bool open[N*N]; // open[i] = true if site i is open
int numOpen = 0; // number of open sites

// Initialize all sites to be blocked
void init() {
    for (int i = 0; i < N*N; i++) {
        id[i] = i;
        open[i] = false;
    }
    id[TOP] = TOP; // Connect virtual top and bottom sites
    id[BOTTOM] = BOTTOM;
}

// Find the component identifier of a site
int find(int p) {
    while (p != id[p]) {
        id[p] = id[id[p]]; // Path compression
        p = id[p];
    }
    return p;
}

// Connect two sites
void connect(int p, int q) {
    int idp = find(p);
    int idq = find(q);
    if (idp == idq) return;
    id[idp] = idq;
}

// Check if two sites are connected
bool connected(int p, int q) {
    return find(p) == find(q);
}

// Open a site and connect it to its neighbors
void openSite(int i, int j) {
    int p = i*N + j;
    open[p] = true;
    numOpen++;
    if (i == 0) connect(p, TOP); // Connect to virtual top site
    if (i == N-1) connect(p, BOTTOM); // Connect to virtual bottom site
    if (i > 0 && open[(i-1)*N+j]) connect(p, (i-1)*N+j); // Connect to left neighbor
    if (i < N-1 && open[(i+1)*N+j]) connect(p, (i+1)*N+j); // Connect to right neighbor
    if (j > 0 && open[i*N+j-1]) connect(p, i*N+j-1); // Connect to top neighbor
    if (j < N-1 && open[i*N+j+1]) connect(p, i*N+j+1); // Connect to bottom neighbor
}

// Print the current state of the grid
void printGrid() {
    for (int i = 0; i < N*N; i++) {
        if (open[i]) printf("O");
        else printf("X");
        if ((i+1) % N == 0) printf("\n");
    }
}

int main() {
    srand(time(NULL));
    init();
    while (!connected(TOP, BOTTOM)) {
        int i = rand() % N;
        int j = rand() % N;
        if (!open[i*N+j]) {
            openSite(i, j); // Open a new site
            printGrid(); // Print the current state of the grid
            printf("Number of open sites: %d\n\n", numOpen);
        }
    }
    printf("Percolation threshold: %f\n", (float)numOpen/(N*N));
    return 0;
}