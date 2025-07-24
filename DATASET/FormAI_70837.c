//FormAI DATASET v1.0 Category: Chess engine ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef enum { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING } Piece;
typedef enum { BLACK = -1, WHITE = 1 } Colour;

typedef struct {
    Piece piece;
    Colour colour;
} Square;

typedef Square Board[8][8];

void initialiseBoard(Board board) {
    Piece pieces[8] = { ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK };
    Colour colours[8] = { BLACK, BLACK, BLACK, BLACK, WHITE, WHITE, WHITE, WHITE };

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (row == 0 || row == 7) {
                board[row][col].piece = pieces[col];
                board[row][col].colour = colours[col];
            } else if (row == 1 || row == 6) {
                board[row][col].piece = PAWN;
                board[row][col].colour = (row == 1 ? BLACK : WHITE);
            } else {
                board[row][col].piece = 0;
                board[row][col].colour = 0;
            }
        }
    }
}

void printBoard(Board board) {
    printf("   a b c d e f g h\n");
    printf("  +---------------+\n");
    for (int row = 0; row < 8; row++) {
        printf("%d |", 8 - row);
        for (int col = 0; col < 8; col++) {
            printf(" %d", board[row][col].piece);
        }
        printf(" |\n");
    }
    printf("  +---------------+\n");
}

int main() {
    Board board;
    initialiseBoard(board);
    printBoard(board);
    return 0;
}