//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

// Maze Initialization
void createMaze(int maze[][COLS], int rows, int cols)
{
    int i, j;

    // Fill maze with walls
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            maze[i][j] = 1;
        }
    }

    // Create random openings
    srand(time(NULL));
    int rand_row = rand() % rows;
    int rand_col = rand() % cols;
    maze[rand_row][0] = 0;
    maze[rand_row][cols-1] = 0;

    // Create random walls
    int num_walls = rows * cols / 3;
    for (i = 0; i < num_walls; i++) {
        int row = rand() % rows;
        int col = rand() % cols;
        // Make sure the opening stays clear
        if (row == rand_row && (col == 0 || col == cols-1)) {
            continue;
        }
        maze[row][col] = 1;
    }
}

// Display the Maze
void displayMaze(int maze[][COLS], int rows, int cols)
{
    int i, j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%c", maze[i][j] == 1 ? '#' : ' ');
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROWS][COLS];
    createMaze(maze, ROWS, COLS);
    displayMaze(maze, ROWS, COLS);
    return 0;
}