//FormAI DATASET v1.0 Category: Robot movement control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>

// Constants
#define GRID_SIZE 10
#define MAX_COMMANDS 100

// Function prototypes
void printGrid(int grid[GRID_SIZE][GRID_SIZE]);
void executeCommands(int grid[GRID_SIZE][GRID_SIZE], char commands[MAX_COMMANDS]);

int main() {
    // Initialize the grid with all zeros
    int grid[GRID_SIZE][GRID_SIZE] = {{0}};

    // Get commands from input
    char commands[MAX_COMMANDS];
    printf("Enter commands: ");
    fgets(commands, MAX_COMMANDS, stdin);

    // Execute the commands and print the final grid
    executeCommands(grid, commands);
    printGrid(grid);

    return 0;
}

// Print the current state of the grid
void printGrid(int grid[GRID_SIZE][GRID_SIZE]) {
    printf("Grid:\n");
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            if (grid[i][j] == 0) {
                printf(". ");
            } else {
                printf("# ");
            }
        }
        printf("\n");
    }
}

// Execute a sequence of commands to move the robot
void executeCommands(int grid[GRID_SIZE][GRID_SIZE], char commands[MAX_COMMANDS]) {
    int x = GRID_SIZE / 2;
    int y = GRID_SIZE / 2;
    for (int i = 0; commands[i] != '\0'; i++) {
        switch (commands[i]) {
            case 'U':
                if (y > 0) {
                    y--;
                }
                break;
            case 'D':
                if (y < GRID_SIZE - 1) {
                    y++;
                }
                break;
            case 'L':
                if (x > 0) {
                    x--;
                }
                break;
            case 'R':
                if (x < GRID_SIZE - 1) {
                    x++;
                }
                break;
            case 'M':
                if (grid[y][x] == 0) {
                    grid[y][x] = 1;
                } else {
                    grid[y][x] = 0;
                }
                break;
        }
    }
}