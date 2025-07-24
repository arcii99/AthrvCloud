//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void printMaze(char maze[][COLS], int rows, int cols)
{
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char maze[][COLS], int row, int col)
{
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS)
    {
        return 0;
    }
    if (maze[row][col] == '|' || maze[row][col] == '-')
    {
        return 0;
    }
    return 1;
}

int findPath(char maze[][COLS], int row, int col, int destRow, int destCol)
{
    if (maze[row][col] == '|')
    {
        return 0;
    }
    if (row == destRow && col == destCol)
    {
        maze[row][col] = '*';
        return 1;
    }
    if (isValidMove(maze, row + 1, col))
    {
        maze[row][col] = '*';
        if (findPath(maze, row + 1, col, destRow, destCol))
        {
            return 1;
        }
        maze[row][col] = ' ';
    }
    if (isValidMove(maze, row, col + 1))
    {
        maze[row][col] = '*';
        if (findPath(maze, row, col + 1, destRow, destCol))
        {
            return 1;
        }
        maze[row][col] = ' ';
    }
    if (isValidMove(maze, row - 1, col))
    {
        maze[row][col] = '*';
        if (findPath(maze, row - 1, col, destRow, destCol))
        {
            return 1;
        }
        maze[row][col] = ' ';
    }
    if (isValidMove(maze, row, col - 1))
    {
        maze[row][col] = '*';
        if (findPath(maze, row, col - 1, destRow, destCol))
        {
            return 1;
        }
        maze[row][col] = ' ';
    }
    return 0;
}


int main()
{
    char maze[ROWS][COLS] = {
        "+-+-+-+-+-+-+-+-+-+-+",
        "| | |         |     |",
        "+ +-+-+ +-+-+-+ +-+ +",
        "|     | |       |   |",
        "+-+-+ + + + +-+ + + +",
        "|   |   | | |   | | |",
        "+ +-+-+-+ + + +-+ + +",
        "|   |     | | | |   |",
        "+-+-+ +-+ + + + + +-+",
        "| |   | | | | |   | |",
        "+-+-+-+-+-+ +-+-+-+ +",
    };
    int startRow = 0, startCol = 0;
    int destRow = 5, destCol = 9;

    printf("Welcome to the Maze Route Finder!\n");
    printf("I'm here to help you navigate through the maze!\n");

    printMaze(maze, ROWS, COLS);

    if (findPath(maze, startRow, startCol, destRow, destCol))
    {
        printf("Hooray! You found your way out!\n");
        printMaze(maze, ROWS, COLS);
    }
    else
    {
        printf("Oh no! You're lost forever!\n");
    }
    return 0;
}