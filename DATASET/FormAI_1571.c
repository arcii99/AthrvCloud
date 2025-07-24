//FormAI DATASET v1.0 Category: Checkers Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

int board[SIZE][SIZE] = {
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
};

int player = 1; // player 1 is human, player -1 is computer

void printBoard() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int isLegalMove(int x1, int y1, int x2, int y2) {
    if (x1 < 0 || y1 < 0 || x2 < 0 || y2 < 0 ||
        x1 >= SIZE || y1 >= SIZE || x2 >= SIZE || y2 >= SIZE) {
        // out of bounds
        return 0;
    }
    if (board[x1][y1] == 0 || board[x2][y2] != 0) {
        // invalid move
        return 0;
    }
    if (abs(x2 - x1) == 1 && abs(y2 - y1) == 1 && board[x1][y1] == player) {
        // regular move
        return 1;
    }
    if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2 &&
        board[x1][y1] == player &&
        board[(x1+x2)/2][(y1+y2)/2] == -player &&
        board[x2][y2] == 0) {
        // capture move
        return 1;
    }
    return 0;
}

int countPieces(int p) {
    int count = 0;
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == p) {
                count++;
            }
        }
    }
    return count;
}

int computerMove(int* x1, int* y1, int* x2, int* y2) {
    // simple AI: just makes the first legal move it finds
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == player) {
                if (isLegalMove(i, j, i+1, j+1)) {
                    *x1 = i;
                    *y1 = j;
                    *x2 = i+1;
                    *y2 = j+1;
                    return 1;
                }
                if (isLegalMove(i, j, i+1, j-1)) {
                    *x1 = i;
                    *y1 = j;
                    *x2 = i+1;
                    *y2 = j-1;
                    return 1;
                }
                if (isLegalMove(i, j, i+2, j+2)) {
                    *x1 = i;
                    *y1 = j;
                    *x2 = i+2;
                    *y2 = j+2;
                    return 1;
                }
                if (isLegalMove(i, j, i+2, j-2)) {
                    *x1 = i;
                    *y1 = j;
                    *x2 = i+2;
                    *y2 = j-2;
                    return 1;
                }
            }
        }
    }
    return 0;
}

int main() {
    int x1, y1, x2, y2;
    while (1) {
        printBoard();
        if (player == 1) {
            printf("Enter move (x1 y1 x2 y2): ");
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        } else {
            printf("Computer thinking...\n");
            computerMove(&x1, &y1, &x2, &y2);
        }
        if (isLegalMove(x1, y1, x2, y2)) {
            board[x1][y1] = 0;
            board[x2][y2] = player;
            if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2) {
                // capture move
                board[(x1+x2)/2][(y1+y2)/2] = 0;
            }
            if (countPieces(-player) == 0) {
                printf("\nCongratulations! Player %d wins!\n\n", player);
                break;
            }
            player = -player;
        } else {
            printf("Invalid move!\n");
        }
    }
    return 0;
}