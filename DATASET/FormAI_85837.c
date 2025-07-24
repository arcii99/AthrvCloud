//FormAI DATASET v1.0 Category: Checkers Game ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Function to clear the board
void clear_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i,j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

// Function to initialize the board with starting positions
void init_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i,j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if((i+j)%2 == 0) {
                if(i < 3) {
                    board[i][j] = 'r';
                } else if(i > 4) {
                    board[i][j] = 'b';
                } else {
                    board[i][j] = ' ';
                }
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to print the board
void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   A B C D E F G H\n");
    printf("  +----------------+\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("%d |", i+1);
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf(" %d\n", i+1);
    }
    printf("  +----------------+\n");
    printf("   A B C D E F G H\n");
}

int main() {

    char board[BOARD_SIZE][BOARD_SIZE];
    clear_board(board);
    init_board(board);
    print_board(board);

    return 0;
}