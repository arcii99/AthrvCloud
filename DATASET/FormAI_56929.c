//FormAI DATASET v1.0 Category: Sudoku solver ; Style: Ada Lovelace
#include <stdio.h>

#define N 9

int grid[N][N];

int row_check(int row, int num){
    for(int col=0; col<N; col++){
        if(grid[row][col] == num){
            return 0;
        }
    }
    return 1;
}

int col_check(int col, int num){
    for(int row=0; row<N; row++){
        if(grid[row][col] == num){
            return 0;
        }
    }
    return 1;
}

int box_check(int row_start, int col_start, int num){
    for(int row=0; row<3; row++){
        for(int col=0; col<3; col++){
            if(grid[row+row_start][col+col_start] == num){
                return 0;
            }
        }
    }
    return 1;
}

int possible(int row, int col, int num){
    return row_check(row, num) && col_check(col, num) && box_check(row-row%3, col-col%3, num);
}

int solve(){
    int row, col;
    for(row=0; row<N; row++){
        for(col=0; col<N; col++){
            if(grid[row][col] == 0){
                for(int num=1; num<=9; num++){
                    if(possible(row, col, num)){
                        grid[row][col] = num;
                        if(solve()){
                            return 1;
                        }
                        grid[row][col] = 0;
                    }
                }
                return 0;
            }
        }
    }
    return 1;
}

void print(){
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            printf("%d ",grid[row][col]);
        }
        printf("\n");
    }
}

int main(){
    printf("Enter the Sudoku grid:\n");
    for(int row=0; row<N; row++){
        for(int col=0; col<N; col++){
            scanf("%d",&grid[row][col]);
        }
    }
    if(solve()){
        printf("The solved Sudoku grid is:\n");
        print();
    }
    else{
        printf("No solution exists.\n");
    }
    return 0;
}