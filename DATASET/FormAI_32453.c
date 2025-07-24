//FormAI DATASET v1.0 Category: Chess engine ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Initialize the chess board
    char board[8][8] = {
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
        {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'}
    };

    // Print the current state of the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    // Prompt the user to make a move
    printf("Enter a move (e.g. \"e2e4\"): ");
    char move[5];
    scanf("%s", move);

    // Parse the move string
    int x1 = move[0] - 'a';
    int y1 = 8 - (move[1] - '0');
    int x2 = move[2] - 'a';
    int y2 = 8 - (move[3] - '0');

    // Move the piece
    board[y2][x2] = board[y1][x1];
    board[y1][x1] = ' ';

    // Print the new state of the board
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }

    return 0;
}