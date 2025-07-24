//FormAI DATASET v1.0 Category: Checkers Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, -1, 0, -1, 0, -1, 0, -1},
    {-1, 0, -1, 0, -1, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0},
    {0, 1, 0, 1, 0, 1, 0, 1}};

int player;

void display_board() {
    printf("\n  ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                printf("X ");
            } else if (board[i][j] == 1) {
                printf("O ");
            } else if (board[i][j] == -2) {
                printf("x ");
            } else if (board[i][j] == 2) {
                printf("o ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int is_valid_move(int from_i, int from_j, int to_i, int to_j) {
    // check that the move is within the bounds of the board
    if (to_i < 0 || to_i >= BOARD_SIZE ||
        to_j < 0 || to_j >= BOARD_SIZE) {
        return 0;
    }

    // check that the destination tile is empty
    if (board[to_i][to_j] != 0) {
        return 0;
    }

    // check that the piece being moved belongs to the current player
    if ((player == 1 && board[from_i][from_j] != 1 && board[from_i][from_j] != 2) ||
        (player == -1 && board[from_i][from_j] != -1 && board[from_i][from_j] != -2)) {
        return 0;
    }

    // Check for diagonal move (normal)
    if (from_i + 1 == to_i && abs(from_j - to_j) == 1) {
        return 1;
    }
    // These if statements check for jump moves.
    if (from_i + 2 == to_i) {
        if (abs(from_j - to_j) == 2 && board[to_i - 1][(from_j + to_j) / 2] != player &&
            board[to_i - 1][(from_j + to_j) / 2] != 0) {
            return 1;
        }
    }

    // if all checks fail, return 0
    return 0;
}

int has_moves_left() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (player == 1 || board[i][j] == -2) {
                if (is_valid_move(i, j, i + 1, j - 1) ||
                    is_valid_move(i, j, i + 1, j + 1) ||
                    is_valid_move(i, j, i + 2, j - 2) ||
                    is_valid_move(i, j, i + 2, j + 2)) {
                    return 1;
                }
            } else if (player == -1 || board[i][j] == 2) {
                if (is_valid_move(i, j, i - 1, j - 1) ||
                    is_valid_move(i, j, i - 1, j + 1) ||
                    is_valid_move(i, j, i - 2, j - 2) ||
                    is_valid_move(i, j, i - 2, j + 2)) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

void make_move(int from_i, int from_j, int to_i, int to_j) {
    // if the piece is moving to the opposite end, make it a king
    if (player == 1 && to_i == BOARD_SIZE - 1) {
        board[to_i][to_j] = 2;
    } else if (player == -1 && to_i == 0) {
        board[to_i][to_j] = -2;
    } else {
        board[to_i][to_j] = board[from_i][from_j];
    }
    board[from_i][from_j] = 0;

    // if the move was a jump, remove the jumped piece
    if (abs(from_i - to_i) == 2) {
        board[(from_i + to_i) / 2][(from_j + to_j) / 2] = 0;
    }
}

void check_for_win() {
    int has_opponent_pieces = 0;
    int has_current_player_pieces = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1 || board[i][j] == -2) {
                has_opponent_pieces = 1;
            } else if (board[i][j] == 1 || board[i][j] == 2) {
                has_current_player_pieces = 1;
            }
        }
    }
    if (!has_current_player_pieces) {
        printf("Game Over! Player %d wins!\n", -player);
        exit(0);
    } else if (!has_opponent_pieces) {
        printf("Game Over! Player %d wins!\n", player);
        exit(0);
    }
}

int main() {
    int from_i, from_j, to_i, to_j;
    while (1) {
        display_board();
        printf("Player %d's turn.\n", player);

        if (!has_moves_left()) {
            printf("Game Over! Player %d wins!\n", -player);
            return 0;
        }

        while (1) {
            printf("Enter the coordinates of the piece you want to move: ");
            scanf("%d %d", &from_i, &from_j);
            printf("Enter the coordinates of the destination tile: ");
            scanf("%d %d", &to_i, &to_j);

            if (is_valid_move(from_i, from_j, to_i, to_j)) {
                break;
            } else {
                printf("Invalid move!\n");
            }
        }

        make_move(from_i, from_j, to_i, to_j);

        // Check if piece should be kinged
        if (player == 1 && board[to_i][to_j] == 1 && to_i == BOARD_SIZE - 1) {
            board[to_i][to_j] = 2;
        } else if (player == -1 && board[to_i][to_j] == -1 && to_i == 0) {
            board[to_i][to_j] = -2;
        }

        display_board();
        check_for_win();
        player = -player;
    }
    return 0;
}