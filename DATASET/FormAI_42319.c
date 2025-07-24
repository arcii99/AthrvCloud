//FormAI DATASET v1.0 Category: Game of Life ; Style: enthusiastic
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main()
{
    int i, j, k;
    int grid[10][10] = {0};
    int tempGrid[10][10] = {0};

    //setting up initial grid
    grid[2][3] = 1;
    grid[3][4] = 1;
    grid[4][2] = 1;
    grid[4][3] = 1;
    grid[4][4] = 1;

    while(1)
    {
        system("clear");
        //displaying the current grid
        printf("Current Generation:\n");
        for(i=0; i<10; i++)
        {
            for(j=0; j<10; j++)
            {
                if(grid[i][j] == 1)
                    printf("* ");
                else
                    printf(". ");
            }
            printf("\n");
        }
        //updating the tempGrid as per rules of the game
        for(i=0; i<10; i++)
        {
            for(j=0; j<10; j++)
            {
                int liveNeighbour = 0;
                //counting the live neighbours of each cell
                for(k=-1; k<=1; k++)
                {
                    if(i+k<0 || i+k>=10)
                        continue;
                    for(int l=-1; l<=1; l++)
                    {
                        if(j+l<0 || j+l>=10 || (k==0 && l==0))
                            continue;
                        if(grid[i+k][j+l] == 1)
                            liveNeighbour++;
                    }
                }
                //applying game rules to update the cell status in tempGrid
                if(grid[i][j] == 1 && liveNeighbour<2)
                    tempGrid[i][j] = 0;
                else if(grid[i][j] == 1 && (liveNeighbour==2 || liveNeighbour==3))
                    tempGrid[i][j] = 1;
                else if(grid[i][j] == 1 && liveNeighbour>3)
                    tempGrid[i][j] = 0;
                else if(grid[i][j] == 0 && liveNeighbour==3)
                    tempGrid[i][j] = 1;
            }
        }
        //updating the grid with updated tempGrid values
        for(i=0; i<10; i++)
        {
            for(j=0; j<10; j++)
            {
                grid[i][j] = tempGrid[i][j];
            }
        }
        //sleeping for 1 second before new generation formation
        sleep(1);
    }
    return 0;
}