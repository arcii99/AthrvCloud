//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: light-weight
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generateMaze(int rows, int cols);

int main()
{
    srand(time(NULL)); // Seeding random number generator with current system time
    int rows = 10;
    int cols = 10;
    generateMaze(rows, cols); // Generating maze with 10 rows and 10 columns
    return 0;
}

void generateMaze(int rows, int cols)
{
    int maze[rows][cols];
    
    // Initializing maze with all walls
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            maze[i][j] = 1;
        }
    }
    
    int startX = rand() % rows; // Starting cell x-coordinate
    int startY = rand() % cols; // Starting cell y-coordinate
    maze[startX][startY] = 0; // Setting starting cell as open
    
    int visitedCells = 1; // Number of visited cells
    int totalCells = rows * cols; // Total number of cells in maze
    
    while(visitedCells < totalCells)
    {
        int x = rand() % rows; // Random x-coordinate for new cell
        int y = rand() % cols; // Random y-coordinate for new cell
        
        // Check if cell is already visited
        if(maze[x][y] == 0)
        {
            continue;
        }
        
        // Check if adjacent cells are visited
        if((x > 0 && maze[x-1][y] == 0) || (x < rows-1 && maze[x+1][y] == 0) ||
            (y > 0 && maze[x][y-1] == 0) || (y < cols-1 && maze[x][y+1] == 0))
        {
            maze[x][y] = 0; // Set new cell as open
            visitedCells++; // Increase visited cells count
        }
    }
    
    // Printing maze
    for(int i=0; i<rows; i++)
    {
        for(int j=0; j<cols; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("[]");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}