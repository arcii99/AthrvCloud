//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 15

int maze[ROWS][COLS];
int visited[ROWS][COLS];

void generateMaze(int row, int col);
int checkNeighbors(int row, int col);

int main()
{
    srand(time(NULL)); // Set random seed
    
    generateMaze(0, 0); // Generate maze starting at (0, 0)

    // Print the maze
    for(int row=0; row<ROWS; row++)
    {
        for(int col=0; col<COLS; col++)
        {
            if(maze[row][col] == 0) printf("#"); // Wall
            else if(maze[row][col] == 1) printf(" "); // Space
        }
        printf("\n");
    }
    
    return 0;
}

void generateMaze(int row, int col)
{
    visited[row][col] = 1; // Mark current location as visited
    
    // Check neighboring cells
    while(checkNeighbors(row, col))
    {
        int directions[4] = {0, 1, 2, 3}; // 0:up, 1:right, 2:down, 3:left
        
        // Shuffle directions
        for(int i=0; i<4; i++)
        {
            int j = rand() % 4;
            int temp = directions[i];
            directions[i] = directions[j];
            directions[j] = temp;
        }
        
        // Walk in a random direction
        for(int i=0; i<4; i++)
        {
            switch(directions[i])
            {
                case 0: // Go up
                    if(row-2 <= 0 || visited[row-2][col] == 1) continue;
                    maze[row-1][col] = 1;
                    generateMaze(row-2, col);
                    break;
                case 1: // Go right
                    if(col+2 >= COLS-1 || visited[row][col+2] == 1) continue;
                    maze[row][col+1] = 1;
                    generateMaze(row, col+2);
                    break;
                case 2: // Go down
                    if(row+2 >= ROWS-1 || visited[row+2][col] == 1) continue;
                    maze[row+1][col] = 1;
                    generateMaze(row+2, col);
                    break;
                case 3: // Go left
                    if(col-2 <= 0 || visited[row][col-2] == 1) continue;
                    maze[row][col-1] = 1;
                    generateMaze(row, col-2);
                    break;
            }
        }
    }
}

int checkNeighbors(int row, int col)
{
    int count = 0;
    
    if(row-2 > 0 && visited[row-2][col] == 0) count++; // Up
    if(col+2 < COLS-1 && visited[row][col+2] == 0) count++; // Right
    if(row+2 < ROWS-1 && visited[row+2][col] == 0) count++; // Down
    if(col-2 > 0 && visited[row][col-2] == 0) count++; // Left
    
    return count;
}