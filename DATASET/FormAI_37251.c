//FormAI DATASET v1.0 Category: Chess AI ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define KING 1000000         // king value
#define QUEEN 900            // queen value
#define ROOK 500             // rook value
#define BISHOP 330           // bishop value
#define KNIGHT 320           // knight value
#define PAWN 100             // pawn value
#define DEPTH 3              // depth of search
#define INFINITY 1000000000  // a very large number

int chessboard[8][8] = {
    {2, 3, 4, 5, 6, 4, 3, 2},
    {1, 1, 1, 1, 1, 1, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {-1, -1, -1, -1, -1, -1, -1, -1},
    {-2, -3, -4, -5, -6, -4, -3, -2}
};  // starting chessboard

int pawnEval[8][8] = {
    {0, 0, 0, 0, 0, 0, 0, 0},
    {50, 50, 50, 50, 50, 50, 50, 50},
    {10, 10, 20, 30, 30, 20, 10, 10},
    {5, 5, 10, 27, 27, 10, 5, 5},
    {0, 0, 0, 25, 25, 0, 0, 0},
    {5, -5, -10, 0, 0, -10, -5, 5},
    {5, 10, 10, -25, -25, 10, 10, 5},
    {0, 0, 0, 0, 0, 0, 0, 0}
};  // pawn evaluation function

int knightEval[8][8] = {
    {-50, -40, -30, -30, -30, -30, -40, -50},
    {-40, -20, 0, 0, 0, 0, -20, -40},
    {-30, 0, 10, 15, 15, 10, 0, -30},
    {-30, 5, 15, 20, 20, 15, 5, -30},
    {-30, 0, 15, 20, 20, 15, 0, -30},
    {-30, 5, 10, 15, 15, 10, 5, -30},
    {-40, -20, 0, 5, 5, 0, -20, -40},
    {-50, -40, -30, -30, -30, -30, -40, -50}
};  // knight evaluation function

int bishopEval[8][8] = {
    {-20, -10, -10, -10, -10, -10, -10, -20},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 0, 5, 10, 10, 5, 0, -10},
    {-10, 5, 5, 10, 10, 5, 5, -10},
    {-10, 0, 10, 10, 10, 10, 0, -10},
    {-10, 10, 10, 10, 10, 10, 10, -10},
    {-10, 5, 0, 0, 0, 0, 5, -10},
    {-20, -10, -10, -10, -10, -10, -10, -20}
};  // bishop evaluation function

int rookEval[8][8] = {
    {0, 0, 0, 5, 5, 0, 0, 0},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {-5, 0, 0, 0, 0, 0, 0, -5},
    {5, 10, 10, 10, 10, 10, 10, 5},
    {0, 0, 0, 0, 0, 0, 0, 0}
};  // rook evaluation function

int queenEval[8][8] = {
    {-20, -10, -10, -5, -5, -10, -10, -20},
    {-10, 0, 0, 0, 0, 0, 0, -10},
    {-10, 0, 5, 5, 5, 5, 0, -10},
    {-5, 0, 5, 5, 5, 5, 0, -5},
    {0, 0, 5, 5, 5, 5, 0, -5},
    {-10, 5, 5, 5, 5, 5, 0, -10},
    {-10, 0, 5, 0, 0, 0, 0, -10},
    {-20, -10, -10, -5, -5, -10, -10, -20}
};  // queen evaluation function

int kingEval[8][8] = {
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-30, -40, -40, -50, -50, -40, -40, -30},
    {-20, -30, -30, -40, -40, -30, -30, -20},
    {-10, -20, -20, -20, -20, -20, -20, -10},
    {20, 20, 0, 0, 0, 0, 20, 20},
    {20, 30, 10, 0, 0, 10, 30, 20}
};  // king evaluation function

int alphabeta(int depth, int alpha, int beta, int player) {
    int i, j, value;
    if (depth == 0) {
        value = evaluate();
        return (player == 1 ? value : -value);
    }
    if (player == 1) {
        value = -INFINITY;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (chessboard[i][j] > 0) {
                    value = max(value, alphabeta(depth - 1, alpha, beta, -player));
                    alpha = max(alpha, value);
                    if (beta <= alpha)
                        return value;
                }
            }
        }
    } else {
        value = INFINITY;
        for (i = 0; i < 8; i++) {
            for (j = 0; j < 8; j++) {
                if (chessboard[i][j] < 0) {
                    value = min(value, alphabeta(depth - 1, alpha, beta, -player));
                    beta = min(beta, value);
                    if (beta <= alpha)
                        return value;
                }
            }
        }
    }
    return value;
}

int evaluate() {
    int i, j, value = 0;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            switch (abs(chessboard[i][j])) {
                case 1:
                    if (chessboard[i][j] > 0)
                        value += PAWN + pawnEval[i][j];
                    else
                        value -= PAWN + pawnEval[7 - i][j];
                    break;
                case 2:
                    if (chessboard[i][j] > 0)
                        value += KNIGHT + knightEval[i][j];
                    else
                        value -= KNIGHT + knightEval[7 - i][j];
                    break;
                case 3:
                    if (chessboard[i][j] > 0)
                        value += BISHOP + bishopEval[i][j];
                    else
                        value -= BISHOP + bishopEval[7 - i][j];
                    break;
                case 4:
                    if (chessboard[i][j] > 0)
                        value += ROOK + rookEval[i][j];
                    else
                        value -= ROOK + rookEval[7 - i][j];
                    break;
                case 5:
                    if (chessboard[i][j] > 0)
                        value += QUEEN + queenEval[i][j];
                    else
                        value -= QUEEN + queenEval[7 - i][j];
                    break;
                case 6:
                    if (chessboard[i][j] > 0)
                        value += KING + kingEval[i][j];
                    else
                        value -= KING + kingEval[7 - i][j];
                    break;
            }
        }
    }
    return value;
}

int max(int a, int b) {
    return (a > b ? a : b);
}

int min(int a, int b) {
    return (a < b ? a : b);
}

int main() {
    int depth, alpha, beta, player;
    player = 1;  // white is positive
    depth = DEPTH; // set depth
    alpha = -INFINITY;  // initially -infinity
    beta = INFINITY;  // initially infinity
    int besti, bestj, bestvalue, i, j, value;
    bestvalue = -INFINITY;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++) {
            if (chessboard[i][j] > 0) {
                value = alphabeta(depth - 1, alpha, beta, -player);
                if (value > bestvalue) {
                    bestvalue = value;
                    besti = i;
                    bestj = j;
                }
            }
        }
    }
    printf("Best Move: %c%d%c%d\n", bestj + 'a', 8 - besti, 'a' + bestj, 8 - besti - 1);
    return 0;
}