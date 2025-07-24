//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Maze size
#define ROWS 20
#define COLS 20

// Directional constants
#define NORTH 0
#define EAST 1
#define SOUTH 2
#define WEST 3

// Cell borders
#define TOP 1
#define RIGHT 2
#define BOTTOM 4
#define LEFT 8

// Function prototypes
void maze_init();
void maze_generate();
void maze_print();

// Global variables
int maze[ROWS][COLS];
int stack[ROWS*COLS][2]; // x,y coordinates stack
int stack_top = -1;

int main()
{
    maze_init();
    maze_generate();
    maze_print();
    
    return 0;
}

// Initialize maze with all walls
void maze_init()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            maze[i][j] = TOP | RIGHT | BOTTOM | LEFT;
        }
    }
}

// Generate maze using depth-first search algorithm
void maze_generate()
{
    srand(time(NULL));
    // Starting position
    int x = rand() % ROWS;
    int y = rand() % COLS;
    maze[y][x] &= ~TOP; // Open top border
    stack[++stack_top][0] = x;
    stack[stack_top][1] = y;
    
    while (stack_top >= 0)
    {
        // Pop current position from stack
        x = stack[stack_top][0];
        y = stack[stack_top][1];
        stack_top--;
        
        // Check for neighbors that haven't been visited
        int neighbors[4];
        int ncount = 0;
        if (y > 0 && maze[y-1][x] == (TOP|RIGHT|BOTTOM|LEFT))
        {
            neighbors[ncount++] = NORTH;
        }
        if (x < COLS-1 && maze[y][x+1] == (TOP|RIGHT|BOTTOM|LEFT))
        {
            neighbors[ncount++] = EAST;
        }
        if (y < ROWS-1 && maze[y+1][x] == (TOP|RIGHT|BOTTOM|LEFT))
        {
            neighbors[ncount++] = SOUTH;
        }
        if (x > 0 && maze[y][x-1] == (TOP|RIGHT|BOTTOM|LEFT))
        {
            neighbors[ncount++] = WEST;
        }
        
        // If there are neighbors, choose one and knock down the wall
        if (ncount > 0)
        {
            int dir = neighbors[rand() % ncount];
            switch (dir)
            {
            case NORTH:
                maze[y][x] &= ~TOP;
                maze[y-1][x] &= ~BOTTOM;
                stack[++stack_top][0] = x;
                stack[stack_top][1] = y-1;
                break;
            case EAST:
                maze[y][x] &= ~RIGHT;
                maze[y][x+1] &= ~LEFT;
                stack[++stack_top][0] = x+1;
                stack[stack_top][1] = y;
                break;
            case SOUTH:
                maze[y][x] &= ~BOTTOM;
                maze[y+1][x] &= ~TOP;
                stack[++stack_top][0] = x;
                stack[stack_top][1] = y+1;
                break;
            case WEST:
                maze[y][x] &= ~LEFT;
                maze[y][x-1] &= ~RIGHT;
                stack[++stack_top][0] = x-1;
                stack[stack_top][1] = y;
                break;
            }
        }
    }
}

// Print maze
void maze_print()
{
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        // Print top border
        for (j = 0; j < COLS; j++)
        {
            printf("%s", maze[i][j] & TOP ? "+--" : "+  ");
        }
        printf("+\n");
        // Print left and right borders
        for (j = 0; j < COLS; j++)
        {
            printf("%s", maze[i][j] & LEFT ? "|  " : "   ");
            printf("%s", maze[i][j] & RIGHT ? "|" : " ");
        }
        printf("\n");
    }
    // Print bottom border
    for (j = 0; j < COLS; j++)
    {
        printf("+--");
    }
    printf("+\n");
}