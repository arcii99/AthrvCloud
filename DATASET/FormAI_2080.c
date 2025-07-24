//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

int main()
{
    int maze[20][20];
    int i, j, x, y, exit_row, exit_col;
    int direction, prev_direction, steps;
    
    srand(time(NULL)); //seed the random number generator
    
    //Initialize maze with walls everywhere
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 20; j++)
        {
            maze[i][j] = 1; //1 represents wall
        }
    }
    
    //Select a random starting point
    x = rand() % 18 + 1;
    y = rand() % 18 + 1;
    maze[x][y] = 0; //0 represents path
    
    prev_direction = 0; //Initialize previous direction to none
    steps = 0; //Initialize steps taken to 0
    
    while(steps < 500) //Generate a maze with at least 500 steps
    {
        //Select a random direction, avoiding walls and previous direction
        do
        {
            direction = rand() % 4 + 1;
        } while((direction == UP && maze[x-1][y] != 1 && direction != prev_direction) ||
            (direction == DOWN && maze[x+1][y] != 1 && direction != prev_direction) ||
            (direction == LEFT && maze[x][y-1] != 1 && direction != prev_direction) ||
            (direction == RIGHT && maze[x][y+1] != 1 && direction != prev_direction));
        
        //Move in the selected direction
        switch(direction)
        {
            case UP:
                x--;
                break;
            case DOWN:
                x++;
                break;
            case LEFT:
                y--;
                break;
            case RIGHT:
                y++;
                break;
        }
        
        //Mark path
        maze[x][y] = 0;
        steps++;
        prev_direction = direction;
    }
    
    //Select a random exit point along top or bottom row
    if(rand() % 2 == 0) //Exit along top row
    {
        exit_col = rand() % 18 + 1;
        exit_row = 0;
    }
    else //Exit along bottom row
    {
        exit_col = rand() % 18 + 1;
        exit_row = 19;
    }
    
    //Mark exit point
    maze[exit_row][exit_col] = 0;
    
    //Print maze
    for(i = 0; i < 20; i++)
    {
        for(j = 0; j < 20; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("[]"); //Print wall
            }
            else if(i == exit_row && j == exit_col)
            {
                printf("=="); //Print exit
            }
            else
            {
                printf("  "); //Print path
            }
        }
        printf("\n"); //Move to next row
    }
    
    return 0;
}