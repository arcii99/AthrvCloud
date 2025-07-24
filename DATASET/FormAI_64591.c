//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define SIZE 20

bool grid[SIZE][SIZE]; // The grid to hold percolation states

int parent[SIZE * SIZE]; // The array to hold the parent indices in the disjoint set

// Function to initialize the disjoint set
void initializeSet() {
    for (int i = 0; i < SIZE * SIZE; i++) {
        parent[i] = i;
    }
}

// Function to find the root of a node in the disjoint set
int find(int x) {
    if (parent[x] != x) {
        parent[x] = find(parent[x]);
    }
    return parent[x];
}

// Function to merge two nodes in the disjoint set
void merge(int x, int y) {
    int root1 = find(x);
    int root2 = find(y);
    parent[root1] = root2;
}

// Function to check if the grid percolates
bool doesPercolate() {
    for (int i = 0; i < SIZE; i++) {
        if (find(i) == find((SIZE - 1) * SIZE + i)) {
            return true;
        }
    }
    return false;
}

// Function to print the grid
void printGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j]) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    // Initialize the grid to all closed cells
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = false;
        }
    }

    // Initialize the disjoint set
    initializeSet();

    // Randomize the seed for the random number generator
    srand(time(NULL));

    // Open a random cell in the top row
    int randomColumn = rand() % SIZE;
    grid[0][randomColumn] = true;

    // Connect the top cell to its open neighbors
    if (randomColumn > 0 && grid[0][randomColumn - 1]) {
        merge(randomColumn, randomColumn - 1);
    }
    if (randomColumn < SIZE - 1 && grid[0][randomColumn + 1]) {
        merge(randomColumn, randomColumn + 1);
    }
    merge(randomColumn, SIZE * SIZE);

    // Loop through each row, opening random cells and connecting them to their open neighbors
    for (int i = 1; i < SIZE; i++) {
        int openCount = 0;
        int openIndices[SIZE];
        for (int j = 0; j < SIZE; j++) {
            if (!grid[i - 1][j]) {
                continue;
            }
            if (j > 0 && grid[i][j - 1]) {
                merge(i * SIZE + j, i * SIZE + j - 1);
            }
            if (j < SIZE - 1 && grid[i][j + 1]) {
                merge(i * SIZE + j, i * SIZE + j + 1);
            }
            if (find(i * SIZE + j) == find(SIZE * SIZE)) {
                openIndices[openCount++] = j;
            }
        }
        if (openCount > 0) {
            int chosenIndex = openIndices[rand() % openCount];
            grid[i][chosenIndex] = true;
            merge(i * SIZE + chosenIndex, SIZE * SIZE);
        }
    }

    // Print the final grid
    printGrid();

    // Check if the grid percolates and print the result
    if (doesPercolate()) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }

    return 0;
}