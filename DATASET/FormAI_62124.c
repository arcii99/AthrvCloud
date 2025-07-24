//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

typedef struct {
    int row, col;
} Move;

int is_valid_move(char player, Move move) {
    if (move.row < 0 || move.row >= BOARD_SIZE ||
        move.col < 0 || move.col >= BOARD_SIZE ||
        board[move.row][move.col] != ' ')
        return 0;
    if (player == 'X') {
        if ((move.row == 1 && move.col == 1) ||
            (move.row == 1 && move.col == 3) ||
            (move.row == 1 && move.col == 5) ||
            (move.row == 1 && move.col == 7))
            return 0;
    } else {
        if ((move.row == 0 && move.col == 0) ||
            (move.row == 0 && move.col == 2) ||
            (move.row == 0 && move.col == 4) ||
            (move.row == 0 && move.col == 6))
            return 0;
    }
    return 1;
}

char get_opponent(char player) {
    if (player == 'X') return 'O';
    else return 'X';
}

int is_king_row(int row, char player) {
    if (player == 'X' && row == BOARD_SIZE - 1) return 1;
    else if (player == 'O' && row == 0) return 1;
    else return 0;
}

int get_direction(char player) {
    if (player == 'X') return 1;
    else return -1;
}

void make_move(char player, Move move) {
    board[move.row][move.col] = player;
    if (is_king_row(move.row, player)) {
        board[move.row][move.col] = toupper(player);
    }
}

void remove_piece(Move move) {
    board[move.row][move.col] = ' ';
}

int is_capture_move(char player, Move move) {
    if (move.row < 2 || move.row >= BOARD_SIZE - 2 ||
        move.col < 2 || move.col >= BOARD_SIZE - 2)
        return 0;
    if (board[move.row][move.col] != ' ') return 0;
    if (player == 'X') {
        if ((board[move.row - 1][move.col - 1] == 'O' &&
             board[move.row - 2][move.col - 2] == ' ') ||
            (board[move.row - 1][move.col + 1] == 'O' &&
             board[move.row - 2][move.col + 2] == ' '))
            return 1;
    } else {
        if ((board[move.row + 1][move.col - 1] == 'X' &&
             board[move.row + 2][move.col - 2] == ' ') ||
            (board[move.row + 1][move.col + 1] == 'X' &&
             board[move.row + 2][move.col + 2] == ' '))
            return 1;
    }
    return 0;
}

int is_capture_move_from(char player, Move move, int row_offset, int col_offset) {
    Move jump_to = { move.row + row_offset * 2, move.col + col_offset * 2 };
    if (!is_valid_move(player, jump_to)) return 0;
    if (board[move.row + row_offset][move.col + col_offset] != get_opponent(player))
        return 0;
    return is_capture_move(player, jump_to);
}

int has_capture_move(char player, Move move) {
    if (is_capture_move_from(player, move, get_direction(player), -1)) return 1;
    if (is_capture_move_from(player, move, get_direction(player), 1)) return 1;
    if (is_capture_move_from(player, move, -get_direction(player), -1)) return 1;
    if (is_capture_move_from(player, move, -get_direction(player), 1)) return 1;
    return 0;
}

int do_capture_move(char player, Move move) {
    if (is_capture_move_from(player, move, get_direction(player), -1)) {
        Move jump_to = { move.row + get_direction(player) * 2, move.col - 2 };
        remove_piece((Move){move.row + get_direction(player), move.col - 1});
        make_move(player, jump_to);
        return 1;
    }
    if (is_capture_move_from(player, move, get_direction(player), 1)) {
        Move jump_to = { move.row + get_direction(player) * 2, move.col + 2 };
        remove_piece((Move){move.row + get_direction(player), move.col + 1});
        make_move(player, jump_to);
        return 1;
    }
    if (is_capture_move_from(player, move, -get_direction(player), -1)) {
        Move jump_to = { move.row - get_direction(player) * 2, move.col - 2 };
        remove_piece((Move){move.row - get_direction(player), move.col - 1});
        make_move(player, jump_to);
        return 1;
    }
    if (is_capture_move_from(player, move, -get_direction(player), 1)) {
        Move jump_to = { move.row - get_direction(player) * 2, move.col + 2 };
        remove_piece((Move){move.row - get_direction(player), move.col + 1});
        make_move(player, jump_to);
        return 1;
    }
    return 0;
}

void print_board() {
    printf("\n");
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  +---------------+\n");
    for (int row = 0; row < BOARD_SIZE; row++) {
        printf("%d | ", row);
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("|\n");
    }
    printf("  +---------------+\n");
}

int main() {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            if ((row + col) % 2 == 0) {
                if (row < 3) board[row][col] = 'O';
                else if (row > 4) board[row][col] = 'X';
                else board[row][col] = ' ';
            } else {
                board[row][col] = ' ';
            }
        }
    }
    char player = 'X';
    while (1) {
        print_board();
        printf("%c's turn.\n", player);
        int has_valid_move = 0;
        for (int row = 0; row < BOARD_SIZE; row++) {
            for (int col = 0; col < BOARD_SIZE; col++) {
                if (board[row][col] == player) {
                    if (has_capture_move(player, (Move){row, col})) {
                        has_valid_move = 1;
                        Move move = {row, col};
                        while (has_capture_move(player, move)) {
                            print_board();
                            printf("Capturing piece at %d,%d\n", move.row, move.col);
                            while (1) {
                                printf("Enter row and column to jump to: ");
                                scanf("%d %d", &move.row, &move.col);
                                if (is_valid_move(player, move) &&
                                    is_capture_move(player, move))
                                    break;
                                printf("Invalid move.\n");
                            }
                            do_capture_move(player, move);
                        }
                    } else {
                        if (is_valid_move(player, (Move){row, col})) {
                            has_valid_move = 1;
                            Move move = {row, col};
                            while (1) {
                                print_board();
                                printf("Enter row and column to move to: ");
                                scanf("%d %d", &move.row, &move.col);
                                if (is_valid_move(player, move) && !is_capture_move(player, move))
                                    break;
                                printf("Invalid move.\n");
                            }
                            make_move(player, move);
                        }
                    }
                }
            }
        }
        if (!has_valid_move) {
            printf("Game over! %c wins!\n", get_opponent(player));
            break;
        }
        player = get_opponent(player);
    }
    return 0;
}