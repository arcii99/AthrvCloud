//FormAI DATASET v1.0 Category: Checkers Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define SIZE 8

// The board
char board[SIZE][SIZE];

// Initialize the board
void init_board() {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if((i + j) % 2 == 0) {
                board[i][j] = ' ';
            } else {
                board[i][j] = '*';
            }
        }
    }
}

// Print the board
void print_board() {
    printf("\n   ");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(int i = 0; i < SIZE; i++) {
        printf(" %d ", i);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    // Initialize the board
    init_board();

    // Print the board
    print_board();
    return 0;
}