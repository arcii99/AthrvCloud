//FormAI DATASET v1.0 Category: Checkers Game ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Constants for checkers
#define EMPTY 0
#define BLACK 1
#define WHITE -1
#define BLACK_KING 2
#define WHITE_KING -2

typedef struct Checker {
    int type;
    bool isKing;
} Checker;

void printBoard(Checker board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j].type == EMPTY ? '-' : (board[i][j].type == BLACK || board[i][j].type == BLACK_KING) ? 'B' : 'W');
        }
        printf("\n");
    }
    printf("\n");
}

bool moveIsLegal(Checker board[BOARD_SIZE][BOARD_SIZE], int row, int col, int destRow, int destCol, int currentPlayer) {
    // Check destination is on board
    if (destRow < 0 || destRow >= BOARD_SIZE || destCol < 0 || destCol >= BOARD_SIZE) {
        return false;
    }
    // Check destination is empty
    if (board[destRow][destCol].type != EMPTY) {
        return false;
    }
    // Check move is diagonal and within 2 squares
    int diffRow = abs(destRow - row);
    int diffCol = abs(destCol - col);
    if (diffRow != diffCol || diffRow > 2 || diffCol > 2) {
        return false;
    }
    // Check if moving in correct direction for player
    bool isKing = board[row][col].isKing;
    if (!isKing && ((currentPlayer == BLACK && destRow > row) || (currentPlayer == WHITE && destRow < row))) {
        return false;
    }
    // Check if jumping over checker
    if (diffRow == 2) {
        int jumpedRow = (destRow + row) / 2;
        int jumpedCol = (destCol + col) / 2;
        int jumpedChecker = board[jumpedRow][jumpedCol].type;
        if ((jumpedChecker == EMPTY) || (currentPlayer == BLACK && jumpedChecker != WHITE && jumpedChecker != WHITE_KING) || (currentPlayer == WHITE && jumpedChecker != BLACK && jumpedChecker != BLACK_KING)) {
            return false;
        }
    }
    return true;
}

bool playerHasMoves(Checker board[BOARD_SIZE][BOARD_SIZE], int currentPlayer) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].type == currentPlayer || (board[i][j].type == currentPlayer * 2 && board[i][j].isKing)) {
                for (int k = -2; k <= 2; k += 4) {
                    for (int l = -2; l <= 2; l += 4) {
                        int destRow = i + currentPlayer * k;
                        int destCol = j + l;
                        if (moveIsLegal(board, i, j, destRow, destCol, currentPlayer)) {
                            return true;
                        }
                    }
                }
            }
        }
    }
    return false;
}

void makeMove(Checker board[BOARD_SIZE][BOARD_SIZE], int row, int col, int destRow, int destCol, int currentPlayer) {
    board[destRow][destCol].type = board[row][col].type;
    board[destRow][destCol].isKing = board[row][col].isKing;
    board[row][col].type = EMPTY;
    // Check if reached other side and promote to king
    if (destRow == 0 && board[destRow][destCol].type == WHITE) {
        board[destRow][destCol].type = WHITE_KING;
        board[destRow][destCol].isKing = true;
    }
    if (destRow == BOARD_SIZE - 1 && board[destRow][destCol].type == BLACK) {
        board[destRow][destCol].type = BLACK_KING;
        board[destRow][destCol].isKing = true;
    }
    // If jumped over checker, remove it
    if (abs(destRow - row) == 2) {
        int jumpedRow = (destRow + row) / 2;
        int jumpedCol = (destCol + col) / 2;
        board[jumpedRow][jumpedCol].type = EMPTY;
        board[jumpedRow][jumpedCol].isKing = false;
    }
}

int main() {
    Checker board[BOARD_SIZE][BOARD_SIZE];
    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0 && i < 3) {
                board[i][j].type = BLACK;
                board[i][j].isKing = false;
            } else if ((i + j) % 2 == 0 && i > BOARD_SIZE - 4) {
                board[i][j].type = WHITE;
                board[i][j].isKing = false;
            } else {
                board[i][j].type = EMPTY;
                board[i][j].isKing = false;
            }
        }
    }
    printBoard(board);
    int currentPlayer = BLACK;
    printf("Black goes first.\n");
    while (true) {
        if (!playerHasMoves(board, currentPlayer)) {
            printf("%s has no moves left and %s wins!\n", currentPlayer == BLACK ? "Black" : "White", currentPlayer == BLACK ? "White" : "Black");
            break;
        }
        printf("%s's turn.\n", currentPlayer == BLACK ? "Black" : "White");
        int row, col, destRow, destCol;
        while (true) {
            printf("Enter row and column of checker to move: ");
            scanf("%d %d", &row, &col);
            printf("Enter row and column of destination square: ");
            scanf("%d %d", &destRow, &destCol);
            if (moveIsLegal(board, row, col, destRow, destCol, currentPlayer)) {
                break;
            }
            printf("Invalid move! Please try again.\n");
        }
        makeMove(board, row, col, destRow, destCol, currentPlayer);
        printBoard(board);
        if ((destRow == BOARD_SIZE - 1 && currentPlayer == BLACK) || (destRow == 0 && currentPlayer == WHITE)) {
            printf("%s wins!\n", currentPlayer == BLACK ? "Black" : "White");
            break;
        }
        currentPlayer = -currentPlayer;
    }
    return 0;
}