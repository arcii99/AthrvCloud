//FormAI DATASET v1.0 Category: Chess engine ; Style: careful
#include <stdio.h>
#include <stdbool.h>

// Enumeration to represent chess pieces
typedef enum {
    PAWN,
    KNIGHT,
    BISHOP,
    ROOK,
    QUEEN,
    KING
} PieceType;

// Structure to represent a chess piece
typedef struct {
    PieceType type;
    bool isWhite;
} Piece;

// 2D array to represent the chess board
Piece board[8][8] = {
    {{ROOK, true}, {KNIGHT, true}, {BISHOP, true}, {QUEEN, true},
    {KING, true}, {BISHOP, true}, {KNIGHT, true}, {ROOK, true}},
    {{PAWN, true}, {PAWN, true}, {PAWN, true}, {PAWN, true},
    {PAWN, true}, {PAWN, true}, {PAWN, true}, {PAWN, true}},
    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},
    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},
    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},
    {{0}, {0}, {0}, {0}, {0}, {0}, {0}, {0}},
    {{PAWN, false}, {PAWN, false}, {PAWN, false}, {PAWN, false},
    {PAWN, false}, {PAWN, false}, {PAWN, false}, {PAWN, false}},
    {{ROOK, false}, {KNIGHT, false}, {BISHOP, false}, {QUEEN, false},
    {KING, false}, {BISHOP, false}, {KNIGHT, false}, {ROOK, false}}
};

// Print the chess board to the console
void printBoard() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j].type == 0) {
                printf(" ");
            } else {
                switch (board[i][j].type) {
                    case PAWN:
                        printf("P");
                        break;
                    case KNIGHT:
                        printf("N");
                        break;
                    case BISHOP:
                        printf("B");
                        break;
                    case ROOK:
                        printf("R");
                        break;
                    case QUEEN:
                        printf("Q");
                        break;
                    case KING:
                        printf("K");
                        break;
                }
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    printBoard();

    return 0;
}