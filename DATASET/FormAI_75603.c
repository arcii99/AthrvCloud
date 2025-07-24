//FormAI DATASET v1.0 Category: Checkers Game ; Style: invasive
#include <stdio.h>

// Board dimensions
#define ROWS 8
#define COLS 8

// Checker pieces
#define EMPTY 0
#define BLACK 1
#define RED 2

// Board layout
int board[ROWS][COLS] = {
    {EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY, RED},
    {RED, EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY},
    {EMPTY, RED, EMPTY, RED, EMPTY, RED, EMPTY, RED},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY},
    {EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK},
    {BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY, BLACK, EMPTY}
};

// Piece movement
int movePiece(int row1, int col1, int row2, int col2) {
    // Check for valid move
    if (board[row2][col2] == EMPTY && (row2 + col2) % 2 != 0) {
        // Check for capture move
        if (row2 == row1 + 2 && (col2 == col1 + 2 || col2 == col1 - 2)) {
            int rowCap = (row1 + row2) / 2;
            int colCap = (col1 + col2) / 2;
            if (board[rowCap][colCap] == BLACK || board[rowCap][colCap] == BLACK + 1) {
                board[row2][col2] = board[row1][col1];
                board[row1][col1] = EMPTY;
                board[rowCap][colCap] = EMPTY;
                if (row2 == ROWS - 1) {
                    board[row2][col2] = RED + 1;
                }
                return 1;
            }
        }
        // Check for normal move
        else if (row2 == row1 + 1 && (col2 == col1 + 1 || col2 == col1 - 1)) {
            board[row2][col2] = board[row1][col1];
            board[row1][col1] = EMPTY;
            if (row2 == ROWS - 1) {
                board[row2][col2] = RED + 1;
            }
            return 1;
        }
    }
    return 0;
}

// Check for valid moves
int validMove(int player) {
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == player || board[row][col] == player + 1) {
                // Check for capture moves
                if (board[row][col] == player + 1) {
                    if ((row > 1 && col > 1 && board[row - 1][col - 1] == BLACK) || (row > 1 && col < COLS - 2 && board[row - 1][col + 1] == BLACK)
                    || (row < ROWS - 2 && col > 1 && board[row + 1][col - 1] == BLACK) || (row < ROWS - 2 && col < COLS - 2 && board[row + 1][col + 1] == BLACK)) {
                        return 1;
                    }
                }
                // Check for normal moves
                else {
                    if ((row > 0 && col > 0 && board[row - 1][col - 1] == EMPTY && (row + col) % 2 != 0) || (row > 0 && col < COLS - 1 && board[row - 1][col + 1] == EMPTY && (row + col) % 2 != 0)
                    || (row < ROWS - 1 && col > 0 && board[row + 1][col - 1] == EMPTY && (row + col) % 2 != 0) || (row < ROWS - 1 && col < COLS - 1 && board[row + 1][col + 1] == EMPTY && (row + col) % 2 != 0)) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// Print board
void printBoard() {
    printf("\n    ");
    for (int col = 0; col < COLS; col++) {
        printf("%d ", col);
    }
    printf("\n   -----------\n");
    for (int row = 0; row < ROWS; row++) {
        printf("%d | ", row);
        for (int col = 0; col < COLS; col++) {
            printf("%c|", board[row][col] == EMPTY ? ' ' : board[row][col] == BLACK ? 'B' : board[row][col] == RED ? 'R' : 'K');
        }
        printf("\n   -----------\n");
    }
}

// Main function
int main() {
    // Game loop
    int turn = RED;
    while (validMove(BLACK) && validMove(RED)) {
        printBoard();
        printf("%s turn!\n", turn == BLACK ? "Black" : "Red");
        int row1, col1, row2, col2;
        while (1) {
            printf("Enter piece location (row col): ");
            scanf("%d %d", &row1, &col1);
            if (board[row1][col1] == turn || board[row1][col1] == turn + 1) {
                break;
            }
            printf("Invalid piece location! Try again.\n");
        }
        while (1) {
            printf("Enter destination location (row col): ");
            scanf("%d %d", &row2, &col2);
            if (movePiece(row1, col1, row2, col2)) {
                if (board[row2][col2] == RED + 1 || board[row2][col2] == BLACK + 1) {
                    printf("King me!!\n");
                }
                if (turn == BLACK) {
                    turn = RED;
                } else {
                    turn = BLACK;
                }
                break;
            }
            printf("Invalid destination location! Try again.\n");
        }
    }
    // Game over
    printBoard();
    if (!validMove(BLACK)) {
        printf("Red wins!\n");
    } else {
        printf("Black wins!\n");
    }
    return 0;
}