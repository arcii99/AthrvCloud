//FormAI DATASET v1.0 Category: Table Game ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//function to display the table
void display_table(int table[][10], int rows){
    for(int i=0; i<rows; i++){
        for(int j=0; j<10; j++){
            printf("%d ", table[i][j]);
        }
        printf("\n");
    }
}

//function to check if the move is valid
int is_valid_move(int table[][10], int row, int col, int num){
    //check if the number is already present in the row
    for(int i=0; i<10; i++){
        if(table[row][i] == num){
            return 0;
        }
    }

    //check if the number is already present in the column
    for(int i=0; i<10; i++){
        if(table[i][col] == num){
            return 0;
        }
    }

    //check if the number is already present in the corresponding 3x3 square
    int square_row = (row / 3) * 3;
    int square_col = (col / 3) * 3;
    for(int i=square_row; i<square_row+3; i++){
        for(int j=square_col; j<square_col+3; j++){
            if(table[i][j] == num){
                return 0;
            }
        }
    }

    //if the number is not already present, return 1
    return 1;
}

//function to solve the table using backtracking
int solve_table(int table[][10], int row, int col){
    //if all the cells have been filled, return 1 as the table is solved
    if(row == 9 && col == 10){
        return 1;
    }

    //if the column index goes beyond 9, move to the next row 
    if(col >= 10){
        row++;
        col = 0;
    }

    //skip the filled cells
    if(table[row][col] > 0){
        return solve_table(table, row, col+1);
    }

    //try to fill each cell with a number between 1 and 9
    for(int num=1; num<=9; num++){
        if(is_valid_move(table, row, col, num)){
            table[row][col] = num;
            if(solve_table(table, row, col+1)){
                return 1;
            }
            table[row][col] = 0;
        }
    }
    //if no valid move is possible, backtrack to the previous cell
    return 0;
}

int main(){
    int table[9][10] = {{0,0,0,0,0,8,0,0,0,3},
                        {7,0,0,0,2,0,1,8,0,0},
                        {0,2,0,0,0,0,6,0,0,0},
                        {0,0,0,0,9,0,5,3,4,0},
                        {0,0,0,3,7,2,0,0,0,0},
                        {0,0,0,0,0,0,0,1,0,0},
                        {9,0,0,0,0,7,8,0,0,1},
                        {4,0,3,0,0,0,0,0,0,5},
                        {0,0,6,0,0,0,0,0,0,0}};

    printf("Initial Table:\n");
    display_table(table, 9);

    //solve the table using backtracking
    if(solve_table(table, 0, 0)){
        printf("\nSolved Table:\n");
        display_table(table, 9);
    } else{
        printf("\nNo solution found.\n");
    }

    return 0;
}