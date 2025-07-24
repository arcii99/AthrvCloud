//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 1000 // Maximum size of grid

bool grid[MAX_SIZE][MAX_SIZE]; // Global 2D array representing the grid

// Function to initialize the grid
void initGrid(int n, float p) {
    srand(n); // Set seed for random number generator
    
    // Set each cell in grid to open or closed according to given probability
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            float r = (float) rand() / (float) RAND_MAX;
            if (r <= p) {
                grid[i][j] = true; // open
            } else {
                grid[i][j] = false; // closed
            }
        }
    }
}

// Function to print the grid
void printGrid(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Function to check if cell is open
bool isOpen(int x, int y) {
    if (x < 0 || x >= MAX_SIZE || y < 0 || y >= MAX_SIZE) {
        return false; // Out of bounds
    }
    return grid[x][y]; // Otherwise return value of cell
}

// Function to check if grid percolates
bool doesPercolate(int n) {
    // Create temporary grid with invisible top and bottom rows for percolation check
    bool tempGrid[MAX_SIZE+2][MAX_SIZE];
    for (int j = 0; j < n; j++) {
        tempGrid[0][j] = false;
        tempGrid[n+1][j] = false;
        for (int i = 1; i < n+1; i++) {
            tempGrid[i][j] = grid[i-1][j];
        }
    }
    
    // Perform percolation check using Depth-First Search algorithm
    bool visited[MAX_SIZE+2][MAX_SIZE] = {false};
    for (int j = 0; j < n; j++) {
        if (tempGrid[1][j]) {
            // If cell in top row is open, perform DFS to check if it can reach the bottom row
            bool stack[MAX_SIZE*MAX_SIZE][2]; // Stack for DFS traversal
            int top = 0; // Top of stack
            stack[top][0] = 1; // x-coordinate of starting cell
            stack[top][1] = j; // y-coordinate of starting cell
            
            while (top >= 0) {
                int x = stack[top][0];
                int y = stack[top][1];
                top--;
                if (!visited[x][y] && tempGrid[x][y]) {
                    visited[x][y] = true;
                    if (x == n+1) {
                        return true; // If DFS reaches bottom row, grid percolates
                    }
                    if (y-1 >= 0) {
                        top++;
                        stack[top][0] = x;
                        stack[top][1] = y-1;
                    }
                    if (y+1 < n) {
                        top++;
                        stack[top][0] = x;
                        stack[top][1] = y+1;
                    }
                    if (x+1 <= n+1) {
                        top++;
                        stack[top][0] = x+1;
                        stack[top][1] = y;
                    }
                }
            }
        }
    }
    
    return false; // If DFS does not reach bottom row, grid does not percolate
}

int main() {
    int n; // Size of grid (n x n)
    float p; // Probability of each cell being open
    
    printf("Enter size of grid: ");
    scanf("%d", &n);
    
    printf("Enter probability of each cell being open (between 0 and 1): ");
    scanf("%f", &p);
    
    initGrid(n, p);
    printf("Initial grid:\n");
    printGrid(n);
    
    if (doesPercolate(n)) {
        printf("The grid percolates!\n");
    } else {
        printf("The grid does not percolate.\n");
    }
    
    return 0;
}