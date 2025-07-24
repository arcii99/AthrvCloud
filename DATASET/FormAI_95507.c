//FormAI DATASET v1.0 Category: Checkers Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

typedef enum { false, true } bool;

typedef enum { EMPTY, RED, BLACK, RED_KING, BLACK_KING } piece;

piece board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) board[i][j] = BLACK;
                else if (i > 4) board[i][j] = RED;
                else board[i][j] = EMPTY;
            }
            else board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    printf("\t  1 2 3 4 5 6 7 8\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("\t%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
            case EMPTY:
                printf(". ");
                break;
            case RED:
                printf("r ");
                break;
            case BLACK:
                printf("b ");
                break;
            case RED_KING:
                printf("R ");
                break;
            case BLACK_KING:
                printf("B ");
                break;
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool is_valid_move(int x1, int y1, int x2, int y2, piece player) {
    if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE) return false;
    if (board[x2][y2] != EMPTY) return false;

    if (player == RED && board[x1][y1] == BLACK) return false;
    if (player == BLACK && board[x1][y1] == RED) return false;
    if (abs(x2 - x1) != 1 || abs(y2 - y1) != 1) return false;

    if (player == RED && board[x1][y1] == RED) {
        if (x2 - x1 == 1) return true;
        else if (x2 - x1 == 2 && board[x1 + 1][y1 + (y2 - y1) / 2] == BLACK) {
            board[x1 + 1][y1 + (y2 - y1) / 2] = EMPTY;
            return true;
        }
        else return false;
    }
    else if (player == BLACK && board[x1][y1] == BLACK) {
        if (x2 - x1 == -1) return true;
        else if (x2 - x1 == -2 && board[x1 - 1][y1 + (y2 - y1) / 2] == RED) {
            board[x1 - 1][y1 + (y2 - y1) / 2] = EMPTY;
            return true;
        }
        else return false;
    }

    if (player == RED && board[x1][y1] == RED_KING) {
        if (abs(x2 - x1) == abs(y2 - y1)) {
            int i = x1 < x2 ? x1 + 1 : x1 - 1;
            int j = y1 < y2 ? y1 + 1 : y1 - 1;
            while (i != x2 && j != y2) {
                if (board[i][j] != EMPTY) return false;
                i = x1 < x2 ? i + 1 : i - 1;
                j = y1 < y2 ? j + 1 : j - 1;
            }
            return true;
        }
        else if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2 && board[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] == BLACK) {
            board[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = EMPTY;
            return true;
        }
        else return false;
    }
    else if (player == BLACK && board[x1][y1] == BLACK_KING) {
        if (abs(x2 - x1) == abs(y2 - y1)) {
            int i = x1 < x2 ? x1 + 1 : x1 - 1;
            int j = y1 < y2 ? y1 + 1 : y1 - 1;
            while (i != x2 && j != y2) {
                if (board[i][j] != EMPTY) return false;
                i = x1 < x2 ? i + 1 : i - 1;
                j = y1 < y2 ? j + 1 : j - 1;
            }
            return true;
        }
        else if (abs(x2 - x1) == 2 && abs(y2 - y1) == 2 && board[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] == RED) {
            board[x1 + (x2 - x1) / 2][y1 + (y2 - y1) / 2] = EMPTY;
            return true;
        }
        else return false;
    }

    return false;
}

bool can_move(piece player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player + 2) {
                if ((player == RED && is_valid_move(i, j, i + 1, j + 1, player)) ||
                    (player == RED && is_valid_move(i, j, i + 1, j - 1, player)) ||
                    (player == RED && is_valid_move(i, j, i + 2, j + 2, player)) ||
                    (player == RED && is_valid_move(i, j, i + 2, j - 2, player)) ||
                    (board[i][j] == RED_KING && is_valid_move(i, j, i - 1, j + 1, player)) ||
                    (board[i][j] == RED_KING && is_valid_move(i, j, i - 1, j - 1, player)) ||
                    (board[i][j] == RED_KING && is_valid_move(i, j, i + 1, j + 1, player)) ||
                    (board[i][j] == RED_KING && is_valid_move(i, j, i + 1, j - 1, player))) {
                    return true;
                }
                if ((player == BLACK && is_valid_move(i, j, i - 1, j + 1, player)) ||
                    (player == BLACK && is_valid_move(i, j, i - 1, j - 1, player)) ||
                    (player == BLACK && is_valid_move(i, j, i - 2, j + 2, player)) ||
                    (player == BLACK && is_valid_move(i, j, i - 2, j - 2, player)) ||
                    (board[i][j] == BLACK_KING && is_valid_move(i, j, i - 1, j + 1, player)) ||
                    (board[i][j] == BLACK_KING && is_valid_move(i, j, i - 1, j - 1, player)) ||
                    (board[i][j] == BLACK_KING && is_valid_move(i, j, i + 1, j + 1, player)) ||
                    (board[i][j] == BLACK_KING && is_valid_move(i, j, i + 1, j - 1, player))) {
                    return true;
                }
            }
        }
    }
    return false;
}

void make_move(int x1, int y1, int x2, int y2, piece player) {
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = EMPTY;
    if (player == RED && x2 == BOARD_SIZE - 1 && board[x2][y2] == RED) board[x2][y2] = RED_KING;
    else if (player == BLACK && x2 == 0 && board[x2][y2] == BLACK) board[x2][y2] = BLACK_KING;
}

int main() {
    initialize_board();
    print_board();

    piece current_player = RED;
    while (can_move(RED) || can_move(BLACK)) {
        printf("%s's turn!\n", current_player == RED ? "Red" : "Black");

        int x1, y1, x2, y2;
        while (true) {
            printf("Enter move from row,col (e.g. 1,2): ");
            scanf("%d,%d", &x1, &y1);
            printf("Enter move to row,col (e.g. 2,3): ");
            scanf("%d,%d", &x2, &y2);
            if (is_valid_move(x1-1, y1-1, x2-1, y2-1, current_player)) break;
            printf("Invalid move! Try again.\n");
        }

        make_move(x1-1, y1-1, x2-1, y2-1, current_player);
        print_board();

        current_player = current_player == RED ? BLACK : RED;
    }

    printf("%s wins!\n", can_move(RED) ? "Black" : "Red");

    return 0;
}