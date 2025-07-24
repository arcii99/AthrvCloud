//FormAI DATASET v1.0 Category: Sudoku solver ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define GRID_DIM 9

int find_empty_location(int arr[][GRID_DIM], int *row, int *col);
int is_valid_move(int arr[][GRID_DIM], int row, int col, int num);
int solve_sudoku(int arr[][GRID_DIM]);
void print_solution(int arr[][GRID_DIM]);

int main(){
    int grid[GRID_DIM][GRID_DIM] = {{0,8,0,0,0,9,7,0,0},
                                     {7,0,0,0,0,0,0,0,0},
                                     {0,1,0,0,0,5,0,0,9},
                                     {0,0,0,5,0,0,0,0,0},
                                     {0,0,0,0,4,0,0,6,0},
                                     {3,0,6,0,7,0,0,0,1},
                                     {0,0,0,0,0,0,0,0,6},
                                     {0,0,0,0,0,0,4,0,0},
                                     {0,0,0,0,0,2,0,0,0}};
    printf("Input Sudoku:\n");
    print_solution(grid);

    if(solve_sudoku(grid)){
        printf("\nSolved Sudoku:\n");
        print_solution(grid);
    }
    else{
        printf("\nCould not solve sudoku. Please check input and try again.\n");
    }

    return 0;
}

// Finds empty location in the sudoku grid
int find_empty_location(int arr[][GRID_DIM], int *row, int *col){
    for(*row=0; *row<GRID_DIM; (*row)++){
        for(*col=0; *col<GRID_DIM; (*col)++){
            if(arr[*row][*col] == 0){
                return TRUE;
            }
        }
    }
    return FALSE;
}

// Check if move is valid in the sudoku grid
int is_valid_move(int arr[][GRID_DIM], int row, int col, int num){
    int i, j;
    // Check row
    for(i=0; i<GRID_DIM; i++){
        if(arr[row][i]==num){
            return FALSE;
        }
    }
    // Check column
    for(i=0; i<GRID_DIM; i++){
        if(arr[i][col]==num){
            return FALSE;
        }
    }
    // Check small 3x3 grid
    int small_grid_x = (row/3)*3;
    int small_grid_y = (col/3)*3;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(arr[small_grid_x+i][small_grid_y+j]==num){
                return FALSE;
            }
        }
    }
    return TRUE;
}

// Solves the sudoku grid using backtracking
int solve_sudoku(int arr[][GRID_DIM]){
    int row, col;
    if(!find_empty_location(arr, &row, &col)){
        return TRUE;
    }
    int num;
    for(num=1; num<=9; num++){
        if(is_valid_move(arr, row, col, num)){
            arr[row][col] = num;
            if(solve_sudoku(arr)){
                return TRUE;
            }
            arr[row][col] = 0;
        }
    }
    return FALSE;
}

// Prints the solved sudoku grid
void print_solution(int arr[][GRID_DIM]){
    int i, j;
    for(i=0; i<GRID_DIM; i++){
        for(j=0; j<GRID_DIM; j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}