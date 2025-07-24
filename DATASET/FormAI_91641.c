//FormAI DATASET v1.0 Category: Checkers Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Configurable Variables
#define BOARD_SIZE 8    // Size of the board
#define PLAYER1 'B'     // Symbol for player 1
#define PLAYER2 'W'     // Symbol for player 2

// Global Variables
char board[BOARD_SIZE][BOARD_SIZE];

// Function Declarations
void initializeBoard();
void printBoard();
int isValidInput(int row, int col, int newRow, int newCol, char player);
int isJumpAvailable(int row, int col, char player);
int movePiece(int row, int col, int newRow, int newCol, char player);
void playGame();

/**
 * Initializes the board with starting pieces.
 */
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j] = PLAYER2;
            } else if ((i + j) % 2 == 0 && i > 4) {
                board[i][j] = PLAYER1;
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

/**
 * Prints the current state of the board.
 */
void printBoard() {
    printf("\n    0   1   2   3   4   5   6   7\n");
    printf("  +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n");
        printf("  +---+---+---+---+---+---+---+---+\n");
    }
}

/**
 * Checks if the given input and move are valid.
 * Returns 1 if valid, 0 if invalid.
 */
int isValidInput(int row, int col, int newRow, int newCol, char player) {
    // Check if new position is within the bounds of the board
    if (newRow < 0 || newRow >= BOARD_SIZE || newCol < 0 || newCol >= BOARD_SIZE) {
        return 0;
    }

    // Check if new position is diagonal from current position
    if (newRow == row || newCol == col) {
        return 0;
    }

    // Check if new position already has a piece on it
    if (board[newRow][newCol] != ' ') {
        return 0;
    }

    // Check if player is moving their own piece
    if (player == PLAYER1 && board[row][col] != PLAYER1) {
        return 0;
    } else if (player == PLAYER2 && board[row][col] != PLAYER2) {
        return 0;
    }

    // Check if player is moving in the correct direction
    if (player == PLAYER1 && newRow >= row) {
        return 0;
    } else if (player == PLAYER2 && newRow <= row) {
        return 0;
    }

    // Check if move is one or two spaces diagonally
    if (abs(newRow - row) != 1 || abs(newCol - col) != 1) {
        if (abs(newRow - row) != 2 || abs(newCol - col) != 2) {
            return 0;
        }
    }

    // Check if player is jumping over an opponent
    if (abs(newRow - row) == 2 && abs(newCol - col) == 2) {
        int middleRow = (row + newRow) / 2;
        int middleCol = (col + newCol) / 2;
        if (player == PLAYER1 && board[middleRow][middleCol] != PLAYER2) {
            return 0;
        } else if (player == PLAYER2 && board[middleRow][middleCol] != PLAYER1) {
            return 0;
        }
    }

    return 1;
}

/**
 * Checks if the given player has any available jumps.
 * Returns 1 if jump is available, 0 if not.
 */
int isJumpAvailable(int row, int col, char player) {
    int newRow, newCol;
    if (player == PLAYER1) {
        newRow = row - 2;
        newCol = col - 2;
        if (isValidInput(row, col, newRow, newCol, player)) {
            return 1;
        }
        newCol = col + 2;
        if (isValidInput(row, col, newRow, newCol, player)) {
            return 1;
        }
    } else if (player == PLAYER2) {
        newRow = row + 2;
        newCol = col - 2;
        if (isValidInput(row, col, newRow, newCol, player)) {
            return 1;
        }
        newCol = col + 2;
        if (isValidInput(row, col, newRow, newCol, player)) {
            return 1;
        }
    }
    return 0;
}

/**
 * Moves a piece on the board and returns the success or failure of the move.
 * Returns 1 if move was successful, 0 if not.
 */
int movePiece(int row, int col, int newRow, int newCol, char player) {
    if (!isValidInput(row, col, newRow, newCol, player)) {
        return 0;
    }

    // Move piece to new position
    board[newRow][newCol] = board[row][col];
    board[row][col] = ' ';

    // Check if there was a jump and remove opponent's piece
    if (abs(newRow - row) == 2 && abs(newCol - col) == 2) {
        int middleRow = (row + newRow) / 2;
        int middleCol = (col + newCol) / 2;
        board[middleRow][middleCol] = ' ';
    }

    // Check if player has become a king
    if (player == PLAYER1 && newRow == 0) {
        board[newRow][newCol] = 'K';
    } else if (player == PLAYER2 && newRow == BOARD_SIZE - 1) {
        board[newRow][newCol] = 'K';
    }

    return 1;
}

/**
 * Plays a full game of checkers.
 */
void playGame() {
    int row, col, newRow, newCol;
    char player = PLAYER1;
    while (1) {
        printBoard();
        printf("%c's turn.\n", player);
        printf("Enter the row and column of the piece you want to move:\n");
        scanf("%d%d", &row, &col);
        printf("Enter the row and column of the position you want to move to:\n");
        scanf("%d%d", &newRow, &newCol);

        // Check if player is trying to exit the game
        if (row == -1 || col == -1 || newRow == -1 || newCol == -1) {
            return;
        }

        // Check if player has any jumps available
        if (isJumpAvailable(row, col, player)) {
            if (!movePiece(row, col, newRow, newCol, player)) {
                printf("Invalid move.\n");
                continue;
            }
            while (abs(newRow - row) == 2 && abs(newCol - col) == 2 && isJumpAvailable(newRow, newCol, player)) {
                row = newRow;
                col = newCol;
                printf("You have another jump available. Enter the row and column of the position you want to move to:\n");
                scanf("%d%d", &newRow, &newCol);
                if (!movePiece(row, col, newRow, newCol, player)) {
                    printf("Invalid move.\n");
                    break;
                }
            }
        } else {
            if (!movePiece(row, col, newRow, newCol, player)) {
                printf("Invalid move.\n");
                continue;
            }
        }

        // Check if game is over
        int player1Pieces = 0, player2Pieces = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == PLAYER1 || board[i][j] == 'K') {
                    player1Pieces++;
                } else if (board[i][j] == PLAYER2 || board[i][j] == 'k') {
                    player2Pieces++;
                }
            }
        }
        if (player1Pieces == 0) {
            printf("Player 2 wins!\n");
            return;
        } else if (player2Pieces == 0) {
            printf("Player 1 wins!\n");
            return;
        }

        // Switch to next player
        player = player == PLAYER1 ? PLAYER2 : PLAYER1;
    }
}

// Driver code
int main() {
    printf("Welcome to Checkers!\n");
    printf("To exit the game, enter -1 for any input.\n");
    initializeBoard();
    playGame();
    return 0;
}