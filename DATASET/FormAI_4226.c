//FormAI DATASET v1.0 Category: Checkers Game ; Style: multivariable
#include <stdio.h>

#define BOARD_SIZE 8

// Define the board as a 2D array
char board[BOARD_SIZE][BOARD_SIZE];

// Store the current player's turn
char currentPlayer = 'B';

// Initialize the board with pieces
void initializeBoard() {
    // Black pieces at the bottom
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                board[row][col] = 'B';
            } else {
                board[row][col] = ' ';
            }
        }
    }
    // White pieces at the top
    for (int row = BOARD_SIZE - 1; row >= BOARD_SIZE - 3; row--) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                board[row][col] = 'W';
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

// Print the current board state
void printBoard() {
    printf("\n   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf(" %c  ", col + 'A');
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf(" %d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("[ %c ]", board[row][col]);
        }
        printf(" %d\n", row + 1);
    }
    printf("   ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf(" %c  ", col + 'A');
    }
    printf("\n");
}

// Check if a move is valid
int isValidMove(char piece, int startRow, int startCol, int endRow, int endCol) {
    // Make sure piece belongs to current player
    if (board[startRow][startCol] != piece) {
        return 0;
    }
    // Make sure end position is empty
    if (board[endRow][endCol] != ' ') {
        return 0;
    }
    // Make sure end position is within bounds
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return 0;
    }
    // Calculate row and column differences
    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;
    // Check if move is a capture
    if (rowDiff == 2 || rowDiff == -2) {
        int captureRow = (startRow + endRow) / 2;
        int captureCol = (startCol + endCol) / 2;
        // Make sure capture position has opponent's piece
        if (board[captureRow][captureCol] == ' ') {
            return 0;
        }
        // Make sure capture position belongs to opponent
        if (board[captureRow][captureCol] == currentPlayer || board[captureRow][captureCol] == currentPlayer + 32) {
            return 0;
        }
    }
    // Check if move is diagonal
    if (rowDiff == colDiff || rowDiff == -colDiff) {
        // Check if move is one or two spaces
        if (rowDiff == 1 || rowDiff == -1) {
            // Regular move
            return 1;
        } else if (rowDiff == 2 || rowDiff == -2) {
            // Capture move
            return 1;
        }
    }
    // Invalid move
    return 0;
}

// Make a move
int makeMove(char piece, int startRow, int startCol, int endRow, int endCol) {
    // Check if move is valid
    if (!isValidMove(piece, startRow, startCol, endRow, endCol)) {
        return 0;
    }
    // Update board
    board[endRow][endCol] = piece;
    board[startRow][startCol] = ' ';
    // Check for captures
    int rowDiff = endRow - startRow;
    int colDiff = endCol - startCol;
    if (rowDiff == 2 || rowDiff == -2) {
        int captureRow = (startRow + endRow) / 2;
        int captureCol = (startCol + endCol) / 2;
        board[captureRow][captureCol] = ' ';
    }
    // Check for king promotion
    if (piece == 'B' && endRow == 0) {
        board[endRow][endCol] = 'K';
    } else if (piece == 'W' && endRow == BOARD_SIZE - 1) {
        board[endRow][endCol] = 'K';
    }
    // Switch player turn
    if (currentPlayer == 'B') {
        currentPlayer = 'W';
    } else {
        currentPlayer = 'B';
    }
    return 1;
}

// Check if game is over
int isGameOver() {
    int blackPieces = 0;
    int whitePieces = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == 'B' || board[row][col] == 'K') {
                blackPieces++;
            } else if (board[row][col] == 'W' || board[row][col] == 'K') {
                whitePieces++;
            }
        }
    }
    if (blackPieces == 0) {
        printf("White wins!\n");
        return 1;
    } else if (whitePieces == 0) {
        printf("Black wins!\n");
        return 1;
    }
    return 0;
}

int main() {
    // Initialize board
    initializeBoard();
    // Game loop
    while (!isGameOver()) {
        // Print board
        printBoard();
        // Get move from current player
        printf("%c's turn (Enter move in format: startX startY endX endY): ", currentPlayer);
        int startRow, startCol, endRow, endCol;
        scanf("%d %d %d %d", &startRow, &startCol, &endRow, &endCol);
        // Convert input to board positions
        startRow--;
        startCol = startCol - 'A';
        endRow--;
        endCol = endCol - 'A';
        // Make move
        if (!makeMove(board[startRow][startCol], startRow, startCol, endRow, endCol)) {
            printf("Invalid move, try again.\n");
        }
    }
    // Print final board state
    printBoard();
    return 0;
}