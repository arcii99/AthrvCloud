//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

#define rows 8
#define cols 8

// declaration of the Chessboard
int chessboard[rows][cols];

// function to initialize the Chessboard
void init_chessboard() {
    int i, j;

    // initialize with 0 for the empty cells
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            chessboard[i][j] = 0;
        }
    }

    // place the pieces for the start of the game
    for (i = 0; i < rows; i++) {
        chessboard[1][i] = 1; // pawn
        chessboard[6][i] = -1; // pawn

        if (i == 0 || i == 7) {
            chessboard[0][i] = 2; // rook
            chessboard[7][i] = -2; // rook
        } else if (i == 1 || i == 6) {
            chessboard[0][i] = 3; // knight
            chessboard[7][i] = -3; // knight
        } else if (i == 2 || i == 5) {
            chessboard[0][i] = 4; // bishop
            chessboard[7][i] = -4; // bishop
        } else if (i == 3) {
            chessboard[0][i] = 5; // queen
            chessboard[7][i] = -5; // queen
        } else if (i == 4) {
            chessboard[0][i] = 6; // king
            chessboard[7][i] = -6; // king
        }
    }
}

// function to print the Chessboard
void print_chessboard() {
    int i, j;

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            if (chessboard[i][j] == 0) {
                printf(". ");
            } else if (chessboard[i][j] == 1) {
                printf("P ");
            } else if (chessboard[i][j] == -1) {
                printf("p ");
            } else if (chessboard[i][j] == 2) {
                printf("R ");
            } else if (chessboard[i][j] == -2) {
                printf("r ");
            } else if (chessboard[i][j] == 3) {
                printf("N ");
            } else if (chessboard[i][j] == -3) {
                printf("n ");
            } else if (chessboard[i][j] == 4) {
                printf("B ");
            } else if (chessboard[i][j] == -4) {
                printf("b ");
            } else if (chessboard[i][j] == 5) {
                printf("Q ");
            } else if (chessboard[i][j] == -5) {
                printf("q ");
            } else if (chessboard[i][j] == 6) {
                printf("K ");
            } else if (chessboard[i][j] == -6) {
                printf("k ");
            }
        }
        printf("\n");
    }
}

// main function
int main() {
    init_chessboard();
    print_chessboard();

    return 0;
}