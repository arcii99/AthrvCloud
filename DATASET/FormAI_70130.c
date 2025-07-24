//FormAI DATASET v1.0 Category: Chess engine ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // seed random number generator with current time
    
    // define the chess board as a 2D array
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
    
    // print the initial board state
    printf("Initial board:\n\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // randomly choose a move for white and print the updated board state
    int fromRow = rand() % 2 + 1;
    int fromCol = rand() % 8;
    int toRow = rand() % 2 + 3;
    int toCol = rand() % 8;
    char piece = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
    board[toRow][toCol] = piece;
    
    printf("White's move: %c%d to %c%d\n\n", fromCol + 97, fromRow + 1, toCol + 97, toRow + 1);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    // randomly choose a move for black and print the updated board state
    fromRow = rand() % 2 + 6;
    fromCol = rand() % 8;
    toRow = rand() % 2 + 4;
    toCol = rand() % 8;
    piece = board[fromRow][fromCol];
    board[fromRow][fromCol] = ' ';
    board[toRow][toCol] = piece;
    
    printf("Black's move: %c%d to %c%d\n\n", fromCol + 97, fromRow + 1, toCol + 97, toRow + 1);
    
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    return 0;
}