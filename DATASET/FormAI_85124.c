//FormAI DATASET v1.0 Category: Game of Life ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void init_grid(int grid[ROWS][COLS]){
    srand(time(NULL));
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[ROWS][COLS]){
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(grid[i][j] == 1){
                printf("*");
            }else{
                printf(" ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int grid[ROWS][COLS], int row, int col){
    int count = 0;
    for(int i=row-1;i<=row+1;i++){
        for(int j=col-1;j<=col+1;j++){
            if(i==row && j==col){
                continue;
            }
            if(i<0 || i>=ROWS || j<0 || j>=COLS){
                continue;
            }
            count += grid[i][j];
        }
    }
    return count;
}

void update_grid(int grid[ROWS][COLS]){
    int neighbors;
    int new_grid[ROWS][COLS];
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            neighbors = count_neighbors(grid, i, j);
            if(grid[i][j] == 1 && (neighbors < 2 || neighbors > 3)){
                new_grid[i][j] = 0;
            }else if(grid[i][j] == 0 && neighbors == 3){
                new_grid[i][j] = 1;
            }else{
                new_grid[i][j] = grid[i][j];
            }
        }
    }
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main(){
    int grid[ROWS][COLS];
    init_grid(grid);
    while(1){
        system("clear");
        print_grid(grid);
        update_grid(grid);
    }
    return 0;
}