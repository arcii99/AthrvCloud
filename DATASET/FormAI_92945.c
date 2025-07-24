//FormAI DATASET v1.0 Category: Chess engine ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BOARD_SIZE 8
#define WHITE 1
#define BLACK 0

#define PAWN 'P'
#define ROOK 'R'
#define KNIGHT 'N'
#define BISHOP 'B'
#define QUEEN 'Q'
#define KING 'K'

char board[BOARD_SIZE][BOARD_SIZE];

/* initialize board */
void init_board() {
    int i, j;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }

    /* Pawns */
    for (i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = PAWN;
        board[6][i] = PAWN;
    }

    /* Rooks */
    board[0][0] = ROOK;
    board[0][7] = ROOK;
    board[7][0] = ROOK;
    board[7][7] = ROOK;

    /* Knights */
    board[0][1] = KNIGHT;
    board[0][6] = KNIGHT;
    board[7][1] = KNIGHT;
    board[7][6] = KNIGHT;

    /* Bishops */
    board[0][2] = BISHOP;
    board[0][5] = BISHOP;
    board[7][2] = BISHOP;
    board[7][5] = BISHOP;

    /* Queens */
    board[0][3] = QUEEN;
    board[7][3] = QUEEN;

    /* Kings */
    board[0][4] = KING;
    board[7][4] = KING;
}

/* print board */
void print_board() {
    int i, j;

    printf("  a b c d e f g h \n");
    printf(" +-----------------+\n");

    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE - i);

        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }

        printf("%d\n", BOARD_SIZE - i);
    }

    printf(" +-----------------+\n");
    printf("  a b c d e f g h \n");
}

/* get piece color */
int get_color(char piece) {
    if (piece == ' ' || islower(piece)) {
        return BLACK;
    }

    return WHITE;
}

/* get piece type */
int get_type(char piece) {
    switch (toupper(piece)) {
        case PAWN:
            return 1;
        case ROOK:
            return 2;
        case KNIGHT:
            return 3;
        case BISHOP:
            return 4;
        case QUEEN:
            return 5;
        case KING:
            return 6;
        default:
            return 0;
    }
}

/* check if move is valid */
int is_valid_move(int from_x, int from_y, int to_x, int to_y, int color) {
    char piece = board[from_y][from_x];
    char target = board[to_y][to_x];
    int type = get_type(piece);
    int dx, dy;
    int i, j;

    if (to_x < 0 || to_x >= BOARD_SIZE ||
        to_y < 0 || to_y >= BOARD_SIZE) {
        return 0;
    }

    if (get_color(target) == color) {
        return 0;
    }

    switch (type) {
        /* Pawn */
        case 1:
            if (dx == 0 && dy == color * 2 - 1 && target == ' ') {
                return 1;
            } else if (dx == 0 && dy == color * 2 - 1 &&
                (target == PAWN || target == ROOK || target == KNIGHT ||
                 target == BISHOP || target == KING || target == QUEEN)) {
                return 0;
            } else if (dx == 0 && dy == color * 1 &&
                       target == ' ') {
                return 1;
            } else if (dx == 0 && dy == color * 1 &&
                       (target == PAWN || target == ROOK ||
                        target == KNIGHT || target == BISHOP ||
                        target == KING || target == QUEEN)) {
                return 0;
            } else if ((dx == -1 || dx == 1) &&
                       dy == color * 1 && target != ' ' &&
                       get_color(target) != color) {
                return 1;
            } else {
                return 0;
            }

        /* Rook */
        case 2:
            if ((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) {
                for (j = from_x + dx, i = from_y + dy;
                     i >= 0 && i < BOARD_SIZE &&
                     j >= 0 && j < BOARD_SIZE;
                     j += dx, i += dy) {
                    if (board[i][j] != ' ') {
                        return 0;
                    }
                }

                return 1;
            } else {
                return 0;
            }

        /* Knight */
        case 3:
            if ((abs(dx) == 1 && abs(dy) == 2) ||
                (abs(dx) == 2 && abs(dy) == 1)) {
                return 1;
            } else {
                return 0;
            }

        /* Bishop */
        case 4:
            if (abs(dx) == abs(dy)) {
                for (j = from_x + dx, i = from_y + dy;
                     i >= 0 && i < BOARD_SIZE &&
                     j >= 0 && j < BOARD_SIZE;
                     j += dx, i += dy) {
                    if (board[i][j] != ' ') {
                        return 0;
                    }
                }

                return 1;
            } else {
                return 0;
            }

        /* Queen */
        case 5:
            if ((dx != 0 && dy == 0) || (dx == 0 && dy != 0)) {
                for (j = from_x + dx, i = from_y + dy;
                     i >= 0 && i < BOARD_SIZE &&
                     j >= 0 && j < BOARD_SIZE;
                     j += dx, i += dy) {
                    if (board[i][j] != ' ') {
                        return 0;
                    }
                }

                return 1;
            } else if (abs(dx) == abs(dy)) {
                for (j = from_x + dx, i = from_y + dy;
                     i >= 0 && i < BOARD_SIZE &&
                     j >= 0 && j < BOARD_SIZE;
                     j += dx, i += dy) {
                    if (board[i][j] != ' ') {
                        return 0;
                    }
                }

                return 1;
            } else {
                return 0;
            }

        /* King */
        case 6:
            if ((abs(dx) == 1 && dy == 0) ||
                (dx == 0 && abs(dy) == 1) ||
                (abs(dx) == 1 && abs(dy) == 1)) {
                return 1;
            } else {
                return 0;
            }
    }

    return 0;
}

/* move piece */
void move_piece(int from_x, int from_y, int to_x, int to_y) {
    board[to_y][to_x] = board[from_y][from_x];
    board[from_y][from_x] = ' ';
}

/* main function */
int main() {
    int game_over = 0;
    int turn = WHITE;
    int from_x, from_y, to_x, to_y;
    char input[5];
    char piece;

    init_board();

    while (!game_over) {
        print_board();

        if (turn == WHITE) {
            printf("White's move: ");
        } else {
            printf("Black's move: ");
        }

        fgets(input, 5, stdin);

        from_x = input[0] - 'a';
        from_y = BOARD_SIZE - (input[1] - '0');
        to_x = input[3] - 'a';
        to_y = BOARD_SIZE - (input[4] - '0');

        piece = board[from_y][from_x];

        if (get_color(piece) == turn &&
            is_valid_move(from_x, from_y, to_x, to_y, turn)) {
            move_piece(from_x, from_y, to_x, to_y);

            if (turn == WHITE) {
                turn = BLACK;
            } else {
                turn = WHITE;
            }
        } else {
            printf("Invalid move.\n");
        }
    }

    return 0;
}