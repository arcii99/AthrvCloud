//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h>

#define GRID_SIZE 100
#define NUM_THREADS 4

// Initialize grid with random open and closed sites
void initialize(bool grid[][GRID_SIZE], double p) {
    srand(time(NULL));
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if ((double)rand() / RAND_MAX < p) {
                grid[i][j] = true;
            } else {
                grid[i][j] = false;
            }
        }
    }
}

// Print out a visual representation of the grid
void printGrid(bool grid[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j]) {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}

// Thread function for percolation simulation
void *simulatePercolation(void *arg) {
    int threadID = *(int *)arg;
    int startRow = (GRID_SIZE / NUM_THREADS) * threadID;
    int endRow = (GRID_SIZE / NUM_THREADS) * (threadID+1);
    bool grid[GRID_SIZE][GRID_SIZE];
    initialize(grid, 0.6);

    for (int i = startRow; i < endRow; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            // Check if site is open
            if (grid[i][j]) {
                // Check adjacent sites to see if any are also open
                if (i > 0 && grid[i-1][j]) {
                    grid[i][j] = false;
                } else if (i < GRID_SIZE-1 && grid[i+1][j]) {
                    grid[i][j] = false;
                } else if (j > 0 && grid[i][j-1]) {
                    grid[i][j] = false;
                } else if (j < GRID_SIZE-1 && grid[i][j+1]) {
                    grid[i][j] = false;
                }
            }
        }
    }

    // Print out grid after percolation simulation
    printf("Grid after percolation simulation by thread %d:\n", threadID);
    printGrid(grid);
    pthread_exit(NULL);
}

int main() {
    pthread_t threadIDs[NUM_THREADS];
    int threadIndex[NUM_THREADS];

    // Create threads
    for (int i = 0; i < NUM_THREADS; i++) {
        threadIndex[i] = i;
        pthread_create(&threadIDs[i], NULL, simulatePercolation, (void *)&threadIndex[i]);
    }

    // Wait for threads to finish
    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threadIDs[i], NULL);
    }

    return 0;
}