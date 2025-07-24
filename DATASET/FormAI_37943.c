//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MATRIX_SIZE 10

int grid[MATRIX_SIZE][MATRIX_SIZE]; // matrix to hold site info

int find(int site) {
    while (site != grid[site/MATRIX_SIZE][site%MATRIX_SIZE]) {
        grid[site/MATRIX_SIZE][site%MATRIX_SIZE] = grid[(site/MATRIX_SIZE)/MATRIX_SIZE][(site/MATRIX_SIZE)%MATRIX_SIZE];
        site = grid[site/MATRIX_SIZE][site%MATRIX_SIZE];
    }
    return site;
}

int unionSites(int site1, int site2) {
    int root1 = find(site1);
    int root2 = find(site2);

    if (root1 == root2) return 0;

    grid[root1/MATRIX_SIZE][root1%MATRIX_SIZE] = root2;
    return 1;
}

void printGrid() {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    // initialize the grid with all sites blocked
    for (int i = 0; i < MATRIX_SIZE; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            grid[i][j] = i * MATRIX_SIZE + j;
        }
    }

    int num_open_sites = 0;

    while (num_open_sites < (MATRIX_SIZE * MATRIX_SIZE / 2)) {
        int i = rand() % MATRIX_SIZE;
        int j = rand() % MATRIX_SIZE;

        if (grid[i][j] == i * MATRIX_SIZE + j) {
            grid[i][j] = -1; // -1 means site is open
            num_open_sites++;

            // check neighbors for connection
            if (i > 0 && grid[i-1][j] == -1) unionSites(i*MATRIX_SIZE+j, (i-1)*MATRIX_SIZE+j);
            if (i < MATRIX_SIZE-1 && grid[i+1][j] == -1) unionSites(i*MATRIX_SIZE+j, (i+1)*MATRIX_SIZE+j);
            if (j > 0 && grid[i][j-1] == -1) unionSites(i*MATRIX_SIZE+j, i*MATRIX_SIZE+j-1);
            if (j < MATRIX_SIZE-1 && grid[i][j+1] == -1) unionSites(i*MATRIX_SIZE+j, i*MATRIX_SIZE+j+1);
        }
    }

    printf("Percolation Simulator:\n");
    printf("(0 means blocked and -1 means open)\n\n");
    printGrid();

    // check if top row and bottom row are connected
    for (int j = 0; j < MATRIX_SIZE; j++) {
        if (grid[0][j] == -1 && grid[MATRIX_SIZE-1][j] == -1) {
            if (find(j) == find((MATRIX_SIZE-1)*MATRIX_SIZE+j)) {
                printf("\nThe system percolates!\n");
                return 0;
            }
        }
    }
    printf("\nThe system does not percolate.\n");
    return 0;
}