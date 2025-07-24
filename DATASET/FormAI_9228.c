//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 10

void initialize(int grid[][GRID_SIZE], int probability){
    srand(time(NULL));
    for(int i=0; i<GRID_SIZE; ++i)
        for(int j=0; j<GRID_SIZE; ++j)
            grid[i][j] = ((rand() % 100) < probability) ? 1 : 0;
}

void display(int grid[][GRID_SIZE]){
    for(int i=0; i<GRID_SIZE; ++i){
        for(int j=0; j<GRID_SIZE; ++j)
            printf("%c ", (grid[i][j]) ? '#' : '.');
        printf("\n");
    }
}

int percolates(int grid[][GRID_SIZE]){
    int connected[GRID_SIZE][GRID_SIZE] = {0};
    for(int i=0; i<GRID_SIZE; ++i)
        if(grid[0][i]) connected[0][i] = 1;

    int found = 1;
    while(found){
        found = 0;
        for(int i=0; i<GRID_SIZE; ++i){
            for(int j=0; j<GRID_SIZE; ++j){
                if(connected[i][j]){
                    if((i+1 < GRID_SIZE) && grid[i+1][j] && !connected[i+1][j]){
                        connected[i+1][j] = 1;
                        found = 1;
                    }
                    if((i-1 >= 0) && grid[i-1][j] && !connected[i-1][j]){
                        connected[i-1][j] = 1;
                        found = 1;
                    }
                    if((j+1 < GRID_SIZE) && grid[i][j+1] && !connected[i][j+1]){
                        connected[i][j+1] = 1;
                        found = 1;
                    }
                    if((j-1 >= 0) && grid[i][j-1] && !connected[i][j-1]){
                        connected[i][j-1] = 1;
                        found = 1;
                    }
                }
            }
        }
    }

    for(int i=0; i<GRID_SIZE; ++i)
        if(connected[GRID_SIZE-1][i])
            return 1;

    return 0;
}

int main(){
    int grid[GRID_SIZE][GRID_SIZE];
    initialize(grid, 60);
    display(grid);

    if(percolates(grid))
        printf("\n\nThe system has percolated!\n\n");
    else
        printf("\n\nThe system has not percolated!\n\n");

    return 0;
}