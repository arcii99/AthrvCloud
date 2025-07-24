//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10 //size of the maze

void generate_maze(int maze[SIZE][SIZE], int row, int col);
void print_maze(int maze[SIZE][SIZE]);

int main()
{
    int maze[SIZE][SIZE];
    
    srand(time(NULL)); //seed the random number generator
    
    generate_maze(maze, 0, 0);
    
    print_maze(maze);
    
    return 0;
}

void generate_maze(int maze[SIZE][SIZE], int row, int col)
{
    maze[row][col] = 1; //mark the current cell as visited
    
    int directions[] = {-1, 0, 1, 0, -1}; //array to store the four possible directions
    
    for(int i=0; i<4; i++)
    {
        int rand_direction = rand() % 4;
        int new_row = row + directions[rand_direction];
        int new_col = col + directions[rand_direction+1];
        
        if(new_row < 0 || new_row > SIZE-1 || new_col < 0 || new_col > SIZE-1) //if the new cell is outside the maze
        {
            continue;
        }
        
        if(maze[new_row][new_col] == 0) //if the new cell has not been visited
        {
            if(rand_direction == 0) //if moving up
            {
                maze[row-1][col] = 1; //mark the wall above as broken
            }
            else if(rand_direction == 1) //if moving right
            {
                maze[row][col+1] = 1; //mark the wall to the right as broken
            }
            else if(rand_direction == 2) //if moving down
            {
                maze[row+1][col] = 1; //mark the wall below as broken
            }
            else if(rand_direction == 3) //if moving left
            {
                maze[row][col-1] = 1; //mark the wall to the left as broken
            }
            generate_maze(maze, new_row, new_col); //recursively call generate_maze with the new cell
        }
    }
}

void print_maze(int maze[SIZE][SIZE])
{
    for(int i=0; i<SIZE; i++)
    {
        for(int j=0; j<SIZE; j++)
        {
            if(maze[i][j] == 1)
            {
                printf("  "); //if the cell has been visited, print a space
            }
            else
            {
                printf("██"); //if the cell has not been visited, print a wall
            }
        }
        printf("\n");
    }
}