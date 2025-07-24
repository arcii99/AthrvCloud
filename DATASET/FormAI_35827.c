//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10      // Size of the grid
#define PROB 0.5     // Probability of site being open

int grid[SIZE][SIZE];
int uf[SIZE * SIZE];
int size[SIZE * SIZE];
int openSites = 0;

// Find function for union-find algorithm
int find(int x) {
    while (x != uf[x]) {
        uf[x] = uf[uf[x]];
        x = uf[x];
    }
    return x;
}

// Union function for union-find algorithm
void unionf(int p, int q) {
    int rootP = find(p);
    int rootQ = find(q);
    if (rootP == rootQ) return;
    if (size[rootP] < size[rootQ]) {
        uf[rootP] = rootQ;
        size[rootQ] += size[rootP];
    } else {
        uf[rootQ] = rootP;
        size[rootP] += size[rootQ];
    }
}

// Check if site (row, col) is open
int isOpen(int row, int col) {
    if (row < 0 || col < 0 || row >= SIZE || col >= SIZE) {
        return 0;
    }
    return grid[row][col] == 1;
}

// Check if site (row, col) is full
int isFull(int row, int col) {
    int p = row * SIZE + col;
    for (int i = 0; i < SIZE; i++) {
        if (uf[i] == p && grid[i / SIZE][i % SIZE] == 1) {
            return 1;
        }
    }
    return 0;
}

// Open site (row, col)
void open(int row, int col) {
    if (!isOpen(row, col)) {
        grid[row][col] = 1;
        openSites++;
        int p = row * SIZE + col;
        uf[p] = p;
        size[p] = 1;
        if (isOpen(row - 1, col)) unionf(p, p - SIZE);
        if (isOpen(row + 1, col)) unionf(p, p + SIZE);
        if (isOpen(row, col - 1)) unionf(p, p - 1);
        if (isOpen(row, col + 1)) unionf(p, p + 1);
    }
}

// Percolation function
int percolates() {
    for (int i = 0; i < SIZE; i++) {
        if (isOpen(0, i)) {
            for (int j = 0; j < SIZE; j++) {
                if (isOpen(SIZE - 1, j) && find(i) == find((SIZE - 1) * SIZE + j)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

// Print the grid
void printGrid() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 0) {
                printf(".");
            } else {
                if (isFull(i, j)) {
                    printf("X");
                } else {
                    printf("#");
                }
            }
        }
        printf("\n");
    }
}

// Main program
int main() {
    srand(time(NULL));
    // Initialize the grid, union-find array and size array
    for (int i = 0; i < SIZE * SIZE; i++) {
        uf[i] = i;
        size[i] = 0;
    }
    // Generate random sites to open
    while (!percolates()) {
        int row = rand() % SIZE;
        int col = rand() % SIZE;
        if (!isOpen(row, col)) {
            open(row, col);
        }
    }
    // Print the grid
    printGrid();
    printf("\nPercolation threshold: %f\n", (float) openSites / (SIZE * SIZE));
    return 0;
}