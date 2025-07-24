//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 10
#define COLS 10

// Define the different states a site can be in
#define BLOCKED 0
#define OPEN 1

// Define the different states the system can be in
#define PERCOLATED 2
#define NOT_PERCOLATED 3

// Define a struct to hold information about each site
typedef struct {
    int state;
    int parent;
} site;

// Define function prototypes
int findRoot(int i, site *sites);
void unionSites(int p, int q, site *sites);
int percolate(site *sites);
void printGrid(site *sites);

// Main function
int main() {
    srand(time(NULL));
    site sites[ROWS*COLS];

    // Initialize sites as blocked
    for(int i = 0; i < ROWS*COLS; i++) {
        sites[i].state = BLOCKED;
        sites[i].parent = -1;
    }

    // Open the top row randomly
    for(int j = 0; j < COLS; j++) {
        int i = rand() % ROWS;
        if(sites[i*COLS+j].state == BLOCKED) {
            sites[i*COLS+j].state = OPEN;
            sites[i*COLS+j].parent = i*COLS+j;
        }
    }

    // Percolate the system
    int state = percolate(sites);

    // Print the final state of the system
    if(state == PERCOLATED) {
        printf("The system percolated\n");
    } else {
        printf("The system did not percolate\n");
    }

    // Print the final grid
    printGrid(sites);

    return 0;
}

// Find the root of a site in the union-find data structure
int findRoot(int i, site *sites) {
    int p = sites[i].parent;
    if(p == i) {
        return i;
    }
    return findRoot(p, sites);
}

// Union two sites in the union-find data structure
void unionSites(int p, int q, site *sites) {
    int rootP = findRoot(p, sites);
    int rootQ = findRoot(q, sites);
    sites[rootQ].parent = rootP;
}

// Percolate the system
int percolate(site *sites) {
    // Open the bottom row
    for(int j = 0; j < COLS; j++) {
        if(sites[(ROWS-1)*COLS+j].state == OPEN) {
            int root1 = findRoot((ROWS-1)*COLS+j, sites);
            int root2 = findRoot(j, sites);
            unionSites(root1, root2, sites);
        }
    }

    // Check if the system percolated
    for(int j = 0; j < COLS; j++) {
        if(sites[j].state == OPEN) {
            int root1 = findRoot(j, sites);
            for(int k = (ROWS-1)*COLS+j; k >= ROWS*COLS-COLS; k -= COLS) {
                if(sites[k].state == OPEN) {
                    int root2 = findRoot(k, sites);
                    if(root1 == root2) {
                        return PERCOLATED;
                    }
                }
            }
        }
    }

    return NOT_PERCOLATED;
}

// Print the final grid
void printGrid(site *sites) {
    printf("The final grid is:\n");
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(sites[i*COLS+j].state == BLOCKED) {
                printf("# ");
            } else if(sites[i*COLS+j].state == OPEN) {
                printf("O ");
            } else {
                printf("~ ");
            }
        }
        printf("\n");
    }
}