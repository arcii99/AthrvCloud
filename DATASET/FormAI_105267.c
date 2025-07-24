//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 5
#define COL 5

int grid[ROW][COL];
int start_x, start_y, end_x, end_y;
bool visited[ROW][COL];

// function to initialize visited array
void initializeVisited()
{
    for(int row=0; row<ROW; row++)
    {
        for(int col=0; col<COL; col++)
        {
            visited[row][col] = false;
        }
    }
}

// function to print the grid
void printGrid()
{
    for(int row=0; row<ROW; row++)
    {
        for(int col=0; col<COL; col++)
        {
            if(grid[row][col] == 1)
            {
                printf("# ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// function to check if row and col are valid
bool isValid(int row, int col)
{
    return (row >= 0) && (col >= 0) && (row < ROW) && (col < COL);
}

// function to check if cell is unblocked
bool isUnblocked(int row, int col)
{
    return grid[row][col] == 0;
}

// function to check if cell is the destination
bool isDestination(int row, int col)
{
    return (row == end_x) && (col == end_y);
}

// function to calculate Manhattan distance
int calculateManhattanDistance(int row, int col)
{
    return abs(row - end_x) + abs(col - end_y);
}

// function to find the shortest path to destination
bool findShortestPath(int row, int col)
{
    if(!isValid(row, col))
    {
        return false;
    }

    if(visited[row][col])
    {
        return false;
    }

    if(!isUnblocked(row, col))
    {
        return false;
    }

    if(isDestination(row, col))
    {
        return true;
    }

    visited[row][col] = true;

    if(findShortestPath(row-1, col))
    {
        return true;
    }

    if(findShortestPath(row+1, col))
    {
        return true;
    }

    if(findShortestPath(row, col-1))
    {
        return true;
    }

    if(findShortestPath(row, col+1))
    {
        return true;
    }

    visited[row][col] = false;

    return false;
}

// function to generate random coordinates
int generateRandomCoord()
{
    return rand() % (ROW-2) + 1;
}

int main()
{
    srand(time(NULL));

    // initialize the grid to be empty
    for(int row=0; row<ROW; row++)
    {
        for(int col=0; col<COL; col++)
        {
            grid[row][col] = 0;
        }
    }

    // randomly generate start and end coordinates
    start_x = generateRandomCoord();
    start_y = generateRandomCoord();
    end_x = generateRandomCoord();
    end_y = generateRandomCoord();

    // initialize visited array
    initializeVisited();

    // mark start and end points in grid
    grid[start_x][start_y] = 2;
    grid[end_x][end_y] = 2;

    // randomly generate obstacles in grid
    int numObstacles = (ROW * COL) / 4;
    int count = 0;
    while(count < numObstacles)
    {
        int row = generateRandomCoord();
        int col = generateRandomCoord();

        if(grid[row][col] == 0)
        {
            grid[row][col] = 1;
            count++;
        }
    }

    // print the grid
    printf("Grid:\n");
    printGrid();

    // find the shortest path
    printf("Finding shortest path...\n");
    if(findShortestPath(start_x, start_y))
    {
        // mark the shortest path in grid
        int row = end_x;
        int col = end_y;
        while(!(row == start_x && col == start_y))
        {
            grid[row][col] = 3;

            if(isValid(row-1, col) && visited[row-1][col] && calculateManhattanDistance(row-1, col) < calculateManhattanDistance(row, col))
            {
                row--;
                continue;
            }

            if(isValid(row+1, col) && visited[row+1][col] && calculateManhattanDistance(row+1, col) < calculateManhattanDistance(row, col))
            {
                row++;
                continue;
            }

            if(isValid(row, col-1) && visited[row][col-1] && calculateManhattanDistance(row, col-1) < calculateManhattanDistance(row, col))
            {
                col--;
                continue;
            }

            if(isValid(row, col+1) && visited[row][col+1] && calculateManhattanDistance(row, col+1) < calculateManhattanDistance(row, col))
            {
                col++;
                continue;
            }
        }

        // mark start and end points in grid
        grid[start_x][start_y] = 2;
        grid[end_x][end_y] = 2;

        // print the grid with the shortest path
        printf("Shortest Path:\n");
        printGrid();
    }
    else
    {
        printf("No path found.\n");
    }

    return 0;
}