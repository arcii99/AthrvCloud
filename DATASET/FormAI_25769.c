//FormAI DATASET v1.0 Category: Table Game ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

void printBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    
    for (int i = 0; i < COLS; i++) {
        printf("  %d ", i+1);
    }
    printf("\n");
}

int dropPiece(char board[][COLS], int col, char piece) {
    int i;
    for (i = ROWS-1; i >= 0; i--) {
        if (board[i][col] == '-') {
            board[i][col] = piece;
            return i;
        }
    }
    return -1;
}

int checkWin(char board[][COLS], int row, int col, char piece) {
    int count = 0;
    int i, j;
    
    //check for vertical win
    for (i = row-3; i <= row+3; i++) {
        if (i >= 0 && i+3 < ROWS) {
            count = 0;
            for (j = i; j <= i+3; j++) {
                if (board[j][col] == piece) {
                    count++;
                }
            }
            if (count == 4) {
                return 1;
            }
        }
    }
    
    //check for horizontal win
    for (j = col-3; j <= col+3; j++) {
        if (j >= 0 && j+3 < COLS) {
            count = 0;
            for (i = j; i <= j+3; i++) {
                if (board[row][i] == piece) {
                    count++;
                }
            }
            if (count == 4) {
                return 1;
            }
        }
    }
    
    //check for backward diagonal win
    for (i = row-3, j = col-3; i <= row+3 && j <= col+3; i++, j++) {
        if (i >= 0 && i+3 < ROWS && j >= 0 && j+3 < COLS) {
            count = 0;
            for (int n = 0; n < 4; n++) {
                if (board[i+n][j+n] == piece) {
                    count++;
                }
            }
            if (count == 4) {
                return 1;
            }
        }
    }
    
    //check for forward diagonal win
    for (i = row+3, j = col-3; i >= row-3 && j <= col+3; i--, j++) {
        if (i >= 0 && i-3 < ROWS && j >= 0 && j+3 < COLS) {
            count = 0;
            for (int n = 0; n < 4; n++) {
                if (board[i-n][j+n] == piece) {
                    count++;
                }
            }
            if (count == 4) {
                return 1;
            }
        }
    }
    
    return 0; //no win
}

int main() {
    char board[ROWS][COLS];
    int col;
    int row;
    char curPlayer = 'X';
    int gameOver = 0;
    
    //initialize board with empty spaces
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
    
    srand(time(0)); //seed random number generator
    
    printf("Welcome to Connect Four!\n");
    printf("Player 1: X\n");
    printf("Player 2: O\n\n");
    
    while (!gameOver) {
        printBoard(board);
        printf("Player %c's turn.\n", curPlayer);
        
        if (curPlayer == 'X') { //player X
            printf("Please enter a column: ");
            scanf("%d", &col);
            while (col < 1 || col > 7 || board[0][col-1] != '-') { //invalid column
                printf("Invalid column. Please enter a column: ");
                scanf("%d", &col);
            }
        }
        else { //player O (computer)
            col = rand() % 7 + 1; //random number between 1 and 7
            while (board[0][col-1] != '-') { //column full
                col = rand() % 7 + 1; //pick new column
            }
            printf("Computer chose column %d.\n", col);
        }
        
        row = dropPiece(board, col-1, curPlayer); //drop piece
        
        if (checkWin(board, row, col-1, curPlayer)) { //win
            printBoard(board);
            printf("Player %c wins!\n", curPlayer);
            gameOver = 1;
        }
        else if (row == 0 && checkWin(board, row, col-1, '-')) { //tie
            printBoard(board);
            printf("It's a tie!\n");
            gameOver = 1;
        }
        
        //switch player
        if (curPlayer == 'X') {
            curPlayer = 'O';
        }
        else {
            curPlayer = 'X';
        }
    }
    
    return 0;
}