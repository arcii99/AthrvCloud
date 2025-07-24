//FormAI DATASET v1.0 Category: Chess engine ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char board[8][8];

void printBoard() {
    int i, j;
    printf("\n   A B C D E F G H\n");

    for (i = 0; i < 8; i++) {
        printf("%d  ", i + 1);
        for (j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i + 1);
    }
    printf("   A B C D E F G H\n");
}

void initializeBoard() {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            board[i][j] = '-';
        }
    }
}

void placePieces() {
    int i;
    for (i = 0; i < 8; i++) {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }
    board[0][0] = 'r';
    board[0][7] = 'r';
    board[7][0] = 'R';
    board[7][7] = 'R';

    board[0][1] = 'n';
    board[0][6] = 'n';
    board[7][1] = 'N';
    board[7][6] = 'N';

    board[0][2] = 'b';
    board[0][5] = 'b';
    board[7][2] = 'B';
    board[7][5] = 'B';

    board[0][3] = 'q';
    board[7][3] = 'Q';

    board[0][4] = 'k';
    board[7][4] = 'K';
}

int main() {
    initializeBoard();
    placePieces();
    printBoard();
    return 0;
}