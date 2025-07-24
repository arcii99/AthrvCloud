//FormAI DATASET v1.0 Category: Chess AI ; Style: shocked
#include <stdio.h>

#define BOARD_SIZE 8

typedef enum { PAWN, ROOK, KNIGHT, BISHOP, QUEEN, KING, EMPTY } Piece;

typedef struct {
    Piece piece;
    int color;
} Square;

Square board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    int row, col;
    for (row = 0; row < BOARD_SIZE; ++row) {
        for (col = 0; col < BOARD_SIZE; ++col) {
            if (row == 0 || row == BOARD_SIZE - 1) {
                int color = (row == 0) ? 1 : 0;
                switch (col) {
                    case 0:
                    case BOARD_SIZE - 1:
                        board[row][col].piece = ROOK;
                        break;
                    case 1:
                    case BOARD_SIZE - 2:
                        board[row][col].piece = KNIGHT;
                        break;
                    case 2:
                    case BOARD_SIZE - 3:
                        board[row][col].piece = BISHOP;
                        break;
                    case 3:
                        board[row][col].piece = QUEEN;
                        break;
                    case 4:
                        board[row][col].piece = KING;
                        break;
                }
                board[row][col].color = color;
            } else if (row == 1 || row == BOARD_SIZE - 2) {
                board[row][col].piece = PAWN;
                board[row][col].color = (row == 1) ? 1 : 0;
            } else {
                board[row][col].piece = EMPTY;
                board[row][col].color = -1;
            }
        }
    }
}

void print_board() {
    int row, col;
    for (row = 0; row < BOARD_SIZE; ++row) {
        for (col = 0; col < BOARD_SIZE; ++col) {
            switch (board[row][col].piece) {
                case PAWN:
                    printf("P");
                    break;
                case ROOK:
                    printf("R");
                    break;
                case KNIGHT:
                    printf("N");
                    break;
                case BISHOP:
                    printf("B");
                    break;
                case QUEEN:
                    printf("Q");
                    break;
                case KING:
                    printf("K");
                    break;
                case EMPTY:
                    printf(".");
                    break;
            }
            printf(" ");
        }
        printf("\n");
    }
}

int main() {
    initialize_board();
    print_board();
    return 0;
}