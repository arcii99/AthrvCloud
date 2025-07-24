//FormAI DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 20
#define COLS 50

//function to initialize the grid randomly
void initializeGrid(int grid[][COLS])
{
    int row, col;
    for(row=0;row<ROWS;row++)
    {
        for(col=0;col<COLS;col++)
        {
            grid[row][col] = rand() % 2;
        }
    }
}

//function to print the current state of the grid
void printGrid(int grid[][COLS])
{
    int row, col;
    for(row=0;row<ROWS;row++)
    {
        for(col=0;col<COLS;col++)
        {
            if(grid[row][col] == 1)
            {
                printf("* ");
            }
            else
            {
                printf(". ");
            }
        }
        printf("\n");
    }
}

//function to calculate the next generation of the grid
void nextGeneration(int grid[][COLS])
{
    int row, col;
    int nextGeneration[ROWS][COLS];
    for(row=0;row<ROWS;row++)
    {
        for(col=0;col<COLS;col++)
        {
            //calculate the number of neighbors
            int neighbors = 
            grid[(row-1)%ROWS][(col-1)%COLS] +  //top left corner
            grid[(row-1)%ROWS][col] +  //top
            grid[(row-1)%ROWS][(col+1)%COLS] + //top right corner
            grid[row][(col-1)%COLS] +  //left
            grid[row][(col+1)%COLS] +  //right
            grid[(row+1)%ROWS][(col-1)%COLS] +  //bottom left corner
            grid[(row+1)%ROWS][col] +  //bottom
            grid[(row+1)%ROWS][(col+1)%COLS];  //bottom right corner
            
            //apply the rules of the Game of Life
            if(grid[row][col] == 1) //alive cell
            {
                if(neighbors<2 || neighbors>3)
                {
                    nextGeneration[row][col] = 0; //dies
                }
                else
                {
                    nextGeneration[row][col] = 1; //lives
                }
            }
            else //dead cell
            {
                if(neighbors == 3)
                { 
                    nextGeneration[row][col] = 1; //comes to life
                }
                else
                {
                    nextGeneration[row][col] = 0; //remains dead
                }
            }
        }
    }
    
    //copy the next generation to the current grid
    for(row=0;row<ROWS;row++)
    {
        for(col=0;col<COLS;col++)
        {
            grid[row][col] = nextGeneration[row][col];
        }
    }
}

int main()
{
    int grid[ROWS][COLS];
    srand(time(NULL)); //initialize the random seed
    initializeGrid(grid);
    while(1)
    {
        system("clear"); //clear the console
        printGrid(grid);
        nextGeneration(grid);
        usleep(200000); //pause for 200 milliseconds
    }
    return 0;
}