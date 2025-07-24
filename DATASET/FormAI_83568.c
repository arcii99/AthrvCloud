//FormAI DATASET v1.0 Category: Checkers Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Player constants
#define PLAYER_1 1
#define PLAYER_2 2

// Board state constants
#define EMPTY 0
#define BLACK 1
#define WHITE 2
#define BLACK_KING 3
#define WHITE_KING 4

// Function to print the board state
void printBoard(int board[][BOARD_SIZE], int currentPlayer) {
    printf("  A B C D E F G H\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col]) {
                case EMPTY: printf("- "); break;
                case BLACK: printf("B "); break;
                case WHITE: printf("W "); break;
                case BLACK_KING: printf("K "); break;
                case WHITE_KING: printf("Q "); break;
            }
        }
        printf("%d\n", row + 1);
    }
    printf("  A B C D E F G H\n");
    printf("Player %d's turn\n", currentPlayer);
}

// Function to check if a move is valid for the selected piece
int isValidMove(int board[][BOARD_SIZE], int row, int col, int newRow, int newCol, int currentPlayer) {
    // Ensure that the destination is within the board bounds
    if (newRow < 0 || newRow >= BOARD_SIZE || newCol < 0 || newCol >= BOARD_SIZE) {
        return 0;
    }
    
    // Ensure that the destination is empty
    if (board[newRow][newCol] != EMPTY) {
        return 0;
    }

    // Check if the selected piece is a king and can move diagonally in any direction
    if ((board[row][col] == BLACK_KING || board[row][col] == WHITE_KING) && abs(newRow - row) == 1 && abs(newCol - col) == 1) {
        return 1;
    }
    
    // Check if the selected piece is a regular player piece and can only move forward diagonally
    if (board[row][col] == BLACK && newRow - row == 1 && abs(newCol - col) == 1) {
        return 1;
    }
    if (board[row][col] == WHITE && newRow - row == -1 && abs(newCol - col) == 1) {
        return 1;
    }

    // Check if the selected piece can capture an opponent's piece
    int playerColor = board[row][col];
    int opponentColor = (playerColor == BLACK || playerColor == BLACK_KING) ? WHITE : BLACK;
    int rowDiff = newRow - row;
    int colDiff = newCol - col;
    if (abs(rowDiff) == 2 && abs(colDiff) == 2 && board[row + rowDiff/2][col + colDiff/2] == opponentColor) {
        return 1;
    }
    
    return 0;
}

// Function to check if the current player has any valid moves
int hasValidMoves(int board[][BOARD_SIZE], int currentPlayer) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] != EMPTY && (board[row][col] == currentPlayer || (board[row][col] == BLACK_KING && currentPlayer == PLAYER_1) || (board[row][col] == WHITE_KING && currentPlayer == PLAYER_2))) {
                // Check each diagonal direction for valid moves
                if (isValidMove(board, row, col, row + 1, col - 1, currentPlayer) ||
                    isValidMove(board, row, col, row + 1, col + 1, currentPlayer) ||
                    isValidMove(board, row, col, row - 1, col - 1, currentPlayer) ||
                    isValidMove(board, row, col, row - 1, col + 1, currentPlayer)) {
                        return 1;
                }
            }
        }
    }
    return 0;
}

// Function to update the board state after a move is made
void makeMove(int board[][BOARD_SIZE], int row, int col, int newRow, int newCol, int currentPlayer) {
    // Determine the type of piece being moved
    int currentPiece = board[row][col];
    int newPiece;
    if (currentPiece == BLACK && newRow == BOARD_SIZE - 1) {
        newPiece = BLACK_KING;
    } else if (currentPiece == WHITE && newRow == 0) {
        newPiece = WHITE_KING;
    } else {
        newPiece = currentPiece;
    }

    // Update the board with the new piece type
    board[row][col] = EMPTY;
    board[newRow][newCol] = newPiece;

    // Check if the selected piece captured an opponent's piece
    int rowDiff = newRow - row;
    int colDiff = newCol - col;
    if (abs(rowDiff) == 2 && abs(colDiff) == 2) {
        board[row + rowDiff/2][col + colDiff/2] = EMPTY;
    }

    // Switch the current player if necessary
    if (!hasValidMoves(board, currentPlayer)) {
        currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;
    }
}

int main() {
    // Initialize the board with the starting position
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
        {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY},
        {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY},
        {EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE},
        {WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY, WHITE, EMPTY}
    };
    int currentPlayer = PLAYER_1;

    // Game loop
    int isGameOver = 0;
    while (!isGameOver) {
        // Print the current board state
        printBoard(board, currentPlayer);

        // Get input from the current player
        printf("Enter the starting position of the piece you want to move (e.g. A3): ");
        char startCol;
        int startRow;
        scanf(" %c%d", &startCol, &startRow);
        int startColIndex = startCol - 'A';
        int startRowIndex = startRow - 1;
        if (startColIndex < 0 || startColIndex >= BOARD_SIZE || startRowIndex < 0 || startRowIndex >= BOARD_SIZE) {
            printf("Invalid starting position. Please try again.\n");
            continue;
        }
        if (board[startRowIndex][startColIndex] == EMPTY || (currentPlayer == PLAYER_1 && board[startRowIndex][startColIndex] != BLACK && board[startRowIndex][startColIndex] != BLACK_KING) || (currentPlayer == PLAYER_2 && board[startRowIndex][startColIndex] != WHITE && board[startRowIndex][startColIndex] != WHITE_KING)) {
            printf("You do not have a piece at that position. Please try again.\n");
            continue;
        }
        printf("Enter the destination position of the piece (e.g. B4): ");
        char destCol;
        int destRow;
        scanf(" %c%d", &destCol, &destRow);
        int destColIndex = destCol - 'A';
        int destRowIndex = destRow - 1;
        if (destColIndex < 0 || destColIndex >= BOARD_SIZE || destRowIndex < 0 || destRowIndex >= BOARD_SIZE) {
            printf("Invalid destination position. Please try again.\n");
            continue;
        }
        if (!isValidMove(board, startRowIndex, startColIndex, destRowIndex, destColIndex, currentPlayer)) {
            printf("Invalid move. Please try again.\n");
            continue;
        }

        // Make the move and switch the player
        makeMove(board, startRowIndex, startColIndex, destRowIndex, destColIndex, currentPlayer);
        currentPlayer = (currentPlayer == PLAYER_1) ? PLAYER_2 : PLAYER_1;

        // Check if the game is over
        if (!hasValidMoves(board, currentPlayer)) {
            printf("Player %d has no valid moves. Game over.\n", currentPlayer);
            isGameOver = 1;
        }
    }

    return 0;
}