//FormAI DATASET v1.0 Category: Chess engine ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Defining global constants
#define MAX_ROWS 8
#define MAX_COLS 8
#define MAX_PIECES 32

// Defining global variables
char chessBoard[MAX_ROWS][MAX_COLS];
char pieces[MAX_PIECES][3];
int numPieces;

// Function to initialize the chessboard
void initializeChessboard() {
    for(int i = 0; i < MAX_ROWS; i++) {
        for(int j = 0; j < MAX_COLS; j++) {
            if(i == 0 || i == 7) {
                if(j == 0 || j == 7) {
                    chessBoard[i][j] = 'R';
                } else if(j == 1 || j == 6) {
                    chessBoard[i][j] = 'N';
                } else if(j == 2 || j == 5) {
                    chessBoard[i][j] = 'B';
                } else if(j == 3) {
                    chessBoard[i][j] = 'Q';
                } else {
                    chessBoard[i][j] = 'K';
                }
            } else if(i == 1 || i == 6) {
                chessBoard[i][j] = 'P';
            } else {
                chessBoard[i][j] = ' ';
            }
        }
    }
}

// Function to print the chessboard
void printChessboard() {
    printf("\n");
    for(int i = 0; i < MAX_ROWS; i++) {
        printf("%d ", MAX_ROWS - i);
        for(int j = 0; j < MAX_COLS; j++) {
            printf("%c ", chessBoard[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n\n");
}

// Function to add a piece to the chessboard
void addPiece(char piece, char col, char row) {
    pieces[numPieces][0] = piece;
    pieces[numPieces][1] = col;
    pieces[numPieces][2] = row;
    numPieces++;
}

// Function to move a piece on the chessboard
void movePiece(char fromCol, char fromRow, char toCol, char toRow) {
    int fromIndex = -1, toIndex = -1;
    
    // Looking for the piece being moved
    for(int i = 0; i < numPieces; i++) {
        if(pieces[i][1] == fromCol && pieces[i][2] == fromRow) {
            fromIndex = i;
            break;
        }
    }
    
    // Looking for existing piece at destination
    for(int i = 0; i < numPieces; i++) {
        if(pieces[i][1] == toCol && pieces[i][2] == toRow && i != fromIndex) {
            toIndex = i;
            break;
        }
    }
    
    // Moving the piece
    pieces[fromIndex][1] = toCol;
    pieces[fromIndex][2] = toRow;
    
    if(toIndex >= 0) {
        // Removing the piece at the destination
        for(int i = toIndex; i < numPieces - 1; i++) {
            pieces[i][0] = pieces[i + 1][0];
            pieces[i][1] = pieces[i + 1][1];
            pieces[i][2] = pieces[i + 1][2];
        }
        numPieces--;
    }
}

// Function to test the chess engine
void testChessEngine() {
    initializeChessboard();
    printChessboard();
    addPiece('P', 'c', '2');
    movePiece('c', '2', 'c', '4');
    printChessboard();
    addPiece('P', 'd', '7');
    movePiece('d', '7', 'd', '5');
    printChessboard();
    addPiece('N', 'g', '8');
    movePiece('g', '8', 'f', '6');
    printChessboard();
    addPiece('Q', 'd', '1');
    movePiece('d', '1', 'd', '7');
    printChessboard();
}

// Main function
int main() {
    testChessEngine();
    return 0;
}