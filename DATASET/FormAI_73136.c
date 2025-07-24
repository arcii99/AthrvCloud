//FormAI DATASET v1.0 Category: Chess engine ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 8
#define COLUMNS 8

int board[ROWS][COLUMNS];

void initializeBoard() {
    int i, j;

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            board[i][j] = 0;
        }
    }
}

int possibleMoves(int x, int y) {
    int i, j, count = 0;
    int moveX, moveY;

    for (i = -2; i <= 2; i++) {
        for (j = -2; j <= 2; j++) {
            if (abs(i) != abs(j) && x+i >= 0 && x+i < ROWS && y+j >= 0 && y+j < COLUMNS) {
                moveX = x+i;
                moveY = y+j;
                if (board[moveX][moveY] == 0) {
                    count++;
                }
            }
        }
    }
    return count;
}

void makeMove(int x, int y) {
    int i, j;
    int moveX, moveY;

    for (i = -2; i <= 2; i++) {
        for (j = -2; j <= 2; j++) {
            if (abs(i) != abs(j) && x+i >= 0 && x+i < ROWS && y+j >= 0 && y+j < COLUMNS) {
                moveX = x+i;
                moveY = y+j;
                if (board[moveX][moveY] == 0) {
                    board[moveX][moveY] = 1;
                }
            }
        }
    }
}

void printBoard() {
    int i, j;

    printf("\n");

    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLUMNS; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initializeBoard();

    srand(time(NULL));

    int i, j;

    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            int moves = possibleMoves(i, j);
            //Don't perform a move if there are no available spots
            if (moves > 0) {
                //Pick a random available spot
                int randomMove = rand() % moves;
                int count = 0;
                //Perform the move
                for (int a = -2; a <= 2; a++) {
                    for (int b = -2; b <= 2; b++) {
                        if (abs(a) != abs(b) && i+a >= 0 && i+a < ROWS && j+b >= 0 && j+b < COLUMNS) {
                            int moveX = i+a;
                            int moveY = j+b;
                            if (board[moveX][moveY] == 0) {
                                if (count == randomMove) {
                                    makeMove(moveX, moveY);
                                    break;
                                } else {
                                    count++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    printBoard();

    return 0;
}