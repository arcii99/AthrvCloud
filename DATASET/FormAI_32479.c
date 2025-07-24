//FormAI DATASET v1.0 Category: Chess engine ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

void initializeBoard();
void printBoard();
void playChess();

int main() {

    initializeBoard();
    printBoard();
    playChess();

    return 0;
}

void initializeBoard() {

    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    board[0][0] = 1;
    board[0][1] = 2;
    board[0][2] = 3;
    board[0][3] = 4;
    board[0][4] = 5;
    board[0][5] = 3;
    board[0][6] = 2;
    board[0][7] = 1;

    board[1][0] = 6;
    board[1][1] = 6;
    board[1][2] = 6;
    board[1][3] = 6;
    board[1][4] = 6;
    board[1][5] = 6;
    board[1][6] = 6;
    board[1][7] = 6;

    board[7][0] = -1;
    board[7][1] = -2;
    board[7][2] = -3;
    board[7][3] = -4;
    board[7][4] = -5;
    board[7][5] = -3;
    board[7][6] = -2;
    board[7][7] = -1;

    board[6][0] = -6;
    board[6][1] = -6;
    board[6][2] = -6;
    board[6][3] = -6;
    board[6][4] = -6;
    board[6][5] = -6;
    board[6][6] = -6;
    board[6][7] = -6;

}

void printBoard() {

    int i, j;

    printf("  A B C D E F G H\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case 0:
                    printf(". ");
                    break;
                case 1:
                    printf("K ");
                    break;
                case 2:
                    printf("Q ");
                    break;
                case 3:
                    printf("R ");
                    break;
                case 4:
                    printf("B ");
                    break;
                case 5:
                    printf("N ");
                    break;
                case 6:
                    printf("P ");
                    break;
                case -1:
                    printf("k ");
                    break;
                case -2:
                    printf("q ");
                    break;
                case -3:
                    printf("r ");
                    break;
                case -4:
                    printf("b ");
                    break;
                case -5:
                    printf("n ");
                    break;
                case -6:
                    printf("p ");
                    break;
            }
        }
        printf("%d\n", i + 1);
    }

    printf("  A B C D E F G H\n");
}

void playChess() {
    // Your chess engine implementaion
}