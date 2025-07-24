//FormAI DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>

// Defining the chess board array
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

// Defining the function to print the chess board
void printBoard() {
    for (int i = 7; i >= 0; i--) {
        printf("%d ", i+1);
        for (int j = 0; j < 8; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("  ");
    for (int i = 0; i < 8; i++) {
        printf("  %c ", 'a'+i);
    }
    printf("\n");
}

int main() {
    printf("Chess Board:\n");
    printBoard();
    return 0;
}