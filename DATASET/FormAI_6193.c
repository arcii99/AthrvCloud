//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include <stdio.h>
#include <stdbool.h>

#define ROWS 8
#define COLS 8

void initialize_board(char board[ROWS][COLS])
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = ' ';
        }
    }

    for (int i = 0; i < ROWS; i += 2) {
        for (int j = 0; j < COLS; j += 2) {
            board[i][j] = 'o';
        }
    }

    for (int i = 1; i < ROWS; i += 2) {
        for (int j = 1; j < COLS; j += 2) {
            board[i][j] = 'o';
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'o') {
                board[i][j] = 'x';
            }
        }
    }

    for (int i = 5; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 'o') {
                board[i][j] = 'x';
            }
        }
    }
}

void print_board(char board[ROWS][COLS])
{
    printf("  0 1 2 3 4 5 6 7\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%d ", i);
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

bool is_valid_move(char board[ROWS][COLS], int s_row, int s_col, int e_row, int e_col, char player)
{
    if (board[e_row][e_col] != ' ') {
        return false;
    }

    if (player == 'x') {
        if (e_row > s_row) {
            return false;
        }

        if (s_row - e_row > 2 || s_row - e_row == 0 || abs(s_col - e_col) > 2) {
            return false;
        }

        if (s_row - e_row == 2) {
            if (s_col > e_col) {
                if (board[s_row-1][s_col-1] != 'o') {
                    return false;
                }
            } else {
                if (board[s_row-1][s_col+1] != 'o') {
                    return false;
                }
            }
        }
    } else if (player == 'o') {
        if (e_row > s_row) {
            return false;
        }

        if (e_row - s_row > 2 || e_row - s_row == 0 || abs(s_col - e_col) > 2) {
            return false;
        }

        if (e_row - s_row == 2) {
            if (s_col > e_col) {
                if (board[s_row+1][s_col-1] != 'x') {
                    return false;
                }
            } else {
                if (board[s_row+1][s_col+1] != 'x') {
                    return false;
                }
            }
        }
    }

    return true;
}

bool can_player_move(char board[ROWS][COLS], char player)
{
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player) {
                if (player == 'x') {
                    if (i > 0) {
                        if (j > 0) {
                            if (is_valid_move(board, i, j, i-1, j-1, player)) {
                                return true;
                            }
                        }
                        if (j < 7) {
                            if (is_valid_move(board, i, j, i-1, j+1, player)) {
                                return true;
                            }
                        }
                    }
                } else if (player == 'o') {
                    if (i < 7) {
                        if (j > 0) {
                            if (is_valid_move(board, i, j, i+1, j-1, player)) {
                                return true;
                            }
                        }
                        if (j < 7) {
                            if (is_valid_move(board, i, j, i+1, j+1, player)) {
                                return true;
                            }
                        }
                    }
                }
            }
        }
    }

    return false;
}

void make_move(char board[ROWS][COLS], int s_row, int s_col, int e_row, int e_col, char player)
{
    if (player == 'x') {
        if (e_row == 0) {
            board[e_row][e_col] = 'X';
        } else {
            board[e_row][e_col] = 'x';
        }

        if (abs(s_row - e_row) == 2) {
            if (s_row > e_row) {
                if (s_col > e_col) {
                    board[s_row-1][s_col-1] = ' ';
                } else {
                    board[s_row-1][s_col+1] = ' ';
                }
            } else {
                if (s_col > e_col) {
                    board[s_row+1][s_col-1] = ' ';
                } else {
                    board[s_row+1][s_col+1] = ' ';
                }
            }
        }
    } else if (player == 'o') {
        if (e_row == ROWS-1) {
            board[e_row][e_col] = 'O';
        } else {
            board[e_row][e_col] = 'o';
        }

        if (abs(s_row - e_row) == 2) {
            if (s_row > e_row) {
                if (s_col > e_col) {
                    board[s_row-1][s_col-1] = ' ';
                } else {
                    board[s_row-1][s_col+1] = ' ';
                }
            } else {
                if (s_col > e_col) {
                    board[s_row+1][s_col-1] = ' ';
                } else {
                    board[s_row+1][s_col+1] = ' ';
                }
            }
        }
    }

    board[s_row][s_col] = ' ';
}

bool is_game_over(char board[ROWS][COLS])
{
    return !can_player_move(board, 'x') || !can_player_move(board, 'o');
}

int main()
{
    char board[ROWS][COLS];
    bool game_over = false;

    initialize_board(board);

    printf("Welcome to the Checkers Game!\n\n");
    printf("Player 1: x\n");
    printf("Player 2: o\n");
    printf("The x player goes first.\n\n");

    int turn = 1;
    while (!game_over) {
        printf("Turn %d\n", turn);
        print_board(board);

        int s_row, s_col, e_row, e_col;
        char player = ' ';

        if (turn % 2 == 1) {
            printf("Player 1 (x) move: ");
            player = 'x';
        } else {
            printf("Player 2 (o) move: ");
            player = 'o';
        }

        scanf("%d %d %d %d", &s_row, &s_col, &e_row, &e_col);

        if (s_row < 0 || s_row >= ROWS ||
            s_col < 0 || s_col >= COLS ||
            e_row < 0 || e_row >= ROWS ||
            e_col < 0 || e_col >= COLS) {
            printf("Invalid move: Out of bounds.\n");
            continue;
        }

        if (board[s_row][s_col] != player && board[s_row][s_col] != toupper(player)) {
            printf("Invalid move: Invalid piece selected.\n");
            continue;
        }

        if (!is_valid_move(board, s_row, s_col, e_row, e_col, player)) {
            printf("Invalid move: Not a valid move.\n");
            continue;
        }

        make_move(board, s_row, s_col, e_row, e_col, player);

        if (is_game_over(board)) {
            game_over = true;

            print_board(board);

            if (!can_player_move(board, 'x')) {
                printf("Player 2 (o) Wins!\n");
            } else if (!can_player_move(board, 'o')) {
                printf("Player 1 (x) Wins!\n");
            }
        }

        turn++;
    }

    return 0;
}