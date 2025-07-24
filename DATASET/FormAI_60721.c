//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 8
#define COLUMN 8

char maze[ROW][COLUMN] = {
    {"########"},
    {"#..#...#"},
    {"#.#.#.#.#"},
    {"#.#.#.#.#"},
    {"#...#.#.#"},
    {"###.#.#.#"},
    {"#.....#.#"},
    {"#########"}
};

int visited[ROW][COLUMN];

typedef struct 
{
    int row;
    int column;
} Point;

void initializeVisited()
{
    for(int i = 0; i < ROW; i++)
    {
        for(int j = 0; j < COLUMN; j++)
        {
            visited[i][j] = 0;
        }
    }
}

int isSafe(int row, int column)
{
    if(row >= 0 && row < ROW && column >= 0 && column < COLUMN && maze[row][column] != '#' && visited[row][column] == 0)
    {
        return 1;
    }
    
    return 0;
}

void printPath(Point path[], int size)
{
    printf("(0, 0) ");
    for(int i = 0; i < size; i++)
    {
        printf("-> (%d, %d) ", path[i].row, path[i].column);
    }
    printf("\n");
}

int findPath(int row, int column, Point path[], int size)
{
    if(row == ROW - 1 && column == COLUMN - 1)
    {
        printPath(path, size);
        return 1;
    }
    
    visited[row][column] = 1;
    
    if(isSafe(row + 1, column))
    {
        path[size].row = row + 1;
        path[size].column = column;
        
        if(findPath(row + 1, column, path, size+1))
        {
            return 1;
        }
    }
    
    if(isSafe(row, column + 1))
    {
        path[size].row = row;
        path[size].column = column + 1;
        
        if(findPath(row, column + 1, path, size+1))
        {
            return 1;
        }
    }
    
    if(isSafe(row - 1, column))
    {
        path[size].row = row - 1;
        path[size].column = column;
        
        if(findPath(row - 1, column, path, size+1))
        {
            return 1;
        }
    }
    
    if(isSafe(row, column - 1))
    {
        path[size].row = row;
        path[size].column = column - 1;
        
        if(findPath(row, column - 1, path, size+1))
        {
            return 1;
        }
    }
    
    visited[row][column] = 0;
    return 0;
}

int main()
{
    initializeVisited();
    
    Point path[ROW*COLUMN];
    findPath(0, 0, path, 0);
    
    return 0;
}