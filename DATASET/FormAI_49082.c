//FormAI DATASET v1.0 Category: Sudoku solver ; Style: rigorous
#include <stdio.h>

#define N 9

int board[N][N] = { {0, 6, 0, 0, 0, 0, 0, 8, 0},     // Sudoku board needs to be solved
                    {5, 0, 0, 3, 1, 0, 0, 0, 7},
                    {0, 8, 9, 0, 0, 0, 0, 0, 0},
                    {1, 0, 0, 0, 0, 7, 0, 0, 8},
                    {0, 0, 0, 0, 0, 0, 0, 0, 0},
                    {8, 0, 0, 6, 0, 0, 0, 0, 3},
                    {0, 0, 0, 0, 0, 0, 7, 5, 0},
                    {6, 0, 0, 0, 4, 8, 0, 0, 0},
                    {0, 7, 0, 0, 0, 0, 0, 9, 0} };

// Function to print the Sudoku 
void printBoard() {
    printf("\n");
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%d ", board[i][j]);
            if(j==2 || j==5) printf(" ");
        }
        if(i==2 || i==5) printf("\n");
        printf("\n");
    }
}

// Function to check if a number can be placed at a given position
int canPlace(int r, int c, int num) {
    for(int i=0; i<N; i++) {
        if(board[i][c] == num || board[r][i] == num) return 0;
    }
    int row = (r/3)*3;
    int col = (c/3)*3;
    for(int i=row; i<row+3; i++) {
        for(int j=col; j<col+3; j++) {
            if(board[i][j] == num) return 0;
        }
    }
    return 1;
}

// Function to solve the Sudoku board
int solve(int r, int c) {
    if(r == N) return 1;
    if(c == N) return solve(r+1, 0);
    if(board[r][c] != 0) return solve(r, c+1);
    for(int num=1; num<=N; num++) {
        if(canPlace(r, c, num)) {
            board[r][c] = num;
            if(solve(r, c+1)) return 1;
            board[r][c] = 0;
        }
    }
    return 0;
}

int main() {
    printf("Sudoku board before solving:\n");
    printBoard();
    if(solve(0,0)) {
        printf("Sudoku board solved:\n");
        printBoard();
    } else {
        printf("Sudoku board could not be solved\n");
    }
    return 0;
}