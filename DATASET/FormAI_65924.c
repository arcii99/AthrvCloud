//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function prototypes
void printMaze(int maze[ROWS][COLS]);
void generateMaze(int maze[ROWS][COLS], int row, int col);

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create maze
    int maze[ROWS][COLS];
    generateMaze(maze, 0, 0);

    // Print maze
    printMaze(maze);

    return 0;
}

// Generates a random maze using recursive division algorithm
void generateMaze(int maze[ROWS][COLS], int row, int col) {
    int i, j;

    // Fill maze with walls
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }

    // Carve out entrance and exit
    maze[0][0] = 0;
    maze[ROWS - 1][COLS - 1] = 0;

    // Apply recursive division algorithm
    if (row + 1 < ROWS - 1 && col + 1 < COLS - 1) {
        int direction = rand() % 2;

        // Horizontal cut
        if (direction == 0) {
            int cut = col + 1 + rand() % (COLS - col - 2);

            for (i = row + 1; i < ROWS - 1; i++) {
                if (i != ROWS / 2) {
                    maze[i][cut] = 0;
                }
            }

            generateMaze(maze, row, col);
            generateMaze(maze, row, cut + 1);
        }
        // Vertical cut
        else {
            int cut = row + 1 + rand() % (ROWS - row - 2);

            for (j = col + 1; j < COLS - 1; j++) {
                if (j != COLS / 2) {
                    maze[cut][j] = 0;
                }
            }

            generateMaze(maze, row, col);
            generateMaze(maze, cut + 1, col);
        }
    }
}

// Prints maze
void printMaze(int maze[ROWS][COLS]) {
    int i, j;

    printf(" ");

    for (j = 0; j < COLS * 2 - 1; j++) {
        printf("_");
    }

    printf("\n");

    for (i = 0; i < ROWS; i++) {
        printf("|");

        for (j = 0; j < COLS; j++) {
            if (maze[i][j] == 0) {
                printf(" ");
            } else {
                printf("_");
            }

            if (j < COLS - 1) {
                if (maze[i][j + 1] == 0 || maze[i][j] == 0) {
                    printf(" ");
                } else {
                    printf("|");
                }
            } else {
                printf("|");
            }
        }

        printf("\n");
    }
}