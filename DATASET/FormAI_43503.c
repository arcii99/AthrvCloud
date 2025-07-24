//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define GRID_SIZE 9
#define SUBGRID_SIZE 3

typedef struct Possible_values{
    bool arePossible[GRID_SIZE];
    int count;
}Possible_values;

Possible_values get_possible_values(int grid[][GRID_SIZE], int row, int col){
    Possible_values possible_values;
    memset(possible_values.arePossible, true, GRID_SIZE);

    for(int i=0; i<GRID_SIZE; i++){
        if(grid[row][i] != 0){
            possible_values.arePossible[grid[row][i]-1] = false;
        }
        if(grid[i][col] != 0){
            possible_values.arePossible[grid[i][col]-1] = false;
        }
    }

    int subgrid_row = (row/SUBGRID_SIZE)*SUBGRID_SIZE, subgrid_col = (col/SUBGRID_SIZE)*SUBGRID_SIZE;
    for(int i=subgrid_row; i<subgrid_row+SUBGRID_SIZE; i++){
        for(int j=subgrid_col; j<subgrid_col+SUBGRID_SIZE; j++){
            if(grid[i][j] != 0){
                possible_values.arePossible[grid[i][j]-1] = false;
            }
        }
    }

    possible_values.count = 0;
    for(int i=0; i<GRID_SIZE; i++){
        if(possible_values.arePossible[i]){
            possible_values.count++;
        }
    }

    return possible_values;
}

bool solve_sudoku(int grid[][GRID_SIZE], int row, int col){
    if(row == GRID_SIZE){
        return true;
    }

    int next_row = col == GRID_SIZE-1 ? row+1 : row;
    int next_col = (col+1) % GRID_SIZE;

    if(grid[row][col] != 0){
        return solve_sudoku(grid, next_row, next_col);
    }

    Possible_values possible_values = get_possible_values(grid, row, col);

    if(possible_values.count == 0){
        return false;
    }

    for(int i=0; i<GRID_SIZE; i++){
        if(possible_values.arePossible[i]){
            grid[row][col] = i+1;
            if(solve_sudoku(grid, next_row, next_col)){
                return true;
            }
            grid[row][col] = 0;
        }
    }

    return false;
}

void print_grid(int grid[][GRID_SIZE]){
    printf("\n-----------------\n");
    for(int i=0; i<GRID_SIZE; i++){
        for(int j=0; j<GRID_SIZE; j++){
            printf("%d ", grid[i][j]);
            if((j+1)%SUBGRID_SIZE == 0){
                printf("| ");
            }
        }
        printf("\n");
        if((i+1)%SUBGRID_SIZE == 0){
            printf("-----------------\n");
        }
    }
}

int main(){
    int grid[GRID_SIZE][GRID_SIZE] = {
        {0, 0, 0, 0, 6, 4, 0, 0, 0},
        {7, 0, 0, 0, 0, 0, 3, 9, 0},
        {8, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 5, 0, 2, 0, 6, 0},
        {0, 8, 0, 4, 0, 0, 0, 0, 0},
        {3, 5, 0, 6, 1, 0, 0, 0, 0},
        {0, 0, 4, 0, 0, 0, 0, 0, 9},
        {0, 0, 0, 0, 0, 0, 0, 2, 0},
        {0, 0, 0, 0, 3, 0, 0, 0, 0},
    };

    printf("\nHere is the original grid:\n");
    print_grid(grid);

    if(solve_sudoku(grid, 0, 0)){
        printf("\nHere is the solved Sudoku grid:\n");
        print_grid(grid);
    }else{
        printf("\nSorry, I could not solve this Sudoku!\n");
    }

    return 0;
}