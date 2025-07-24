//FormAI DATASET v1.0 Category: Chess AI ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    char board[BOARD_SIZE][BOARD_SIZE];
    char turn;
} Game;

int evaluate(Game *game) {
    int score = 0;
    char player = game->turn;
    char opponent = player == 'W' ? 'B' : 'W';
    for (int r = 0; r < BOARD_SIZE; ++r) {
        for (int c = 0; c < BOARD_SIZE; ++c) {
            char piece = game->board[r][c];
            if (piece == player) {
                score += 10;
                if ((player == 'W' && r == 0) || (player == 'B' && r == BOARD_SIZE - 1)) {
                    score += 100;
                }
            } else if (piece == opponent) {
                score -= 10;
                if ((opponent == 'W' && r == 0) || (opponent == 'B' && r == BOARD_SIZE - 1)) {
                    score -= 100;
                }
            }
        }
    }
    return score;
}

bool is_valid_move(Game *game, Position start, Position end) {
    char piece = game->board[start.row][start.col];
    char target = game->board[end.row][end.col];
    if (piece == 'W' && target == 'B' && end.row - start.row == -1 && abs(end.col - start.col) == 1) {
        return true;
    }
    if (piece == 'B' && target == 'W' && end.row - start.row == 1 && abs(end.col - start.col) == 1) {
        return true;
    }
    return false;
}

bool is_game_over(Game *game) {
    for (int r = 0; r < BOARD_SIZE; ++r) {
        for (int c = 0; c < BOARD_SIZE; ++c) {
            char piece = game->board[r][c];
            if (piece == 'W' || piece == 'B') {
                Position start = { r, c };
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int r2 = r + i;
                        int c2 = c + j;
                        if (r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
                            continue;
                        }
                        Position end = { r2, c2 };
                        if (is_valid_move(game, start, end)) {
                            return false;
                        }
                    }
                }
            }
        }
    }
    return true;
}

int minimax(Game *game, int depth, int alpha, int beta) {
    if (depth == MAX_DEPTH || is_game_over(game)) {
        return evaluate(game);
    }
    if (game->turn == 'W') {
        int max_eval = -10000;
        for (int r = 0; r < BOARD_SIZE; ++r) {
            for (int c = 0; c < BOARD_SIZE; ++c) {
                char piece = game->board[r][c];
                if (piece == 'W') {
                    Position start = { r, c };
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            int r2 = r + i;
                            int c2 = c + j;
                            if (r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
                                continue;
                            }
                            Position end = { r2, c2 };
                            if (is_valid_move(game, start, end)) {
                                Game next_game = *game;
                                next_game.board[r][c] = '.';
                                next_game.board[r2][c2] = 'W';
                                next_game.turn = 'B';
                                int eval = minimax(&next_game, depth + 1, alpha, beta);
                                if (eval > max_eval) {
                                    max_eval = eval;
                                }
                                if (eval > alpha) {
                                    alpha = eval;
                                }
                                if (beta <= alpha) {
                                    return max_eval;
                                }
                            }
                        }
                    }
                }
            }
        }
        return max_eval;
    } else {
        int min_eval = 10000;
        for (int r = 0; r < BOARD_SIZE; ++r) {
            for (int c = 0; c < BOARD_SIZE; ++c) {
                char piece = game->board[r][c];
                if (piece == 'B') {
                    Position start = { r, c };
                    for (int i = -1; i <= 1; ++i) {
                        for (int j = -1; j <= 1; ++j) {
                            int r2 = r + i;
                            int c2 = c + j;
                            if (r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
                                continue;
                            }
                            Position end = { r2, c2 };
                            if (is_valid_move(game, start, end)) {
                                Game next_game = *game;
                                next_game.board[r][c] = '.';
                                next_game.board[r2][c2] = 'B';
                                next_game.turn = 'W';
                                int eval = minimax(&next_game, depth + 1, alpha, beta);
                                if (eval < min_eval) {
                                    min_eval = eval;
                                }
                                if (eval < beta) {
                                    beta = eval;
                                }
                                if (beta <= alpha) {
                                    return min_eval;
                                }
                            }
                        }
                    }
                }
            }
        }
        return min_eval;
    }
}

Position find_best_move(Game *game) {
    Position best_move = { -1, -1 };
    int best_eval = -10000;
    for (int r = 0; r < BOARD_SIZE; ++r) {
        for (int c = 0; c < BOARD_SIZE; ++c) {
            char piece = game->board[r][c];
            if (piece == game->turn) {
                Position start = { r, c };
                for (int i = -1; i <= 1; ++i) {
                    for (int j = -1; j <= 1; ++j) {
                        int r2 = r + i;
                        int c2 = c + j;
                        if (r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
                            continue;
                        }
                        Position end = { r2, c2 };
                        if (is_valid_move(game, start, end)) {
                            Game next_game = *game;
                            next_game.board[r][c] = '.';
                            next_game.board[r2][c2] = piece;
                            next_game.turn = game->turn == 'W' ? 'B' : 'W';
                            int eval = minimax(&next_game, 0, -10000, 10000);
                            if (eval > best_eval) {
                                best_eval = eval;
                                best_move = end;
                            }
                        }
                    }
                }
            }
        }
    }
    return best_move;
}

int main() {
    Game game = {
        { "B.B.B.BB",
          ".B.B.B.B",
          "........",
          "........",
          "........",
          ".W.W.W.W",
          "W.W.W.W.",
          "WW..W.W." },
        'W'
    };
    printf("Welcome to Happy Chess AI!\n");
    while (!is_game_over(&game)) {
        srand(time(NULL));
        if (game.turn == 'W') {
            printf("It's White player's turn!\n");
            Position move = find_best_move(&game);
            printf("White player moves from (%d, %d) to (%d, %d).\n", 7 - move.row, move.col, 7 - move.row + 1, move.col + 1);
            game.board[move.row][move.col] = '.';
            game.board[move.row + 1][move.col] = 'W';
            game.turn = 'B';
        } else {
            printf("It's Black player's turn!\n");
            int valid_moves[32][2];
            int num_valid_moves = 0;
            for (int r = 0; r < BOARD_SIZE; ++r) {
                for (int c = 0; c < BOARD_SIZE; ++c) {
                    if (game.board[r][c] == 'B') {
                        Position start = { r, c };
                        for (int i = -1; i <= 1; ++i) {
                            for (int j = -1; j <= 1; ++j) {
                                int r2 = r + i;
                                int c2 = c + j;
                                if (r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
                                    continue;
                                }
                                Position end = { r2, c2 };
                                if (is_valid_move(&game, start, end)) {
                                    valid_moves[num_valid_moves][0] = r;
                                    valid_moves[num_valid_moves][1] = c;
                                    ++num_valid_moves;
                                }
                            }
                        }
                    }
                }
            }
            if (num_valid_moves == 0) {
                printf("Black player cannot move! White player wins!\n");
                return 0;
            }
            int random_index = rand() % num_valid_moves;
            Position start = { valid_moves[random_index][0], valid_moves[random_index][1] };
            int num_valid_destinations = 0;
            Position valid_destinations[32];
            for (int i = -1; i <= 1; ++i) {
                for (int j = -1; j <= 1; ++j) {
                    int r2 = start.row + i;
                    int c2 = start.col + j;
                    if (r2 < 0 || r2 >= BOARD_SIZE || c2 < 0 || c2 >= BOARD_SIZE) {
                        continue;
                    }
                    Position end = { r2, c2 };
                    if (is_valid_move(&game, start, end)) {
                        valid_destinations[num_valid_destinations++] = end;
                    }
                }
            }
            random_index = rand() % num_valid_destinations;
            Position end = valid_destinations[random_index];
            printf("Black player moves from (%d, %d) to (%d, %d).\n", 7 - start.row, start.col + 1, 7 - end.row, end.col + 1);
            game.board[start.row][start.col] = '.';
            game.board[end.row][end.col] = 'B';
            game.turn = 'W';
        }
    }
    if (evaluate(&game) > 0) {
        printf("White player wins!\n");
    } else {
        printf("Black player wins!\n");
    }
    return 0;
}