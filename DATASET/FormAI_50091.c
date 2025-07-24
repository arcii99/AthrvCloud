//FormAI DATASET v1.0 Category: Checkers Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>

void drawBoard(char board[8][8]) {
    int row, col;
    printf("\n  ");
    for (col = 0; col < 8; col++) {
        printf(" %i", col + 1);
    }
    printf("\n");
    for (col = 0; col < 8; col++) {
        printf("  _");
    }
    printf("\n");
    for (row = 0; row < 8; row++) {
        printf("%i|", row + 1);
        for (col = 0; col < 8; col++) {
            printf("%c|", board[row][col]);
        }
        printf("\n");
        for (col = 0; col < 8; col++) {
            printf("  _");
        }
        printf("\n");
    }
}

void setupBoard(char board[8][8]) {
    int row, col;
    for (row = 0; row < 8; row++) {
        for (col = 0; col < 8; col++) {
            if ((row + col) % 2 != 0) {
                if (row < 3) {
                    board[row][col] = 'X';
                } else if (row > 4) {
                    board[row][col] = 'O';
                } else {
                    board[row][col] = ' ';
                }
            } else {
                board[row][col] = ' ';
            }
        }
    }
}

int moveChecker(char checker, int fromRow, int fromCol, int toRow, int toCol, char board[8][8]) {
    if (board[fromRow][fromCol] != checker) {
        printf("You don't have a checker there!\n");
        return 0;
    } else if (board[toRow][toCol] != ' ') {
        printf("That spot is already taken!\n");
        return 0;
    } else {
        int rowDiff = toRow - fromRow;
        int colDiff = toCol - fromCol;
        if (checker == 'X') {
            if (rowDiff == -1 && abs(colDiff) == 1) {
                board[fromRow][fromCol] = ' ';
                board[toRow][toCol] = 'X';
                return 1;
            } else if (rowDiff == -2 && abs(colDiff) == 2) {
                int jumpedRow = fromRow - 1;
                int jumpedCol = fromCol + (colDiff / 2);
                if (board[jumpedRow][jumpedCol] != 'O') {
                    printf("You can only jump over an opponent's checker!\n");
                    return 0;
                } else {
                    board[fromRow][fromCol] = ' ';
                    board[jumpedRow][jumpedCol] = ' ';
                    board[toRow][toCol] = 'X';
                    return 2;
                }
            } else {
                printf("Invalid move!\n");
                return 0;
            }
        } else if (checker == 'O') {
            if (rowDiff == 1 && abs(colDiff) == 1) {
                board[fromRow][fromCol] = ' ';
                board[toRow][toCol] = 'O';
                return 1;
            } else if (rowDiff == 2 && abs(colDiff) == 2) {
                int jumpedRow = fromRow + 1;
                int jumpedCol = fromCol + (colDiff / 2);
                if (board[jumpedRow][jumpedCol] != 'X') {
                    printf("You can only jump over an opponent's checker!\n");
                    return 0;
                } else {
                    board[fromRow][fromCol] = ' ';
                    board[jumpedRow][jumpedCol] = ' ';
                    board[toRow][toCol] = 'O';
                    return 2;
                }
            } else {
                printf("Invalid move!\n");
                return 0;
            }
        }
    }
}

int main() {
    char board[8][8];
    char currentPlayer = 'X';
    int numMoves = 0;
    setupBoard(board);
    while (1) {
        drawBoard(board);
        printf("%c's turn to move\n", currentPlayer);
        int fromRow, fromCol, toRow, toCol, numJumped;
        printf("Enter the row and column of the checker you want to move: ");
        scanf("%i %i", &fromRow, &fromCol);
        printf("Enter the row and column of the spot you want to move to: ");
        scanf("%i %i", &toRow, &toCol);
        numJumped = moveChecker(currentPlayer, fromRow - 1, fromCol - 1, toRow - 1, toCol - 1, board);
        if (numJumped == 0) {
            continue;
        } else {
            numMoves++;
            if (numJumped == 2) {
                printf("Nice jump! You get to go again\n");
            }
        }
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
        int row;
        for (row = 0; row < 8; row++) {
            if (board[0][row] == 'O') {
                printf("Congratulations, player O wins!\n");
                return 0;
            }
            if (board[7][row] == 'X') {
                printf("Congratulations, player X wins!\n");
                return 0;
            }
        }
        if (numMoves == 50) {
            printf("Game over, it's a draw!\n");
            return 0;
        }
    }
    return 0;
}