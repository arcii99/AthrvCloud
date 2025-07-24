//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10

int maze[ROWS][COLS];

void generate_maze(int row, int col)
{
    // Generate random maze using depth-first search algorithm
    // Each cell is either a wall (0) or a passage (1)
    // Initialize all cells as walls
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            maze[i][j] = 0;
        }
    }
    
    // Set starting cell as passage
    maze[0][0] = 1;
    
    // Choose random valid neighbour and make a passage
    int x = 0, y = 0;
    while (1)
    {
        // Check for valid neighbours
        int neighbours[4][2] = {{0,-1}, {0,1}, {-1,0}, {1,0}}; // left, right, up, down
        int valid_neighbours[4][2];
        int num_valid = 0;
        for (int i = 0; i < 4; i++)
        {
            int newx = x + neighbours[i][0];
            int newy = y + neighbours[i][1];
            if (newx >= 0 && newx < row && newy >= 0 && newy < col && maze[newx][newy] == 0)
            {
                valid_neighbours[num_valid][0] = newx;
                valid_neighbours[num_valid][1] = newy;
                num_valid++;
            }
        }
        
        // Choose random valid neighbour
        if (num_valid == 0)
        {
            break;
        }
        int random_neighbour = rand() % num_valid;
        int newx = valid_neighbours[random_neighbour][0];
        int newy = valid_neighbours[random_neighbour][1];
        maze[newx][newy] = 1;
        
        // Move to new cell
        x = newx;
        y = newy;
    }
    
    // Set ending cell as passage
    maze[row-1][col-1] = 1;
}

void print_maze(int row, int col)
{
    // Print the maze
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (maze[i][j] == 0)
            {
                printf("X ");
            }
            else
            {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main()
{
    srand(time(NULL)); // Seed random number generator
    generate_maze(ROWS,COLS);
    print_maze(ROWS,COLS);
    return 0;
}