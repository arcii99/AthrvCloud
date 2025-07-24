//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10
#define NUM_TRIALS 10

// Function to initialize the grid with random values
void initializeGrid(int grid[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            grid[i][j] = rand() % 2; // Random value of 0 or 1
        }
    }
}

// Function to print the grid
void printGrid(int grid[][SIZE]) {
    int i, j;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// Function to check if the percolation occurs
int checkPercolation(int grid[][SIZE]) {
    int i, j;
    int topRow[SIZE] = {0}; // Array to store values of the top row
    for (j = 0; j < SIZE; j++) {
        topRow[j] = grid[0][j]; // Store values of the top row
        if (topRow[j] == 1) { // Check if top row has a value of 1
            int visited[SIZE][SIZE] = {0}; // Array to keep track of visited nodes
            visited[0][j] = 1; // Initial node is already visited
            int stack[SIZE * SIZE][2]; // Stack to store the nodes to be visited
            int top = 0; // Stack pointer
            stack[top][0] = 0; // Push the initial node
            stack[top][1] = j;
            while (top != -1) { // While stack is not empty
                int curRow = stack[top][0]; // Pop the top node
                int curCol = stack[top][1];
                top--;
                if (curRow == SIZE - 1) { // If a node in bottom row is reached, percolation occurs
                    return 1;
                }
                if (curCol != 0 && grid[curRow][curCol - 1] == 1 && visited[curRow][curCol - 1] == 0) {
                    visited[curRow][curCol - 1] = 1; // Mark the visited node as visited
                    top++; // Push the node onto the stack
                    stack[top][0] = curRow;
                    stack[top][1] = curCol - 1;
                }
                if (curCol != SIZE - 1 && grid[curRow][curCol + 1] == 1 && visited[curRow][curCol + 1] == 0) {
                    visited[curRow][curCol + 1] = 1;
                    top++;
                    stack[top][0] = curRow;
                    stack[top][1] = curCol + 1;
                }
                if (curRow != SIZE - 1 && grid[curRow + 1][curCol] == 1 && visited[curRow + 1][curCol] == 0) {
                    visited[curRow + 1][curCol] = 1;
                    top++;
                    stack[top][0] = curRow + 1;
                    stack[top][1] = curCol;
                }
            }
        }
    }
    return 0; // Percolation does not occur
}

int main() {
    srand(time(NULL)); // Random seed based on current time
    int numSuccess = 0; // Number of times percolation is successful
    int numTrials = 0; // Number of trials
    while (numTrials < NUM_TRIALS) {
        int grid[SIZE][SIZE] = {0}; // Initialize the grid with all 0's
        initializeGrid(grid); // Initialize the grid with random values
        printGrid(grid); // Print the initialized grid
        int percolation = checkPercolation(grid); // Check if percolation occurs
        printf("Percolation: %d\n\n", percolation);
        if (percolation == 1) {
            numSuccess++; // If percolation occurs, count it as success
        }
        numTrials++; // Increment the number of trials
    }
    printf("Success rate: %f\n", (float) numSuccess / NUM_TRIALS); // Print the success rate (fraction of successful trials)
    return 0;
}