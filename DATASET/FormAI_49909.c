//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20 // Define the size of the grid

int uf[N * N]; // 1D array to represent the grid
int open[N * N]; // Binary array to track whether the site is open or not
int count = 0; // Count the number of open sites

// Function to find the root element of a given element
int root(int i) {
    while (i != uf[i])
        i = uf[i];
    return i;
}

// Function to check if two elements are in the same component
int connected(int p, int q) {
    return root(p) == root(q);
}

// Function to unify two elements in the same component
void unionize(int p, int q) {
    int i = root(p);
    int j = root(q);
    uf[i] = j;
}

// Function to check if the given indices are within the grid
int valid(int row, int col) {
    return row >= 0 && col >= 0 && row < N && col < N;
}

// Function to open a site and connect it to its neighbors if they are open
void openSite(int row, int col) {
    int i = row * N + col;
    open[i] = 1;
    count++;
    if (valid(row - 1, col) && open[(row - 1) * N + col])
        unionize(i, (row - 1) * N + col);
    if (valid(row + 1, col) && open[(row + 1) * N + col])
        unionize(i, (row + 1) * N + col);
    if (valid(row, col - 1) && open[row * N + col - 1])
        unionize(i, row * N + col - 1);
    if (valid(row, col + 1) && open[row * N + col + 1])
        unionize(i, row * N + col + 1);
}

// Function to check if the percolation has occurred
int percolates(void) {
    for (int i = N * (N - 1); i < N * N; i++)
        if (open[i] && connected(i, 0))
            return 1;
    return 0;
}

int main(void) {
    srand(time(NULL));
    for (int i = 0; i < N * N; i++)
        uf[i] = i; // Initially, all elements are their own roots
    
    // Open random sites until the percolation occurs
    while (!percolates()) {
        int row = rand() % N;
        int col = rand() % N;
        if (!open[row * N + col])
            openSite(row, col);
    }

    // Print the grid
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (open[i * N + j])
                printf(" ");
            else
                printf("#");
        }
        printf("\n");
    }
    printf("The percolation threshold is %f\n", (float) count / (N * N));
    return 0;
}