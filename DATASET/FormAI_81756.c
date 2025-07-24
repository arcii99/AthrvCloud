//FormAI DATASET v1.0 Category: Game of Life ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 30
#define COLS 60

int grid[ROWS][COLS];

void initialize_grid(){
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            grid[i][j] = rand() % 2;
        }
    }
}

void print_grid(){
    printf("\n");
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            if(grid[i][j]){
                printf("\u25A0 ");
            }
            else{
                printf("\u25A1 ");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int row, int col){
    int count = 0;
    for(int i = row - 1; i <= row + 1; i++){
        for(int j = col - 1; j <= col + 1; j++){
            if(i == row && j == col){
                continue;
            }
            if(i < 0 || i >= ROWS || j < 0 || j >= COLS){
                continue;
            }
            if(grid[i][j]){
                count++;
            }
        }
    }
    return count;
}

void update_grid(){
    int new_grid[ROWS][COLS];
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            int neighbors = count_neighbors(i, j);
            if(grid[i][j]){
                if(neighbors < 2 || neighbors > 3){
                    new_grid[i][j] = 0;
                }
                else{
                    new_grid[i][j] = 1;
                }
            }
            else{
                if(neighbors == 3){
                    new_grid[i][j] = 1;
                }
                else{
                    new_grid[i][j] = 0;
                }
            }
        }
    }
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            grid[i][j] = new_grid[i][j];
        }
    }
}

int main(){
    initialize_grid();
    while(1){
        usleep(100000);
        print_grid();
        update_grid();
        system("clear");
    }
    return 0;
}