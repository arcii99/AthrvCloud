//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

enum Piece { NONE, WHITE, RED };
enum MoveType { NORMAL, ATTACK };

typedef struct {
    int piece;
    int crowned;
} Square;

typedef struct {
    int x, y;
} Point;

typedef struct {
    Point from, to;
    enum MoveType type;
} Move;

Square board[BOARD_SIZE][BOARD_SIZE];

void init_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                board[i][j].piece = NONE;
                board[i][j].crowned = 0;
            } else if (i < 3) {
                board[i][j].piece = RED;
                board[i][j].crowned = 0;
            } else if (i > 4) {
                board[i][j].piece = WHITE;
                board[i][j].crowned = 0;
            } else {
                board[i][j].piece = NONE;
                board[i][j].crowned = 0;
            }
        }
    }
}

int is_valid_point(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

int is_valid_move(Point from, Point to) {
    if (!is_valid_point(from.x, from.y) || !is_valid_point(to.x, to.y)) {
        return 0;
    }

    if (board[from.x][from.y].piece == NONE || board[to.x][to.y].piece != NONE) {
        return 0;
    }

    int dx = to.x - from.x;
    int dy = to.y - from.y;
    int piece = board[from.x][from.y].piece;

    if (piece == WHITE && dy < 0) {
        return 0;
    } else if (piece == RED && dy > 0) {
        return 0;
    }

    int adx = abs(dx);
    int ady = abs(dy);

    if (adx == 1 && ady == 1 && board[from.x][from.y].crowned == 0) {
        return 1;
    } else if (adx == 2 && ady == 2) {
        int cx = from.x + dx / 2;
        int cy = from.y + dy / 2;

        if (board[cx][cy].piece == NONE) {
            return 0;
        } else if (board[cx][cy].piece == piece) {
            return 0;
        } else {
            return 1;
        }
    } else {
        return 0;
    }
}

Move get_move() {
    Move move;
    char buf[256];

    printf("Enter move (in the format of 'x1,y1 x2,y2'): ");
    fgets(buf, sizeof(buf), stdin);

    if (sscanf(buf, "%d,%d %d,%d", &move.from.x, &move.from.y, &move.to.x, &move.to.y) != 4) {
        move.from.x = move.from.y = move.to.x = move.to.y = -1;
        return move;
    }

    if (!is_valid_move(move.from, move.to)) {
        move.from.x = move.from.y = move.to.x = move.to.y = -1;
    }

    return move;
}

void do_move(Move move) {
    int dx = move.to.x - move.from.x;
    int dy = move.to.y - move.from.y;
    int piece = board[move.from.x][move.from.y].piece;

    board[move.to.x][move.to.y].piece = piece;
    board[move.from.x][move.from.y].piece = NONE;

    if (dx == 2 && dy == 2) {
        int cx = move.from.x + dx / 2;
        int cy = move.from.y + dy / 2;

        board[cx][cy].piece = NONE;
    }

    if (piece == WHITE && move.to.x == 0) {
        board[move.to.x][move.to.y].crowned = 1;
    } else if (piece == RED && move.to.x == BOARD_SIZE - 1) {
        board[move.to.x][move.to.y].crowned = 1;
    }
}

void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);

        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j].piece == NONE) {
                printf(". ");
            } else if (board[i][j].piece == RED) {
                if (board[i][j].crowned) {
                    printf("R ");
                } else {
                    printf("r ");
                }
            } else if (board[i][j].piece == WHITE) {
                if (board[i][j].crowned) {
                    printf("W ");
                } else {
                    printf("w ");
                }
            }
        }

        printf("%d\n", i);
    }

    printf("  0 1 2 3 4 5 6 7\n");
}

int main() {
    init_board();
    print_board();

    while (1) {
        Move move = get_move();

        if (move.from.x == -1) {
            break;
        }

        do_move(move);
        print_board();
    }

    return 0;
}