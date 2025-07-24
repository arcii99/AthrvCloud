//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 25
#define COLS 50

void create_maze(int maze[ROWS][COLS]);
void print_maze(int maze[ROWS][COLS]);

int main()
{
    int maze[ROWS][COLS];
    
    srand(time(0));
    
    create_maze(maze);
    print_maze(maze);
    
    return 0;
}

void create_maze(int maze[ROWS][COLS])
{
    int i, j;
    // Initialize all cells to be walls
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            maze[i][j] = 1;
        }
    }
    
    // Choose a random starting point
    int start_row = rand() % ROWS;
    int start_col = rand() % COLS;
    maze[start_row][start_col] = 0;
    
    // Implement depth first search to create maze
    int current_row = start_row;
    int current_col = start_col;
    while(1)
    {
        // Generate random order to visit neighbors
        int order[4] = {0, 1, 2, 3};
        for(i = 0; i < 4; i++)
        {
            int temp = order[i];
            int random_index = rand() % 4;
            order[i] = order[random_index];
            order[random_index] = temp;
        }
        
        int created_path = 0;
        for(i = 0; i < 4; i++)
        {
            int next_row = current_row;
            int next_col = current_col;
            switch(order[i])
            {
                // Visit neighbor above
                case 0:
                    if(current_row > 0 && maze[current_row-1][current_col] == 1)
                    {
                        next_row--;
                        maze[current_row-1][current_col] = 0;
                        maze[next_row][next_col] = 0;
                        current_row = next_row;
                        current_col = next_col;
                        created_path = 1;
                    }
                    break;
                // Visit neighbor right
                case 1:
                    if(current_col < COLS-1 && maze[current_row][current_col+1] == 1)
                    {
                        next_col++;
                        maze[current_row][current_col+1] = 0;
                        maze[next_row][next_col] = 0;
                        current_row = next_row;
                        current_col = next_col;
                        created_path = 1;
                    }
                    break;
                // Visit neighbor below
                case 2:
                    if(current_row < ROWS-1 && maze[current_row+1][current_col] == 1)
                    {
                        next_row++;
                        maze[current_row+1][current_col] = 0;
                        maze[next_row][next_col] = 0;
                        current_row = next_row;
                        current_col = next_col;
                        created_path = 1;
                    }
                    break;
                // Visit neighbor left
                case 3:
                    if(current_col > 0 && maze[current_row][current_col-1] == 1)
                    {
                        next_col--;
                        maze[current_row][current_col-1] = 0;
                        maze[next_row][next_col] = 0;
                        current_row = next_row;
                        current_col = next_col;
                        created_path = 1;
                    }
                    break;
            }
            if(created_path)
            {
                break;
            }
        }
        if(!created_path)
        {
            // Backtrack if no new paths can be created
            for(i = 0; i < ROWS; i++)
            {
                for(j = 0; j < COLS; j++)
                {
                    if(maze[i][j] == 0)
                    {
                        current_row = i;
                        current_col = j;
                        break;
                    }
                }
                if(maze[i][j] == 0)
                {
                    break;
                }
            }
            // Check if maze is complete
            int complete = 1;
            for(i = 0; i < ROWS; i++)
            {
                for(j = 0; j < COLS; j++)
                {
                    if(maze[i][j] == 1)
                    {
                        complete = 0;
                        break;
                    }
                }
                if(!complete)
                {
                    break;
                }
            }
            if(complete)
            {
                break;
            }
        }
    }
}

void print_maze(int maze[ROWS][COLS])
{
    int i, j;
    // Print maze in Romeo and Juliet style
    for(i = 0; i < ROWS; i++)
    {
        for(j = 0; j < COLS; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("Oh Romeo, wherefore art thou Romeo? Deny thy walls and refuse thy maze. Or if thou wilt not, be but sworn my love, and I'll no longer be lost.\n");
            }
            else
            {
                printf("Arise, fair sun, and kill the envious maze. It is the maze, and Juliet is the sun.\n");
            }
        }
        printf("\n");
    }
}