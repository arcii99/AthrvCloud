//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

int grid[MAX_SIZE][MAX_SIZE]; // grid used for percolation

void initializeGrid() {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            grid[i][j] = 0; // initialize all grid cells as blocked
        }
    }
}

void printGrid() {
    int i, j;
    printf("\n");
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j] == 1) {
                printf("1 ");
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int ufFind(int x, int y, int parent[], int size[]) {
    int index = x * MAX_SIZE + y;
    while (index != parent[index]) {
        parent[index] = parent[parent[index]];
        index = parent[index];
    }
    return index;
}

void ufUnion(int p, int q, int parent[], int size[]) {
    int rootP = ufFind(p/MAX_SIZE, p%MAX_SIZE, parent, size);
    int rootQ = ufFind(q/MAX_SIZE, q%MAX_SIZE, parent, size);
    if (rootP == rootQ) {
        return;
    }
    if (size[rootP] < size[rootQ]) {
        parent[rootP] = rootQ;
        size[rootQ] += size[rootP];
    } else {
        parent[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
}

int percolates() {
    int parent[MAX_SIZE*MAX_SIZE], size[MAX_SIZE*MAX_SIZE];
    int i, j, k;
    for (i = 0; i < MAX_SIZE*MAX_SIZE; i++) {
        parent[i] = i;
        size[i] = 1; // set initial size as 1
    }
    // connect first row to virtual top site
    for (i = 0; i < MAX_SIZE; i++) {
        if (grid[0][i]) {
            ufUnion(i, MAX_SIZE*MAX_SIZE-1, parent, size);
        }
    }
    // connect adjacent open sites
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            if (grid[i][j]) {
                // connect with top site
                if (i > 0 && grid[i-1][j]) {
                    ufUnion(i*MAX_SIZE+j, (i-1)*MAX_SIZE+j, parent, size);
                }
                // connect with bottom site
                if (i < MAX_SIZE-1 && grid[i+1][j]) {
                    ufUnion(i*MAX_SIZE+j, (i+1)*MAX_SIZE+j, parent, size);
                }
                // connect with left site
                if (j > 0 && grid[i][j-1]) {
                    ufUnion(i*MAX_SIZE+j, i*MAX_SIZE+j-1, parent, size);
                }
                // connect with right site
                if (j < MAX_SIZE-1 && grid[i][j+1]) {
                    ufUnion(i*MAX_SIZE+j, i*MAX_SIZE+j+1, parent, size);
                }
            }
        }
    }
    // check if bottom site is connected to top site
    if (ufFind(MAX_SIZE-1, MAX_SIZE-1, parent, size) == ufFind(MAX_SIZE*MAX_SIZE-1, 0, parent, size)) {
        return 1; // percolates
    } else {
        return 0; // does not percolate
    }
}

int main() {
    srand(time(NULL));
    initializeGrid();
    int i, j, n, p, q;
    printf("Simulation starting...\n");
    for (n = 0; n < MAX_SIZE * MAX_SIZE / 2; n++) {
        i = rand() % MAX_SIZE;
        j = rand() % MAX_SIZE;
        grid[i][j] = 1; // open a random cell
        if (percolates()) {
            printf("System percolates after %d sites opened!\n", n+1);
            break;
        }
    }
    if (n == MAX_SIZE * MAX_SIZE / 2) {
        printf("System does not percolate after %d sites opened!\n", n);
    }
    printGrid(); // print final grid
    return 0;
}