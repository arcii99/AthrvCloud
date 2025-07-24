//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 1, 1},
    {1, 1, 1, 1, 1, 0, 1, 1},
    {1, 0, 0, 0, 1, 0, 1, 1},
    {1, 0, 1, 0, 1, 0, 1, 1},
    {1, 0, 1, 1, 0, 0, 1, 1},
    {1, 0, 0, 0, 0, 1, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1}
};

int path[ROWS][COLS];

int findPath(int row, int col)
{
    if (row < 0 || col < 0 || row >= ROWS || col >= COLS)
        return 0;
    if (maze[row][col] == 0 || path[row][col] == 1)
        return 0;
    if (row == ROWS - 1 && col == COLS - 1)
    {
        path[row][col] = 1;
        return 1;
    }
    path[row][col] = 1;
    if (findPath(row, col + 1) || findPath(row + 1, col) ||
        findPath(row, col - 1) || findPath(row - 1, col))
        return 1;
    path[row][col] = 0;
    return 0;
}

void printPath()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            path[i][j] = 0;
        }
    }
    int start_row = 0, start_col = 0;
    if (findPath(start_row, start_col))
        printPath();
    else
        printf("No path found.\n");
    return 0;
}