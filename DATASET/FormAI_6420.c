//FormAI DATASET v1.0 Category: Checkers Game ; Style: relaxed
#include <stdio.h>

// Constants
#define BOARD_SIZE 8

// Function prototypes
void displayBoard(char board[][BOARD_SIZE]);
void movePiece(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY);
int isMoveValid(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY);
void checkForWinner(char board[][BOARD_SIZE], char currentPlayer);

int main() {
    // Initialize board
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {'-', 'O', '-', 'O', '-', 'O', '-', 'O'},
        {'O', '-', 'O', '-', 'O', '-', 'O', '-'},
        {'-', 'O', '-', 'O', '-', 'O', '-', 'O'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'X', '-', 'X', '-', 'X', '-', 'X', '-'},
        {'-', 'X', '-', 'X', '-', 'X', '-', 'X'},
        {'X', '-', 'X', '-', 'X', '-', 'X', '-'}
    };

    // Variables
    int startX, startY, endX, endY;
    char currentPlayer = 'O';

    // Game loop
    while (1) {
        // Display board
        printf("\nCurrent player: %c\n", currentPlayer);
        displayBoard(board);

        // Get player input
        printf("Enter the x and y coordinates of the piece you want to move (start): ");
        scanf("%d %d", &startX, &startY);
        printf("Enter the x and y coordinates of the position you want to move the piece to (end): ");
        scanf("%d %d", &endX, &endY);

        // Check if move is valid
        if (isMoveValid(board, startX, startY, endX, endY)) {
            // Move the piece
            movePiece(board, startX, startY, endX, endY);

            // Check for winner
            checkForWinner(board, currentPlayer);

            // Switch player
            currentPlayer = (currentPlayer == 'O') ? 'X' : 'O';
        } else {
            printf("\nInvalid move! Please try again.\n");
        }
    }

    return 0;
}

/**
 * Displays the current state of the board.
 * @param board The game board.
 */
void displayBoard(char board[][BOARD_SIZE]) {
    printf("\n    0   1   2   3   4   5   6   7  \n");
    printf("  ---------------------------------\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d |", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf(" %c |", board[row][col]);
        }
        printf("\n");
        printf("  ---------------------------------\n");
    }
}

/**
 * Moves a piece from the starting position to the end position.
 * @param board The game board.
 * @param startX The starting x position.
 * @param startY The starting y position.
 * @param endX The ending x position.
 * @param endY The ending y position.
 */
void movePiece(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    board[endX][endY] = board[startX][startY];
    board[startX][startY] = '-';
}

/**
 * Checks if the move from the starting position to the end position is valid.
 * @param board The game board.
 * @param startX The starting x position.
 * @param startY The starting y position.
 * @param endX The ending x position.
 * @param endY The ending y position.
 * @return 1 if the move is valid, 0 otherwise.
 */
int isMoveValid(char board[][BOARD_SIZE], int startX, int startY, int endX, int endY) {
    // Check if piece is being moved onto itself
    if (startX == endX && startY == endY) {
        return 0;
    }

    // Check if the piece being moved belongs to the current player
    if (board[startX][startY] == 'O' && board[startX][startY] != 'O') {
        return 0;
    } else if (board[startX][startY] == 'X' && board[startX][startY] != 'X') {
        return 0;
    }

    // Check if the destination position is out of bounds
    if (endX < 0 || endX >= BOARD_SIZE || endY < 0 || endY >= BOARD_SIZE) {
        return 0;
    }

    // Check if the destination position is already occupied by another piece
    if (board[endX][endY] != '-') {
        return 0;
    }

    // Check if the move is valid for the specified piece
    if (board[startX][startY] == 'O') { // Check for regular piece moves
        if (startX - endX == 1 && (startY - endY == 1 || startY - endY == -1)) { // Diagonal move by 1 space
            return 1;
        } else if (startX - endX == 2 && (startY - endY == 2 || startY - endY == -2)) { // Jump move by 2 spaces
            int jumpedX = (startX + endX) / 2;
            int jumpedY = (startY + endY) / 2;
            if (board[jumpedX][jumpedY] == 'X') {
                return 1;
            }
        }
    } else { // Check for king piece moves
        if (abs(startX - endX) == 1 && abs(startY - endY) == 1) { // Diagonal move by 1 space
            return 1;
        } else if (abs(startX - endX) == 2 && abs(startY - endY) == 2) { // Jump move by 2 spaces
            int jumpedX = (startX + endX) / 2;
            int jumpedY = (startY + endY) / 2;
            if (board[jumpedX][jumpedY] == 'O' || board[jumpedX][jumpedY] == 'X') {
                return 1;
            }
        }
    }

    return 0;
}

/**
 * Checks if there is a winner.
 * @param board The game board.
 * @param currentPlayer The current player.
 */
void checkForWinner(char board[][BOARD_SIZE], char currentPlayer) {
    // Check if the other player has no more pieces
    int playerPieceFound = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == (currentPlayer == 'O' ? 'X' : 'O')) {
                playerPieceFound = 1;
                break;
            }
        }
    }
    if (!playerPieceFound) {
        printf("%c wins!\n", currentPlayer);
        exit(0);
    }

    // Check if the other player has no moves left
    int canMove = 0;
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == (currentPlayer == 'O' ? 'X' : 'O')) {
                if (row - 1 >= 0 && col - 1 >= 0 && board[row - 1][col - 1] == '-') { // Diagonal move by 1 space
                    canMove = 1;
                } else if (row - 1 >= 0 && col + 1 < BOARD_SIZE && board[row - 1][col + 1] == '-') { // Diagonal move by 1 space
                    canMove = 1;
                } else if (row - 2 >= 0 && col - 2 >= 0 && board[row - 2][col - 2] == '-' && (board[row - 1][col - 1] == 'O' || board[row - 1][col - 1] == 'X')) { // Jump move by 2 spaces
                    canMove = 1;
                } else if (row - 2 >= 0 && col + 2 < BOARD_SIZE && board[row - 2][col + 2] == '-' && (board[row - 1][col + 1] == 'O' || board[row - 1][col + 1] == 'X')) { // Jump move by 2 spaces
                    canMove = 1;
                } else if (board[row][col] == 'X') {
                    if (row + 1 < BOARD_SIZE && col - 1 >= 0 && board[row + 1][col - 1] == '-') { // Diagonal move by 1 space
                        canMove = 1;
                    } else if (row + 1 < BOARD_SIZE && col + 1 < BOARD_SIZE && board[row + 1][col + 1] == '-') { // Diagonal move by 1 space
                        canMove = 1;
                    } else if (row + 2 < BOARD_SIZE && col - 2 >= 0 && board[row + 2][col - 2] == '-' && (board[row + 1][col - 1] == 'O' || board[row + 1][col - 1] == 'X')) { // Jump move by 2 spaces
                        canMove = 1;
                    } else if (row + 2 < BOARD_SIZE && col + 2 < BOARD_SIZE && board[row + 2][col + 2] == '-' && (board[row + 1][col + 1] == 'O' || board[row + 1][col + 1] == 'X')) { // Jump move by 2 spaces
                        canMove = 1;
                    }
                }
                if (canMove) {
                    break;
                }
            }
        }
        if (canMove) {
            break;
        }
    }
    if (!canMove) {
        printf("%c wins!\n", currentPlayer == 'O' ? 'X' : 'O');
        exit(0);
    }
}