//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 25

void createMaze(int maze[ROWS][COLS], int rowMaj[4], int colMaj[4], int curRow, int curCol)
{
    maze[curRow][curCol] = 1; // Mark cell as visited
    
    int randIndex, newRow, newCol;
    
    // Shuffle the major direction array
    for (int i = 0; i < 4; i++)
    {
        randIndex = rand() % 4;
        int temp = rowMaj[i];
        rowMaj[i] = rowMaj[randIndex];
        rowMaj[randIndex] = temp;
        
        temp = colMaj[i];
        colMaj[i] = colMaj[randIndex];
        colMaj[randIndex] = temp;
    }
    
    // Try to move in each major direction
    for (int i = 0; i < 4; i++)
    {
        newRow = curRow + rowMaj[i];
        newCol = curCol + colMaj[i];
        
        if (newRow >= 0 && newRow < ROWS && newCol >= 0 && newCol < COLS && maze[newRow][newCol] == 0)
        {
            // Carve a path to the unvisited cell
            if (rowMaj[i] == -1)
            {
                maze[curRow-1][curCol] = 1;
            }
            else if (rowMaj[i] == 1)
            {
                maze[curRow+1][curCol] = 1;
            }
            else if (colMaj[i] == -1)
            {
                maze[curRow][curCol-1] = 1;
            }
            else if (colMaj[i] == 1)
            {
                maze[curRow][curCol+1] = 1;
            }
            
            createMaze(maze, rowMaj, colMaj, newRow, newCol);
        }
    }
}

int main()
{
    srand(time(NULL)); // Seed random number generator
    
    int maze[ROWS][COLS] = {0}; // Initialize maze array to all 0
    
    // Initialize major direction arrays
    int rowMaj[4] = {-1, 0, 1, 0};
    int colMaj[4] = {0, 1, 0, -1};
    
    createMaze(maze, rowMaj, colMaj, 0, 0);
    
    // Print maze
    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
        {
            if (maze[i][j] == 0)
            {
                printf("# ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
    
    return 0;
}