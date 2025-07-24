//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROWS 15
#define COLS 30

void generateMaze(int maze[ROWS][COLS])
{
    srand(time(NULL));  // seed the random number generator with current time

    // initialize the maze with walls and paths
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(i==0 || i==ROWS-1 || j==0 || j==COLS-1 || (i%2==0 && j%2==0))
                maze[i][j] = 1;  // wall
            else
                maze[i][j] = 0;  // path
        }
    }

    // randomly select a starting point on the border
    int start = 0;
    while(start%2==0)
        start = rand() % (ROWS-2) + 1;  // exclude the border cells
    if(start==1)
        maze[start+1][0] = 0;  // open a path to the maze at the left starting point
    else if(start==ROWS-2)
        maze[start-1][COLS-1] = 0;  // open a path to the maze at the right starting point
    else if(start%2==1)  // on upper or lower border
    {
        int r = rand() % 2;  // randomly choose left or right border
        if(r==0)
            maze[start][0] = 0;  // open a path to the maze at the left border
        else
            maze[start][COLS-1] = 0;  // open a path to the maze at the right border
    }

    // generate the maze using Depth-First Search algorithm
    int stack[ROWS*COLS][2];
    int top = -1;
    int current[2] = {start,0};
    int visited[ROWS][COLS] = {0};
    visited[start][0] = 1;

    while(1)
    {
        // find unvisited neighbors
        int neighbors[4][2] = {{current[0]-2,current[1]}, {current[0],current[1]-2},
                               {current[0]+2,current[1]}, {current[0],current[1]+2}};
        int unvisited[4][2];
        int count = 0;
        for(int i=0; i<4; i++)
        {
            if(neighbors[i][0]>0 && neighbors[i][0]<ROWS-1 && neighbors[i][1]>0 && neighbors[i][1]<COLS-1)
            {
                if(!visited[neighbors[i][0]][neighbors[i][1]])
                {
                    unvisited[count][0] = neighbors[i][0];
                    unvisited[count][1] = neighbors[i][1];
                    count++;
                }
            }
        }

        if(count>0)
        {
            // choose a random unvisited neighbor
            int r = rand() % count;

            // push the current cell to stack
            top++;
            stack[top][0] = current[0];
            stack[top][1] = current[1];

            // open the wall between current cell and the chosen neighbor
            int row = (current[0] + unvisited[r][0]) / 2;
            int col = (current[1] + unvisited[r][1]) / 2;
            maze[row][col] = 0;

            // move to the chosen neighbor
            current[0] = unvisited[r][0];
            current[1] = unvisited[r][1];
            visited[current[0]][current[1]] = 1;
        }
        else if(top>=0)
        {
            // backtrack to the previous cell
            current[0] = stack[top][0];
            current[1] = stack[top][1];
            top--;
        }
        else
        {
            // maze generation is done
            break;
        }
    }
}

void printMaze(int maze[ROWS][COLS])
{
    for(int i=0; i<ROWS; i++)
    {
        for(int j=0; j<COLS; j++)
        {
            if(maze[i][j]==1)
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int main()
{
    int maze[ROWS][COLS];

    generateMaze(maze);

    printMaze(maze);

    return 0;
}