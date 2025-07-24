//FormAI DATASET v1.0 Category: Chess AI ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];
int eval_board[BOARD_SIZE][BOARD_SIZE] = {
    { 0,  0,  0,  0,  0,  0,  0,  0 },
    { 0,  1,  1,  1,  1,  1,  1,  1 },
    { 0, -1,  0,  0,  0,  0,  0, -1 },
    { 0, -1,  0,  0,  0,  0,  0, -1 },
    { 0, -1,  0,  0,  0,  0,  0, -1 },
    { 0, -1,  0,  0,  0,  0,  0, -1 },
    { 0,  1,  1,  1,  1,  1,  1,  1 },
    { 0,  0,  0,  0,  0,  0,  0,  0 }
};

struct Move {
    int from_x;
    int from_y;
    int to_x;
    int to_y;
};

struct Move moves[100];
int num_moves = 0;

int min(int a, int b) {
    return a < b ? a : b;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int evaluate_board() {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            score += eval_board[i][j] * board[i][j];
        }
    }
    return score;
}

int get_best_move(int depth) {
    int best_score = -1000000;
    int best_move = -1;

    for (int i = 0; i < num_moves; i++) {
        struct Move move = moves[i];
        int from_x = move.from_x;
        int from_y = move.from_y;
        int to_x = move.to_x;
        int to_y = move.to_y;

        int tmp_board[BOARD_SIZE][BOARD_SIZE];
        memcpy(&tmp_board, &board, sizeof(board));

        int tmp = board[to_x][to_y];
        board[to_x][to_y] = board[from_x][from_y];
        board[from_x][from_y] = 0;

        int score = -alpha_beta(-1000000, 1000000, depth - 1);

        memcpy(&board, &tmp_board, sizeof(board));
        
        if (score > best_score) {
            best_score = score;
            best_move = i;
        } 
    }

    return best_move;
}

int alpha_beta(int alpha, int beta, int depth) {
    if (depth == 0) {
        return evaluate_board();
    }

    int best_score = -1000000;

    for (int i = 0; i < num_moves; i++) {
        struct Move move = moves[i];
        int from_x = move.from_x;
        int from_y = move.from_y;
        int to_x = move.to_x;
        int to_y = move.to_y;

        int tmp_board[BOARD_SIZE][BOARD_SIZE];
        memcpy(&tmp_board, &board, sizeof(board));

        int tmp = board[to_x][to_y];
        board[to_x][to_y] = board[from_x][from_y];
        board[from_x][from_y] = 0;

        int score = -alpha_beta(-beta, -alpha, depth - 1);

        memcpy(&board, &tmp_board, sizeof(board));
        
        if (score >= beta) {
            return score;
        }

        if (score > best_score) {
            best_score = score;
        }

        alpha = max(alpha, score);
    }

    return best_score;
}

void generate_moves(int player) {
    num_moves = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                if (i > 0 && j > 0 && board[i-1][j-1] == 0) {
                    moves[num_moves++] = (struct Move){i, j, i-1, j-1};
                }
                if (i > 0 && j < BOARD_SIZE-1 && board[i-1][j+1] == 0) {
                    moves[num_moves++] = (struct Move){i, j, i-1, j+1};
                }
                if (i < BOARD_SIZE-1 && j > 0 && board[i+1][j-1] == 0) {
                    moves[num_moves++] = (struct Move){i, j, i+1, j-1};
                }
                if (i < BOARD_SIZE-1 && j < BOARD_SIZE-1 && board[i+1][j+1] == 0) {
                    moves[num_moves++] = (struct Move){i, j, i+1, j+1};
                }
            }
        }
    }
}

void do_move(int player, struct Move move) {
    board[move.to_x][move.to_y] = player;
    board[move.from_x][move.from_y] = 0;
}

int main() {
    memset(&board, 0, sizeof(board));
    board[3][3] = 1;
    board[4][4] = 1;
    board[3][4] = -1;
    board[4][3] = -1;

    int turn = 1;

    while (1) {
        generate_moves(turn);
        if (num_moves == 0) {
            break;
        }
        int best_move = get_best_move(4);
        do_move(turn, moves[best_move]);
        turn *= -1;
    }

    printf("Game over\n");

    return 0;
}