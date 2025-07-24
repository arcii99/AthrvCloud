//FormAI DATASET v1.0 Category: Checkers Game ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Board array to store the current game state
int board[BOARD_SIZE][BOARD_SIZE];

// Function to initialize the board to the starting game state
void initializeBoard() {
    // Initialize all squares to 0 (empty)
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }

    // Set up the red pieces on the top three rows
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = 1;
            }
        }
    }

    // Set up the black pieces on the bottom three rows
    for (int i = BOARD_SIZE - 3; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j] = 2;
            }
        }
    }
}

// Function to print the current state of the board
void printBoard() {
    printf("  0 1 2 3 4 5 6 7\n");
    printf("-----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case 0:
                    printf(" |");
                    break;
                case 1:
                    printf("r|");
                    break;
                case 2:
                    printf("b|");
                    break;
                case 3:
                    printf("R|");
                    break;
                case 4:
                    printf("B|");
                    break;
            }
        }
        printf("\n");
        printf("-----------------\n");
    }
}

// Function to check if a square is a valid move for a piece
int isValidMove(int piece, int x, int y, int newX, int newY) {
    // Check that the new position is on the board
    if (newX < 0 || newX >= BOARD_SIZE || newY < 0 || newY >= BOARD_SIZE) {
        return 0;
    }

    // Check that the new position is empty
    if (board[newX][newY] != 0) {
        return 0;
    }

    // Check that regular pieces are only moving forward
    if (piece == 1 && newX > x) {
        return 0;
    }
    if (piece == 2 && newX < x) {
        return 0;
    }

    // Check if this is a regular move or a jump
    if (abs(newX - x) == 1 && abs(newY - y) == 1) {
        // Regular move - only one square diagonally
        return 1;
    } else if (abs(newX - x) == 2 && abs(newY - y) == 2) {
        // Jump - must be over an opponent's piece
        int midX = (newX + x) / 2;
        int midY = (newY + y) / 2;
        if (board[midX][midY] == 0 || board[midX][midY] == piece || board[midX][midY] == piece + 2) {
            return 0;
        } else {
            return 2; // Return 2 to indicate a jump
        }
    } else {
        return 0;
    }
}

// Function to execute a move
void makeMove(int piece, int x, int y, int newX, int newY) {
    board[newX][newY] = piece;

    if (abs(newX - x) == 2 && abs(newY - y) == 2) {
        // Jump - remove the captured piece
        int midX = (newX + x) / 2;
        int midY = (newY + y) / 2;
        board[midX][midY] = 0;
    }

    if (newX == 0 || newX == BOARD_SIZE - 1) {
        // Promote the piece to a king if it reaches the opposite end of the board
        board[newX][newY] += 2;
    }
}

// Function to check if a player has any more moves
int hasMoves(int player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player + 2) {
                for (int dx = -2; dx <= 2; dx++) {
                    for (int dy = -2; dy <= 2; dy++) {
                        if (isValidMove(board[i][j], i, j, i + dx, j + dy) == 2) {
                            return 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}

// Function to play the game
void playGame() {
    int currentPlayer = 1;
    int x, y, newX, newY, isValid;
    while (1) {
        printf("Player %d's turn\n", currentPlayer);
        printBoard();
        printf("Enter current position of the piece (row and column): ");
        scanf("%d %d", &x, &y);
        printf("Enter new position of the piece (row and column): ");
        scanf("%d %d", &newX, &newY);
        isValid = isValidMove(board[x][y], x, y, newX, newY);
        if (isValid == 0) {
            printf("Invalid move\n");
            continue;
        } else if (isValid == 1) {
            makeMove(board[x][y], x, y, newX, newY);
        } else {
            makeMove(board[x][y], x, y, newX, newY);
            printf("Jumped over a piece!\n");
        }
        if (!hasMoves(currentPlayer)) {
            if (currentPlayer == 1) {
                printf("Player 2 wins!\n");
            } else {
                printf("Player 1 wins!\n");
            }
            return;
        }
        // Switch to the other player
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }
}

int main() {
    initializeBoard();
    playGame();
    return 0;
}