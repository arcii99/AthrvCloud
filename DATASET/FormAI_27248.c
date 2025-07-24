//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL)); //Initialize random seed
    int rows = 15, cols = 25; //Maze dimensions
    char maze[rows][cols]; //Initialize the maze

    //Create a border around the maze
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            if(i==0 || i==rows-1 || j==0 || j==cols-1)
                maze[i][j] = '#';
            else
                maze[i][j] = ' ';
        }
    }
 
    //set the entrance and exit of the maze
    int entrance = rand() % (cols-2) + 1;
    int exit = rand() % (cols-2) + 1;
    maze[0][entrance] = 'S';
    maze[rows-1][exit] = 'E';

    //Randomly generate walls for the maze
    for(int i=1;i<rows-1;i++)
    {
        for(int j=1;j<cols-1;j++)
        {
            if(maze[i][j] == ' ')
            {
                int random_num = rand() % 10;
                if(random_num < 4)
                    maze[i][j] = '#';
            }
        }
    }

    //Print the maze
    printf("\n");
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%c",maze[i][j]);
        }
        printf("\n");
    }

    return 0;
}