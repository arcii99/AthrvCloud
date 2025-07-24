//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Function to initialize maze with all walls
void initMaze(int maze[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            maze[i][j] = 1;
        }
    }
}

// Function to print maze
void printMaze(int maze[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (maze[i][j] == 1) {
                printf("X ");
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Function to generate random number
int randomNum(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

// Function to generate maze
void generateMaze(int maze[ROWS][COLS], int row, int col)
{
    maze[row][col] = 0; // mark cell as visited

    while (1) {
        int dir = randomNum(0, 3); // generate random direction

        if (dir == 0 && row > 1 && maze[row - 2][col] == 1) {
            maze[row - 1][col] = 0; // mark wall as removed
            generateMaze(maze, row - 2, col);
        }
        else if (dir == 1 && col < COLS - 2 && maze[row][col + 2] == 1) {
            maze[row][col + 1] = 0; // mark wall as removed
            generateMaze(maze, row, col + 2);
        }
        else if (dir == 2 && row < ROWS - 2 && maze[row + 2][col] == 1) {
            maze[row + 1][col] = 0; // mark wall as removed
            generateMaze(maze, row + 2, col);
        }
        else if (dir == 3 && col > 1 && maze[row][col - 2] == 1) {
            maze[row][col - 1] = 0; // mark wall as removed
            generateMaze(maze, row, col - 2);
        }

        // check if maze has been fully generated
        if (maze[1][1] == 0 && maze[ROWS - 2][COLS - 2] == 0) {
            break;
        }
    }
}

int main()
{
    int maze[ROWS][COLS];
    srand(time(NULL)); // seed random number generator
    initMaze(maze);
    generateMaze(maze, 1, 1); // start generating maze from top left corner
    printMaze(maze);
    return 0;
}