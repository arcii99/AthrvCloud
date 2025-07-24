//FormAI DATASET v1.0 Category: Checkers Game ; Style: random
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

enum Player { Player_1, Player_2 };

struct Position { int row, col; };

struct Checker { enum Player player; int is_king; };

struct Move { struct Position start, end; };

struct Game {
    struct Checker board[BOARD_SIZE][BOARD_SIZE];
    enum Player current_player;
};

void print_checker(struct Checker checker)
{
    if (checker.player == Player_1) {
        printf(checker.is_king ? "wW " : "w  ");
    } else {
        printf(checker.is_king ? "bB " : "b  ");
    }
}

void print_board(struct Game* game)
{
    printf("  | 0 1 2 3 4 5 6 7 \n");
    printf("--|----------------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            print_checker(game->board[i][j]);
        }
        printf("\n");
    }
}

void set_initial_checkers(struct Game* game)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i <= 2 && (i + j) % 2 == 0) {
                game->board[i][j] = (struct Checker){ Player_1, 0 };
            } else if (i >= 5 && (i + j) % 2 == 0) {
                game->board[i][j] = (struct Checker){ Player_2, 0 };
            } else {
                game->board[i][j] = (struct Checker){ -1, 0 };
            }
        }
    }
}

int can_move(struct Game* game, struct Move move)
{
    struct Position start = move.start;
    struct Position end = move.end;
    enum Player player = game->current_player;

    struct Checker checker = game->board[start.row][start.col];
    if (checker.player != player) {
        return 0;
    }

    if (end.row < 0 || end.row >= BOARD_SIZE || end.col < 0 || end.col >= BOARD_SIZE) {
        return 0;
    }
    if (game->board[end.row][end.col].player != -1) {
        return 0;
    }

    int delta_row = end.row - start.row;
    int delta_col = end.col - start.col;
    if (!checker.is_king) {
        if (checker.player == Player_1 && delta_row <= 0) {
            return 0;
        }
        if (checker.player == Player_2 && delta_row >= 0) {
            return 0;
        }
    }
    if (abs(delta_row) != abs(delta_col)) {
        return 0;
    }
    if (abs(delta_row) == 1) {
        return 1;
    }
    int jump_row = start.row + delta_row / 2;
    int jump_col = start.col + delta_col / 2;
    if (game->board[jump_row][jump_col].player != (player == Player_1 ? Player_2 : Player_1)) {
        return 0;
    }

    return 1;
}

void make_move(struct Game* game, struct Move move)
{
    struct Position start = move.start;
    struct Position end = move.end;
    enum Player player = game->current_player;

    game->board[end.row][end.col] = game->board[start.row][start.col];
    game->board[start.row][start.col] = (struct Checker){ -1, 0 };
    if (abs(end.row - start.row) == 2) {
        int jump_row = start.row + (end.row - start.row) / 2;
        int jump_col = start.col + (end.col - start.col) / 2;
        game->board[jump_row][jump_col] = (struct Checker){ -1, 0 };
    }

    if (!game->board[end.row][end.col].is_king) {
        if (game->board[end.row][end.col].player == Player_1 && end.row == BOARD_SIZE - 1) {
            game->board[end.row][end.col].is_king = 1;
        }
        if (game->board[end.row][end.col].player == Player_2 && end.row == 0) {
            game->board[end.row][end.col].is_king = 1;
        }
    }

    game->current_player = player == Player_1 ? Player_2 : Player_1;
}

int has_moves(struct Game* game)
{
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            struct Move move = { { i, j }, { i + 1, j + 1 } };
            if (can_move(game, move)) {
                return 1;
            }
            move.end.col = j - 1;
            if (can_move(game, move)) {
                return 1;
            }
            if (game->board[i][j].is_king) {
                move.end.row = i - 1;
                move.end.col = j + 1;
                if (can_move(game, move)) {
                    return 1;
                }
                move.end.col = j - 1;
                if (can_move(game, move)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int get_num_checkers(struct Game* game, enum Player player)
{
    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j].player == player) {
                count++;
            }
        }
    }
    return count;
}

void run_game(struct Game* game)
{
    set_initial_checkers(game);

    printf("*** CHECKERS ***\n");
    printf("Player 1: w\nPlayer 2: b\n\n");

    while (get_num_checkers(game, Player_1) > 0 && get_num_checkers(game, Player_2) > 0) {
        print_board(game);
        printf("\nPlayer %d's turn.\n", game->current_player + 1);

        if (!has_moves(game)) {
            printf("No moves left for Player %d! They forfeit.\n", game->current_player + 1);
            game->current_player = game->current_player == Player_1 ? Player_2 : Player_1;
            continue;
        }

        int start_row, start_col, end_row, end_col;
        printf("Enter start position (row col): ");
        scanf("%d %d", &start_row, &start_col);
        printf("Enter end position (row col): ");
        scanf("%d %d", &end_row, &end_col);

        struct Move move = { { start_row, start_col }, { end_row, end_col } };
        if (!can_move(game, move)) {
            printf("Invalid move.\n");
            continue;
        }

        make_move(game, move);
    }

    printf("\nGame over!\n");
    if (get_num_checkers(game, Player_1) > 0) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
}

int main()
{
    struct Game game = { .current_player = Player_1 };
    run_game(&game);
    return 0;
}