//FormAI DATASET v1.0 Category: Chess engine ; Style: automated
#include <stdio.h>

void printBoard(char board[][8]) {
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void initBoard(char board[][8]) {
    // Initialize the board with starting positions
    board[0][0] = 'r';
    board[0][1] = 'n';
    board[0][2] = 'b';
    board[0][3] = 'q';
    board[0][4] = 'k';
    board[0][5] = 'b';
    board[0][6] = 'n';
    board[0][7] = 'r';

    for(int i = 0; i < 8; i++) {
        board[1][i] = 'p';
    }

    for(int i = 2; i < 6; i++) {
        for(int j = 0; j < 8; j++) {
            board[i][j] = '.';
        }
    }

    for(int i = 0; i < 8; i++) {
        board[6][i] = 'P';
    }

    board[7][0] = 'R';
    board[7][1] = 'N';
    board[7][2] = 'B';
    board[7][3] = 'Q';
    board[7][4] = 'K';
    board[7][5] = 'B';
    board[7][6] = 'N';
    board[7][7] = 'R';
}

int main() {

    char board[8][8];
    initBoard(board);
    printBoard(board);

    return 0;
}