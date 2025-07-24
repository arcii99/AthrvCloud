//FormAI DATASET v1.0 Category: Maze Route Finder ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define ROWS 10
#define COLS 10

// function prototypes
bool isValid(int, int);
bool isWall(int, int);
bool isVisited(int, int);
bool findPath(int, int, int, int);

// define the maze
int maze[ROWS][COLS] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 0, 1, 1, 1, 1},
    {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 1, 0, 0, 0, 1, 1, 0, 1},
    {1, 0, 0, 0, 1, 1, 1, 0, 0, 1},
    {1, 1, 0, 1, 0, 0, 0, 1, 1, 1},
    {1, 0, 0, 1, 1, 1, 0, 0, 0, 1},
    {1, 1, 1, 0, 0, 0, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

// define the visited cells
bool visited[ROWS][COLS];

int main()
{
    // initialize all cells as unvisited
    for(int i = 0; i < ROWS; i++)
    {
        for(int j = 0; j < COLS; j++)
        {
            visited[i][j] = false;
        }
    }

    // call the findPath function to find a path from (1, 1) to (8, 8)
    bool result = findPath(1, 1, 8, 8);

    // output the result
    if(result)
    {
        printf("Path found!\n");
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}

// checks if a cell is valid
bool isValid(int row, int col)
{
    if(row < 0 || col < 0 || row >= ROWS || col >= COLS)
        return false;
    else
        return true;
}

// checks if a cell is a wall
bool isWall(int row, int col)
{
    if(maze[row][col] == 1)
        return true;
    else
        return false;
}

// checks if a cell has already been visited
bool isVisited(int row, int col)
{
    if(visited[row][col] == true)
        return true;
    else
        return false;
}

// recursive function to find a path from start to end
bool findPath(int startRow, int startCol, int endRow, int endCol)
{
    // base case
    if(startRow == endRow && startCol == endCol)
    {
        return true;
    }

    // if the cell is invalid or a wall, return false
    if(!isValid(startRow, startCol) || isWall(startRow, startCol))
    {
        return false;
    }

    // if the cell has already been visited, return false
    if(isVisited(startRow, startCol))
    {
        return false;
    }

    // mark the current cell as visited
    visited[startRow][startCol] = true;

    // recursively check the neighbors in the order: up, right, down, left
    bool result = findPath(startRow - 1, startCol, endRow, endCol); // up
    if(!result)
    {
        result = findPath(startRow, startCol + 1, endRow, endCol); // right
    }
    if(!result)
    {
        result = findPath(startRow + 1, startCol, endRow, endCol); // down
    }
    if(!result)
    {
        result = findPath(startRow, startCol - 1, endRow, endCol); // left
    }

    // if a path has been found, return true
    if(result)
    {
        return true;
    }

    // mark the cell as unvisited and return false
    visited[startRow][startCol] = false;
    return false;
}