//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void generate_maze(char maze[ROWS][COLS]);
void print_maze(char maze[ROWS][COLS]);

int main()
{
    char maze[ROWS][COLS];

    srand(time(NULL));

    generate_maze(maze);
    print_maze(maze);

    return 0;
}

void generate_maze(char maze[ROWS][COLS])
{
    int i, j;

    // Initialize the maze to all walls
    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            maze[i][j] = '#';
        }
    }

    // Choose a random starting point
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;

    // Carve out the maze
    maze[start_row][start_col] = ' ';

    while(1)
    {
        // Find all neighbors of the current cell
        int neighbors[4][2] = { {start_row-1, start_col},
                                {start_row+1, start_col},
                                {start_row, start_col-1},
                                {start_row, start_col+1} };

        // Count the number of available neighbors
        int available_neighbors = 0;
        for(i=0; i<4; i++)
        {
            int row = neighbors[i][0];
            int col = neighbors[i][1];

            // Check if the neighbor is in bounds and a wall
            if(row >= 0 && row < ROWS && col >= 0 && col < COLS &&
               maze[row][col] == '#')
            {
                available_neighbors++;
            }
        }

        // If no neighbors are available, backtrack until one is found
        if(available_neighbors == 0)
        {
            int backtrack[2] = {start_row, start_col};
            while(1)
            {
                // Find all neighbors of the current cell
                int neighbors[4][2] = { {backtrack[0]-1, backtrack[1]},
                                        {backtrack[0]+1, backtrack[1]},
                                        {backtrack[0], backtrack[1]-1},
                                        {backtrack[0], backtrack[1]+1} };

                // Check if any neighbors are unvisited
                int unvisited_neighbors = 0;
                for(i=0; i<4; i++)
                {
                    int row = neighbors[i][0];
                    int col = neighbors[i][1];

                    // Check if the neighbor is in bounds, a wall, or already visited
                    if(row >= 0 && row < ROWS && col >= 0 && col < COLS &&
                       maze[row][col] == ' ')
                    {
                        unvisited_neighbors++;
                    }
                }

                // If there is an unvisited neighbor, select it and break out of backtracking
                if(unvisited_neighbors > 0)
                {
                    int chosen_neighbor = rand() % unvisited_neighbors;
                    int counter = 0;
                    for(i=0; i<4; i++)
                    {
                        int row = neighbors[i][0];
                        int col = neighbors[i][1];

                        // Check if the neighbor is unvisited
                        if(row >= 0 && row < ROWS && col >= 0 && col < COLS &&
                           maze[row][col] == ' ')
                        {
                            if(counter == chosen_neighbor)
                            {
                                start_row = row;
                                start_col = col;
                                backtrack[0] = row;
                                backtrack[1] = col;
                                maze[start_row][start_col] = ' ';
                                break;
                            }
                            else
                            {
                                counter++;
                            }
                        }
                    }
                    break;
                }
                // Otherwise, continue backtracking
                else
                {
                    start_row = backtrack[0];
                    start_col = backtrack[1];

                    // If we've backtracked all the way to the original starting point, we're done
                    if(start_row == 0 && start_col == 0)
                    {
                        return;
                    }

                    backtrack[0] = start_row;
                    backtrack[1] = start_col;
                }
            }
        }
        // Otherwise, choose a random available neighbor and carve the maze
        else
        {
            int chosen_neighbor = rand() % available_neighbors;
            int counter = 0;
            for(i=0; i<4; i++)
            {
                int row = neighbors[i][0];
                int col = neighbors[i][1];

                // Check if the neighbor is available
                if(row >= 0 && row < ROWS && col >= 0 && col < COLS &&
                   maze[row][col] == '#')
                {
                    if(counter == chosen_neighbor)
                    {
                        start_row = row;
                        start_col = col;
                        maze[start_row][start_col] = ' ';
                        break;
                    }
                    else
                    {
                        counter++;
                    }
                }
            }
        }
    }
}

void print_maze(char maze[ROWS][COLS])
{
    int i, j;

    for(i=0; i<ROWS; i++)
    {
        for(j=0; j<COLS; j++)
        {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}