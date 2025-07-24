//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define EMPTY ' '
#define BLACK 'b'
#define WHITE 'w'
#define BLACK_KING 'B'
#define WHITE_KING 'W'

void create_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (i % 2 == 0) {
                if (j % 2 == 0) {
                    board[i][j] = EMPTY;
                } else {
                    board[i][j] = BLACK;
                }
            } else {
                if (j % 2 == 0) {
                    board[i][j] = BLACK;
                } else {
                    board[i][j] = EMPTY;
                }
            }
        }
    }

    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == BLACK && i <= 2) {
                board[i][j] = WHITE;
            } else if (board[i][j] == EMPTY && i <= 2) {
                board[i][j] = WHITE;
            } else if (board[i][j] == WHITE && i >= 5) {
                board[i][j] = BLACK;
            } else if (board[i][j] == EMPTY && i >= 5) {
                board[i][j] = BLACK;
            }
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;

    printf("\n  ");
    for (i = 65; i < 65 + BOARD_SIZE; ++i) {
        printf("%c ", i);
    }
    printf("\n");

    for (i = 0; i < BOARD_SIZE; ++i) {
        printf("%d ", i + 1);
        for (j = 0; j < BOARD_SIZE; ++j) {
            printf("%c ", board[i][j]);
        }
        printf("%d ", i + 1);
        printf("\n");
    }

    printf("  ");
    for (i = 65; i < 65 + BOARD_SIZE; ++i) {
        printf("%c ", i);
    }
    printf("\n");
}

int move_is_valid(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col, char player) {
    int dir, i;

    if (board[to_row][to_col] != EMPTY) {
        return 0;
    }

    if (player == BLACK && to_row > from_row) {
        return 0;
    }

    if (player == WHITE && to_row < from_row) {
        return 0;
    }

    if (board[from_row][from_col] == BLACK_KING || board[from_row][from_col] == WHITE_KING) {
        if (abs(to_row - from_row) != abs(to_col - from_col)) {
            return 0;
        }

        if (to_row > from_row && to_col > from_col) {
            dir = 1;
        } else if (to_row > from_row && to_col < from_col) {
            dir = 2;
        } else if (to_row < from_row && to_col < from_col) {
            dir = 3;
        } else {
            dir = 4;
        }

        i = 1;
        while (i < abs(to_row - from_row)) {
            if (dir == 1) {
                if (board[from_row + i][from_col + i] != EMPTY) {
                    return 0;
                }
            } else if (dir == 2) {
                if (board[from_row + i][from_col - i] != EMPTY) {
                    return 0;
                }
            } else if (dir == 3) {
                if (board[from_row - i][from_col - i] != EMPTY) {
                    return 0;
                }
            } else if (dir == 4) {
                if (board[from_row - i][from_col + i] != EMPTY) {
                    return 0;
                }
            }
            ++i;
        }
    } else {
        if (abs(to_row - from_row) != 1 || abs(to_col - from_col) != 1) {
            return 0;
        }
    }

    return 1;
}

void make_move(char board[BOARD_SIZE][BOARD_SIZE], int from_row, int from_col, int to_row, int to_col, char player) {
    char piece = board[from_row][from_col];
    board[from_row][from_col] = EMPTY;
    board[to_row][to_col] = piece;

    if (player == BLACK && to_row == 0) {
        board[to_row][to_col] = BLACK_KING;
    } else if (player == WHITE && to_row == BOARD_SIZE - 1) {
        board[to_row][to_col] = WHITE_KING;
    }
}

int can_player_move(char board[BOARD_SIZE][BOARD_SIZE], char player) {
    int i, j;

    for (i = 0; i < BOARD_SIZE; ++i) {
        for (j = 0; j < BOARD_SIZE; ++j) {
            if (board[i][j] == player || board[i][j] == player + 2) {
                if (i < BOARD_SIZE - 1 && j < BOARD_SIZE - 1 && move_is_valid(board, i, j, i + 1, j + 1, player)) {
                    return 1;
                }

                if (i < BOARD_SIZE - 1 && j > 0 && move_is_valid(board, i, j, i + 1, j - 1, player)) {
                    return 1;
                }

                if (player == BLACK || board[i][j] == BLACK_KING) {
                    if (i > 0 && j < BOARD_SIZE - 1 && move_is_valid(board, i, j, i - 1, j + 1, player)) {
                        return 1;
                    }

                    if (i > 0 && j > 0 && move_is_valid(board, i, j, i - 1, j - 1, player)) {
                        return 1;
                    }
                }
            }
        }
    }

    return 0;
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    int from_col, from_row, to_col, to_row;
    char player = BLACK;

    create_board(board);

    while (1) {
        if (player == BLACK) {
            printf("\nBlack's turn:\n");
        } else {
            printf("\nWhite's turn:\n");
        }

        print_board(board);

        printf("From (row, column): ");
        scanf("%d %d", &from_row, &from_col);
        --from_col;
        --from_row;

        printf("To (row, column): ");
        scanf("%d %d", &to_row, &to_col);
        --to_col;
        --to_row;

        if (move_is_valid(board, from_row, from_col, to_row, to_col, player)) {
            make_move(board, from_row, from_col, to_row, to_col, player);
            if (!can_player_move(board, player)) {
                if (player == BLACK) {
                    printf("\nWhite Wins!\n");
                } else {
                    printf("\nBlack Wins!\n");
                }
                break;
            }
            if (player == BLACK) {
                player = WHITE;
            } else {
                player = BLACK;
            }
        } else {
            printf("\nInvalid move\n");
        }
    }

    return 0;
}