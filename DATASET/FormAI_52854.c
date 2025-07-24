//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: random
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 3
#define MAX_DEPTH 9

enum GameStatus {
    WIN,
    DRAW,
    IN_PROGRESS
};

typedef struct {
    int x;
    int y;
} Move;

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int turn;
} GameState;

typedef struct {
    GameState state;
    int score;
} GameNode;

bool is_valid_move(GameState state, Move move) {
    if (move.x < 0 || move.x >= BOARD_SIZE || move.y < 0 || move.y >= BOARD_SIZE) {
        return false;
    }
    if (state.board[move.x][move.y] != 0) {
        return false;
    }
    return true;
}

bool is_game_over(GameState state) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (state.board[i][0] == state.board[i][1] && state.board[i][0] == state.board[i][2] && state.board[i][0] != 0) {
            return true;
        }
    }

    for (j = 0; j < BOARD_SIZE; j++) {
        if (state.board[0][j] == state.board[1][j] && state.board[0][j] == state.board[2][j] && state.board[0][j] != 0) {
            return true;
        }
    }

    if (state.board[0][0] == state.board[1][1] && state.board[0][0] == state.board[2][2] && state.board[0][0] != 0) {
        return true;
    }

    if (state.board[0][2] == state.board[1][1] && state.board[0][2] == state.board[2][0] && state.board[0][2] != 0) {
        return true;
    }

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (state.board[i][j] == 0) {
                return false;
            }
        }
    }

    return true;
}

int evaluate_score(GameState state) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (state.board[i][0] == state.board[i][1] && state.board[i][0] == state.board[i][2] && state.board[i][0] != 0) {
            if (state.board[i][0] == 1) {
                return -1;
            } else if (state.board[i][0] == 2) {
                return 1;
            }
        }
    }

    for (j = 0; j < BOARD_SIZE; j++) {
        if (state.board[0][j] == state.board[1][j] && state.board[0][j] == state.board[2][j] && state.board[0][j] != 0) {
            if (state.board[0][j] == 1) {
                return -1;
            } else if (state.board[0][j] == 2) {
                return 1;
            }
        }
    }

    if (state.board[0][0] == state.board[1][1] && state.board[0][0] == state.board[2][2] && state.board[0][0] != 0) {
        if (state.board[0][0] == 1) {
            return -1;
        } else if (state.board[0][0] == 2) {
            return 1;
        }
    }

    if (state.board[0][2] == state.board[1][1] && state.board[0][2] == state.board[2][0] && state.board[0][2] != 0) {
        if (state.board[0][2] == 1) {
            return -1;
        } else if (state.board[0][2] == 2) {
            return 1;
        }
    }

    return 0;
}

GameNode minimax(GameState state, int depth, int alpha, int beta) {
    if (is_game_over(state) || depth == MAX_DEPTH) {
        GameNode node;
        node.state = state;
        node.score = evaluate_score(state);
        return node;
    }

    GameNode best_node;

    if (state.turn == 1) {
        best_node.score = alpha;
    } else {
        best_node.score = beta;
    }

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state.board[i][j] == 0) {
                GameState new_state = state;
                new_state.board[i][j] = state.turn;

                if (state.turn == 1) {
                    new_state.turn = 2;
                } else {
                    new_state.turn = 1;
                }

                GameNode node = minimax(new_state, depth + 1, alpha, beta);

                if (state.turn == 1) {
                    if (node.score > best_node.score) {
                        best_node.score = node.score;
                        best_node.state = new_state;
                    }
                    if (best_node.score >= beta) {
                        return best_node;
                    }
                    if (best_node.score > alpha) {
                        alpha = best_node.score;
                    }
                } else {
                    if (node.score < best_node.score) {
                        best_node.score = node.score;
                        best_node.state = new_state;
                    }
                    if (best_node.score <= alpha) {
                        return best_node;
                    }
                    if (best_node.score < beta) {
                        beta = best_node.score;
                    }
                }
            }
        }
    }

    return best_node;
}

void print_board(GameState state) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (state.board[i][j] == 0) {
                printf("_");
            } else if (state.board[i][j] == 1) {
                printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
}

int main() {
    GameState state;
    state.turn = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            state.board[i][j] = 0;
        }
    }

    print_board(state);

    while (!is_game_over(state)) {
        if (state.turn == 1) {
            Move move;
            printf("Enter your move (row column): ");
            scanf("%d %d", &move.x, &move.y);
            if (is_valid_move(state, move)) {
                state.board[move.x][move.y] = 1;
                state.turn = 2;
            } else {
                printf("Invalid move!\n");
            }
            printf("\n");
        } else {
            printf("Computers move: \n");
            GameNode node = minimax(state, 0, -1000000, 1000000);
            state = node.state;
            print_board(state);
        }
    }

    int status = evaluate_score(state);
    if (status == -1) {
        printf("You win!\n");
    } else if (status == 1) {
        printf("Computer wins!\n");
    } else {
        printf("It's a draw!\n");
    }

    return 0;
}