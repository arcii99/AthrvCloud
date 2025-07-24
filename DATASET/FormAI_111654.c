//FormAI DATASET v1.0 Category: Chess AI ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define ROWS 8
#define COLS 8

int pawnValue = 1;
int knightValue = 3;
int bishopValue = 3;
int rookValue = 5;
int queenValue = 9;
int kingValue = 1000;

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char piece;
    int value;
    bool hasMoved;
    Position position;
} BoardTile;

typedef struct {
    BoardTile board[ROWS][COLS];
    char team;
    bool check;
    bool checkmate;
    Position kingPos;
} ChessBoard;

void initBoard(ChessBoard *board) {
    char startingRow[] = "rnbqkbnr";
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            board->board[row][col].position.row = row;
            board->board[row][col].position.col = col;
            if (row == 0 || row == 7) {
                board->board[row][col].hasMoved = false;
                if (col == 0 || col == 7) {
                    board->board[row][col].piece = startingRow[col];
                } else if (col == 1 || col == 6) {
                    board->board[row][col].piece = 'n';
                    board->board[row][col].value = knightValue;
                } else if (col == 2 || col == 5) {
                    board->board[row][col].piece = 'b';
                    board->board[row][col].value = bishopValue;
                } else if (col == 3) {
                    board->board[row][col].piece = 'q';
                    board->board[row][col].value = queenValue;
                } else {
                    board->board[row][col].piece = 'k';
                    board->board[row][col].value = kingValue;
                    board->kingPos.row = row;
                    board->kingPos.col = col;
                }
            } else if (row == 1 || row == 6) {
                board->board[row][col].hasMoved = false;
                board->board[row][col].piece = 'p';
                board->board[row][col].value = pawnValue;
            } else {
                board->board[row][col].piece = '.';
            }
        }
    }
    board->team = 'w';
    board->check = false;
    board->checkmate = false;
}

void printBoard(ChessBoard board) {
    printf("\n  A B C D E F G H\n");
    for (int row = 0; row < ROWS; row++) {
        printf("%d ", row + 1);
        for (int col = 0; col < COLS; col++) {
            printf("%c ", board.board[row][col].piece);
        }
        printf("%d", row + 1);
        printf("\n");
    }
    printf("  A B C D E F G H\n");
}

void playChess(ChessBoard *board) {
    initBoard(board);
    printBoard(*board);
}

int main() {
    ChessBoard board;
    playChess(&board);
    return 0;
}