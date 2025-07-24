//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maze dimensions
#define ROWS 15
#define COLS 15

// Array to represent the maze
int maze[ROWS][COLS];

// Recursive function to generate the maze
void generate_maze(int x, int y)
{
    // Directions to check if we can move in that direction
    int directions[4][2] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
    
    // Randomly shuffle the directions
    for(int i=0; i<4; i++)
    {
        int j = rand() % 4;
        int tempX = directions[i][0];
        int tempY = directions[i][1];
        directions[i][0] = directions[j][0];
        directions[i][1] = directions[j][1];
        directions[j][0] = tempX;
        directions[j][1] = tempY;
    }
    
    // Loop through the directions
    for(int i=0; i<4; i++)
    {
        int newX = x + directions[i][0]*2;
        int newY = y + directions[i][1]*2;
        
        if(newX >= 0 && newX < ROWS && newY >= 0 && newY < COLS && maze[newX][newY] == 0)
        {
            // Carve a path between the current cell and the new cell
            maze[newX][newY] = 1;
            maze[x + directions[i][0]][y + directions[i][1]] = 1;
            
            // Recursively call the function on the new cell
            generate_maze(newX, newY);
        }
    }
}

int main()
{
    // Initialize the random seed
    srand(time(NULL));
    
    // Set all cells to be walls
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            maze[i][j] = 0;
        }
    }
    
    // Choose a random start cell
    int startX = rand() % ROWS;
    int startY = rand() % COLS;
    
    // Carve a path between the start cell and its neighbors
    maze[startX][startY] = 1;
    generate_maze(startX, startY);
    
    // Print out the maze
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("  ");
            }
            else
            {
                printf("# ");
            }
        }
        printf("\n");
    }
    
    return 0;
}