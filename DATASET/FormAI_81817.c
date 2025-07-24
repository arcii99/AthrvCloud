//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

// define the size of the grid and the probability of each site being open
#define SIZE 10
#define PROBABILITY 0.5

// define the states of each site in the grid
#define BLOCKED 0
#define OPEN 1
#define FULL 2

// define a structure to hold the properties of each site
typedef struct {
    int state; // blocked, open or full
    int parent; // index of the site that this site is connected to
} Site;

// define the global variables
Site grid[SIZE][SIZE];
int parentList[SIZE*SIZE];
int openSites = 0;

// function to initialize the grid with blocked sites
void initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j].state = BLOCKED;
            grid[i][j].parent = -1;
        }
    }
}

// function to randomly open some of the sites in the grid
void openRandomSites() {
    srand(time(NULL));
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if ((double) rand() / (RAND_MAX + 1) < PROBABILITY) {
                grid[i][j].state = OPEN;
                openSites++;
            }
        }
    }
}

// function to connect an open site to its neighbours
void connectSiteToNeighbours(int i, int j) {
    int parent = i * SIZE + j;
    if (i > 0 && grid[i-1][j].state == OPEN) parent = grid[i-1][j].parent;
    if (j > 0 && grid[i][j-1].state == OPEN && grid[i][j-1].parent < parent) parent = grid[i][j-1].parent;
    if (i < SIZE-1 && grid[i+1][j].state == OPEN && grid[i+1][j].parent < parent) parent = grid[i+1][j].parent;
    if (j < SIZE-1 && grid[i][j+1].state == OPEN && grid[i][j+1].parent < parent) parent = grid[i][j+1].parent;
    grid[i][j].parent = parent;
}

// function to connect all open sites in the grid
void percolate() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].state == OPEN) connectSiteToNeighbours(i, j);
        }
    }
    for (int i = 0; i < SIZE*SIZE; i++) parentList[i] = i;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].state == OPEN) {
                int p = i * SIZE + j;
                while (p != grid[p/SIZE][p%SIZE].parent) p = grid[p/SIZE][p%SIZE].parent;
                int q = grid[i][j].parent;
                while (q != grid[q/SIZE][q%SIZE].parent) q = grid[q/SIZE][q%SIZE].parent;
                if (p != q) parentList[q] = p;
            }
        }
    }
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].state == OPEN) {
                int p = i * SIZE + j;
                while (p != grid[p/SIZE][p%SIZE].parent) p = grid[p/SIZE][p%SIZE].parent;
                if (parentList[p] == p) grid[i][j].state = FULL;
            }
        }
    }
}

// function to print the state of each site in the grid
void printGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            switch (grid[i][j].state) {
                case BLOCKED:
                    printf("X ");
                    break;
                case OPEN:
                    printf("_ ");
                    break;
                case FULL:
                    printf("O ");
                    break;
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    initializeGrid();
    openRandomSites();
    percolate();
    printGrid();
    return 0;
}