//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#define ROWS 10
#define COLS 10

int maze[ROWS][COLS] = 
{
    {0, 1, 1, 1, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
    {0, 0, 0, 0, 0, 1, 1, 1, 1, 0},
    {1, 1, 1, 1, 0, 1, 0, 0, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 0, 0},
    {0, 1, 0, 0, 0, 1, 0, 1, 0, 0},
    {0, 1, 0, 1, 1, 1, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void printMaze()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            if (maze[i][j] == 0) printf("#");
            else printf(" ");
        }
        printf("\n");
    }
}

int findPath(int row, int col)
{
    if (row >= 0 && col >= 0 && row < ROWS && col < COLS)
    {
        if (maze[row][col] == 2) return 1; // goal found
        else if (maze[row][col] == 1) {
            maze[row][col] = 3; // mark as visited
            if (findPath(row - 1, col)) return 1;
            if (findPath(row, col + 1)) return 1;
            if (findPath(row + 1, col)) return 1;
            if (findPath(row, col - 1)) return 1;
            maze[row][col] = 0; // mark as dead end
        }
    }
    return 0;
}

int main(int argc, char *argv[])
{
    int row, col;

    printf("Welcome to the Maze Route Finder!\n\n");
    printMaze();

    printf("Enter the starting row: ");
    scanf("%d", &row);
    printf("Enter the starting column: ");
    scanf("%d", &col);

    if (findPath(row, col)) {
        printf("\nPath found!\n\n");
        printMaze();
    }
    else
        printf("\nNo path found.\n\n");

    return 0;
}