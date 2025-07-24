//FormAI DATASET v1.0 Category: Chess engine ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    char type;
    bool color;
} Piece;

typedef Piece Board[BOARD_SIZE][BOARD_SIZE];

void printBoard(Board board) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col].type);
        }
        printf("\n");
    }
    printf("\n");
}

void initializeBoard(Board board) {
    // initialize pawns
    for (int col = 0; col < BOARD_SIZE; col++) {
        board[1][col] = (Piece) {'p', false};
        board[6][col] = (Piece) {'p', true};
    }
    
    // initialize other pieces
    board[0][0] = (Piece) {'r', false};
    board[0][1] = (Piece) {'n', false};
    board[0][2] = (Piece) {'b', false};
    board[0][3] = (Piece) {'q', false};
    board[0][4] = (Piece) {'k', false};
    board[0][5] = (Piece) {'b', false};
    board[0][6] = (Piece) {'n', false};
    board[0][7] = (Piece) {'r', false};

    board[7][0] = (Piece) {'r', true};
    board[7][1] = (Piece) {'n', true};
    board[7][2] = (Piece) {'b', true};
    board[7][3] = (Piece) {'q', true};
    board[7][4] = (Piece) {'k', true};
    board[7][5] = (Piece) {'b', true};
    board[7][6] = (Piece) {'n', true};
    board[7][7] = (Piece) {'r', true};
}

bool isValidMove(Board board, int startRow, int startCol, int endRow, int endCol, bool color) {
    if (endRow < 0 || endRow >= BOARD_SIZE || endCol < 0 || endCol >= BOARD_SIZE) {
        return false;
    }
    
    char pieceType = board[startRow][startCol].type;
    bool pieceColor = board[startRow][startCol].color;
    
    if (pieceColor != color) {
        return false;
    }
    
    if (pieceType == 'p') {
        // handle pawn moves
        int deltaY = color ? -1 : 1;
        if (endRow == startRow + deltaY && endCol == startCol) {
            if (board[endRow][endCol].type == '\0') {
                return true;
            }
        } else if (endRow == startRow + deltaY && abs(endCol - startCol) == 1) {
            if (board[endRow][endCol].type != '\0' && board[endRow][endCol].color != color) {
                return true;
            }
        }
        return false;
    } else if (pieceType == 'r') {
        // handle rook moves
        if (startRow != endRow && startCol != endCol) {
            return false;
        }
        int rowDelta = (endRow - startRow) > 0 ? 1 : -1;
        int colDelta = (endCol - startCol) > 0 ? 1 : -1;
        if (startRow == endRow) {
            for (int col = startCol + colDelta; col != endCol; col += colDelta) {
                if (board[startRow][col].type != '\0') {
                    return false;
                }
            }
        } else {
            for (int row = startRow + rowDelta; row != endRow; row += rowDelta) {
                if (board[row][startCol].type != '\0') {
                    return false;
                }
            }
        }
        if (board[endRow][endCol].type != '\0' && board[endRow][endCol].color == color) {
            return false;
        }
        return true;
    } else if (pieceType == 'n') {
        // handle knight moves
        int rowDelta = abs(endRow - startRow);
        int colDelta = abs(endCol - startCol);
        if ((rowDelta == 2 && colDelta == 1) || (rowDelta == 1 && colDelta == 2)) {
            if (board[endRow][endCol].type != '\0') {
                if (board[endRow][endCol].color != color) {
                    return true;
                }
            } else {
                return true;
            }
        }
        return false;
    } else if (pieceType == 'b') {
        // handle bishop moves
        if (abs(endRow - startRow) != abs(endCol - startCol)) {
            return false;
        }
        int rowDelta = (endRow - startRow) > 0 ? 1 : -1;
        int colDelta = (endCol - startCol) > 0 ? 1 : -1;
        int row = startRow + rowDelta;
        int col = startCol + colDelta;
        while (row != endRow && col != endCol) {
            if (board[row][col].type != '\0') {
                return false;
            }
            row += rowDelta;
            col += colDelta;
        }
        if (board[endRow][endCol].type != '\0' && board[endRow][endCol].color == color) {
            return false;
        }
        return true;
    } else if (pieceType == 'q') {
        // handle queen moves
        if (startRow == endRow || startCol == endCol) {
            return isValidMove(board, startRow, startCol, endRow, endCol, color - 1);
        } else {
            return isValidMove(board, startRow, startCol, endRow, endCol, color - 1);
        }
    } else if (pieceType == 'k') {
        // handle king moves
        int rowDelta = abs(endRow - startRow);
        int colDelta = abs(endCol - startCol);
        if (rowDelta <= 1 && colDelta <= 1) {
            if (board[endRow][endCol].type != '\0') {
                if (board[endRow][endCol].color != color) {
                    return true;
                }
            } else {
                return true;
            }
        }
        return false;
    }
}

int main() {
    Board board = {0};
    initializeBoard(board);
    printBoard(board);
    return 0;
}