//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 // Change this value to modify the size of the grid
#define PERCENTAGE 60 // Change this value to modify the percentage of filled squares

void initialize_grid(int *grid)
{
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (rand() % 100 < PERCENTAGE) {
            *(grid + i) = 1;
        } else {
            *(grid + i) = 0;
        }
    }
}

void print_grid(int *grid)
{
    for (int i = 0; i < SIZE * SIZE; i++) {
        if (*(grid + i) == 0) {
            printf(". ");
        } else {
            printf("# ");
        }

        if ((i + 1) % SIZE == 0) {
            printf("\n");
        }
    }
}

int check_percolation(int *grid)
{
    for (int i = (SIZE * (SIZE - 1)); i < SIZE * SIZE; i++) {
        if (*(grid + i) == 1) {
            return 1;
        }
    }

    return 0;
}

int main()
{
    srand(time(NULL)); // Set the random seed

    int grid[SIZE][SIZE] = {0}; // Initialize the grid

    initialize_grid(&grid[0][0]); // Fill the grid with random elements

    print_grid(&grid[0][0]); // Print the grid

    if (check_percolation(&grid[0][0])) { // Check if the system percolates
        printf("The system percolates!\n");
    } else {
        printf("The system does not percolate.\n");
    }

    return 0;
}