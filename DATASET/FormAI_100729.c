//FormAI DATASET v1.0 Category: Game of Life ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the dimensions of the grid
#define ROWS 20
#define COLS 50

// Define the number of iterations to run the game
#define ITERATIONS 100

// Function to initialize the grid randomly
void init_grid(int grid[ROWS][COLS]){
    srand(time(NULL));
    
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            grid[i][j] = rand() % 2;
        }
    }
}

// Function to print the grid
void print_grid(int grid[ROWS][COLS]){
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            if(grid[i][j] == 1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

// Function to count the number of live neighbors of a cell
int count_neighbors(int grid[ROWS][COLS], int x, int y){
    int count = 0;
    for(int i=-1; i<=1; i++){
        for(int j=-1; j<=1; j++){
            if(i == 0 && j == 0){
                continue;
            }
            if(x+i < 0 || x+i >= ROWS){
                continue;
            }
            if(y+j < 0 || y+j >= COLS){
                continue;
            }
            if(grid[x+i][y+j] == 1){
                count++;
            }
        }
    }
    return count;
}

// Function to update the grid according to the Game of Life rules
void update_grid(int grid[ROWS][COLS]){
    int new_grid[ROWS][COLS];
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            int neighbors = count_neighbors(grid, i, j);
            if(grid[i][j] == 1){
                if(neighbors < 2 || neighbors > 3){
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if(neighbors == 3){
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    for(int i=0; i<ROWS; i++){
        for(int j=0; j<COLS; j++){
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main(void){
    int grid[ROWS][COLS];
    init_grid(grid);
    
    for(int i=0; i<ITERATIONS; i++){
        print_grid(grid);
        update_grid(grid);
    }
    
    return 0;
}