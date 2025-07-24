//FormAI DATASET v1.0 Category: Game ; Style: protected
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int main(void) {
    int grid[ROWS][COLS];
    int i, j;

    srand(time(NULL)); // Seed the random number generator with the current time

    // Fill the grid with random numbers between 0 and 9
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            grid[i][j] = rand() % 10;
        }
    }

    // Print the grid
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Find the maximum value in the grid
    int max_val = -1; // Start with a value that is guaranteed to be less than anything in the array
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (grid[i][j] > max_val) {
                max_val = grid[i][j];
            }
        }
    }

    printf("The maximum value in the grid is %d\n", max_val);

    return 0;
}