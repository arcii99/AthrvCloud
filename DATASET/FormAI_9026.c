//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAZE_SIZE 15

int maze[MAZE_SIZE][MAZE_SIZE];

void display_maze()
{
    int i, j;
    for(i=0; i<MAZE_SIZE; i++)
    {
        for(j=0; j<MAZE_SIZE; j++)
        {
            if(maze[i][j] == 0)
                printf("# ");
            else
                printf(". ");
        }
        printf("\n");
    }
}

void generate_maze(int row, int col)
{
    int i, direction, temp_row, temp_col, restart_flag;
    int directions[] = {0, 1, 2, 3}; // 0-UP, 1-RIGHT, 2-DOWN, 3-LEFT
    int directions_len = 4;
    
    maze[row][col] = 1; // mark current cell as visited
    
    // shuffle direction array
    for(i=0; i<directions_len; i++)
    {
        int temp = directions[i];
        int rand_index = rand() % directions_len;
        directions[i] = directions[rand_index];
        directions[rand_index] = temp;
    }
    
    restart_flag = 0;
    for(i=0; i<directions_len; i++)
    {
        direction = directions[i];
        switch(direction)
        {
            case 0: // UP
                if(row-2 < 0 || maze[row-2][col] == 1) // check if new position is valid
                    continue;
                maze[row-1][col] = 1; // mark cell in between current cell and new cell as visited
                temp_row = row-2;
                temp_col = col;
                break;
            
            case 1: // RIGHT
                if(col+2 >= MAZE_SIZE || maze[row][col+2] == 1) // check if new position is valid
                    continue;
                maze[row][col+1] = 1; // mark cell in between current cell and new cell as visited
                temp_row = row;
                temp_col = col+2;
                break;
            
            case 2: // DOWN
                if(row+2 >= MAZE_SIZE || maze[row+2][col] == 1) // check if new position is valid
                    continue;
                maze[row+1][col] = 1; // mark cell in between current cell and new cell as visited
                temp_row = row+2;
                temp_col = col;
                break;
            
            case 3: // LEFT
                if(col-2 < 0 || maze[row][col-2] == 1) // check if new position is valid
                    continue;
                maze[row][col-1] = 1; // mark cell in between current cell and new cell as visited
                temp_row = row;
                temp_col = col-2;
                break;
        }
        generate_maze(temp_row, temp_col);
        restart_flag = 1;
    }
    if(restart_flag == 0)
        return;
    else
        return;
}

int main()
{
    srand(time(0)); // seed random number generator with current time
    
    // initialize maze with walls
    int i, j;
    for(i=0; i<MAZE_SIZE; i++)
    {
        for(j=0; j<MAZE_SIZE; j++)
        {
            if(i==0 || i==MAZE_SIZE-1 || j==0 || j==MAZE_SIZE-1)
                maze[i][j] = 0;
            else
                maze[i][j] = 1;
        }
    }
    
    generate_maze(1, 1); // generate maze starting from cell (1,1)
    display_maze(); // display generated maze
    
    return 0;
}