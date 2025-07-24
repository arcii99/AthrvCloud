//FormAI DATASET v1.0 Category: Sudoku solver ; Style: futuristic
#include <stdio.h>
#define N 9

int grid[N][N]={
    {0,0,0,3,0,0,0,0,5},
    {8,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,9},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0}
};

void print_grid(int arr[N][N]){
    for(int i=0; i<N; i++){
        if(i%3==0 && i!=0){
            printf("---+---+---\n");
        }
        for(int j=0; j<N; j++){
            if(j%3==0 && j!=0){
                printf("|");
            }
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }
}

int find_zero(int arr[N][N], int *row, int *col){
    for(*row=0; *row<N; (*row)++){
        for(*col=0; *col<N; (*col)++){
            if(arr[*row][*col]==0){
                return 1; // true
            }
        }
    }
    return 0; // false
}

int is_valid(int arr[N][N], int row, int col, int num){
    // check row
    for(int i=0; i<N; i++){
        if(arr[row][i]==num){
            return 0; // false
        }
    }
    // check column
    for(int i=0; i<N; i++){
        if(arr[i][col]==num){
            return 0; // false
        }
    }
    // check subgrid
    int subgrid_row = (row/3)*3;
    int subgrid_col = (col/3)*3;
    for(int i=subgrid_row; i<subgrid_row+3; i++){
        for(int j=subgrid_col; j<subgrid_col+3; j++){
            if(arr[i][j]==num){
                return 0; // false
            }
        }
    }
    return 1; // true
}

int solve_sudoku(int arr[N][N]){
    int row, col;
    if(!find_zero(arr, &row, &col)){
        return 1; // sudoku solved
    }
    for(int num=1; num<=9; num++){
        if(is_valid(arr, row, col, num)){
            arr[row][col] = num;
            if(solve_sudoku(arr)){
                return 1; // sudoku solved
            }
            arr[row][col] = 0;
        }
    }
    return 0; // sudoku unsolvable
}

int main(){
    printf("Original Sudoku Grid:\n");
    print_grid(grid);
    printf("\nSolved Sudoku Grid:\n");
    if(solve_sudoku(grid)){
        print_grid(grid);
    } else{
        printf("Sudoku cannot be solved.");
    }
    return 0;
}