//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include<stdio.h>

#define ROW 10
#define COL 10

int maze[ROW][COL] = { {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                       {1, 1, 0, 1, 1, 1, 1, 1, 1, 0},
                       {0, 1, 1, 1, 0, 0, 0, 0, 1, 0},
                       {0, 0, 0, 1, 0, 1, 1, 1, 1, 0},
                       {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                       {0, 1, 1, 1, 1, 1, 0, 1, 1, 1},
                       {0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
                       {0, 1, 1, 1, 0, 1, 1, 1, 0, 1},
                       {0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
                       {0, 1, 1, 1, 1, 1, 1, 1, 1, 1} };

int visited[ROW][COL] = { {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                          {0, 0, 0, 0, 0, 0, 0, 0, 0, 0} };

int isSafe(int row, int col)
{
    if(row>=0 && row<ROW && col>=0 && col<COL && maze[row][col] && !visited[row][col])
        return 1;
    return 0;
}

void printPath(int path[][COL], int row, int col)
{
    if(row == 0 && col == 0)
    {
        printf("(%d,%d) ", row, col);
        return;
    }
    printPath(path, path[row][col]/COL, path[row][col]%COL);
    printf("(%d,%d) ", row, col);
}

int findPath(int row, int col, int path[][COL])
{
    visited[row][col] = 1;

    if(row == ROW-1 && col == COL-1)
        return 1;

    int newRow, newCol;
    if(isSafe(row+1, col))
    {
        newRow = row+1;
        newCol = col;
        path[newRow][newCol] = row*COL + col;
        if(findPath(newRow, newCol, path))
            return 1;
    }

    if(isSafe(row-1, col))
    {
        newRow = row-1;
        newCol = col;
        path[newRow][newCol] = row*COL + col;
        if(findPath(newRow, newCol, path))
            return 1;
    }

    if(isSafe(row, col+1))
    {
        newRow = row;
        newCol = col+1;
        path[newRow][newCol] = row*COL + col;
        if(findPath(newRow, newCol, path))
            return 1;
    }

    if(isSafe(row, col-1))
    {
        newRow = row;
        newCol = col-1;
        path[newRow][newCol] = row*COL + col;
        if(findPath(newRow, newCol, path))
            return 1;
    }

    return 0;
}

int main()
{
    int path[ROW][COL] = { {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1},
                           {-1, -1, -1, -1, -1, -1, -1, -1, -1, -1} };

    if(findPath(0,0,path))
        printPath(path, ROW-1, COL-1);
    else
        printf("Path does not exist!");

    return 0;
}