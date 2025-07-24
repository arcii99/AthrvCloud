//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 10
#define COL 15

// Function to display the maze
void displayMaze(char maze[][COL])
{
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

// Function to check if the current cell is within boundaries or not
bool isSafe(char maze[][COL], int posX, int posY)
{
    return (posX >= 0 && posX < ROW && posY >= 0 && posY < COL && maze[posX][posY] == ' ');
}

// Function to find the exit of the maze by recursive backtracking
bool findExit(char maze[][COL], int posX, int posY)
{
    // If we have reached the last row, then we have found the exit
    if (posX == ROW - 1) {
        return true;
    }

    // Mark the current cell as visited
    maze[posX][posY] = '.';

    // Check if we can move down
    if (isSafe(maze, posX + 1, posY)) {
        if (findExit(maze, posX + 1, posY)) {
            return true;
        }
    }

    // Check if we can move right
    if (isSafe(maze, posX, posY + 1)) {
        if (findExit(maze, posX, posY + 1)) {
            return true;
        }
    }

    // Check if we can move up
    if (isSafe(maze, posX - 1, posY)) {
        if (findExit(maze, posX - 1, posY)) {
            return true;
        }
    }

    // Check if we can move left
    if (isSafe(maze, posX, posY - 1)) {
        if (findExit(maze, posX, posY - 1)) {
            return true;
        }
    }

    // If we reach here, then there is no possible path from the current cell
    // to the exit. Hence, backtrack and mark the current cell as unvisited
    maze[posX][posY] = ' ';
    return false;
}

int main()
{
    // Create the maze
    char maze[ROW][COL] = {
        "+-+-+-+-+-+-+-+-+-+-+",
        "| |           |   | |",
        "+ +-+-+-+-+-+-+-+ + +",
        "|   | |         | | |",
        "+-+-+ + +-+-+-+-+ + +",
        "|   | |       |   | |",
        "+-+-+ + +-+-+ + +-+ +",
        "|     |     | |     |",
        "+-+-+-+-+ + + + +-+-+",
        "|     |   |   | |   |",
        "+-+-+-+-+-+-+-+ +-+-+"
    };

    // Find the exit
    if (findExit(maze, 0, 1)) {
        printf("The maze has been solved:\n");
        displayMaze(maze);
    }
    else {
        printf("There is no possible path to the exit\n");
    }

    return 0;
}