//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10 //size of the maze

void draw_maze(char maze[N][N]) //function to draw the maze
{
    int i, j;
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("%c ", maze[i][j]); //print each cell
        }
        printf("\n");
    }
}

int main()
{
    char maze[N][N];
    int i, j, random;
    srand(time(NULL)); //set the seed for random numbers
    
    //initialize the maze with walls
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(i == 0 || j == 0 || i == N-1 || j == N-1) //if on the border
            {
                maze[i][j] = '#'; //set as wall
            }
            else
            {
                maze[i][j] = '.'; //set as free passage
            }
        }
    }
    
    //randomly generate a maze
    for(i = 2; i < N-2; i++)
    {
        for(j = 2; j < N-2; j++)
        {
            random = rand() % 4; //generate a random number between 0 and 3
            
            if(maze[i][j] == '.') //if in free passage
            {
                switch(random) //choose a random direction
                {
                    case 0: //up
                        if(maze[i-1][j] == '.') //if the cell above is free passage
                        {
                            maze[i-1][j] = '#'; //set it as wall
                        }
                        break;
                    
                    case 1: //right
                        if(maze[i][j+1] == '.') //if the cell on the right is free passage
                        {
                            maze[i][j+1] = '#'; //set it as wall
                        }
                        break;
                    
                    case 2: //down
                        if(maze[i+1][j] == '.') //if the cell below is free passage
                        {
                            maze[i+1][j] = '#'; //set it as wall
                        }
                        break;
                    
                    case 3: //left
                        if(maze[i][j-1] == '.') //if the cell on the left is free passage
                        {
                            maze[i][j-1] = '#'; //set it as wall
                        }
                        break;
                }
            }
        }
    }
    
    //draw the maze
    draw_maze(maze);
    
    return 0;
}