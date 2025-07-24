//FormAI DATASET v1.0 Category: Chess AI ; Style: realistic
#include <stdio.h>

#define INF 1000000000
#define MAX_DEPTH 4

int board[8][8] = { // Initial chess board position
    {-6, -4, -3, -5, -2, -3, -4, -6},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 0,  0,  0,  0,  0,  0,  0,  0},
    { 1,  1,  1,  1,  1,  1,  1,  1},
    { 6,  4,  3,  5,  2,  3,  4,  6},
};

int evaluate() { // Evaluates the current board position for the current player
    int score = 0;
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            int v = board[x][y];
            if (v < 0) {
                score -= v; // Negative pieces for player 1
            } else if (v > 0) {
                score += v; // Positive pieces for player 2
            }
        }
    }
    return score;
}

int minimax(int depth, int alpha, int beta, int player) { // Minimax algorithm with Alpha-Beta pruning
    if (depth == 0) {
        return evaluate();
    }
    if (player == 1) { // Player 1 is trying to minimize the score
        int score = INF;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] < 0) { // Only consider negative pieces (player 1)
                    int v = board[x][y];
                    board[x][y] = 0;
                    int tmp = score;
                    score = (score < (minimax(depth - 1, alpha, beta, 2))) ? score : minimax(depth - 1, alpha, beta, 2);
                    board[x][y] = v;
                    alpha = (alpha > score) ? alpha : score;
                    if (alpha >= beta) {
                        return score;
                    }
                }
            }
        }
        return score;
    } else { // Player 2 is trying to maximize the score
        int score = -INF;
        for (int x = 0; x < 8; x++) {
            for (int y = 0; y < 8; y++) {
                if (board[x][y] > 0) { // Only consider positive pieces (player 2)
                    int v = board[x][y];
                    board[x][y] = 0;
                    int tmp = score;
                    score = (score > (minimax(depth - 1, alpha, beta, 1))) ? score : minimax(depth - 1, alpha, beta, 1);
                    board[x][y] = v;
                    beta = (beta < score) ? beta : score;
                    if (beta <= alpha) {
                        return score;
                    }
                }
            }
        }
        return score;
    }
}

int main() { // Main function to test the AI
    printf("Eval: %d\n", evaluate());
    printf("Minimax: %d\n", minimax(MAX_DEPTH, -INF, INF, 1)); // Player 1 (minimizer) starts
    return 0;
}