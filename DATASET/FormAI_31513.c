//FormAI DATASET v1.0 Category: Checkers Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROWS 8
#define COLS 8

void printBoard(char board[ROWS][COLS]) {
    printf("\n  0 1 2 3 4 5 6 7\n");
    printf("  ----------------\n");
    for(int i=0; i<ROWS; i++) {
        printf("%d|", i);
        for(int j=0; j<COLS; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        printf(" -----------------\n");
    }
}

void initializeBoard(char board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if((i+j)%2 == 0) {
                if(i < 3) {
                    board[i][j] = 'x';
                } else if(i > 4) {
                    board[i][j] = 'o';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

int isValidMove(char board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    if(board[row2][col2] != ' ' || (row2+col2)%2 != 0) {
        return 0;
    }
    if(abs(row2 - row1) == 1 && abs(col2 - col1) == 1) {
        return 1;
    } else if(abs(row2 - row1) == 2 && abs(col2 - col1) == 2) {
        int r = (row1 + row2)/2;
        int c = (col1 + col2)/2;
        if(board[r][c] == 'x' || (board[r][c] == 'X' && board[row1][col1] == 'o')) {
            return 2;
        }
    }
    return 0;
}

void makeMove(char board[ROWS][COLS], int row1, int col1, int row2, int col2) {
    board[row2][col2] = board[row1][col1];
    board[row1][col1] = ' ';
    if(abs(row2 - row1) == 2 && abs(col2 - col1) == 2) {
        int r = (row1 + row2)/2;
        int c = (col1 + col2)/2;
        board[r][c] = ' ';
    }
    if(board[row2][col2] == 'o' && row2 == ROWS-1) {
        board[row2][col2] = 'X';
    } else if(board[row2][col2] == 'x' && row2 == 0) {
        board[row2][col2] = 'O';
    }
}

int getComputerMove(char board[ROWS][COLS], int *row1, int *col1, int *row2, int *col2) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            if(board[i][j] == 'o' || board[i][j] == 'O') {
                if(i+1 < ROWS && j-1 >= 0 && (board[i+1][j-1] == ' ' || board[i+1][j-1] == 'x' || board[i+1][j-1] == 'X')) {
                    *row1 = i; *col1 = j;
                    *row2 = i+1; *col2 = j-1;
                    return 1;
                }
                if(i+1 < ROWS && j+1 < COLS && (board[i+1][j+1] == ' ' || board[i+1][j+1] == 'x' || board[i+1][j+1] == 'X')) {
                    *row1 = i; *col1 = j;
                    *row2 = i+1; *col2 = j+1;
                    return 1;
                }
                if(board[i][j] == 'O') {
                    if(i-1 >= 0 && j-1 >= 0 && (board[i-1][j-1] == ' ' || board[i-1][j-1] == 'x' || board[i-1][j-1] == 'X')) {
                        *row1 = i; *col1 = j;
                        *row2 = i-1; *col2 = j-1;
                        return 1;
                    }
                    if(i-1 >= 0 && j+1 < COLS && (board[i-1][j+1] == ' ' || board[i-1][j+1] == 'x' || board[i-1][j+1] == 'X')) {
                        *row1 = i; *col1 = j;
                        *row2 = i-1; *col2 = j+1;
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

int getUserMove(char board[ROWS][COLS], int *row1, int *col1, int *row2, int *col2) {
    printf("Enter row and column of piece you want to move: ");
    scanf("%d %d", row1, col1);
    if(board[*row1][*col1] == ' ' || (*row1+*col1)%2 != 0) {
        return 0;
    }
    printf("Enter row and column of where you want to move the piece: ");
    scanf("%d %d", row2, col2);
    if(!isValidMove(board, *row1, *col1, *row2, *col2)) {
        return 0;
    }
    return 1;
}

int main() {
    char board[ROWS][COLS];
    int gameover = 0, choice = 0;
    int turn = 1;
    int row1, col1, row2, col2;
    initializeBoard(board);
    printf("Welcome to Checkers\n");
    printf("====================\n");
    while(!gameover) {
        printBoard(board);
        if(turn == 1) {
            while(!getUserMove(board, &row1, &col1, &row2, &col2));
        } else {
            printf("Computer's turn:\n");
            while(!getComputerMove(board, &row1, &col1, &row2, &col2));
        }
        makeMove(board, row1, col1, row2, col2);
        if(turn == 1) {
            turn = 2;
        } else {
            turn = 1;
        }
        //check if game is over
        int xcount = 0, ocount = 0;
        for(int i=0; i<ROWS; i++) {
            for(int j=0; j<COLS; j++) {
                if(board[i][j] == 'x' || board[i][j] == 'X') {
                    xcount++;
                } else if(board[i][j] == 'o' || board[i][j] == 'O') {
                    ocount++;
                }
            }
        }
        if(xcount == 0 || ocount == 0) {
            gameover = 1;
            if(xcount == 0) {
                printf("Game Over. Computer Wins!\n");
            } else {
                printf("Game Over. You Win!\n");
            }
        }
    }
    return 0;
}