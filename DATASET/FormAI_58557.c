//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include <stdio.h>

#define BOARD_SIZE 8

// Players
#define PLAYER_1 1
#define PLAYER_2 2

// Game pieces
#define EMPTY 0
#define PLAYER_1_PIECE 1
#define PLAYER_1_KING 2
#define PLAYER_2_PIECE 3
#define PLAYER_2_KING 4

// Directions for moving game pieces
#define FORWARD_LEFT 0
#define FORWARD_RIGHT 1
#define BACK_LEFT 2
#define BACK_RIGHT 3

// Board data structure
int board[BOARD_SIZE][BOARD_SIZE];

// Print the board to the console
void printBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

// Initialize the board
void initializeBoard() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 != j % 2) {
                if (i < 3) {
                    board[i][j] = PLAYER_1_PIECE;
                } else if (i > 4) {
                    board[i][j] = PLAYER_2_PIECE;
                } else {
                    board[i][j] = EMPTY;
                }
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

// Move a game piece on the board
void movePiece(int row, int col, int direction, int player) {
    // Check if the move is valid
    if (row + 1 >= BOARD_SIZE || col + 1 >= BOARD_SIZE || row - 1 < 0 || col - 1 < 0) {
        return;
    }
    int newRow = row;
    int newCol = col;
    switch (direction) {
        case FORWARD_LEFT:
            newRow--;
            newCol--;
            break;
        case FORWARD_RIGHT:
            newRow--;
            newCol++;
            break;
        case BACK_LEFT:
            newRow++;
            newCol--;
            break;
        case BACK_RIGHT:
            newRow++;
            newCol++;
            break;
        default:
            return;
    }

    // Check if the space is vacant
    if (board[newRow][newCol] == EMPTY) {
        board[newRow][newCol] = board[row][col];
        board[row][col] = EMPTY;
        return;
    }

    // Check if the space is occupied by the opposing player
    if ((player == PLAYER_1 && board[newRow][newCol] == PLAYER_2_PIECE) || (player == PLAYER_2 && board[newRow][newCol] == PLAYER_1_PIECE)) {
        // Check if the jump space is valid
        if (newRow + 1 >= BOARD_SIZE || newCol + 1 >= BOARD_SIZE || newRow - 1 < 0 || newCol - 1 < 0) {
            return;
        }
        int jumpRow = newRow;
        int jumpCol = newCol;
        switch (direction) {
            case FORWARD_LEFT:
                jumpRow--;
                jumpCol--;
                break;
            case FORWARD_RIGHT:
                jumpRow--;
                jumpCol++;
                break;
            case BACK_LEFT:
                jumpRow++;
                jumpCol--;
                break;
            case BACK_RIGHT:
                jumpRow++;
                jumpCol++;
                break;
            default:
                return;
        }

        // Check if the jump space is vacant
        if (board[jumpRow][jumpCol] == EMPTY) {
            board[jumpRow][jumpCol] = board[row][col];
            board[newRow][newCol] = EMPTY;
            board[row][col] = EMPTY;
            return;
        }
    }
}

int main() {
    initializeBoard();
    printBoard();
    return 0;
}