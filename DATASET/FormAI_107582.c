//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMS 75
#define GRID_ROWS 5
#define GRID_COLS 15

int main()
{
    int grid[GRID_ROWS][GRID_COLS] = {0};
    int nums[MAX_NUMS] = {0};
    int num_index = 0;
    int i, j;
    srand(time(NULL));
    
    // generate the numbers
    for(i = 0; i < MAX_NUMS; i++)
    {
        nums[i] = i+1;
    }
    // shuffle the numbers
    for(i = 0; i < MAX_NUMS-1; i++)
    {
        j = i + rand() / (RAND_MAX / (MAX_NUMS - i) + 1);
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
    
    // fill the grid
    for(i = 0; i < GRID_ROWS; i++)
    {
        for(j = 0; j < GRID_COLS; j++)
        {
            // center spot is free
            if(i == 2 && j == 6)
            {
                grid[i][j] = -1;
            }
            else
            {
                grid[i][j] = nums[num_index++];
            }
        }
    }
    
    // print the grid
    printf("\n\n\t\tBINGO SIMULATOR\n\n");
    for(i = 0; i < GRID_ROWS; i++)
    {
        for(j = 0; j < GRID_COLS; j++)
        {
            if(grid[i][j] == -1)
            {
                printf("|  FREE  ");
            }
            else
            {
                printf("|  %2d   ", grid[i][j]);
            }
        }
        printf("|\n");
    }
    printf("\n\n");
    
    return 0;
}