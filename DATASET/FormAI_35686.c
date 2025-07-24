//FormAI DATASET v1.0 Category: Game ; Style: Machiavellien
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3

typedef enum { X = -1, EMPTY = 0, O = 1 } mark_t;
typedef struct { int row, col; } position_t;
typedef mark_t board_t[BOARD_SIZE][BOARD_SIZE];
typedef struct { board_t board; mark_t player; } game_t;

void print_board(const board_t board) {
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            switch (board[row][col]) {
                case X: putchar('X'); break;
                case EMPTY: putchar('.'); break;
                case O: putchar('O'); break;
            }
            putchar(' ');
        }
        putchar('\n');
    }
}

void get_move(const game_t* game, position_t* move) {
    do {
        printf("%c's move: ", game->player == X ? 'X' : 'O');
        if (scanf("%d%d", &move->row, &move->col) != 2) {
            continue;
        }
        --move->row;
        --move->col;
    } while (move->row < 0 || move->row >= BOARD_SIZE || move->col < 0 || move->col >= BOARD_SIZE || game->board[move->row][move->col] != EMPTY);
}

mark_t winner(const board_t board) {
    // Check rows
    for (int row = 0; row < BOARD_SIZE; ++row) {
        if (board[row][0] == board[row][1] && board[row][1] == board[row][2]) {
            return board[row][0];
        }
    }
    // Check columns
    for (int col = 0; col < BOARD_SIZE; ++col) {
        if (board[0][col] == board[1][col] && board[1][col] == board[2][col]) {
            return board[0][col];
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return board[0][2];
    }
    // No winner
    return EMPTY;
}

mark_t minimax(game_t* game, position_t* move) {
    if (winner(game->board) != EMPTY) {
        return winner(game->board);
    }
    int moves_left = 0;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (game->board[row][col] == EMPTY) {
                ++moves_left;
            }
        }
    }
    if (moves_left == 0) {
        return EMPTY;
    }
    // Compute the value of all possible moves
    position_t best_move = { -1, -1 };
    mark_t best_value = game->player == X ? O : X;
    for (int row = 0; row < BOARD_SIZE; ++row) {
        for (int col = 0; col < BOARD_SIZE; ++col) {
            if (game->board[row][col] == EMPTY) {
                // Try this move
                game_t next_game = *game;
                next_game.board[row][col] = game->player;
                next_game.player = game->player == X ? O : X;
                position_t next_move;
                mark_t value = minimax(&next_game, &next_move);
                if (game->player == value) {
                    // We can force a win
                    *move = (position_t) { row, col };
                    return game->player;
                } else if (value == EMPTY) {
                    // This is a draw
                    best_move = (position_t) { row, col };
                    best_value = EMPTY;
                } else if (best_move.row == -1 || (game->player == X ? value < best_value : value > best_value)) {
                    // Found a better move
                    best_move = (position_t) { row, col };
                    best_value = value;
                }
            }
        }
    }
    *move = best_move;
    return best_value;
}

int main() {
    srand(time(NULL));
    game_t game = { .board = { { EMPTY, EMPTY, EMPTY }, { EMPTY, EMPTY, EMPTY }, { EMPTY, EMPTY, EMPTY } } };
    game.player = rand() % 2 == 0 ? X : O;
    while (winner(game.board) == EMPTY) {
        print_board(game.board);
        if (game.player == X) {
            position_t move;
            get_move(&game, &move);
            game.board[move.row][move.col] = X;
        } else {
            position_t move;
            minimax(&game, &move);
            game.board[move.row][move.col] = O;
            printf("O plays (%d,%d)\n", move.row + 1, move.col + 1);
        }
        game.player = game.player == X ? O : X;
    }
    print_board(game.board);
    printf("%c wins!\n", winner(game.board) == X ? 'X' : 'O');
    return 0;
}