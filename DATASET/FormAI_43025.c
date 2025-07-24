//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define ROWS 10
#define COLS 10
#define THRESHOLD 0.5

// Declare functions
void printGrid(int grid[ROWS][COLS]);
void simulatePercolation(int grid[ROWS][COLS]);

int main() {
    
    // Seed the random number generator
    srand(time(NULL));
    
    // Initialize the grid with random values
    int grid[ROWS][COLS];
    
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            double randnum = (double) rand() / RAND_MAX;
            if (randnum < THRESHOLD) {
                grid[i][j] = 0;
            } else {
                grid[i][j] = 1;
            }
        }
    }
    
    // Print the initial grid
    printGrid(grid);
    
    // Simulate percolation and print the final grid
    simulatePercolation(grid);
    printGrid(grid);
    
    return 0;
}

void printGrid(int grid[ROWS][COLS]) {
    printf("Current Grid:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

void simulatePercolation(int grid[ROWS][COLS]) {
    
    // Initialize arrays to keep track of clusters
    int cluster[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cluster[i][j] = 0;
        }
    }
    
    // Label clusters with flood fill algorithm
    int label = 1;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j] == 1 && cluster[i][j] == 0) {
                int queue[ROWS*COLS][2];
                int front = 0;
                int back = 0;
                queue[back][0] = i;
                queue[back][1] = j;
                cluster[i][j] = label;
                while (front <= back) {
                    int curr_i = queue[front][0];
                    int curr_j = queue[front][1];
                    front++;
                    if (curr_i > 0 && grid[curr_i-1][curr_j] == 1 && cluster[curr_i-1][curr_j] == 0) {
                        back++;
                        queue[back][0] = curr_i-1;
                        queue[back][1] = curr_j;
                        cluster[curr_i-1][curr_j] = label;
                    }
                    if (curr_i < ROWS-1 && grid[curr_i+1][curr_j] == 1 && cluster[curr_i+1][curr_j] == 0) {
                        back++;
                        queue[back][0] = curr_i+1;
                        queue[back][1] = curr_j;
                        cluster[curr_i+1][curr_j] = label;
                    }
                    if (curr_j > 0 && grid[curr_i][curr_j-1] == 1 && cluster[curr_i][curr_j-1] == 0) {
                        back++;
                        queue[back][0] = curr_i;
                        queue[back][1] = curr_j-1;
                        cluster[curr_i][curr_j-1] = label;
                    }
                    if (curr_j < COLS-1 && grid[curr_i][curr_j+1] == 1 && cluster[curr_i][curr_j+1] == 0) {
                        back++;
                        queue[back][0] = curr_i;
                        queue[back][1] = curr_j+1;
                        cluster[curr_i][curr_j+1] = label;
                    }
                }
                label++;
            }
        }
    }
    
    // Check if top and bottom clusters connect
    int topConnected = 0;
    int bottomConnected = 0;
    for (int j = 0; j < COLS; j++) {
        if (cluster[0][j] > 0) {
            topConnected = 1;
        }
        if (cluster[ROWS-1][j] > 0) {
            bottomConnected = 1;
        }
    }
    
    // Fill in percolated clusters and empty non-percolated clusters
    if (topConnected && bottomConnected) {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (cluster[i][j] > 0) {
                    grid[i][j] = 2;
                } else {
                    grid[i][j] = 0;
                }
            }
        }
    } else {
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                grid[i][j] = 0;
            }
        }
    }
}