//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Global variables
char board[8][8];
int playerTurn = 0;

// Function prototypes
void initBoard();
void printBoard();
int makeMove(int, int, int, int);
void checkCapture(int, int);

int main() {
    int row1, col1, row2, col2, captured = 0;

    // Initialize the game board
    initBoard();

    // Game loop
    while (1) {
        // Print the current state of the board
        printf("\nCurrent Board:\n");
        printBoard();

        // Determine which player's turn it is
        if (playerTurn % 2 == 0) {
            printf("Player 1's turn\n");
        } else {
            printf("Player 2's turn\n");
        }

        // Prompt the user to enter their move
        printf("Enter the row and column of the piece you want to move: ");
        scanf("%d %d", &row1, &col1);
        printf("Enter the row and column of where you want to move the piece: ");
        scanf("%d %d", &row2, &col2);

        // Make the move
        captured = makeMove(row1, col1, row2, col2);

        // Check for additional captures
        while (captured == 1) {
            // Print the board with the updated capture
            printf("\nBoard after capture:\n");
            printBoard();

            // Prompt the player for their next capture
            printf("Enter the row and column of the piece you want to move for an additional capture: ");
            scanf("%d %d", &row1, &col1);
            printf("Enter the row and column of where you want to move the piece after the capture: ");
            scanf("%d %d", &row2, &col2);

            // Make the move
            captured = makeMove(row1, col1, row2, col2);
        }

        // Increment the player turn counter
        playerTurn++;
    }

    return 0;
}

// Function to initialize the game board
void initBoard() {
    int row, col;

    // Initialize the board with spaces
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            board[row][col] = ' ';
        }
    }

    // Add player 1 pieces to the board
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 8; col++) {
            if ((row % 2 == 0 && col % 2 == 1) || (row % 2 == 1 && col % 2 == 0)) {
                board[row][col] = 'X';
            }
        }
    }

    // Add player 2 pieces to the board
    for (row = 5; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            if ((row % 2 == 0 && col % 2 == 1) || (row % 2 == 1 && col % 2 == 0)) {
                board[row][col] = 'O';
            }
        }
    }
}

// Function to print the game board
void printBoard() {
    int row, col;

    printf("  0 1 2 3 4 5 6 7\n");
    for (row = 0; row < 8; row++) {
        printf("%d ", row);
        for (col = 0; col < 8; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

// Function to make a move on the board
int makeMove(int row1, int col1, int row2, int col2) {
    // Make sure the move is within the bounds of the board
    if (row1 < 0 || row1 > 7 || col1 < 0 || col1 > 7 ||
        row2 < 0 || row2 > 7 || col2 < 0 || col2 > 7) {
        printf("Invalid move. Try again.\n");
        return 0;
    }

    // Make sure the player is moving their own piece
    if ((playerTurn % 2 == 0 && board[row1][col1] != 'X') ||
        (playerTurn % 2 == 1 && board[row1][col1] != 'O')) {
        printf("Invalid move. Try again.\n");
        return 0;
    }

    // Make sure the player is moving diagonally
    if ((playerTurn % 2 == 0 && row2 >= row1) ||
        (playerTurn % 2 == 1 && row2 <= row1)) {
        printf("Invalid move. Try again.\n");
        return 0;
    }

    // Determine if the move is a capture
    if ((row2 == row1 - 2 && col2 == col1 - 2 && board[row1-1][col1-1] == 'O') ||
        (row2 == row1 - 2 && col2 == col1 + 2 && board[row1-1][col1+1] == 'O') ||
        (row2 == row1 + 2 && col2 == col1 - 2 && board[row1+1][col1-1] == 'X') ||
        (row2 == row1 + 2 && col2 == col1 + 2 && board[row1+1][col1+1] == 'X')) {

        // Remove the captured piece
        checkCapture(row1, col1);
        return 1;

    // Determine if the move is a regular move
    } else if ((row2 == row1 - 1 && col2 == col1 - 1 && board[row1-1][col1-1] == ' ') ||
               (row2 == row1 - 1 && col2 == col1 + 1 && board[row1-1][col1+1] == ' ') ||
               (row2 == row1 + 1 && col2 == col1 - 1 && board[row1+1][col1-1] == ' ') ||
               (row2 == row1 + 1 && col2 == col1 + 1 && board[row1+1][col1+1] == ' ')) {

        // Move the piece to the new location
        board[row2][col2] = board[row1][col1];
        board[row1][col1] = ' ';
        return 0;

    // Invalid move
    } else {
        printf("Invalid move. Try again.\n");
        return 0;
    }
}

// Function to check for a capture
void checkCapture(int row1, int col1) {
    int rowCaptured, colCaptured;

    if (board[row1][col1] == 'X') {
        if (row1 - 2 >= 0 && col1 - 2 >= 0 && board[row1-1][col1-1] == 'O' && board[row1-2][col1-2] == ' ') {
            rowCaptured = row1 - 1;
            colCaptured = col1 - 1;
        } else if (row1 - 2 >= 0 && col1 + 2 <= 7 && board[row1-1][col1+1] == 'O' && board[row1-2][col1+2] == ' ') {
            rowCaptured = row1 - 1;
            colCaptured = col1 + 1;
        }
    } else {
        if (row1 + 2 <= 7 && col1 - 2 >= 0 && board[row1+1][col1-1] == 'X' && board[row1+2][col1-2] == ' ') {
            rowCaptured = row1 + 1;
            colCaptured = col1 - 1;
        } else if (row1 + 2 <= 7 && col1 + 2 <= 7 && board[row1+1][col1+1] == 'X' && board[row1+2][col1+2] == ' ') {
            rowCaptured = row1 + 1;
            colCaptured = col1 + 1;
        }
    }

    // Remove the captured piece from the board
    board[rowCaptured][colCaptured] = ' ';
}