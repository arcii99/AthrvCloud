//FormAI DATASET v1.0 Category: Chess engine ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* Define a 2D array to represent the chess board */
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

/* Define a function to print the chess board */
void print_board() {
    int row, col;
    printf("\n   A B C D E F G H\n");
    for (row = 0; row < 8; row++) {
        printf("%d  ", 8 - row);
        for (col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf(" %d", 8 - row);
        printf("\n");
    }
    printf("   A B C D E F G H\n\n");
}

int main() {
    print_board();
    return 0;
}