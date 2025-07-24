//FormAI DATASET v1.0 Category: Game of Life ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

int grid[SIZE][SIZE];

void initialize_grid() {
    int i, j;
    srand(time(NULL));
    for(i = 0; i<SIZE; i++){
        for(j = 0; j<SIZE; j++){
            if(rand()%2 == 0)
                grid[i][j] = 0;
            else
                grid[i][j] = 1;
        }
    }
}

void display_grid() {
    int i, j;
    printf("\n");
    for(i = 0; i<SIZE; i++){
        for(j = 0; j<SIZE; j++){
            if(grid[i][j] == 0)
                printf(".");
            else
                printf("*");
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbours(int row, int col) {
    int count = 0;
    if(row-1>=0 && col-1>=0 && grid[row-1][col-1] == 1)
        count++;
    if(row-1>=0 && grid[row-1][col] == 1)
        count++;
    if(row-1>=0 && col+1<SIZE && grid[row-1][col+1] == 1)
        count++;
    if(col-1>=0 && grid[row][col-1] == 1)
        count++;
    if(col+1<SIZE && grid[row][col+1] == 1)
        count++;
    if(row+1<SIZE && col-1>=0 && grid[row+1][col-1] == 1)
        count++;
    if(row+1<SIZE && grid[row+1][col] == 1)
        count++;
    if(row+1<SIZE && col+1<SIZE && grid[row+1][col+1] == 1)
        count++;
    return count;
}

void copy_grid(int copy[SIZE][SIZE]) {
    int i, j;
    for(i = 0; i<SIZE; i++){
        for(j = 0; j<SIZE; j++){
            copy[i][j] = grid[i][j];
        }
    }
}

int main() {

    initialize_grid();
    display_grid();
    
    int copy[SIZE][SIZE];
    int i, j, neighbours;
    while(1) {
        copy_grid(copy);
        for(i = 0; i<SIZE; i++){
            for(j = 0; j<SIZE; j++){
                neighbours = count_neighbours(i,j);
                if(copy[i][j] == 1 && (neighbours<2 || neighbours>3))
                    grid[i][j] = 0;
                else if(copy[i][j] == 0 && neighbours == 3)
                    grid[i][j] = 1;
            }
        }
        display_grid();
    }
    return 0;
}