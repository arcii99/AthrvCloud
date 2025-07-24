//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 25

void generate_maze(int maze[ROWS][COLS], int row, int col)
{
    // Initialize random seed
    srand(time(NULL));
   
    // Set all elements in the maze to 1 (wall)
    for(int i = 0; i < row; i++)
        for(int j = 0; j < col; j++)
            maze[i][j] = 1;
   
    // Start at a random location
    int r = rand() % row;
    int c = rand() % col;
    maze[r][c] = 0;  // Set starting location to 0 (path)
   
    while(1)
    {
        // Check if maze is complete
        int complete = 1;
        for(int i = 0; i < row; i++)
            for(int j = 0; j < col; j++)
                if(maze[i][j] == 1)
                    complete = 0;
        if(complete)
            break;
       
        // Choose a random direction
        int dir = rand() % 4;  // 0 = top, 1 = right, 2 = bottom, 3 = left
        switch(dir)
        {
            case 0:  // Move up
                if(r-2 <= 0)
                    continue;
                if(maze[r-2][c] != 0)
                {
                    maze[r-2][c] = 0;
                    maze[r-1][c] = 0;
                    r -= 2;
                }
                break;
            case 1:  // Move right
                if(c+2 >= col)
                    continue;
                if(maze[r][c+2] != 0)
                {
                    maze[r][c+2] = 0;
                    maze[r][c+1] = 0;
                    c += 2;
                }
                break;
            case 2:  // Move down
                if(r+2 >= row)
                    continue;
                if(maze[r+2][c] != 0)
                {
                    maze[r+2][c] = 0;
                    maze[r+1][c] = 0;
                    r += 2;
                }
                break;
            case 3:  // Move left
                if(c-2 <= 0)
                    continue;
                if(maze[r][c-2] != 0)
                {
                    maze[r][c-2] = 0;
                    maze[r][c-1] = 0;
                    c -= 2;
                }
                break;
        }
    }
}

void print_maze(int maze[ROWS][COLS], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            if(maze[i][j] == 1)
                printf("\u2588");  // Wall character
            else
                printf(" ");  // Path character
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROWS][COLS];
    generate_maze(maze, ROWS, COLS);
    print_maze(maze, ROWS, COLS);
    return 0;
}