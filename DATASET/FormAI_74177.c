//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#define ROW 5
#define COL 5

int maze[ROW][COL] = {
    { 1, 1, 0, 0, 0 },
    { 1, 1, 0, 0, 0 },
    { 1, 1, 1, 1, 1 },
    { 0, 0, 0, 0, 1 },
    { 0, 0, 0, 0, 1 }
};

int path[ROW][COL] = { 0 };

int isValid(int row, int col)
{
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && maze[row][col];
}

void printPath()
{
    for(int i=0;i<ROW;i++){
        for(int j=0;j<COL;j++){
            printf("%d ", path[i][j]);
        }
        printf("\n");
    }
}

int solveMaze(int row, int col)
{
   
    if (row == ROW - 1 && col == COL - 1 && maze[row][col])
    {
        path[row][col] = 1;
        return 1;
    }

    if (isValid(row, col))
    {
        path[row][col] = 1;

        if (solveMaze(row + 1, col))
        {
            return 1;
        }

        if (solveMaze(row, col + 1))
        {
            return 1;
        }

   
        path[row][col] = 0;
        return 0;
    }

    return 0;
}

int main()
{
    if (solveMaze(0, 0))
    {
        printf("Maze Solved Successfully!\n");
        printf("Path Solution:\n");
        printPath();
    }
    else
    {
        printf("Unable to Solve Maze :(\n");
    }

    return 0;
}