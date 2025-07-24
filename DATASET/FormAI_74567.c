//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// function to initialize the board with empty cells
void init_board(char board[3][3]) {
    int i, j;
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            board[i][j] = '-';
        }
    }
}

// function to print the current state of the board
void print_board(char board[3][3]) {
    int i, j;
    for(i=0;i<3;i++) {
        for(j=0;j<3;j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[3][3];
    int i, j;

    init_board(board);
    print_board(board);

    return 0;
}