//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// Function Declarations
void maze_generator(int maze[ROWS][COLS], int start_row, int start_col);
void print_maze(int maze[ROWS][COLS]);
void create_wall(int maze[ROWS][COLS], int row, int col);
void carve_path(int maze[ROWS][COLS], int row, int col, int prev_row, int prev_col);

// Main Function
int main()
{
    int maze[ROWS][COLS];

    // Initialize random seed
    srand(time(NULL));

    // Call maze generator function
    maze_generator(maze, 0, 0);

    // Print maze
    print_maze(maze);

    return 0;
}

// Function Definitions
void maze_generator(int maze[ROWS][COLS], int start_row, int start_col)
{
    // Initialize maze with walls
    for(int row=0; row<ROWS; row++)
    {
        for(int col=0; col<COLS; col++)
        {
            maze[row][col] = 1;
        }
    }

    // Remove wall at starting point
    maze[start_row][start_col] = 0;

    // Create path through maze
    carve_path(maze, start_row, start_col, start_row, start_col);
}

void print_maze(int maze[ROWS][COLS])
{
    for(int row=0; row<ROWS; row++)
    {
        for(int col=0; col<COLS; col++)
        {
            if(maze[row][col] == 0)
            {
                printf(" ");
            }
            else
            {
                printf("#");
            }
        }
        printf("\n");
    }
}

void create_wall(int maze[ROWS][COLS], int row, int col)
{
    // Check if position is within maze bounds
    if(row<0 || row>=ROWS || col<0 || col>=COLS)
    {
        return;
    }

    // Create wall if cell is not already a wall
    if(maze[row][col] == 0)
    {
        maze[row][col] = 1;
    }
}

void carve_path(int maze[ROWS][COLS], int row, int col, int prev_row, int prev_col)
{
    // Create copy of possible directions
    int directions[4] = {0, 1, 2, 3};
    int temp, next_row, next_col;

    // Shuffle directions
    for(int i=0; i<4; i++)
    {
        int j = rand() % 4;
        temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }

    // Carve path in random direction
    for(int i=0; i<4; i++)
    {
        switch(directions[i])
        {
            // Up
            case 0:
                next_row = row-1;
                next_col = col;
                break;
            // Right
            case 1:
                next_row = row;
                next_col = col+1;
                break;
            // Down
            case 2:
                next_row = row+1;
                next_col = col;
                break;
            // Left
            case 3:
                next_row = row;
                next_col = col-1;
                break;
        }

        // Check if next position is within maze bounds
        if(next_row>=0 && next_row<ROWS && next_col>=0 && next_col<COLS)
        {
            // Check if next position is unexplored
            if(maze[next_row][next_col] == 1)
            {
                // Remove wall between current and next position
                maze[(row+next_row)/2][(col+next_col)/2] = 0;
                maze[next_row][next_col] = 0;
                // Recursively explore next position
                carve_path(maze, next_row, next_col, row, col);
            }
        }
    }
}