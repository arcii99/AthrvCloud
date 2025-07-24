//FormAI DATASET v1.0 Category: Chess AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

const int BOARD_SIZE = 8;
const int INF = 1000000;

int evaluate_board(int board[][8]) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) continue;
            int piece_score = 0;
            switch(abs(board[i][j])) {
                case 1:
                    piece_score = 10;
                    break;
                case 2:
                    piece_score = 30;
                    break;
                case 3:
                    piece_score = 30;
                    break;
                case 4:
                    piece_score = 50;
                    break;
                case 5:
                    piece_score = 90;
                    break;
                case 6:
                    piece_score = 900;
                    break;
            }
            if (board[i][j] < 0) piece_score *= -1;
            score += piece_score;
        }
    }
    return score;
}

bool in_bounds(int x, int y) {
    return (x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}

int min_max_search(int board[][8], int depth, bool is_maximizing, int alpha, int beta) {
    if (depth == 0) {
        return evaluate_board(board);
    }

    int best_score = (is_maximizing) ? -INF : INF;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0 || ((is_maximizing && board[i][j] < 0) || (!is_maximizing && board[i][j] > 0))) continue;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int new_x = i + dx, new_y = j + dy;
                    if (in_bounds(new_x, new_y)) {
                        int old_piece = board[new_x][new_y];
                        board[new_x][new_y] = board[i][j];
                        board[i][j] = 0;
                        int score = min_max_search(board, depth - 1, !is_maximizing, alpha, beta);
                        board[i][j] = board[new_x][new_y];
                        board[new_x][new_y] = old_piece;

                        if (is_maximizing) {
                            best_score = max(best_score, score);
                            alpha = max(alpha, best_score);
                        } else {
                            best_score = min(best_score, score);
                            beta = min(beta, best_score);
                        }

                        if (beta <= alpha) {
                            return best_score;
                        }
                    }
                }
            }
        }
    }

    return best_score;
}

void get_best_move(int board[][8]) {
    int best_score = -INF, best_move[4] = {0, 0, 0, 0};

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0 || board[i][j] > 0) continue;

            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++) {
                    if (dx == 0 && dy == 0) continue;
                    int new_x = i + dx, new_y = j + dy;
                    if (in_bounds(new_x, new_y)) {
                        int old_piece = board[new_x][new_y];
                        board[new_x][new_y] = board[i][j];
                        board[i][j] = 0;
                        int score = min_max_search(board, 3, false, -INF, INF);
                        board[i][j] = board[new_x][new_y];
                        board[new_x][new_y] = old_piece;

                        if (score > best_score) {
                            best_score = score;
                            best_move[0] = i;
                            best_move[1] = j;
                            best_move[2] = new_x;
                            best_move[3] = new_y;
                        }
                    }
                }
            }
        }
    }

    printf("Best Move: (%d, %d) -> (%d, %d)\n", best_move[0], best_move[1], best_move[2], best_move[3]);
}

int main() {
    int board[8][8] = {{-4, -2, -3, -5, -6, -3, -2, -4},
                       {-1, -1, -1, -1, -1, -1, -1, -1},
                       { 0,  0,  0,  0,  0,  0,  0,  0},
                       { 0,  0,  0,  0,  0,  0,  0,  0},
                       { 0,  0,  0,  0,  0,  0,  0,  0},
                       { 0,  0,  0,  0,  0,  0,  0,  0},
                       { 1,  1,  1,  1,  1,  1,  1,  1},
                       { 4,  2,  3,  5,  6,  3,  2,  4}};

    get_best_move(board);

    return 0;
}