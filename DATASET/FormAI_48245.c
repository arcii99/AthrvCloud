//FormAI DATASET v1.0 Category: Robot movement control ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLUMNS 10

enum DIRECTION { UP, DOWN, LEFT, RIGHT };

int main() {
    // Initialize robot starting position and direction
    int row = 0, col = 0;
    enum DIRECTION direction = RIGHT;
    int moves = 0;

    // Initialize the grid with zeros
    int grid[ROWS][COLUMNS] = {0};

    // Randomly scatter obstacles in the grid
    srand(time(NULL));
    int obstacles = 20;
    while (obstacles) {
        int r = rand() % ROWS;
        int c = rand() % COLUMNS;
        if (grid[r][c] == 0) {
            grid[r][c] = 1;
            obstacles--;
        }
    }

    // Move the robot until it reaches the bottom right corner or runs out of moves
    while (row != ROWS - 1 || col != COLUMNS - 1) {
        // Print the current grid and robot position
        printf("Moves: %d\n", moves);
        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLUMNS; c++) {
                if (r == row && c == col)
                    printf("X ");
                else if (grid[r][c] == 1)
                    printf("# ");
                else
                    printf(". ");
            }
            printf("\n");
        }

        // Determine the next move
        int next_row = row, next_col = col;
        switch (direction) {
            case UP:
                next_row--;
                break;
            case DOWN:
                next_row++;
                break;
            case LEFT:
                next_col--;
                break;
            case RIGHT:
                next_col++;
                break;
        }

        // Check if the next move is valid and adjust direction if necessary
        if (next_row < 0 || next_row >= ROWS || next_col < 0 || next_col >= COLUMNS || grid[next_row][next_col] == 1) {
            direction = (direction + 1) % 4;
        } else {
            row = next_row;
            col = next_col;
            moves++;
        }

        // Check if the robot has run out of moves
        if (moves > ROWS * COLUMNS) {
            printf("Robot has run out of moves\n");
            break;
        }
    }

    // Print the final grid and number of moves
    printf("Final Grid:\n");
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLUMNS; c++) {
            if (grid[r][c] == 1)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
    printf("Number of Moves: %d\n", moves);

    return 0;
}