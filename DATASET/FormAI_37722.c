//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: artistic
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define GRID_SIZE 10

void initializeGrid(bool grid[GRID_SIZE][GRID_SIZE]);
int getNeighborCount(bool grid[GRID_SIZE][GRID_SIZE], int x, int y);
void updateGrid(bool grid[GRID_SIZE][GRID_SIZE]);
void drawGrid(bool grid[GRID_SIZE][GRID_SIZE]);

int main()
{
    bool grid[GRID_SIZE][GRID_SIZE];
    srand(time(NULL)); //randomize the seed for pseudo-randomness
    initializeGrid(grid);
    
    while (true)
    {
        drawGrid(grid);
        updateGrid(grid);
        printf("Press enter to continue or 'q' to quit\n");
        char input = getchar();
        if (input == 'q')
        {
            break;
        }
        getchar(); //consume the second enter character
    }
    
    return 0;
}

//initialize the grid with random live and dead cells
void initializeGrid(bool grid[GRID_SIZE][GRID_SIZE])
{
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = rand() % 2; //50/50 chance of being alive or dead
        }
    }
}

//get the number of live neighbors for a given cell
int getNeighborCount(bool grid[GRID_SIZE][GRID_SIZE], int x, int y)
{
    int count = 0;
    for (int i = x-1; i <= x+1; i++)
    {
        for (int j = y-1; j <= y+1; j++)
        {
            //skip the current cell
            if (i == x && j == y)
            {
                continue;
            }
            
            //wrap around the edges
            int wrappedX = (i + GRID_SIZE) % GRID_SIZE;
            int wrappedY = (j + GRID_SIZE) % GRID_SIZE;
            
            if (grid[wrappedX][wrappedY])
            {
                count++;
            }
        }
    }
    return count;
}

//update the grid based on the Game of Life rules
void updateGrid(bool grid[GRID_SIZE][GRID_SIZE])
{
    bool newGrid[GRID_SIZE][GRID_SIZE];
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            int neighborCount = getNeighborCount(grid, i, j);
            if (grid[i][j])
            {
                //cell is alive
                if (neighborCount < 2 || neighborCount > 3)
                {
                    //cell dies due to underpopulation or overpopulation
                    newGrid[i][j] = false;
                }
                else
                {
                    //cell survives
                    newGrid[i][j] = true;
                }
            }
            else
            {
                //cell is dead
                if (neighborCount == 3)
                {
                    //cell becomes alive due to reproduction
                    newGrid[i][j] = true;
                }
                else
                {
                    //cell remains dead
                    newGrid[i][j] = false;
                }
            }
        }
    }
    //copy the new grid over to the old grid
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            grid[i][j] = newGrid[i][j];
        }
    }
}

//draw the grid to the console
void drawGrid(bool grid[GRID_SIZE][GRID_SIZE])
{
    system("clear"); //clear the console (UNIX)
    //system("cls"); //clear the console (Windows)
    for (int i = 0; i < GRID_SIZE; i++)
    {
        for (int j = 0; j < GRID_SIZE; j++)
        {
            if (grid[i][j])
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}