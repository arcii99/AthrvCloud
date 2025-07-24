//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include <stdio.h>

#define SIZE 8

int board[SIZE][SIZE];

void initialize_board() {
    // set the black pieces
    for(int i=0; i<3; i++) {
        for(int j=0; j<SIZE; j++) {
            if((i+j)%2 == 0) board[i][j] = 1;
        }
    }
    // set the white pieces
    for(int i=5; i<SIZE; i++) {
        for(int j=0; j<SIZE; j++) {
            if((i+j)%2 == 0) board[i][j] = -1;
        }
    }
}

void print_board() {
    for(int i=0; i<SIZE; i++) {
        printf("|");
        for(int j=0; j<SIZE; j++) {
            if(board[i][j] == 0) printf("  ");
            else if(board[i][j] == 1) printf("B ");
            else if(board[i][j] == -1) printf("W ");
        }
        printf("|\n");
    }
    printf("----------------\n");
}

int main() {
    initialize_board();
    print_board();
    return 0;
}