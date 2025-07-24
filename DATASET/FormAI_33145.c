//FormAI DATASET v1.0 Category: Chess engine ; Style: retro
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

char board[ROWS][COLS] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

void display_board() {
    int i, j;
    printf("\n\n");
    for (i = 0; i < ROWS; i++) {
        printf("%d  ", (ROWS - i));
        for (j = 0; j < COLS; j++)
            printf("%c ", board[i][j]);
        printf("\n");
    }
    printf("   a b c d e f g h\n");
}

int main() {
    display_board();
    return 0;
}