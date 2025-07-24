//FormAI DATASET v1.0 Category: Chess AI ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

// Piece constants
#define EMPTY 0
#define PAWN 1
#define KNIGHT 2
#define BISHOP 3
#define ROOK 4
#define QUEEN 5
#define KING 6

// Board array
int board[BOARD_SIZE][BOARD_SIZE] = {
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
    {PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN},
    {ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK}
};

// Color constants
enum Color { WHITE, BLACK };

// Struct for pieces
struct Piece {
    int type;
    bool hasMoved;
    enum Color color;
};

// Move struct
struct Move {
    int startX;
    int startY;
    int endX;
    int endY;
};

// Gets the piece at a location
struct Piece getPiece(int x, int y) {
    struct Piece piece;
    piece.type = board[y][x];
    piece.hasMoved = false;
    if (piece.type != EMPTY) {
        piece.hasMoved = true;
    }
    if (y < 2) {
        piece.color = BLACK;
    }
    else {
        piece.color = WHITE;
    }
    return piece;
}

// Gets whether a move is valid or not
bool isValidMove(struct Move move) {
    struct Piece piece = getPiece(move.startX, move.startY);
    if (piece.type == EMPTY) {
        return false;
    }
    if (move.endX < 0 || move.endX >= BOARD_SIZE || move.endY < 0 || move.endY >= BOARD_SIZE) {
        return false;
    }
    int deltaX = move.endX - move.startX;
    int deltaY = move.endY - move.startY;
    switch (piece.type) {
        case PAWN:
            if (piece.color == WHITE) {
                if (deltaY == 1 && deltaY == 0 && getPiece(move.endX, move.endY).type == EMPTY) {
                    return true;
                }
                if (deltaY == 2 && deltaY == 0 && getPiece(move.endX, move.endY).type == EMPTY && getPiece(move.startX, move.startY + 1).type == EMPTY) {
                    return true;
                }
                if (deltaY == 1 && abs(deltaX) == 1 && getPiece(move.endX, move.endY).type != EMPTY && getPiece(move.endX, move.endY).color == BLACK) {
                    return true;
                }
            }
            else {
                if (deltaY == -1 && deltaX == 0 && getPiece(move.endX, move.endY).type == EMPTY) {
                    return true;
                }
                if (deltaY == -2 && deltaX == 0 && getPiece(move.endX, move.endY).type == EMPTY && getPiece(move.startX, move.startY - 1).type == EMPTY) {
                    return true;
                }
                if (deltaY == -1 && abs(deltaX) == 1 && getPiece(move.endX, move.endY).type != EMPTY && getPiece(move.endX, move.endY).color == WHITE) {
                    return true;
                }
            }
            break;
        case KNIGHT:
            if ((abs(deltaX) == 2 && abs(deltaY) == 1) || (abs(deltaX) == 1 && abs(deltaY) == 2)) {
                return true;
            }
            break;
        case BISHOP:
            if (abs(deltaX) == abs(deltaY)) {
                int xDir = deltaX > 0 ? 1 : -1;
                int yDir = deltaY > 0 ? 1 : -1;
                int x = move.startX + xDir;
                int y = move.startY + yDir;
                while (x != move.endX && y != move.endY) {
                    if (getPiece(x, y).type != EMPTY) {
                        return false;
                    }
                    x += xDir;
                    y += yDir;
                }
                return true;
            }
            break;
        case ROOK:
            if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
                int dir = deltaX != 0 ? deltaX / abs(deltaX) : deltaY / abs(deltaY);
                if (deltaX != 0) {
                    for (int x = move.startX + dir; x != move.endX; x += dir) {
                        if (getPiece(x, move.startY).type != EMPTY) {
                            return false;
                        }
                    }
                }
                else {
                    for (int y = move.startY + dir; y != move.endY; y += dir) {
                        if (getPiece(move.startX, y).type != EMPTY) {
                            return false;
                        }
                    }
                }
                return true;
            }
            break;
        case QUEEN:
            if (abs(deltaX) == abs(deltaY)) {
                int xDir = deltaX > 0 ? 1 : -1;
                int yDir = deltaY > 0 ? 1 : -1;
                int x = move.startX + xDir;
                int y = move.startY + yDir;
                while (x != move.endX && y != move.endY) {
                    if (getPiece(x, y).type != EMPTY) {
                        return false;
                    }
                    x += xDir;
                    y += yDir;
                }
                return true;
            }
            else if ((deltaX == 0 && deltaY != 0) || (deltaX != 0 && deltaY == 0)) {
                int dir = deltaX != 0 ? deltaX / abs(deltaX) : deltaY / abs(deltaY);
                if (deltaX != 0) {
                    for (int x = move.startX + dir; x != move.endX; x += dir) {
                        if (getPiece(x, move.startY).type != EMPTY) {
                            return false;
                        }
                    }
                }
                else {
                    for (int y = move.startY + dir; y != move.endY; y += dir) {
                        if (getPiece(move.startX, y).type != EMPTY) {
                            return false;
                        }
                    }
                }
                return true;
            }
            break;
        case KING:
            if (abs(deltaX) <= 1 && abs(deltaY) <= 1) {
                return true;
            }
            break;
    }
    return false;
}

// Moves a piece
void makeMove(struct Move move) {
    board[move.endY][move.endX] = board[move.startY][move.startX];
    board[move.startY][move.startX] = EMPTY;
}

// Prints the board
void printBoard() {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("%d ", y);
        for (int x = 0; x < BOARD_SIZE; x++) {
            switch(board[y][x]) {
                case EMPTY:
                    printf(". ");
                    break;
                case PAWN:
                    printf("P ");
                    break;
                case KNIGHT:
                    printf("N ");
                    break;
                case BISHOP:
                    printf("B ");
                    break;
                case ROOK:
                    printf("R ");
                    break;
                case QUEEN:
                    printf("Q ");
                    break;
                case KING:
                    printf("K ");
                    break;
            }
        }
        printf("%d\n", y);
    }
    printf("  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
}

int main() {
    printBoard();
    return 0;
}