//FormAI DATASET v1.0 Category: Chess AI ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 10000000

int alpha_beta_max_value(int board[][8], int alpha, int beta, int depth);
int alpha_beta_min_value(int board[][8], int alpha, int beta, int depth);
int max(int a, int b);
int min(int a, int b);
void print_board(int board[][8]);
void move_piece(int board[][8], int from_x, int from_y, int to_x, int to_y);
int evaluate_board(int board[][8], int side);

int main() {

    int board[8][8] = {
        {1, 2, 3, 4, 5, 3, 2, 1},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {-6, -6, -6, -6, -6, -6, -6, -6},
        {-1, -2, -3, -4, -5, -3, -2, -1}
    };

    print_board(board);

    int depth = 4;
    int best_move_score = -INF;
    int best_from_x = 0;
    int best_from_y = 0;
    int best_to_x = 0;
    int best_to_y = 0;

    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] > 0) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (((board[i][j] == 1 || board[i][j] == 4) && i == k) || (board[i][j] == 2 && j == l)) {
                            continue;
                        }
                        if (board[k][l] == -6) { // capture the king
                            move_piece(board, i, j, k, l);
                            printf("AI moved (%d, %d) to %d, %d)\n", i, j, k, l);
                            best_move_score = INF;
                            goto exit_loop;
                        }
                        if (board[i][j] == 1 && k < i) { // cannot move backwards
                            continue;
                        }
                        int piece = board[i][j];
                        int captured_piece = board[k][l];
                        move_piece(board, i, j, k, l);
                        int move_score = alpha_beta_min_value(board, -INF, INF, depth - 1);
                        if (move_score > best_move_score) {
                            best_move_score = move_score;
                            best_from_x = i;
                            best_from_y = j;
                            best_to_x = k;
                            best_to_y = l;
                        }
                        move_piece(board, k, l, i, j);
                        board[k][l] = captured_piece;
                        board[i][j] = piece;
                    }
                }
            }
        }
    }

    printf("AI moved (%d, %d) to %d, %d)\n", best_from_x, best_from_y, best_to_x, best_to_y);
    move_piece(board, best_from_x, best_from_y, best_to_x, best_to_y);
    print_board(board);

exit_loop:
    return 0;
}

int alpha_beta_max_value(int board[][8], int alpha, int beta, int depth) {
    if (depth == 0) {
        return evaluate_board(board, 1);
    }
    int score = -INF;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] > 0) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (((board[i][j] == 1 || board[i][j] == 4) && i == k) || (board[i][j] == 2 && j == l)) {
                            continue;
                        }
                        if (board[k][l] == -6) { // capture the king
                            move_piece(board, i, j, k, l);
                            score = INF;
                            goto exit_loop;
                        }
                        if (board[i][j] == 1 && k < i) { // cannot move backwards
                            continue;
                        }
                        int piece = board[i][j];
                        int captured_piece = board[k][l];
                        move_piece(board, i, j, k, l);
                        score = max(score, alpha_beta_min_value(board, alpha, beta, depth - 1));
                        move_piece(board, k, l, i, j);
                        board[k][l] = captured_piece;
                        board[i][j] = piece;
                        if (score >= beta) {
                            goto exit_loop;
                        }
                        alpha = max(alpha, score);
                    }
                }
            }
        }
    }
exit_loop:
    return score;
}

int alpha_beta_min_value(int board[][8], int alpha, int beta, int depth) {
    if (depth == 0) {
        return evaluate_board(board, -1);
    }
    int score = INF;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] < 0) {
                for (int k = 0; k < 8; k++) {
                    for (int l = 0; l < 8; l++) {
                        if (((board[i][j] == -1 || board[i][j] == -4) && i == k) || (board[i][j] == -2 && j == l)) {
                            continue;
                        }
                        if (board[k][l] == 6) { // capture the king
                            move_piece(board, i, j, k, l);
                            score = -INF;
                            goto exit_loop;
                        }
                        if (board[i][j] == -1 && k > i) { // cannot move backwards
                            continue;
                        }
                        int piece = board[i][j];
                        int captured_piece = board[k][l];
                        move_piece(board, i, j, k, l);
                        score = min(score, alpha_beta_max_value(board, alpha, beta, depth - 1));
                        move_piece(board, k, l, i, j);
                        board[k][l] = captured_piece;
                        board[i][j] = piece;
                        if (score <= alpha) {
                            goto exit_loop;
                        }
                        beta = min(beta, score);
                    }
                }
            }
        }
    }
exit_loop:
    return score;
}

void move_piece(int board[][8], int from_x, int from_y, int to_x, int to_y) {
    int piece = board[from_x][from_y];
    board[to_x][to_y] = piece;
    board[from_x][from_y] = 0;
}

int evaluate_board(int board[][8], int side) {
    int score = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if (board[i][j] == 1) { // pawn
                score += 1;
            } else if (board[i][j] == 2) { // knight
                score += 3;
            } else if (board[i][j] == 3) { // bishop
                score += 3;
            } else if (board[i][j] == 4) { // rook
                score += 5;
            } else if (board[i][j] == 5) { // queen
                score += 9;
            } else if (board[i][j] == -1) { // pawn
                score -= 1;
            } else if (board[i][j] == -2) { // knight
                score -= 3;
            } else if (board[i][j] == -3) { // bishop
                score -= 3;
            } else if (board[i][j] == -4) { // rook
                score -= 5;
            } else if (board[i][j] == -5) { // queen
                score -= 9;
            }
        }
    }
    return side * score;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

void print_board(int board[][8]) {
    printf("\n");
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}