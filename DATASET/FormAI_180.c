//FormAI DATASET v1.0 Category: Sudoku solver ; Style: accurate
#include <stdio.h>

void print_board(int board[9][9]){
    for(int i = 0 ; i < 9 ; i++ ){
        printf("|");
        for(int j = 0 ; j < 9 ; j++ ){
            printf("%d",board[i][j]);
            if(j==2 || j==5 ){
                printf("|");
            }
        }
        printf("|\n");
        if(i==2 || i==5 ){
            printf("|===|===|===|\n");
        }
    }
}

int is_valid(int board[9][9], int row, int col, int num){
    //check if the same number exists in the same row
    for(int i=0;i<9;i++){
        if(board[row][i] == num){
            return 0;
        }
    }
    //check if the same number exists in the same column
    for(int i=0;i<9;i++){
        if(board[i][col] == num){
            return 0;
        }
    }
    //check if the same number exists in the same 3x3 grid
    int start_row = row - row%3;
    int start_col = col - col%3;
    for(int i = start_row ; i < start_row + 3 ; i++ ){
        for(int j = start_col ; j < start_col + 3 ; j++ ){
            if(board[i][j] == num){
                return 0;
            }
        }
    }
    return 1;
}

int sudoku_solver(int board[9][9]){
    int row=-1;
    int col=-1;
    int flag=0;
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            if(board[i][j]==0){
                row=i;
                col=j;
                flag=1;
                break;
            }
        }
        if(flag==1){
            break;
        }
    }
    if(row==-1 || col==-1){
        return 1;
    }
    for(int num=1;num<=9;num++){
        if(is_valid(board,row,col,num)==1){
            board[row][col]=num;
            if(sudoku_solver(board)==1){
                return 1;
            }
            board[row][col]=0;
        }
    }
    return 0;
}

int main(){
    int board[9][9] = 
    {{5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9}};
    print_board(board);
    if(sudoku_solver(board)==1){
        printf("\n\nSolution:\n\n");
        print_board(board);
    }else{
        printf("\n\nNo solution found\n");
    }
}