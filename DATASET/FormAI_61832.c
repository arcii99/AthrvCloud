//FormAI DATASET v1.0 Category: Checkers Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

typedef enum {EMPTY, BLACK, RED} Piece;

void printBoard(Piece board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case BLACK:
                    printf("B");
                    break;
                case RED:
                    printf("R");
                    break;
                default:
                    printf(" ");
            }
        }
        printf("\n");
    }
}

int main() {
    Piece board[BOARD_SIZE][BOARD_SIZE];
    // Initialize the board
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(i<=2 && (i+j)%2==0) {
                board[i][j] = RED;
            } else if(i>=5 && (i+j)%2==0) {
                board[i][j] = BLACK;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }

    printBoard(board);
    return 0;
}