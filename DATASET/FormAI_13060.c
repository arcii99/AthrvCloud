//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 3
#define MAX_DEPTH 9

typedef enum {
    HUMAN_PLAYER = -1,
    COMPUTER_PLAYER = 1
} player_t;

typedef struct {
    player_t player;
    int row;
    int col;
} move_t;

typedef struct {
    int board[BOARD_SIZE][BOARD_SIZE];
    int num_moves;
} game_t;

int evaluate_board(game_t *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        int row_sum = 0;
        int col_sum = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            row_sum += game->board[i][j];
            col_sum += game->board[j][i];
        }
        if (row_sum == -3 || col_sum == -3) {
            return HUMAN_PLAYER;
        } else if (row_sum == 3 || col_sum == 3) {
            return COMPUTER_PLAYER;
        }
    }
    int diag_sum1 = 0;
    int diag_sum2 = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        diag_sum1 += game->board[i][i];
        diag_sum2 += game->board[i][BOARD_SIZE - 1 - i];
    }
    if (diag_sum1 == -3 || diag_sum2 == -3) {
        return HUMAN_PLAYER;
    } else if (diag_sum1 == 3 || diag_sum2 == 3) {
        return COMPUTER_PLAYER;
    }
    if (game->num_moves < BOARD_SIZE * BOARD_SIZE) {
        return 0;
    }
    return 1;
}

move_t minimax(game_t *game, player_t curr_player, int depth) {
    move_t best_move;
    best_move.player = curr_player == COMPUTER_PLAYER ? HUMAN_PLAYER : COMPUTER_PLAYER;
    int best_score = curr_player == COMPUTER_PLAYER ? -10 : 10;
    int score = evaluate_board(game);
    if (score != 0) {
        if (score == COMPUTER_PLAYER) {
            best_score = 10 - depth;
        } else if (score == HUMAN_PLAYER) {
            best_score = depth - 10;
        }
        return best_move;
    }
    if (depth == MAX_DEPTH) {
        best_score = 0;
        return best_move;
    }
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game->board[i][j] == 0) {
                game_t new_game = *game;
                new_game.board[i][j] = curr_player;
                new_game.num_moves++;
                move_t next_move = minimax(&new_game, curr_player == COMPUTER_PLAYER ? HUMAN_PLAYER : COMPUTER_PLAYER, depth + 1);
                if (curr_player == COMPUTER_PLAYER) {
                    if (next_move.player == HUMAN_PLAYER && next_move.row == -1 && next_move.col == -1) {
                        score = 0;
                    } else {
                        score = next_move.row == i && next_move.col == j ? next_move.player : 0;
                    }
                    if (score > best_score) {
                        best_score = score;
                        best_move.row = i;
                        best_move.col = j;
                        best_move.player = score;
                    }
                } else {
                    if (next_move.player == COMPUTER_PLAYER && next_move.row == -1 && next_move.col == -1) {
                        score = 0;
                    } else {
                        score = next_move.row == i && next_move.col == j ? next_move.player : 0;
                    }
                    if (score < best_score) {
                        best_score = score;
                        best_move.row = i;
                        best_move.col = j;
                        best_move.player = score;
                    }
                }
            }
        }
    }
    return best_move;
}

void print_board(game_t *game) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            switch (game->board[i][j]) {
                case COMPUTER_PLAYER:
                    printf(" X ");
                    break;
                case HUMAN_PLAYER:
                    printf(" O ");
                    break;
                default:
                    printf("   ");
                    break;
            }
            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("---+---+---\n");
        }
    }
}

move_t get_human_move(game_t *game) {
    move_t move;
    move.player = HUMAN_PLAYER;
    printf("Enter row (1-3) and column (1-3) separated by a space: ");
    scanf("%d %d", &move.row, &move.col);
    move.row--;
    move.col--;
    while (move.row < 0 || move.row >= BOARD_SIZE || move.col < 0 || move.col >= BOARD_SIZE || game->board[move.row][move.col] != 0) {
        printf("Invalid move! Enter row (1-3) and column (1-3) separated by a space: ");
        scanf("%d %d", &move.row, &move.col);
        move.row--;
        move.col--;
    }
    game->board[move.row][move.col] = HUMAN_PLAYER;
    game->num_moves++;
    return move;
}

move_t get_computer_move(game_t *game) {
    printf("Computer is thinking...\n");
    move_t move = minimax(game, COMPUTER_PLAYER, 0);
    game->board[move.row][move.col] = COMPUTER_PLAYER;
    game->num_moves++;
    return move;
}

int main() {
    srand(time(NULL));
    game_t game = {
        .board = {{0}},
        .num_moves = 0
    };
    int coin_flip = rand() % 2;
    printf("Welcome to Tic Tac Toe!\n");
    if (coin_flip == 0) {
        printf("You go first!\n");
        while (true) {
            print_board(&game);
            move_t human_move = get_human_move(&game);
            int winner = evaluate_board(&game);
            if (winner != 0) {
                print_board(&game);
                if (winner == COMPUTER_PLAYER) {
                    printf("Computer wins!\n");
                } else if (winner == HUMAN_PLAYER) {
                    printf("You win!\n");
                } else {
                    printf("It's a tie!\n");
                }
                break;
            }
            print_board(&game);
            move_t computer_move = get_computer_move(&game);
            winner = evaluate_board(&game);
            if (winner != 0) {
                print_board(&game);
                if (winner == COMPUTER_PLAYER) {
                    printf("Computer wins!\n");
                } else if (winner == HUMAN_PLAYER) {
                    printf("You win!\n");
                } else {
                    printf("It's a tie!\n");
                }
                break;
            }
        }
    } else {
        printf("Computer goes first!\n");
        while (true) {
            print_board(&game);
            move_t computer_move = get_computer_move(&game);
            int winner = evaluate_board(&game);
            if (winner != 0) {
                print_board(&game);
                if (winner == COMPUTER_PLAYER) {
                    printf("Computer wins!\n");
                } else if (winner == HUMAN_PLAYER) {
                    printf("You win!\n");
                } else {
                    printf("It's a tie!\n");
                }
                break;
            }
            print_board(&game);
            move_t human_move = get_human_move(&game);
            winner = evaluate_board(&game);
            if (winner != 0) {
                print_board(&game);
                if (winner == COMPUTER_PLAYER) {
                    printf("Computer wins!\n");
                } else if (winner == HUMAN_PLAYER) {
                    printf("You win!\n");
                } else {
                    printf("It's a tie!\n");
                }
                break;
            }
        }
    }
    return 0;
}