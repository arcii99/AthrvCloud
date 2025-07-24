//FormAI DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

void printBoard(char board[ROWS][COLS]) {
    printf("\n  1 2 3 4 5 6 7 8\n");
    for(int i = 0; i < ROWS; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

bool canMove(char board[ROWS][COLS], int fromRow, int fromCol, int toRow, int toCol) {
    if (toRow < 0 || toRow >= ROWS || toCol < 0 || toCol >= COLS) {
        // Can't move out of bounds
        return false;
    }
    if (board[toRow][toCol] != '-') {
        // Can't move onto an occupied square
        return false;
    }
    if (board[fromRow][fromCol] == 'r') {
        // Red pieces can only move diagonally down the board
        if (toRow <= fromRow) {
            return false;
        }
        if (toRow - fromRow > 2 || abs(toCol - fromCol) > 2) {
            return false;
        }
        if (toRow - fromRow == 2) {
            if (toCol - fromCol == 2 && board[fromRow+1][fromCol+1] != 'b') {
                return false;
            }
            if (toCol - fromCol == -2 && board[fromRow+1][fromCol-1] != 'b') {
                return false;
            }
        }
    } else if (board[fromRow][fromCol] == 'b') {
        // Black pieces can only move diagonally up the board
        if (toRow >= fromRow) {
            return false;
        }
        if (fromRow - toRow > 2 || abs(toCol - fromCol) > 2) {
            return false;
        }
        if (fromRow - toRow == 2) {
            if (toCol - fromCol == 2 && board[fromRow-1][fromCol+1] != 'r') {
                return false;
            }
            if (toCol - fromCol == -2 && board[fromRow-1][fromCol-1] != 'r') {
                return false;
            }
        }
    } else {
        // Empty squares can't move
        return false;
    }
    return true;
}

void makeMove(char board[ROWS][COLS], int fromRow, int fromCol, int toRow, int toCol) {
    board[toRow][toCol] = board[fromRow][fromCol];
    board[fromRow][fromCol] = '-';
    if (abs(toRow - fromRow) == 2) {
        // If it was a capture move, remove the captured piece
        board[(toRow+fromRow)/2][(toCol+fromCol)/2] = '-';
    }
}

int main() {
    char board[ROWS][COLS] = {
        {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
        {'r', '-', 'r', '-', 'r', '-', 'r', '-'},
        {'-', 'r', '-', 'r', '-', 'r', '-', 'r'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'-', '-', '-', '-', '-', '-', '-', '-'},
        {'b', '-', 'b', '-', 'b', '-', 'b', '-'},
        {'-', 'b', '-', 'b', '-', 'b', '-', 'b'},
        {'b', '-', 'b', '-', 'b', '-', 'b', '-'}
    };
    int turn = 0; // red = 0, black = 1
    int moves = 0;
    while (true) {
        printBoard(board);
        int fromRow, fromCol, toRow, toCol;
        bool validMove = false;
        do {
            printf("\nTurn %d: %s to move\n", moves+1, turn == 0 ? "Red" : "Black");
            printf("Enter move (e.g. '3 2 4 3'): ");
            scanf("%d %d %d %d", &fromRow, &fromCol, &toRow, &toCol);
            if (canMove(board, fromRow-1, fromCol-1, toRow-1, toCol-1)) {
                makeMove(board, fromRow-1, fromCol-1, toRow-1, toCol-1);
                validMove = true;
            } else {
                printf("Invalid move\n");
            }
        } while (!validMove);
        // Check if the game is over
        bool gameOver = true;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == 'r') {
                    gameOver = false;
                }
                if (board[i][j] == 'b') {
                    gameOver = false;
                }
            }
        }
        if (gameOver) {
            printf("\nGame over after %d moves. %s wins!\n", moves+1, turn == 0 ? "Black" : "Red");
            break;
        }
        // Switch turns
        turn = 1 - turn;
        moves++;
    }
    return 0;
}