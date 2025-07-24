//FormAI DATASET v1.0 Category: Table Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 6
#define COLS 7

void printBoard(char board[ROWS][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  1   2   3   4   5   6   7\n");
}

int makeMove(char board[ROWS][COLS], int col, char piece) {
    for(int i = ROWS - 1; i >= 0; i--) {
        if(board[i][col] == ' ') {
            board[i][col] = piece;
            return i;
        }
    }
    return -1;
}

int checkWin(char board[ROWS][COLS], int row, int col) {
    char piece = board[row][col];

    // Check horizontal
    for(int j = 0; j <= COLS - 4; j++) {
        if(board[row][j] == piece && board[row][j+1] == piece && board[row][j+2] == piece && board[row][j+3] == piece) {
            return 1;
        }
    }

    // Check vertical
    for(int i = 0; i <= ROWS - 4; i++) {
        if(board[i][col] == piece && board[i+1][col] == piece && board[i+2][col] == piece && board[i+3][col] == piece) {
            return 1;
        }
    }

    // Check diagonal (down-right)
    for(int i = 0; i <= ROWS - 4; i++) {
        for(int j = 0; j <= COLS - 4; j++) {
            if(board[i][j] == piece && board[i+1][j+1] == piece && board[i+2][j+2] == piece && board[i+3][j+3] == piece) {
                return 1;
            }
        }
    }

    // Check diagonal (up-right)
    for(int i = 3; i < ROWS; i++) {
        for(int j = 0; j <= COLS - 4; j++) {
            if(board[i][j] == piece && board[i-1][j+1] == piece && board[i-2][j+2] == piece && board[i-3][j+3] == piece) {
                return 1;
            }
        }
    }

    return 0;
}

int main() {
    char board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    int currentPlayer = 1;
    char pieces[2] = {'X', 'O'};
    int col;
    int row;
    int winner = 0;

    srand(time(NULL));

    while(!winner) {
        printBoard(board);
        printf("Player %d's turn. Please choose a column (1-7): ", currentPlayer);
        scanf("%d", &col);
        col--;

        row = makeMove(board, col, pieces[currentPlayer-1]);

        while(row == -1) {
            printf("Column full. Please choose a different column (1-7): ");
            scanf("%d", &col);
            col--;
            row = makeMove(board, col, pieces[currentPlayer-1]);
        }

        winner = checkWin(board, row, col);

        if(currentPlayer == 1) {
            currentPlayer = 2;
        } else {
            currentPlayer = 1;
        }
    }

    printf("Congratulations Player %d! You have won!\n", currentPlayer);

    return 0;
}