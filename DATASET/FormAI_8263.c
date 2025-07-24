//FormAI DATASET v1.0 Category: Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

int main(void)
{
    // Declare variables
    int i, j, score = 0, grid[GRID_SIZE][GRID_SIZE];
    char direction;
    srand(time(NULL)); // Seed the random number generator

    // Initialize grid with random numbers
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            grid[i][j] = rand() % 10;
        }
    }

    // Print the initial grid
    printf("Score: %d\n\n", score);
    for (i = 0; i < GRID_SIZE; i++) {
        for (j = 0; j < GRID_SIZE; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }

    // Main game loop
    while (1) {
        // Ask for user direction
        printf("\nEnter direction (up, down, left, right): ");
        scanf(" %c", &direction);

        // Move numbers in the grid according to user direction
        switch (direction) {
            case 'u':
                for (i = 1; i < GRID_SIZE; i++) {
                    for (j = 0; j < GRID_SIZE; j++) {
                        if (grid[i][j] != 0 && grid[i-1][j] == 0) {
                            grid[i-1][j] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
            case 'd':
                for (i = GRID_SIZE-2; i >= 0; i--) {
                    for (j = 0; j < GRID_SIZE; j++) {
                        if (grid[i][j] != 0 && grid[i+1][j] == 0) {
                            grid[i+1][j] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
            case 'l':
                for (i = 0; i < GRID_SIZE; i++) {
                    for (j = 1; j < GRID_SIZE; j++) {
                        if (grid[i][j] != 0 && grid[i][j-1] == 0) {
                            grid[i][j-1] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
            case 'r':
                for (i = 0; i < GRID_SIZE; i++) {
                    for (j = GRID_SIZE-2; j >= 0; j--) {
                        if (grid[i][j] != 0 && grid[i][j+1] == 0) {
                            grid[i][j+1] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
            default:
                printf("Invalid direction!\n");
                continue; // Restart the loop
        }

        // Combine numbers that are adjacent to each other
        for (i = 0; i < GRID_SIZE; i++) {
            for (j = 0; j < GRID_SIZE-1; j++) {
                if (grid[i][j] == grid[i][j+1]) {
                    grid[i][j] *= 2;
                    grid[i][j+1] = 0;
                    score += grid[i][j];
                }
            }
        }

        // Move numbers in the grid again to fill the gaps created by combining numbers
        switch (direction) {
            case 'u':
                for (i = 1; i < GRID_SIZE; i++) {
                    for (j = 0; j < GRID_SIZE; j++) {
                        if (grid[i][j] != 0 && grid[i-1][j] == 0) {
                            grid[i-1][j] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
            case 'd':
                for (i = GRID_SIZE-2; i >= 0; i--) {
                    for (j = 0; j < GRID_SIZE; j++) {
                        if (grid[i][j] != 0 && grid[i+1][j] == 0) {
                            grid[i+1][j] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
            case 'l':
                for (i = 0; i < GRID_SIZE; i++) {
                    for (j = 1; j < GRID_SIZE; j++) {
                        if (grid[i][j] != 0 && grid[i][j-1] == 0) {
                            grid[i][j-1] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
            case 'r':
                for (i = 0; i < GRID_SIZE; i++) {
                    for (j = GRID_SIZE-2; j >= 0; j--) {
                        if (grid[i][j] != 0 && grid[i][j+1] == 0) {
                            grid[i][j+1] = grid[i][j];
                            grid[i][j] = 0;
                        }
                    }
                }
                break;
        }

        // Print the updated grid and score
        printf("Score: %d\n\n", score);
        for (i = 0; i < GRID_SIZE; i++) {
            for (j = 0; j < GRID_SIZE; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}