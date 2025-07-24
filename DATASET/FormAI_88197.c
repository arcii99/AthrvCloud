//FormAI DATASET v1.0 Category: Chess engine ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the chess board
char board[8][8] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'},
};

// Helper function to print the board
void print_board() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// Helper function to move a piece
void move_piece(char piece, int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = piece;
    board[from_row][from_col] = ' ';
}

int main() {
    
    // Print the starting board
    print_board();
    
    // Move a pawn
    move_piece('P', 6, 2, 4, 2);
    print_board();
    
    // Move a knight
    move_piece('N', 7, 1, 5, 2);
    print_board();
    
    // Move a bishop
    move_piece('B', 7, 2, 5, 0);
    print_board();
    
    // Move a queen
    move_piece('Q', 7, 3, 4, 3);
    print_board();
    
    // Move a rook
    move_piece('R', 7, 0, 5, 0);
    print_board();
    
    return 0;
}