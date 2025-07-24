//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define MAX_DEPTH 9
#define PLAYER_ONE 1
#define PLAYER_TWO -1

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int score;
} State;

typedef struct {
    int x;
    int y;
} Move;

int check_winner(const State *state) {
    int i, j, sum;

    // Check rows
    for (i = 0; i < BOARD_SIZE; i++) {
        sum = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            sum += state->board[i][j];
        }
        if (sum == BOARD_SIZE || sum == -BOARD_SIZE) {
            return sum / BOARD_SIZE;
        }
    }

    // Check columns
    for (i = 0; i < BOARD_SIZE; i++) {
        sum = 0;
        for (j = 0; j < BOARD_SIZE; j++) {
            sum += state->board[j][i];
        }
        if (sum == BOARD_SIZE || sum == -BOARD_SIZE) {
            return sum / BOARD_SIZE;
        }
    }

    // Check diagonals
    sum = state->board[0][0] + state->board[1][1] + state->board[2][2];
    if (sum == BOARD_SIZE || sum == -BOARD_SIZE) {
        return sum / BOARD_SIZE;
    }

    sum = state->board[0][2] + state->board[1][1] + state->board[2][0];
    if (sum == BOARD_SIZE || sum == -BOARD_SIZE) {
        return sum / BOARD_SIZE;
    }

    // Check for a tie
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] == 0) {
                return 0;
            }
        }
    }

    return 0;
}

int evaluate(const State *state) {
    int winner = check_winner(state);
    if (winner == PLAYER_ONE) {
        return 10;
    } else if (winner == PLAYER_TWO) {
        return -10;
    } else {
        return 0;
    }
}

int minmax(State *state, int depth, int maximizing_player) {
    int i, j, score, best_score;
    int winner = check_winner(state);

    if (winner != 0) {
        return evaluate(state);
    }

    if (depth == 0) {
        return evaluate(state);
    }

    if (maximizing_player) {
        best_score = -100000;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (state->board[i][j] == 0) {
                    state->board[i][j] = PLAYER_ONE;
                    score = minmax(state, depth - 1, 0);
                    state->board[i][j] = 0;
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        best_score = 100000;
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (state->board[i][j] == 0) {
                    state->board[i][j] = PLAYER_TWO;
                    score = minmax(state, depth - 1, 1);
                    state->board[i][j] = 0;
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

Move find_best_move(const State *state) {
    int i, j, best_score = -100000, score;
    Move best_move;
    State new_state;

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] == 0) {
                new_state = *state;
                new_state.board[i][j] = PLAYER_ONE;
                score = minmax(&new_state, MAX_DEPTH, 0);
                if (score > best_score) {
                    best_score = score;
                    best_move.x = i;
                    best_move.y = j;
                }
            }
        }
    }

    return best_move;
}

void print_board(const State *state) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (state->board[i][j] == PLAYER_ONE) {
                printf("X ");
            } else if (state->board[i][j] == PLAYER_TWO) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int main() {
    State state = {{{0}}};
    Move move;

    // X plays first
    while (check_winner(&state) == 0) {
        print_board(&state);
        printf("X's turn.\n");
        move = find_best_move(&state);
        state.board[move.x][move.y] = PLAYER_ONE;
        if (check_winner(&state) != 0) {
            break;
        }
        print_board(&state);
        printf("O's turn.\n");
        printf("Enter move x y: ");
        scanf("%d %d", &move.x, &move.y);
        while (state.board[move.x][move.y] != 0) {
            printf("Invalid move.\n");
            printf("Enter move x y: ");
            scanf("%d %d", &move.x, &move.y);
        }
        state.board[move.x][move.y] = PLAYER_TWO;
    }

    print_board(&state);
    int winner = check_winner(&state);
    if (winner == PLAYER_ONE) {
        printf("X wins!\n");
    } else if (winner == PLAYER_TWO) {
        printf("O wins!\n");
    } else {
        printf("Tie!\n");
    }

    return 0;
}