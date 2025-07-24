//FormAI DATASET v1.0 Category: Checkers Game ; Style: artistic
#include <stdio.h>

#define ROWS 8
#define COLUMNS 8

enum piece_type {
    NO_PIECE = 0,
    RED_PAWN,
    RED_KING,
    BLACK_PAWN,
    BLACK_KING
};

enum player {
    NO_PLAYER = 0,
    PLAYER_RED,
    PLAYER_BLACK
};

struct piece {
    enum piece_type type;
    enum player owner;
};

struct board {
    struct piece squares[ROWS][COLUMNS];
};

void print_board(struct board *board)
{
    printf("  ");
    for (int i = 0; i < COLUMNS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLUMNS; j++) {
            switch (board->squares[i][j].type) {
                case NO_PIECE:
                    printf(". ");
                    break;
                case RED_PAWN:
                    printf("r ");
                    break;
                case RED_KING:
                    printf("R ");
                    break;
                case BLACK_PAWN:
                    printf("b ");
                    break;
                case BLACK_KING:
                    printf("B ");
                    break;
                default:
                    break;
            }
        }
        printf("\n");
    }
}

void create_starting_position(struct board *board)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMNS; j++) {
            if ((i + j) % 2 == 1) {
                if (i < 3) {
                    board->squares[i][j].type = BLACK_PAWN;
                    board->squares[i][j].owner = PLAYER_BLACK;
                } else if (i > 4) {
                    board->squares[i][j].type = RED_PAWN;
                    board->squares[i][j].owner = PLAYER_RED;
                } else {
                    board->squares[i][j].type = NO_PIECE;
                    board->squares[i][j].owner = NO_PLAYER;
                }
            } else {
                board->squares[i][j].type = NO_PIECE;
                board->squares[i][j].owner = NO_PLAYER;
            }
        }
    }
}

int main()
{
    struct board board;
    create_starting_position(&board);
    print_board(&board);
    return 0;
}