//FormAI DATASET v1.0 Category: Chess AI ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Function to print the chess board
void printBoard(char board[][8]) {
    printf("\n    A   B   C   D   E   F   G   H   \n");
    printf("  ---------------------------------\n");

    for (int i = 0; i < 8; i++) {

        // Print the row number
        printf("%d ", 8 - i);

        // Print the current row
        for (int j = 0; j < 8; j++) {
            printf("| %c ", board[i][j]);
        }

        // Print a closing bar to complete the row
        printf("| %d\n", 8 - i);
        printf("  ---------------------------------\n");
    }

    // Print the column letters
    printf("    A   B   C   D   E   F   G   H   \n");
}

// Function to check if a given move is valid
bool isValidMove(char board[][8], int fromRow, int fromCol, int toRow, int toCol) {

    // Check if the given positions are within the board
    if (fromRow < 0 || fromRow > 7 || fromCol < 0 || fromCol > 7 || toRow < 0 || toRow > 7 || toCol < 0 || toCol > 7) {
        return false;
    }

    // Check if there is a piece at the starting position
    if (board[fromRow][fromCol] == ' ') {
        return false;
    }

    // Check if the ending position is not occupied by a friendly piece
    if (board[toRow][toCol] != ' ' && board[toRow][toCol] / board[fromRow][fromCol] > 0) {
        return false;
    }

    // Check if the piece can move to the given position
    switch (board[fromRow][fromCol]) {
        case 'P':
            // Pawn can move either one or two steps forward from its starting position
            if (fromCol == toCol) {
                if (toRow - fromRow == 1 || (fromRow == 1 && toRow - fromRow == 2)) {
                    return true;
                }
            }
            break;
        case 'R':
            // Rook can move horizontally or vertically any number of steps
            if (fromRow == toRow || fromCol == toCol) {
                return true;
            }
            break;
        case 'N':
            // Knight can move in L-shape
            if ((toRow == fromRow + 2 && toCol == fromCol + 1) || (toRow == fromRow + 2 && toCol == fromCol - 1) ||
                    (toRow == fromRow - 2 && toCol == fromCol + 1) || (toRow == fromRow - 2 && toCol == fromCol - 1) ||
                    (toRow == fromRow + 1 && toCol == fromCol + 2) || (toRow == fromRow - 1 && toCol == fromCol + 2) ||
                    (toRow == fromRow + 1 && toCol == fromCol - 2) || (toRow == fromRow - 1 && toCol == fromCol - 2)) {
                return true;
            }
            break;
        case 'B':
            // Bishop can move diagonally any number of steps
            if (abs(fromRow - toRow) == abs(fromCol - toCol)) {
                return true;
            }
            break;
        case 'Q':
            // Queen can move horizontally, vertically or diagonally any number of steps
            if (fromRow == toRow || fromCol == toCol || abs(fromRow - toRow) == abs(fromCol - toCol)) {
                return true;
            }
            break;
        case 'K':
            // King can move one step in any direction
            if (abs(fromRow - toRow) <= 1 && abs(fromCol - toCol) <= 1) {
                return true;
            }
            break;
    }

    // If none of the above conditions apply, the move is not valid
    return false;
}

// Function to get a valid move from the player
void getMove(char board[][8], int *fromRow, int *fromCol, int *toRow, int *toCol) {
    printf("Enter move (e.g. \"e2 e4\"): ");
    scanf("%c%d %c%d", fromCol, fromRow, toCol, toRow);

    // Convert the columns to 0-indexed values
    *fromCol = (*fromCol) - 'A';
    *toCol = (*toCol) - 'A';

    // Convert the rows to 0-indexed values
    *fromRow = 8 - (*fromRow);
    *toRow = 8 - (*toRow);

    // Check if the move is valid
    if (!isValidMove(board, *fromRow, *fromCol, *toRow, *toCol)) {
        printf("Invalid move!\n");
        getMove(board, fromRow, fromCol, toRow, toCol);
    }
}

// Main function
int main() {
    // Initialize the board
    char board[8][8] = {
        {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
        {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
        {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
    };

    // Print the board
    printBoard(board);

    // Game loop
    while (true) {
        // Get the player's move
        int fromRow, fromCol, toRow, toCol;
        getMove(board, &fromRow, &fromCol, &toRow, &toCol);

        // Make the move
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';

        // Print the board
        printBoard(board);
    }

    return 0;
}