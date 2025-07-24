//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Size of the grid
#define THRESHOLD 0.6 // Percolation threshold

// Function prototype
void initialize_grid(int grid[][SIZE]);
int percolates(int grid[][SIZE]);

int main()
{
    int grid[SIZE][SIZE];
    int i, j, count;
    float occupancy;

    srand(time(NULL)); // Seed the random number generator

    // Generate random occupancy until percolation is achieved
    do {
        initialize_grid(grid);
        count = 0;
        for (i = 0; i < SIZE; i++) {
            for (j = 0; j < SIZE; j++) {
                if (grid[i][j] == 1) count++;
            }
        }
        occupancy = (float) count / (SIZE * SIZE);
    } while (occupancy < THRESHOLD || !percolates(grid));

    // Print the final grid
    printf("Final grid:\n");
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Print the final results
    printf("Percolation achieved with %.2f%% occupancy\n", occupancy * 100);

    return 0;
}

void initialize_grid(int grid[][SIZE])
{
    int i, j;
    float rand_num;
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            rand_num = (float) rand() / RAND_MAX; // Generate a random number between 0 and 1
            if (rand_num < THRESHOLD) grid[i][j] = 1;
            else grid[i][j] = 0;
        }
    }
}

int percolates(int grid[][SIZE])
{
    int i, j;
    int top = 0, bottom = 0;

    // Check if the top row is connected to the bottom row
    for (j = 0; j < SIZE; j++) {
        if (grid[0][j] == 1) {
            top = 1;
            break;
        }
    }
    for (j = 0; j < SIZE; j++) {
        if (grid[SIZE-1][j] == 1) {
            bottom = 1;
            break;
        }
    }
    if (top && bottom) return 1;

    return 0;
}