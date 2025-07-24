//FormAI DATASET v1.0 Category: Checkers Game ; Style: expert-level
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define BOARD_SIZE 8 // Define size of the checkerboard to be 8

struct piece {
    bool isKing; // Is the piece a king? True or False.
    char symbol; // Symbol indicating piece color, K for black, W for white.
};

typedef struct piece Piece; // Using typedef to simplify function parameters.

Piece board[BOARD_SIZE][BOARD_SIZE]; // Declare and initiate board

// Declare functions to be used later
void newGame();
void printBoard();
bool movePiece(int, int, int, int);
bool capturePiece(int, int, int, int);
bool isJump(int, int, int, int);
bool checkValidMove(int, int, int, int);

int main() {
    newGame(); // Start a new game

    while(1) { // Loop until game has ended
        int startRow, startCol, endRow, endCol;

        printBoard(); // Print board to the screen

        printf("\nEnter move (start row, start col, end row, end col): ");
        scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);

        if(movePiece(startRow, startCol, endRow, endCol)) { // Attempt move
            if(capturePiece(startRow, startCol, endRow, endCol)) { // Attempt capture
                printf("CAPTURED!\n");
            }
            printf("MOVED\n");
        } else {
            printf("INVALID MOVE\n");
        }
    }

    return 0;
}

void newGame() {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(i < 3 && (i+j)%2 != 0) { // Top three rows should be white pieces
                board[i][j].isKing = false;
                board[i][j].symbol = 'W';
            } else if(i > 4 && (i+j)%2 != 0) { // Bottom three rows should be black pieces
                board[i][j].isKing = false;
                board[i][j].symbol = 'B';
            } else { // Everything else should be empty
                board[i][j].isKing = false;
                board[i][j].symbol = ' ';
            }
        }
    }
}

void printBoard() {
    printf("\n   ");
    for(int i = 0; i < BOARD_SIZE; i++) { // Print column numbers at the top
        printf("%d ", i);
    }
    printf("\n");

    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i); // Print row number at start of row
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("[%c]", board[i][j].symbol); // Print the current symbol for the piece
        }
        printf("\n");
    }
}

bool movePiece(int startRow, int startCol, int endRow, int endCol) {
    if(!checkValidMove(startRow, startCol, endRow, endCol)) { // Verify move is valid
        return false;
    }

    board[endRow][endCol] = board[startRow][startCol]; // Move piece to new position
    board[startRow][startCol].symbol = ' '; // Set old position to empty
    board[startRow][startCol].isKing = false; // Set any possible king to false

    if(board[endRow][endCol].symbol == 'W' && endRow == 0) { // If a white piece reaches the end, king it
        board[endRow][endCol].isKing = true; // Set king to true
        board[endRow][endCol].symbol = 'K'; // Change symbol to K
    } else if(board[endRow][endCol].symbol == 'B' && endRow == BOARD_SIZE-1) { // If a black piece reaches the end, king it
        board[endRow][endCol].isKing = true; // Set king to true
        board[endRow][endCol].symbol = 'K'; // Change symbol to K
    }

    return true; // Move was successful
}

bool capturePiece(int startRow, int startCol, int endRow, int endCol) {
    if(isJump(startRow, startCol, endRow, endCol)) { // Check if move is a capture
        int middleRow = (startRow+endRow)/2, middleCol = (startCol+endCol)/2;

        board[middleRow][middleCol].symbol = ' '; // "Remove" captured piece
        board[middleRow][middleCol].isKing = false; // Set capture piece king to false

        return true; // Capture was successful
    }
    return false; // Move was not a capture
}

bool isJump(int startRow, int startCol, int endRow, int endCol) {
    if(abs(endRow-startRow) == 2 && abs(endCol-startCol) == 2) { // Check if move is two rows and two columns away
        int middleRow = (startRow+endRow)/2, middleCol = (startCol+endCol)/2;

        if(board[middleRow][middleCol].symbol != ' ' && // Check if there is an opponent piece in between
           board[middleRow][middleCol].symbol != board[startRow][startCol].symbol) {
            return true; // This is a valid jump move
        }
    }
    return false; // This is not a valid jump move
}

bool checkValidMove(int startRow, int startCol, int endRow, int endCol) {
    int rowDiff = endRow - startRow, colDiff = endCol - startCol;

    if(board[startRow][startCol].symbol == ' ' || board[endRow][endCol].symbol != ' ') { // Check if movement is allowed and end spot is empty
        return false;
    }
    if(abs(rowDiff) != abs(colDiff)) { // Check if move is diagonal
        return false;
    }
    if(!board[startRow][startCol].isKing) { // Check if piece is a king (can move backwards)
        if(board[startRow][startCol].symbol == 'W' && rowDiff > 0) { // White can only move down
            return false;
        } else if(board[startRow][startCol].symbol == 'B' && rowDiff < 0) { // Black can only move up
            return false;
        }
    }

    if(!isJump(startRow, startCol, endRow, endCol)) { // If it's not a jump, check if it's a valid single movement
        if(abs(rowDiff) > 1) { // Can only move one square at a time unless it's a jump
            return false;
        }
    }

    return true; // The move is valid
}