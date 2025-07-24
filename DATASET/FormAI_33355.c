//FormAI DATASET v1.0 Category: Chess engine ; Style: single-threaded
#include <stdio.h>
#include <string.h>

// Define the chess board as a 2D character array
char board[8][8] = {
    {'R','N','B','Q','K','B','N','R'},
    {'P','P','P','P','P','P','P','P'},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {' ',' ',' ',' ',' ',' ',' ',' '},
    {'p','p','p','p','p','p','p','p'},
    {'r','n','b','q','k','b','n','r'}
};

// Define a function to print the board
void print_board() {
    printf("  a b c d e f g h\n");
    for (int i = 0; i < 8; i++) {
        printf("%d ", 8-i);
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", 8-i);
    }
    printf("  a b c d e f g h\n");
}

int main() {
    print_board();
    return 0;
}