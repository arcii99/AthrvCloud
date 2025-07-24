//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW_SIZE 5
#define COL_SIZE 5

// Function to print the maze
void printMaze(char maze[ROW_SIZE][COL_SIZE])
{
    for (int i = 0; i < ROW_SIZE; i++) {
        printf("%s\n", maze[i]);
    }
    printf("\n");
}

// Function to check if the move is valid
bool isMoveValid(char maze[ROW_SIZE][COL_SIZE], int rowIndex, int colIndex)
{
    if (rowIndex >= 0 && rowIndex < ROW_SIZE && colIndex >= 0 && colIndex < COL_SIZE && maze[rowIndex][colIndex] == '.') {
        return true;
    }
    return false;
}

// Function to find the route in maze
bool findRoute(char maze[ROW_SIZE][COL_SIZE], int rowIndex, int colIndex, int destRow, int destCol)
{
    if (rowIndex == destRow && colIndex == destCol) {
        maze[rowIndex][colIndex] = '*';
        printMaze(maze);
        return true;
    }

    if (isMoveValid(maze, rowIndex, colIndex)) {
        maze[rowIndex][colIndex] = '*';

        // move right
        if (findRoute(maze, rowIndex, colIndex + 1, destRow, destCol)) {
            return true;
        }

        // move down
        if (findRoute(maze, rowIndex + 1, colIndex, destRow, destCol)) {
            return true;
        }

        // move left
        if (findRoute(maze, rowIndex, colIndex - 1, destRow, destCol)) {
            return true;
        }

        // move up
        if (findRoute(maze, rowIndex - 1, colIndex, destRow, destCol)) {
            return true;
        }

        // backtrack
        maze[rowIndex][colIndex] = '.';
    }

    return false;
}

int main()
{
    char maze[ROW_SIZE][COL_SIZE] = { { '.', '.', '.', 'X', '.' },
                                      { '.', 'X', '.', 'X', '.' },
                                      { '.', 'X', '.', '.', '.' },
                                      { '.', 'X', 'X', 'X', '.' },
                                      { '.', '.', '.', '.', '.' } };

    int srcRow = 0, srcCol = 0, destRow = 4, destCol = 4;

    printf("Maze:\n");
    printMaze(maze);

    printf("Route:\n");
    if (!findRoute(maze, srcRow, srcCol, destRow, destCol)) {
        printf("No route found!");
    }

    return 0;
}