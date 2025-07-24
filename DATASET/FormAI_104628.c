//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the 2D grid

int grid[SIZE][SIZE]; // Define a 2D grid to simulate the material
int visited[SIZE][SIZE]; // Define a boolean array to track visited cells

// Function to randomly generate the material
void generateMaterial() {
    srand(time(NULL)); // Seed the random number generator with the current time

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2; // Generate either 0 or 1 randomly
            visited[i][j] = 0; // Mark the cell as unvisited
        }
    }

    // Print the initial state of the material
    printf("Initial state of the material:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

// Function to check whether a given cell is valid and unvisited
int isValid(int row, int col) {
    return row >= 0 && row < SIZE && col >= 0 && col < SIZE && !visited[row][col];
}

// Function to recursively mark all connected cells as visited
void dfs(int row, int col) {
    visited[row][col] = 1; // Mark the current cell as visited

    // Recursively visit all neighboring cells if they are valid and contain 1
    if (isValid(row-1, col) && grid[row-1][col]) {
        dfs(row-1, col);
    }
    if (isValid(row, col+1) && grid[row][col+1]) {
        dfs(row, col+1);
    }
    if (isValid(row+1, col) && grid[row+1][col]) {
        dfs(row+1, col);
    }
    if (isValid(row, col-1) && grid[row][col-1]) {
        dfs(row, col-1);
    }
}

int main() {
    generateMaterial(); // Generate the initial material

    int percolates = 0; // Flag to indicate whether the material percolates
    for (int i = 0; i < SIZE; i++) {
        if (grid[0][i] && !visited[0][i]) { // Check for percolation from the top row
            dfs(0, i); // Recursively mark all connected cells as visited
        }
    }

    // Check if the bottom row contains a visited cell to determine if the material percolates
    for (int i = 0; i < SIZE; i++) {
        if (visited[SIZE-1][i]) {
            percolates = 1;
            break;
        }
    }

    // Print the final state of the material and whether it percolates
    printf("\nFinal state of the material:\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", visited[i][j]);
        }
        printf("\n");
    }
    printf("\nThe material %spercolates.\n", percolates ? "" : "does not ");

    return 0;
}