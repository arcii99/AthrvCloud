//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 21 // maze height
#define COLS 41 // maze width
#define WALL 1
#define PATH 0

// Function Prototypes
void generateMaze(int maze[ROWS][COLS]);
void printMaze(int maze[ROWS][COLS]);

int main() {
    int maze[ROWS][COLS];

    // Seed random number generator
    srand(time(NULL));
    
    // Generate maze
    generateMaze(maze);

    // Print maze
    printMaze(maze);

    return 0;
}

// Function to generate maze
void generateMaze(int maze[ROWS][COLS]) {
    // Set all cells as walls
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = WALL;
        }
    }

    // Dig the path
    for (int i = 1; i < ROWS - 1; i += 2) {
        for (int j = 1; j < COLS - 1; j += 2) {
            maze[i][j] = PATH;

            int direction = rand() % 4; // Randomly select a direction
            switch (direction) {
                case 0:
                    if (i - 2 > 0) {
                        maze[i - 1][j] = PATH;
                        maze[i - 2][j] = PATH;
                    }
                    break;
                case 1:
                    if (j + 2 < COLS - 1) {
                        maze[i][j + 1] = PATH;
                        maze[i][j + 2] = PATH;
                    }
                    break;
                case 2:
                    if (i + 2 < ROWS - 1) {
                        maze[i + 1][j] = PATH;
                        maze[i + 2][j] = PATH;
                    }
                    break;
                case 3:
                    if (j - 2 > 0) {
                        maze[i][j - 1] = PATH;
                        maze[i][j - 2] = PATH;
                    }
                    break;
            }
        }
    }

    // Add entrance and exit
    maze[0][1] = PATH;
    maze[ROWS - 1][COLS - 2] = PATH;
}

// Function to print maze
void printMaze(int maze[ROWS][COLS]) {
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == WALL) {
                printf("#");
            } else {
                printf(".");
            }
        }

        printf("\n");
    }
}