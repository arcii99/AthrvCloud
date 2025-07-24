//FormAI DATASET v1.0 Category: Checkers Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = {
    {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
    {'X', ' ', 'X', ' ', 'X', ' ', 'X', ' '},
    {' ', 'X', ' ', 'X', ' ', 'X', ' ', 'X'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '},
    {' ', 'O', ' ', 'O', ' ', 'O', ' ', 'O'},
    {'O', ' ', 'O', ' ', 'O', ' ', 'O', ' '}
};

void print_board() {
    printf("  1 2 3 4 5 6 7 8\n");
    printf(" +--------------+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        printf(" +--------------+\n");
    }
}

int main() {
    printf("Welcome to C Checkers Game!\n");
    print_board();
    return 0;
}