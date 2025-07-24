//FormAI DATASET v1.0 Category: Checkers Game ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define BOARD_SIZE 8

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char symbol;
    bool isKing;
} Checker;

void drawBoard(Checker board[][BOARD_SIZE]) {
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%c ", 'A' + col);
    }
    printf("\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row + 1);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col].symbol);
        }
        printf("%d\n", row + 1);
    }
    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++) {
        printf("%c ", 'A' + col);
    }
    printf("\n");
}

bool isMoveValid(Checker board[][BOARD_SIZE], Position from, Position to) {
    int rowDiff = to.row - from.row;
    int colDiff = to.col - from.col;
    if (board[from.row][from.col].symbol == 'O') {
        if (rowDiff == -1 && (colDiff == 1 || colDiff == -1)) {
            return true;
        }
        if (rowDiff == -2 && colDiff == 2) {
            if (board[from.row - 1][from.col + 1].symbol == 'X') {
                return true;
            }
        }
        if (rowDiff == -2 && colDiff == -2) {
            if (board[from.row - 1][from.col - 1].symbol == 'X') {
                return true;
            }
        }
    } else if (board[from.row][from.col].symbol == 'X') {
        if (rowDiff == 1 && (colDiff == 1 || colDiff == -1)) {
            return true;
        }
        if (rowDiff == 2 && colDiff == 2) {
            if (board[from.row + 1][from.col + 1].symbol == 'O') {
                return true;
            }
        }
        if (rowDiff == 2 && colDiff == -2) {
            if (board[from.row + 1][from.col - 1].symbol == 'O') {
                return true;
            }
        }
    } else if (board[from.row][from.col].isKing == true) {
        if (rowDiff == -1 || rowDiff == 1) {
            if (colDiff == 1 || colDiff == -1) {
                return true;
            }
        }
        if (rowDiff == -2 && colDiff == 2) {
            if (board[from.row - 1][from.col + 1].symbol == 'X' ||
                board[from.row - 1][from.col + 1].symbol == 'X' + 'K' ||
                board[from.row - 1][from.col + 1].symbol == 'O' ||
                board[from.row - 1][from.col + 1].symbol == 'O' + 'K') {
                return true;
            }
        }
        if (rowDiff == -2 && colDiff == -2) {
            if (board[from.row - 1][from.col - 1].symbol == 'X' ||
                board[from.row - 1][from.col - 1].symbol == 'X' + 'K' ||
                board[from.row - 1][from.col - 1].symbol == 'O' ||
                board[from.row - 1][from.col - 1].symbol == 'O' + 'K') {
                return true;
            }
        }
        if (rowDiff == 2 && colDiff == 2) {
            if (board[from.row + 1][from.col + 1].symbol == 'X' ||
                board[from.row + 1][from.col + 1].symbol == 'X' + 'K' ||
                board[from.row + 1][from.col + 1].symbol == 'O' ||
                board[from.row + 1][from.col + 1].symbol == 'O' + 'K') {
                return true;
            }
        }
        if (rowDiff == 2 && colDiff == -2) {
            if (board[from.row + 1][from.col - 1].symbol == 'X' ||
                board[from.row + 1][from.col - 1].symbol == 'X' + 'K' ||
                board[from.row + 1][from.col - 1].symbol == 'O' ||
                board[from.row + 1][from.col - 1].symbol == 'O' + 'K') {
                return true;
            }
        }
    }
    return false;
}

bool hasCapture(Checker board[][BOARD_SIZE], int player) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col].symbol == 'X' + player || board[row][col].symbol == 'X' + player + 'K') {
                if (row < BOARD_SIZE - 2 && col < BOARD_SIZE - 2 && board[row + 1][col + 1].symbol == 'O' + (player ^ 1) &&
                    (board[row + 2][col + 2].symbol == '_' || board[row + 2][col + 2].symbol == ' ')) {
                    return true;
                }
                if (row < BOARD_SIZE - 2 && col > 1 && board[row + 1][col - 1].symbol == 'O' + (player ^ 1) &&
                    (board[row + 2][col - 2].symbol == '_' || board[row + 2][col - 2].symbol == ' ')) {
                    return true;
                }
                if (row > 1 && col < BOARD_SIZE - 2 && board[row - 1][col + 1].symbol == 'O' + (player ^ 1) &&
                    (board[row - 2][col + 2].symbol == '_' || board[row - 2][col + 2].symbol == ' ')) {
                    return true;
                }
                if (row > 1 && col > 1 && board[row - 1][col - 1].symbol == 'O' + (player ^ 1) &&
                    (board[row - 2][col - 2].symbol == '_' || board[row - 2][col - 2].symbol == ' ')) {
                    return true;
                }
            }
        }
    }
    return false;
}

bool makeMove(Checker board[][BOARD_SIZE], Position from, Position to) {
    if (isMoveValid(board, from, to)) {
        board[to.row][to.col] = board[from.row][from.col];
        board[from.row][from.col].symbol = '_';
        if (board[to.row][to.col].symbol == 'O' && to.row == 0) {
            board[to.row][to.col].symbol = 'O' + 'K';
            board[to.row][to.col].isKing = true;
        } else if (board[to.row][to.col].symbol == 'X' && to.row == BOARD_SIZE - 1) {
            board[to.row][to.col].symbol = 'X' + 'K';
            board[to.row][to.col].isKing = true;
        }        
        if (abs(to.row - from.row) == 2 && abs(to.col - from.col) == 2) {
            int rowDiff = (from.row + to.row) / 2 - from.row;
            int colDiff = (from.col + to.col) / 2 - from.col;
            board[from.row + rowDiff][from.col + colDiff].symbol = '_';
        }
        return true;
    }
    return false;
}

bool isPositionValid(char* str, Position* pos) {
    if (strlen(str) != 2 || !isalpha(str[0]) || !isdigit(str[1])) {
        return false;
    }
    int row = atoi(&str[1]) - 1;
    int col = toupper(str[0]) - 'A';
    if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE) {
        return false;
    }
    pos->row = row;
    pos->col = col;
    return true;
}

void playCheckers() {
    Checker board[BOARD_SIZE][BOARD_SIZE];
    memset(board, '_', BOARD_SIZE*BOARD_SIZE*sizeof(Checker));
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (row % 2 == col % 2) {
                board[row][col].symbol = 'O';
                board[BOARD_SIZE - 1 - row][col].symbol = 'X';
            }
        }
    }
    int currentPlayer = 0;
    bool gameOver = false;
    while (!gameOver) {
        drawBoard(board);
        if (hasCapture(board, currentPlayer)) {
            printf("Player %d has a capture move, enter move in the format 'A1 B2': ", currentPlayer + 1);
        } else {
            printf("Player %d, enter move in the format 'A1 B2': ", currentPlayer + 1);
        }
        char input[6];
        fgets(input, sizeof(input), stdin);
        Position from, to;
        if (sscanf(input, "%*c%d%*c%d%*c%d%*c%d", &from.row, &from.col, &to.row, &to.col) == 4) {
            from.row--;
            from.col--;
            to.row--;
            to.col--;
            if (from.row == to.row && from.col == to.col) {
                printf("Invalid move: cannot move to the same position.\n");
            } else if (board[from.row][from.col].symbol == '_' || board[from.row][from.col].symbol == ' ') {
                printf("Invalid move: there is no checker at position %c%d.\n", 'A' + from.col, from.row + 1);
            } else if ((board[from.row][from.col].symbol == 'O' && currentPlayer == 1) ||
                       (board[from.row][from.col].symbol == 'X' && currentPlayer == 0)) {
                printf("Invalid move: cannot move opponent's checker.\n");
            } else if (!makeMove(board, from, to)) {
                printf("Invalid move: cannot move from %c%d to %c%d.\n", 'A' + from.col, from.row + 1, 'A' + to.col, to.row + 1);
            } else {
                printf("Moved from %c%d to %c%d.\n", 'A' + from.col, from.row + 1, 'A' + to.col, to.row + 1);
                if (!hasCapture(board, currentPlayer)) {
                    currentPlayer ^= 1;
                }
                int xCount = 0, oCount = 0;
                for (int row = 0; row < BOARD_SIZE; row++) {
                    for (int col = 0; col < BOARD_SIZE; col++) {
                        if (board[row][col].symbol == 'X' || board[row][col].symbol == 'X' + 'K') {
                            xCount++;
                        } else if (board[row][col].symbol == 'O' || board[row][col].symbol == 'O' + 'K') {
                            oCount++;
                        }
                    }
                }
                if (xCount == 0) {
                    printf("Game over: Player 2 wins!\n");
                    gameOver = true;
                } else if (oCount == 0) {
                    printf("Game over: Player 1 wins!\n");
                    gameOver = true;
                }
            }
        } else {
            printf("Invalid input: expected two positions separated by space.\n");
        }
    }
}

int main() {
    printf("Welcome to Cyberpunk Checkers!\n");
    printf("Player 1 is 'O' while Player 2 is 'X'.\n");
    printf("To make a move, enter the position of your checker followed by the position you want to move to, separated by a space.\n");
    printf("For example, to move from A3 to B4, enter 'A3 B4'.\n");
    printf("Capturing moves are mandatory, but if you have a choice between capturing moves, you can choose which one to make.\n");
    printf("All checkers can only move diagonally, and kings can move diagonally backwards too.\n");
    printf("Kings are represented by uppercase symbols.\n");
    printf("Have fun!\n\n");
    playCheckers();
    return 0;
}