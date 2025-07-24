//FormAI DATASET v1.0 Category: Chess AI ; Style: complete
#include <stdio.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board
void initializeBoard() {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

// Function to print the board
void printBoard() {
    int i, j;

    printf("    a   b   c   d   e   f   g   h\n");
    printf("  +---+---+---+---+---+---+---+---+\n");

    for(i=0; i<BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for(j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                printf("   |");
            } else {
                printf(" %c |", board[i][j]);
            }
        }
        printf(" %d\n", i+1);
        printf("  +---+---+---+---+---+---+---+---+\n");
    }

    printf("    a   b   c   d   e   f   g   h\n");
}

int main() {
    initializeBoard();
    printBoard();

    return 0;
}