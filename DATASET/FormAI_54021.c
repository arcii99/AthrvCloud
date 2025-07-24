//FormAI DATASET v1.0 Category: Procedurally Generated Maze ; Style: statistical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 11
#define COL 11

int maze[ROW+2][COL+2];

void generateMaze(int row, int col);
void printMaze();

int main()
{
    srand(time(NULL)); //initialize random seed
    
    generateMaze(1, 1); //generate maze starting from cell (1,1)
    
    printMaze(); //print the maze
    
    return 0;
}

//function to generate the maze
void generateMaze(int row, int col)
{
    //set current cell as visited
    maze[row][col] = 1;
    
    //create a random order of directions to explore
    int directions[4] = {1, 2, 3, 4};
    for (int i = 0; i < 4; i++)
    {
        int j = rand() % 4;
        int temp = directions[i];
        directions[i] = directions[j];
        directions[j] = temp;
    }
    
    //explore each direction
    for (int i = 0; i < 4; i++)
    {
        int direction = directions[i];
        int nextRow = row;
        int nextCol = col;
        
        //set the variables for the next cell based on the direction
        switch (direction)
        {
            case 1: //up
                nextRow -= 2;
                break;
            case 2: //down
                nextRow += 2;
                break;
            case 3: //left
                nextCol -= 2;
                break;
            case 4: //right
                nextCol += 2;
                break;
        }
        
        //check if the next cell is within bounds and unvisited
        if (nextRow >= 1 && nextRow <= ROW && nextCol >= 1 && nextCol <= COL && maze[nextRow][nextCol] == 0)
        {
            //carve out the path between this cell and the next cell
            if (direction == 1) //up
                maze[row-1][col] = 1;
            else if (direction == 2) //down
                maze[row+1][col] = 1;
            else if (direction == 3) //left
                maze[row][col-1] = 1;
            else if (direction == 4) //right
                maze[row][col+1] = 1;

            generateMaze(nextRow, nextCol); //recursively generate the maze from the next cell
        }
    }
}

//function to print the maze
void printMaze()
{
    for (int i = 0; i < ROW+2; i++)
    {
        for (int j = 0; j < COL+2; j++)
        {
            if (i == 0 || i == ROW+1 || j == 0 || j == COL+1) //print border
                printf("# ");
            else if (maze[i][j] == 1) //print path
                printf("  ");
            else //print wall
                printf("# ");
        }
        printf("\n");
    }
}