//FormAI DATASET v1.0 Category: Chess engine ; Style: distributed
// Distributed Chess Engine Example Program

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to display the chessboard
void displayBoard(char board[][8]) {
    int row, col;
    
    printf("\n");
    for(row = 0; row < 8; row++) {
        for(col = 0; col < 8; col++) {
            printf("%c\t", board[row][col]);
        }
        printf("\n");
    }
}

// Function to check if the given position is in the board
bool isValidPosition(int row, int col) {
    if(row >= 0 && row < 8 && col >= 0 && col < 8) {
        return true;
    }
    return false;
}

// Function to move the piece from source to destination
bool movePiece(char board[][8], int srcRow, int srcCol, int destRow, int destCol) {
    // Check if the source and destination positions are valid
    if(!isValidPosition(srcRow, srcCol) || !isValidPosition(destRow, destCol)) {
        printf("Invalid positions!\n");
        return false;
    }
    
    // Check if the source position has a piece
    if(board[srcRow][srcCol] == '-') {
        printf("No piece at the source position!\n");
        return false;
    }
    
    // Check if the destination position is empty or has an opponent's piece to capture
    if(board[destRow][destCol] == '-' || board[srcRow][srcCol] != board[destRow][destCol] + 32) {
        // Move the piece to the destination position
        board[destRow][destCol] = board[srcRow][srcCol];
        board[srcRow][srcCol] = '-';
        return true;
    }
    
    // Destination position has own piece
    printf("Own piece at the destination position!\n");
    return false;
}

int main() {
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };
    
    displayBoard(board);
    
    // Move a piece
    if(movePiece(board, 6, 4, 4, 4)) {
        printf("\nMoved the piece successfully!\n");
    }
    
    displayBoard(board);
    
    return 0;
}