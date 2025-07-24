//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 40
#define COLS 80
#define GENERATIONS 100

void init_grid(int grid[ROWS][COLS]){
    int i, j;
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(int grid[ROWS][COLS]){
    int i, j;
    printf("\033[2J\033[1;1H"); //clear screen
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            if(grid[i][j] == 1){
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

int get_neighbor_count(int grid[ROWS][COLS], int i, int j){
    int count = 0;
    if(i > 0){
        if(j > 0 && grid[i-1][j-1] == 1){
            count++;
        }
        if(grid[i-1][j] == 1){
            count++;
        }
        if(j < COLS-1 && grid[i-1][j+1] == 1){
            count++;
        }
    }
    if(j > 0 && grid[i][j-1] == 1){
        count++;
    }
    if(j < COLS-1 && grid[i][j+1] == 1){
        count++;
    }
    if(i < ROWS-1){
        if(j > 0 && grid[i+1][j-1] == 1){
            count++;
        }
        if(grid[i+1][j] == 1){
            count++;
        }
        if(j < COLS-1 && grid[i+1][j+1] == 1){
            count++;
        }
    }
    return count;
}

void update_grid(int grid[ROWS][COLS]){
    int i, j, neighbor_count;
    int new_grid[ROWS][COLS];
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            neighbor_count = get_neighbor_count(grid, i, j);
            if(grid[i][j] == 1){
                if(neighbor_count < 2 || neighbor_count > 3){
                    new_grid[i][j] = 0;
                } else {
                    new_grid[i][j] = 1;
                }
            } else {
                if(neighbor_count == 3){
                    new_grid[i][j] = 1;
                } else {
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    for(i=0; i<ROWS; i++){
        for(j=0; j<COLS; j++){
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main(){
    srand(time(NULL));
    int grid[ROWS][COLS];
    init_grid(grid);
    int i;
    for(i=0; i<GENERATIONS; i++){
        print_grid(grid);
        update_grid(grid);
    }
    return 0;
}