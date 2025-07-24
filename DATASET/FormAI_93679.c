//FormAI DATASET v1.0 Category: Sudoku solver ; Style: protected
#include <stdio.h>

//Function to find if any cell is unassigned
int is_unassigned(int puzzle[9][9], int row, int col){
    for(row = 0; row < 9; row++){
        for(col = 0; col < 9; col++){
            if(puzzle[row][col] == 0){
                return 1;
            }
        }
    }
    return 0;
}

//Function to check if number can be placed in cell
int is_safe(int puzzle[9][9], int row, int col, int num){
    int i, j;
    //Column Check
    for(i=0; i<9; i++){
        if(puzzle[row][i] == num){
            return 0;
        }
    }
    //Row Check
    for(j=0; j<9; j++){
        if(puzzle[j][col] == num){
            return 0;
        }
    }
    //Box Check
    int x = col - col%3;
    int y = row - row%3;
    for(i=0; i<3; i++){
        for(j=0; j<3; j++){
            if(puzzle[i+y][j+x] == num){
                return 0;
            }
        }
    }   
    return 1;
}

//Function to solve the sudoku
int solve_sudoku(int puzzle[9][9], int row, int col){
    if(!is_unassigned(puzzle, row, col)){
        return 1;
    }
    int i, num;
    for(num=1; num<=9; num++){
        if(is_safe(puzzle, row, col, num)){
            puzzle[row][col] = num;
            if(solve_sudoku(puzzle, row, col)){
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    return 0;
}

//Function to display the Sudoku
void print_sudoku(int puzzle[9][9]){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            printf("%d ", puzzle[i][j]);
            if(j == 2 || j == 5){
                printf("| ");
            }
        }
        printf("\n");
        if(i == 2 || i == 5){
            printf("--------------------- \n");
        }
    }
}

int main(){
    int puzzle[9][9] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                        {6, 0, 0, 1, 9, 5, 0, 0, 0},
                        {0, 9, 8, 0, 0, 0, 0, 6, 0},
                        {8, 0, 0, 0, 6, 0, 0, 0, 3},
                        {4, 0, 0, 8, 0, 3, 0, 0, 1},
                        {7, 0, 0, 0, 2, 0, 0, 0, 6},
                        {0, 6, 0, 0, 0, 0, 2, 8, 0},
                        {0, 0, 0, 4, 1, 9, 0, 0, 5},
                        {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    if(solve_sudoku(puzzle, 0, 0)){
        print_sudoku(puzzle);
    }
    else{
        printf("No solution exists.");
    }
    return 0;
}