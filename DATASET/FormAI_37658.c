//FormAI DATASET v1.0 Category: Game of Life ; Style: real-life
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define ROW 20
#define COL 20

void printGrid(int grid[][COL], int row, int col);
void updateGrid(int grid[][COL], int row, int col);

int main()
{
    int grid[ROW][COL]={0};
    srand(time(NULL)); // Setting the seed for random numbers generator
 
    // Initializing the Grid with Random values
    int i, j;
    for(i=0; i<ROW; i++)
    {
        for(j=0; j<COL; j++)
        {
            grid[i][j]=(rand() % 2);
        }
    }
 
    // Printing the Initial Grid
    printf("\nInitial Grid:\n");
    printGrid(grid, ROW, COL);

    // Running the simulation
    int generations=10; // Number of Generations to run the simulation
    for(i=0; i<generations; i++)
    {
        updateGrid(grid, ROW, COL);
        printf("\nGeneration %d:\n", i+1);
        printGrid(grid, ROW, COL);
    }
 
    printf("\nSimulation Completed!\n");
    return 0;
}

void printGrid(int grid[][COL], int row, int col)
{
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            if(grid[i][j]==0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
}

void updateGrid(int grid[][COL], int row, int col)
{
    int new_grid[ROW][COL]={0}; // Initializing a new Grid to update the values
 
    int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            int count=0;
            int x, y;
            for(x=i-1; x<=i+1; x++)
            {
                for(y=j-1; y<=j+1; y++)
                {
                    if(x==i && y==j)
                        continue;
                    if(x<0 || x>=row || y<0 || y>=col)
                        continue;
                    count+=grid[x][y];
                }
            }
 
            if(grid[i][j]==1)
            {
                if(count==2 || count==3)
                    new_grid[i][j]=1;
            }
            else
            {
                if(count==3)
                    new_grid[i][j]=1;
            }
        }
    }
 
    // Copying new_grid to the original Grid
    for(i=0; i<row; i++)
    {
        for(j=0; j<col; j++)
        {
            grid[i][j]=new_grid[i][j];
        }
    }
}