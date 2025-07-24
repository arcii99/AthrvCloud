//FormAI DATASET v1.0 Category: Checkers Game ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

enum { EMPTY, RED, RED_KING, BLACK, BLACK_KING };

void create_board();
void print_board();
int check_move(int player, int row, int col, int move_row, int move_col);
int make_move(int player, int row, int col, int move_row, int move_col);
void make_king(int row, int col);
int check_win();

int main()
{
    create_board();
    int player = BLACK;
    int game_over = 0;
    int row, col, move_row, move_col;

    while (!game_over) {
        print_board();

        if (player == BLACK)
            printf("\nBlack's turn\n");
        else
            printf("\nRed's turn\n");

        printf("Enter starting position (row, column): ");
        scanf("%d %d", &row, &col);

        printf("Enter move position (row, column): ");
        scanf("%d %d", &move_row, &move_col);

        if (check_move(player, row, col, move_row, move_col)) {
            make_move(player, row, col, move_row, move_col);

            if (board[move_row][move_col] == EMPTY && abs(row - move_row) == 2) {
                int jump_row = (row + move_row) / 2;
                int jump_col = (col + move_col) / 2;
                board[jump_row][jump_col] = EMPTY;
            }

            if (player == RED && move_row == BOARD_SIZE - 1)
                make_king(move_row, move_col);
            else if (player == BLACK && move_row == 0)
                make_king(move_row, move_col);

            if (check_win()) {
                game_over = 1;
                printf("\n");

                if (player == RED)
                    printf("Red wins!\n");
                else
                    printf("Black wins!\n");

                print_board();
            }

            if (player == BLACK)
                player = RED;
            else
                player = BLACK;
        }
        else {
            printf("\nInvalid move, try again.\n");
        }
    }

    return 0;
}

void create_board()
{
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3)
                    board[row][col] = BLACK;
                else if (row > 4)
                    board[row][col] = RED;
                else
                    board[row][col] = EMPTY;
            }
            else {
                board[row][col] = EMPTY;
            }
        }
    }
}

void print_board()
{
    printf("\n");

    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", BOARD_SIZE - row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            switch (board[row][col]) {
                case EMPTY:
                    printf("  ");
                    break;
                case RED:
                    printf("r ");
                    break;
                case RED_KING:
                    printf("R ");
                    break;
                case BLACK:
                    printf("b ");
                    break;
                case BLACK_KING:
                    printf("B ");
                    break;
            }
        }
        printf("\n");
    }

    printf("  ");
    for (int col = 0; col < BOARD_SIZE; col++)
        printf("%c ", 'a' + col);
    printf("\n");
}

int check_move(int player, int row, int col, int move_row, int move_col)
{
    int diff_row = move_row - row;
    int diff_col = move_col - col;

    if ((board[move_row][move_col] != EMPTY) ||
        ((move_row + move_col) % 2 != 0) ||
        (abs(diff_row) != abs(diff_col)) ||
        ((player == RED) && (diff_row > 0)) ||
        ((player == BLACK) && (diff_row < 0)))
        return 0;

    if (abs(diff_row) == 1) {
        if (diff_col == 1 || diff_col == -1)
            return 1;
        else
            return 0;
    }
    else if (abs(diff_row) == 2) {
        int jump_row = (row + move_row) / 2;
        int jump_col = (col + move_col) / 2;
        if ((board[jump_row][jump_col] == RED || board[jump_row][jump_col] == RED_KING) && player == BLACK)
            return 1;
        if ((board[jump_row][jump_col] == BLACK || board[jump_row][jump_col] == BLACK_KING) && player == RED)
            return 1;
    }

    return 0;
}

int make_move(int player, int row, int col, int move_row, int move_col)
{
    board[row][col] = EMPTY;

    if (player == RED)
        board[move_row][move_col] = RED;
    else
        board[move_row][move_col] = BLACK;

    return 1;
}

void make_king(int row, int col)
{
    if (board[row][col] == RED)
        board[row][col] = RED_KING;
    else if (board[row][col] == BLACK)
        board[row][col] = BLACK_KING;
}

int check_win()
{
    int black_count = 0, red_count = 0;

    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if (board[row][col] == RED || board[row][col] == RED_KING)
                red_count++;
            else if (board[row][col] == BLACK || board[row][col] == BLACK_KING)
                black_count++;
        }
    }

    if (!black_count)
        return 1;
    else if (!red_count)
        return 1;
    else
        return 0;
}