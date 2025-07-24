//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: protected
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 15
#define COLUMN 25

void generateMaze(int maze[][COLUMN]);
void printMaze(int maze[][COLUMN]);

int main()
{
    int maze[ROW][COLUMN];
    srand(time(0)); //to get different random numbers every time we run the program.

    //Initializing the maze with random walls.
    for(int i=0;i<ROW;i++)
    {
        for(int j=0;j<COLUMN;j++)
        {
            //If its a boundary cell, make it a wall.
            if(i==0 || j==0 || i==ROW-1 || j==COLUMN-1)
            {
                maze[i][j] = 1;
            }
            //Else randomly assign the cell as wall or not.
            else if(i%2==0 && j%2==0)
            {
                if(rand()%2 == 0)
                {
                    maze[i][j] = 1; //1 represents Wall
                }
                else{
                    maze[i][j] = 0; //0 represents Open Path
                }
            }
            else{
                maze[i][j] = 0; //Path
            }
        }
    }

    generateMaze(maze);
    printMaze(maze);
    return 0;
}

//Function to generate the maze using Depth First Search Algorithm.
void generateMaze(int maze[][COLUMN])
{
    int stack[ROW*COLUMN][2]; //Stack to store the visited cells.
    int top = -1;
    int visited[ROW][COLUMN]; //To mark Visited Cells.
    int dirs[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; //(row, col)
    int r = 1, c = 1; //Starting Cells.
    int i, j, ni, nj;

    //Initialize Visited Matrix.
    for(i = 0;i < ROW; i++)
    {
        for(j = 0;j < COLUMN;j++)
        {
            visited[i][j] = 0;
        }
    }

    //Push the Starting Cell.
    stack[++top][0] = r;
    stack[top][1] = c;

    while(top != -1)
    {
        //Pop the top cell.
        r = stack[top][0];
        c = stack[top][1];
        visited[r][c] = 1;
        top--;

        //Randomly visit the neighbors.
        for(i=0;i<4;i++)
        {
            ni = r + dirs[i][0];
            nj = c + dirs[i][1];
            if(ni >= 0 && nj >= 0 && ni < ROW && nj < COLUMN && visited[ni][nj] == 0) //If Neighbor is Valid.
            {
                maze[ni][nj] = 0; //Make the Holes in the Wall.
                top++;
                stack[top][0] = ni;
                stack[top][1] = nj;
                visited[ni][nj] = 1; //Mark the Cell as Visited.
            }
        }
    }
}

//Function to print the maze.
void printMaze(int maze[][COLUMN])
{
    int i, j;
    for(i=0;i<ROW;i++)
    {
        for(j=0;j<COLUMN;j++)
        {
            if(maze[i][j]==1)
            {
                printf("XX"); //Wall.
            }
            else if(i==1 && j==1)
            {
                printf("ST"); //Starting Cell.
            }
            else if(i==ROW-2 && j==COLUMN-2)
            {
                printf("EN"); //Ending Cell.
            }
            else{
                printf("  "); //Path.
            }
        }
        printf("\n");
    }
}