//FormAI DATASET v1.0 Category: Chess AI ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

typedef struct {
    char square[SIZE][SIZE];
    int position[2];
} Chessboard;

void initialize_board(Chessboard *board) {
    // set up the initial pieces on the board
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (i == 0) {
                if (j == 0 || j == SIZE - 1) {
                    board->square[i][j] = 'R';
                } else if (j == 1 || j == SIZE - 2) {
                    board->square[i][j] = 'N';
                } else if (j == 2 || j == SIZE - 3) {
                    board->square[i][j] = 'B';
                } else if (j == 3) {
                    board->square[i][j] = 'Q';
                } else if (j == 4) {
                    board->square[i][j] = 'K';
                }
            } else if (i == 1) {
                board->square[i][j] = 'P';
            } else if (i == SIZE - 2) {
                board->square[i][j] = 'p';
            } else if (i == SIZE - 1) {
                if (j == 0 || j == SIZE - 1) {
                    board->square[i][j] = 'r';
                } else if (j == 1 || j == SIZE - 2) {
                    board->square[i][j] = 'n';
                } else if (j == 2 || j == SIZE - 3) {
                    board->square[i][j] = 'b';
                } else if (j == 3) {
                    board->square[i][j] = 'q';
                } else if (j == 4) {
                    board->square[i][j] = 'k';
                }
            } else {
                board->square[i][j] = '_';
            }
        }
    }
}

void print_board(Chessboard *board) {
    // print out the current board state
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%c ", board->square[i][j]);
        }
        printf("\n");
    }
}

int main() {
    Chessboard board;
    initialize_board(&board);
    print_board(&board);
    return 0;
}