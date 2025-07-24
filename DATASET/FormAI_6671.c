//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 15
#define COLS 20

int maze[ROWS][COLS]; // Initializing the maze
int visited[ROWS][COLS] = {0}; // Initializing the 'visited' array to 0

void generate_maze(int row, int col)
{
    int num_neighbors = 0;
    int neighbors[4] = {0};
    int i, r, c, temp;

    visited[row][col] = 1;

    // Check all adjacent cells
    if (row > 0 && visited[row - 1][col] == 0) // Check cell above
    {
        neighbors[num_neighbors] = 1;
        num_neighbors++;
    }
    if (col < COLS - 1 && visited[row][col + 1] == 0) // Check cell to right
    {
        neighbors[num_neighbors] = 2;
        num_neighbors++;
    }
    if (row < ROWS - 1 && visited[row + 1][col] == 0) // Check cell below
    {
        neighbors[num_neighbors] = 3;
        num_neighbors++;
    }
    if (col > 0 && visited[row][col - 1] == 0) // Check cell to left
    {
        neighbors[num_neighbors] = 4;
        num_neighbors++;
    }

    // Randomly shuffle the adjacent cells
    for (i = 0; i < num_neighbors; i++)
    {
        r = rand() % num_neighbors;
        temp = neighbors[i];
        neighbors[i] = neighbors[r];
        neighbors[r] = temp;
    }

    // Recursively generate the maze
    for (i = 0; i < num_neighbors; i++)
    {
        switch (neighbors[i])
        {
            case 1: // Cell above
                maze[row - 1][col] = 1;
                generate_maze(row - 1, col);
                break;
            case 2: // Cell to right
                maze[row][col + 1] = 1;
                generate_maze(row, col + 1);
                break;
            case 3: // Cell below
                maze[row + 1][col] = 1;
                generate_maze(row + 1, col);
                break;
            case 4: // Cell to left
                maze[row][col - 1] = 1;
                generate_maze(row, col - 1);
                break;
        }
    }
}

int main()
{
    // Initialize random seed
    srand(time(NULL));

    // Initialize maze to all 0's
    int i, j;
    for (i = 0; i < ROWS; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            maze[i][j] = 0;
        }
    }

    // Generate maze starting at top left cell
    generate_maze(0, 0);

    // Output maze
    printf(" ");
    for (j = 0; j < COLS * 2; j++)
    {
        printf("_");
    }
    printf("\n");
    for (i = 0; i < ROWS; i++)
    {
        printf("|"); // left boundary
        for (j = 0; j < COLS; j++)
        {        
            if (maze[i][j] == 1) // passage exists
            {
                printf(" ");
            }
            else // wall exists
            {
                printf("_");
            }
            
            if (j < COLS - 1 && (maze[i][j] == 1 || maze[i][j + 1] == 1))
            {
                printf(" "); // space between cells
            }
            else if (maze[i][j] == 0 && i < ROWS - 1 && maze[i + 1][j] == 0)
            {
                printf("_"); // bottom wall
            }
            else
            {
                printf("|"); // right boundary
            }
        }
        printf("\n");
    }

    return 0;
}