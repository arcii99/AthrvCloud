//FormAI DATASET v1.0 Category: Sudoku solver ; Style: beginner-friendly
#include<stdio.h>
#include<math.h>

int isValid(int board[9][9], int row, int col, int num);
int solveSudoku(int board[9][9], int row, int col);
void printBoard(int board[9][9]);

int isValid(int board[9][9], int row, int col, int num){
    int i, j;
    // Check vertical and horizontal
    for(i=0;i<9;i++){
        if(board[row][i] == num) return 0;
        if(board[i][col] == num) return 0;
    }
    // Check grid
    int a = row - row%3;
    int b = col - col%3;
    for(i=a;i<a+3;i++){
        for(j=b;j<b+3;j++){
            if(board[i][j] == num) return 0;
        }
    }
    return 1;
}

int solveSudoku(int board[9][9], int row, int col){
    // Move to next row if column exceeds 8th
    if(col > 8){
        col = 0;
        row++;
    }
    // Reached end of the grid
    if(row > 8){
        return 1;
    }
    // Skip if already filled
    if(board[row][col] != 0){
        return solveSudoku(board, row, col + 1);
    }
    int i;
    for(i=1;i<=9;i++){
        if(isValid(board, row, col, i)){
            board[row][col] = i;
            if(solveSudoku(board, row, col + 1) == 1){
                return 1;
            }
        }
        board[row][col] = 0;  // Backtrack
    }
    return 0;
}

void printBoard(int board[9][9]){
    int i, j;
    for(i=0;i<9;i++){
        printf("|");
        for(j=0;j<9;j++){
            printf(" %d ", board[i][j]);
            if(j%3 == 2) printf("|");
        }
        printf("\n");
        if(i%3 == 2){
            printf("+");
            for(j=0;j<9;j++){
                printf("---+");
            }
            printf("\n");
        }
    }
}

int main(){
    int board[9][9] = {
        {0, 0, 0, 7, 4, 0, 8, 0, 0},
        {0, 8, 0, 0, 0, 6, 0, 0, 0},
        {2, 0, 0, 0, 0, 8, 0, 0, 5},
        {0, 0, 8, 6, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 6, 7, 0},
        {0, 1, 6, 0, 0, 9, 0, 0, 0},
        {0, 7, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 9, 0},
        {5, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    printf("Unsolved:\n");
    printBoard(board);
    if(solveSudoku(board, 0, 0) == 1){
        printf("\nSolved:\n");
        printBoard(board);
    }else{
        printf("Not solvable!\n");
    }
    return 0;
}