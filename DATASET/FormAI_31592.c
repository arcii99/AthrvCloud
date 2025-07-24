//FormAI DATASET v1.0 Category: Percolation Simulator ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void print_grid(int grid[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(grid[i][j] == 0)
                printf(" ");
            else if(grid[i][j] == 1)
                printf("*");
            else
                printf("X");
        }
        printf("\n");
    }
}

int is_percolated(int grid[SIZE][SIZE]){
    int top_row[SIZE] = {0};
    for(int i = 0; i < SIZE; i++){
        if(grid[0][i] == 1)
            top_row[i] = 1;
    }

    for(int i = 1; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(grid[i][j] == 1){
                if(j > 0 && top_row[j-1])
                    top_row[j] = 1;
                if(top_row[j])
                    return 1;
                if(j < SIZE-1 && top_row[j+1])
                    top_row[j] = 1;
            }
        }
    }
    return 0;
}

void percolate(int grid[SIZE][SIZE]){
    // Randomly select top row
    int chosen_column = rand() % SIZE;
    grid[0][chosen_column] = 1;

    while(!is_percolated(grid)){
        // Randomly select a position to open
        int row, col;
        do{
            row = rand() % SIZE;
            col = rand() % SIZE;
        }while(grid[row][col] == 1);

        // Open the position
        grid[row][col] = 1;

        // Connect to neighboring sites if they are open
        if(row > 0 && grid[row-1][col] == 1){
            if(grid[row-1][col] != chosen_column)
                grid[row][col] = grid[row-1][col];
        }
        if(row < SIZE-1 && grid[row+1][col] == 1){
            if(grid[row+1][col] != chosen_column)
                grid[row][col] = grid[row+1][col];
        }
        if(col > 0 && grid[row][col-1] == 1){
            if(grid[row][col-1] != chosen_column)
                grid[row][col] = grid[row][col-1];
        }
        if(col < SIZE-1 && grid[row][col+1] == 1){
            if(grid[row][col+1] != chosen_column)
                grid[row][col] = grid[row][col+1];
        }
    }
}

int main(){
    int grid[SIZE][SIZE] = {0};
    srand(time(NULL));

    percolate(grid);

    print_grid(grid);

    return 0;
}