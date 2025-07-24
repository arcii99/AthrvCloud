//FormAI DATASET v1.0 Category: Chess AI ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 3

char board[BOARD_SIZE][BOARD_SIZE] = {
    {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'},
    {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {' ', '.', ' ', '.', ' ', '.', ' ', '.'},
    {'.', ' ', '.', ' ', '.', ' ', '.', ' '},
    {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
    {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'}
};

int pawn_scores[BOARD_SIZE][BOARD_SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {5,  5, 10, 25, 25, 10, 5,  5},
    {0,  0,  0, 20, 20,  0, 0,  0},
    {5, -5,-10,  0,  0,-10,-5,  5},
    {5, 10, 10,-20,-20, 10,10,  5},
    {0,  0,  0,  0,  0,  0, 0,  0}
};

int knight_scores[BOARD_SIZE][BOARD_SIZE] = {
    {-50,-40,-30,-30,-30,-30,-40,-50},
    {-40,-20,  0,  0,  0,  0,-20,-40},
    {-30,  0, 10, 15, 15, 10,  0,-30},
    {-30,  5, 15, 20, 20, 15,  5,-30},
    {-30,  0, 15, 20, 20, 15,  0,-30},
    {-30,  5, 10, 15, 15, 10,  5,-30},
    {-40,-20,  0,  5,  5,  0,-20,-40},
    {-50,-40,-30,-30,-30,-30,-40,-50}
};

int bishop_scores[BOARD_SIZE][BOARD_SIZE] = {
    {-20,-10,-10,-10,-10,-10,-10,-20},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-10,  0,  5, 10, 10,  5,  0,-10},
    {-10,  5,  5, 10, 10,  5,  5,-10},
    {-10,  0, 10, 10, 10, 10,  0,-10},
    {-10, 10, 10, 10, 10, 10, 10,-10},
    {-10,  5,  0,  0,  0,  0,  5,-10},
    {-20,-10,-10,-10,-10,-10,-10,-20}
};

int rook_scores[BOARD_SIZE][BOARD_SIZE] = {
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 5, 10, 10, 10, 10, 10, 10,  5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    {-5,  0,  0,  0,  0,  0,  0, -5},
    { 0,  0,  0,  5,  5,  0,  0,  0}
};

int queen_scores[BOARD_SIZE][BOARD_SIZE] = {
    {-20,-10,-10, -5, -5,-10,-10,-20},
    {-10,  0,  0,  0,  0,  0,  0,-10},
    {-10,  0,  5,  5,  5,  5,  0,-10},
    { -5,  0,  5,  5,  5,  5,  0, -5},
    {  0,  0,  5,  5,  5,  5,  0, -5},
    {-10,  5,  5,  5,  5,  5,  0,-10},
    {-10,  0,  5,  0,  0,  0,  0,-10},
    {-20,-10,-10, -5, -5,-10,-10,-20}
};

int king_scores[BOARD_SIZE][BOARD_SIZE] = {
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-30,-40,-40,-50,-50,-40,-40,-30},
    {-20,-30,-30,-40,-40,-30,-30,-20},
    {-10,-20,-20,-20,-20,-20,-20,-10},
    { 20, 20,  0,  0,  0,  0, 20, 20},
    { 20, 30, 10,  0,  0, 10, 30, 20}
};

int evaluate_board() {
    int score = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case 'P':
                    score += 100 + pawn_scores[i][j];
                    break;
                case 'N':
                    score += 320 + knight_scores[i][j];
                    break;
                case 'B':
                    score += 330 + bishop_scores[i][j];
                    break;
                case 'R':
                    score += 500 + rook_scores[i][j];
                    break;
                case 'Q':
                    score += 900 + queen_scores[i][j];
                    break;
                case 'K':
                    score += 20000 + king_scores[i][j];
                    break;
            }
        }
    }
    return score;
}

int minmax(int depth, int alpha, int beta, bool maximizing_player) {
    if(depth == 0) {
        return evaluate_board();
    }

    if(maximizing_player) {
        int max_score = INT_MIN;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] != ' ') {
                    continue;
                }
                board[i][j] = 'P';
                int score = minmax(depth - 1, alpha, beta, false);
                board[i][j] = ' ';
                if(score > max_score) {
                    max_score = score;
                }
                if(score > alpha) {
                    alpha = score;
                }
                if(alpha >= beta) {
                    return max_score;
                }
            }
        }
        return max_score;
    } else {
        int min_score = INT_MAX;
        for(int i = 0; i < BOARD_SIZE; i++) {
            for(int j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] != ' ') {
                    continue;
                }
                board[i][j] = 'p';
                int score = minmax(depth - 1, alpha, beta, true);
                board[i][j] = ' ';
                if(score < min_score) {
                    min_score = score;
                }
                if(score < beta) {
                    beta = score;
                }
                if(alpha >= beta) {
                    return min_score;
                }
            }
        }
        return min_score;
    }
}

void make_best_move(int depth) {
    int max_score = INT_MIN;
    int best_move_i = -1;
    int best_move_j = -1;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] != ' ') {
                continue;
            }
            board[i][j] = 'P';
            int score = minmax(depth - 1, INT_MIN, INT_MAX, false);
            board[i][j] = ' ';
            if(score > max_score) {
                max_score = score;
                best_move_i = i;
                best_move_j = j;
            }
        }
    }
    board[best_move_i][best_move_j] = 'P';
}

int main() {
    make_best_move(MAX_DEPTH);
    return 0;
}