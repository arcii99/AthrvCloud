//FormAI DATASET v1.0 Category: Chess engine ; Style: systematic
#include <stdio.h>

// Board representation as a 2D array
char board[8][8] = {
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', ' '},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
};

// Function to print the current state of the board
void print_board() {
    printf("    a b c d e f g h\n");
    for(int i = 0; i < 8; i++) {
        printf("%d | ", 8 - i);
        for(int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("|\n");
    }
    printf("    a b c d e f g h\n");
}

int main() {
    print_board();
    return 0;
}