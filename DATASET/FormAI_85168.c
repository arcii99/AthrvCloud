//FormAI DATASET v1.0 Category: Checkers Game ; Style: careful
#include <stdio.h>

#define ROWS 8
#define COLS 8

// Function to draw the checkers board
void drawBoard(char board[][COLS]) {
    printf("     1   2   3   4   5   6   7   8\n");
    printf("   +---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < ROWS; i++) {
        printf(" %c ", 'A' + i);
        for (int j = 0; j < COLS; j++) {
            printf("| %c ", board[i][j]);
        }
        printf("|\n");
        printf("   +---+---+---+---+---+---+---+---+\n");
    }
}

// Function to initialize the checkers board
void initBoard(char board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i < 3 && (i + j) % 2 == 0) {
                board[i][j] = 'B';
            } else if (i > 4 && (i + j) % 2 == 0) {
                board[i][j] = 'W';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

// Function to move the checkers piece
void movePiece(char board[][COLS], int fromRow, int fromCol, int toRow, int toCol) {
    if (board[toRow][toCol] != ' ') {
        printf("Invalid move, position already taken!\n");
    } else if (toRow == fromRow + 1 && (toCol == fromCol + 1 || toCol == fromCol - 1)) {
        board[toRow][toCol] = board[fromRow][fromCol];
        board[fromRow][fromCol] = ' ';
    } else if (toRow == fromRow + 2 && (toCol == fromCol + 2 || toCol == fromCol - 2)) {
        int jumpRow = (fromRow + toRow) / 2;
        int jumpCol = (fromCol + toCol) / 2;
        if (board[jumpRow][jumpCol] == ' ' || board[jumpRow][jumpCol] == board[fromRow][fromCol]) {
            printf("Invalid move, position cannot be jumped!\n");
        } else {
            board[toRow][toCol] = board[fromRow][fromCol];
            board[fromRow][fromCol] = ' ';
            board[jumpRow][jumpCol] = ' ';
        }
    } else {
        printf("Invalid move, please try again!\n");
    }
}

int main() {
    char board[ROWS][COLS];
    int fromRow, fromCol, toRow, toCol;
    char player = 'W';

    initBoard(board);

    do {
        drawBoard(board);
        printf("Player %c's turn!\n", player);
        printf("Enter piece location (ex. A3): ");
        scanf(" %c%d", &fromRow, &fromCol);
        fromRow -= 'A';
        fromCol--;
        printf("Enter destination (ex. B4): ");
        scanf(" %c%d", &toRow, &toCol);
        toRow -= 'A';
        toCol--;

        movePiece(board, fromRow, fromCol, toRow, toCol);

        if (player == 'W') {
            player = 'B';
        } else {
            player = 'W';
        }
    } while (1);

    return 0;
}