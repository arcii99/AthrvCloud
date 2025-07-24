//FormAI DATASET v1.0 Category: Chess AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {
    {-5, -2, -3, -9, -6, -3, -2, -5},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {5, 2, 3, 9, 6, 3, 2, 5},
};
int (*p_board)[BOARD_SIZE] = board;
int turn = 1;

int is_valid_move(int x, int y, int dx, int dy) {
    if (p_board[x][y] * turn < 0)
        return 0;
    if (dx < 0 || dx >= BOARD_SIZE || dy < 0 || dy >= BOARD_SIZE)
        return 0;
    int piece = p_board[x][y] * turn;
    if (p_board[dx][dy] == -piece || p_board[dx][dy] == piece)
        return 0;
    if (!piece)
        return 0;
    if (piece == 1) {
        if (dx == x - 1 && dy == y)
            return 1;
        if (dx == x - 2 && y == dy && x == 6 && !p_board[x - 1][y] && !p_board[x - 2][y])
            return 1;
        if (dx <= x - 2 || abs(dy - y) > 1)
            return 0;
        return p_board[dx][dy] == 0;
    } else if (piece == 2) {
        if (abs(dx - x) > 1 || abs(dy - y) > 1)
            return 0;
        return 1;
    } else if (piece == 3) {
        if (dx == x || dy == y)
            return 0;
        if (abs(dx - x) != abs(dy - y))
            return 0;
        int i;
        int step_x = dx > x ? 1 : -1;
        int step_y = dy > y ? 1 : -1;
        for (i = 1; i < abs(dx - x); i++) {
            if (p_board[x + i * step_x][y + i * step_y])
                return 0;
        }
    } else if (piece == 5) {
        if (dx == x || dy == y)
            return 0;
        if (p_board[dx][dy] && (abs(dx - x) > 1 || abs(dy - y) > 1))
            return 0;
        int i;
        int step_x = dx > x ? 1 : -1;
        int step_y = dy > y ? 1 : -1;
        for (i = 1; i < abs(dx - x); i++) {
            if (p_board[x + i * step_x][y + i * step_y])
                return 0;
        }
    } else if (piece == 6) {
        if (abs(dx - x) > 1 || abs(dy - y) > 1)
            return 0;
        if (dx && dy)
            return 0;
        int i;
        if (dx == x) {
            int step = dy > y ? 1 : -1;
            for (i = 1; i < abs(dy - y); i++) {
                if (p_board[x][y + i * step])
                    return 0;
            }
        } else {
            int step = dx > x ? 1 : -1;
            for (i = 1; i < abs(dx - x); i++) {
                if (p_board[x + i * step][y])
                    return 0;
            }
        }
    } else if (piece == 9) {
        if (dx == x || dy == y)
            return 0;
        if (abs(dx - x) != abs(dy - y))
            return 0;
        int step_x = dx > x ? 1 : -1;
        int step_y = dy > y ? 1 : -1;
        int i;
        for (i = 1; i < abs(dx - x); i++) {
            if (p_board[x + i * step_x][y + i * step_y])
                return 0;
        }
    }
    return 1;
}

int is_threatened(int x, int y) {
    int dy = y;
    int piece;
    if (p_board[x][y] == 1) {
        if (x > 0 && y > 0 && p_board[x - 1][y - 1] == -5)
            return 1;
        if (x > 0 && y < BOARD_SIZE - 1 && p_board[x - 1][y + 1] == -5)
            return 1;
    }
    if (p_board[x][y] == -1) {
        if (x < BOARD_SIZE - 1 && y > 0 && p_board[x + 1][y - 1] == 5)
            return 1;
        if (x < BOARD_SIZE - 1 && y < BOARD_SIZE - 1 && p_board[x + 1][y + 1] == 5)
            return 1;
    }
    for (dy = y - 1; dy >= 0; dy--) {
        piece = p_board[x][dy] * turn;
        if (piece == -5 || piece == -6)
            return 1;
        if (piece)
            break;
    }
    for (dy = y + 1; dy < BOARD_SIZE; dy++) {
        piece = p_board[x][dy] * turn;
        if (piece == -5 || piece == -6)
            return 1;
        if (piece)
            break;
    }
    int dx;
    for (dx = x - 1; dx >= 0; dx--) {
        piece = p_board[dx][y] * turn;
        if (piece == -3 || piece == -6)
            return 1;
        if (piece)
            break;
    }
    for (dx = x + 1; dx < BOARD_SIZE; dx++) {
        piece = p_board[dx][y] * turn;
        if (piece == -3 || piece == -6)
            return 1;
        if (piece)
            break;
    }
    for (dx = x - 1, dy = y - 1; dx >= 0 && dy >= 0; dx--, dy--) {
        piece = p_board[dx][dy] * turn;
        if (piece == -3 || piece == -5)
            return 1;
        if (piece)
            break;
    }
    for (dx = x + 1, dy = y - 1; dx < BOARD_SIZE && dy >= 0; dx++, dy--) {
        piece = p_board[dx][dy] * turn;
        if (piece == -3 || piece == -5)
            return 1;
        if (piece)
            break;
    }
    for (dx = x - 1, dy = y + 1; dx >= 0 && dy < BOARD_SIZE; dx--, dy++) {
        piece = p_board[dx][dy] * turn;
        if (piece == -3 || piece == -5)
            return 1;
        if (piece)
            break;
    }
    for (dx = x + 1, dy = y + 1; dx < BOARD_SIZE && dy < BOARD_SIZE; dx++, dy++) {
        piece = p_board[dx][dy] * turn;
        if (piece == -3 || piece == -5)
            return 1;
        if (piece)
            break;
    }
    if (p_board[x][y] == -1) {
        if (x > 0 && y > 1 && p_board[x - 1][y - 2] == 2)
            return 1;
        if (x > 1 && y > 0 && p_board[x - 2][y - 1] == 2)
            return 1;
        if (x > 1 && y < BOARD_SIZE - 1 && p_board[x - 2][y + 1] == 2)
            return 1;
        if (x > 0 && y < BOARD_SIZE - 2 && p_board[x - 1][y + 2] == 2)
            return 1;
        if (x < BOARD_SIZE - 1 && y > 1 && p_board[x + 1][y - 2] == 2)
            return 1;
        if (x < BOARD_SIZE - 2 && y > 0 && p_board[x + 2][y - 1] == 2)
            return 1;
        if (x < BOARD_SIZE - 2 && y < BOARD_SIZE - 1 && p_board[x + 2][y + 1] == 2)
            return 1;
        if (x < BOARD_SIZE - 1 && y < BOARD_SIZE - 2 && p_board[x + 1][y + 2] == 2)
            return 1;
    } else if (p_board[x][y] == 1) {
        if (x > 0 && y > 1 && p_board[x - 1][y - 2] == -2)
            return 1;
        if (x > 1 && y > 0 && p_board[x - 2][y - 1] == -2)
            return 1;
        if (x > 1 && y < BOARD_SIZE - 1 && p_board[x - 2][y + 1] == -2)
            return 1;
        if (x > 0 && y < BOARD_SIZE - 2 && p_board[x - 1][y + 2] == -2)
            return 1;
        if (x < BOARD_SIZE - 1 && y > 1 && p_board[x + 1][y - 2] == -2)
            return 1;
        if (x < BOARD_SIZE - 2 && y > 0 && p_board[x + 2][y - 1] == -2)
            return 1;
        if (x < BOARD_SIZE - 2 && y < BOARD_SIZE - 1 && p_board[x + 2][y + 1] == -2)
            return 1;
        if (x < BOARD_SIZE - 1 && y < BOARD_SIZE - 2 && p_board[x + 1][y + 2] == -2)
            return 1;
    } else if (p_board[x][y] == -2) {
        if (x > 0 && y > 0 && p_board[x - 1][y - 1] == 1)
            return 1;
        if (x > 0 && y < BOARD_SIZE - 1 && p_board[x - 1][y + 1] == 1)
            return 1;
        if (x < BOARD_SIZE - 1 && y > 0 && p_board[x + 1][y - 1] == 1)
            return 1;
        if (x < BOARD_SIZE - 1 && y < BOARD_SIZE - 1 && p_board[x + 1][y + 1] == 1)
            return 1;
    } else if (p_board[x][y] == 2) {
        if (x > 0 && y > 0 && p_board[x - 1][y - 1] == -1)
            return 1;
        if (x > 0 && y < BOARD_SIZE - 1 && p_board[x - 1][y + 1] == -1)
            return 1;
        if (x < BOARD_SIZE - 1 && y > 0 && p_board[x + 1][y - 1] == -1)
            return 1;
        if (x < BOARD_SIZE - 1 && y < BOARD_SIZE - 1 && p_board[x + 1][y + 1] == -1)
            return 1;
    }
    return 0;
}

int is_check() {
    int king_x, king_y;
    int piece, dx, dy;
    int (*p_tmp_board)[BOARD_SIZE] = malloc(sizeof(board));
    memcpy(p_tmp_board, board, sizeof(board));
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (p_board[x][y] == turn * 9) {
                king_x = x;
                king_y = y;
            }
        }
    }
    turn *= -1;
    for (int x = 0; x < BOARD_SIZE; x++) {
        for (int y = 0; y < BOARD_SIZE; y++) {
            if (p_board[x][y]) {
                if (p_board[x][y] * turn > 0) {
                    piece = p_board[x][y];
                    for (dx = 0; dx < BOARD_SIZE; dx++) {
                        for (dy = 0; dy < BOARD_SIZE; dy++) {
                            if (is_valid_move(x, y, dx, dy)) {
                                p_board[dx][dy] = piece;
                                p_board[x][y] = 0;
                                if (p_board[dx][dy] == turn * 9 && !is_threatened(dx, dy)) {
                                    turn *= -1;
                                    memcpy(board, p_tmp_board, sizeof(board));
                                    free(p_tmp_board);
                                    return 1;
                                }
                                memcpy(p_board, p_tmp_board, sizeof(board));
                            }
                        }
                    }
                }
            }
        }
    }
    turn *= -1;
    memcpy(board, p_tmp_board, sizeof(board));
    free(p_tmp_board);
    return 0;
}

int main() {
    int x1, y1, x2, y2;
    while (1) {
        char input[128];
        printf("Enter move <x1,y1,x2,y2>: ");
        fgets(input, 128, stdin);
        sscanf(input, "%d,%d,%d,%d", &x1, &y1, &x2, &y2);
        if (is_valid_move(x1, y1, x2, y2)) {
            p_board[x2][y2] = p_board[x1][y1];
            p_board[x1][y1] = 0;
            turn *= -1;
            if (is_check()) {
                printf("Check!\n");
            }
        } else {
            printf("Invalid move!\n");
        }
        printf("\n");
    }
    return 0;
}