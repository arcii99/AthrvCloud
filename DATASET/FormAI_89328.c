//FormAI DATASET v1.0 Category: Table Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 6
#define MAX_MOVES 18

void initializeBoard(char board[][COLS]) {
    for(int i=0 ; i<ROWS ; i++) {
        for(int j=0 ; j<COLS ; j++) {
            board[i][j] = '.';
        }
    }
}

void printBoard(char board[][COLS]) {
    printf("\n");
    printf("   ");
    for(int i=0 ; i<COLS ; i++) {
        printf("%-2d ", i+1);
    }
    printf("\n");

    for(int i=0 ; i<ROWS ; i++) {
        printf("%-2d ", i+1);
        for(int j=0 ; j<COLS ; j++) {
            printf("%-2c ", board[i][j]);
        }
        printf("\n");
    }
}

int isValidMove(char board[][COLS], int row, int col) {
    if(row>=0 && row<ROWS && col>=0 && col<COLS && board[row][col]=='.') {
        return 1;
    }
    return 0;
}

void computerMove(char board[][COLS], int *row, int *col) {
    srand(time(NULL));
    do {
        *row = rand() % ROWS;
        *col = rand() % COLS;
    } while(!isValidMove(board, *row, *col));
}

int checkWin(char board[][COLS], char player) {
    int fullRow, fullCol, fullDiag1, fullDiag2;

    // check rows
    for(int i=0 ; i<ROWS ; i++) {
        fullRow = 1;
        for(int j=0 ; j<COLS ; j++) {
            if(board[i][j] != player) {
                fullRow = 0;
                break;
            }
        }
        if(fullRow) {
            return 1;
        }
    }

    // check columns
    for(int j=0 ; j<COLS ; j++) {
        fullCol = 1;
        for(int i=0 ; i<ROWS ; i++) {
            if(board[i][j] != player) {
                fullCol = 0;
                break;
            }
        }
        if(fullCol) {
            return 1;
        }
    }

    // check diagonal (top-left to bottom-right)
    fullDiag1 = 1;
    for(int i=0 ; i<ROWS ; i++) {
        if(board[i][i] != player) {
            fullDiag1 = 0;
            break;
        }
    }
    if(fullDiag1) {
        return 1;
    }

    // check diagonal (top-right to bottom-left)
    fullDiag2 = 1;
    for(int i=0 ; i<ROWS ; i++) {
        if(board[i][COLS-i-1] != player) {
            fullDiag2 = 0;
            break;
        }
    }
    if(fullDiag2) {
        return 1;
    }

    // no win conditions met
    return 0;
}

void playGame(char board[][COLS]) {
    int row, col, moves = 0;
    char player = 'X';

    while(moves < MAX_MOVES) {
        printf("\n\n%s's turn.\n", player == 'X' ? "Player" : "Computer");
        if(player == 'X') {
            printf("Enter row (1-6): ");
            scanf("%d", &row);
            row--;
            printf("Enter column (1-6): ");
            scanf("%d", &col);
            col--;
        } else {
            computerMove(board, &row, &col);
        }

        if(isValidMove(board, row, col)) {
            board[row][col] = player;
            printBoard(board);
            if(checkWin(board, player)) {
                printf("\n\n%s wins!\n\n", player == 'X' ? "Player" : "Computer");
                return;
            }
            player = player == 'X' ? 'O' : 'X';
            moves++;
        } else {
            printf("\n\nInvalid move. Try again.\n");
        }
    }

    printf("\n\nGame Over. No winner.\n\n");
}

int main() {
    char board[ROWS][COLS];
    initializeBoard(board);
    printBoard(board);
    playGame(board);
    return 0;
}