//FormAI DATASET v1.0 Category: Chess AI ; Style: secure
#include <stdio.h>
#include <stdbool.h>

#define BOARD_SIZE 8

typedef struct {
    int x;
    int y;
} Position;

// Calculates the absolute difference between two integers
int absDiff(int a, int b) {
    if (a > b) {
        return a - b;
    } else {
        return b - a;
    }
}

// Returns true if the given position is inside the chess board
bool isValidPosition(Position p) {
    if (p.x >=0 && p.x < BOARD_SIZE && p.y >=0 && p.y < BOARD_SIZE) {
        return true;
    } else {
        return false;
    }
}

// Returns the manhattan distance between two positions
int manhattanDistance(Position p1, Position p2) {
    return absDiff(p1.x, p2.x) + absDiff(p1.y, p2.y);
}

// Calculates the legal moves for a knight at the given position
void calculateKnightMoves(int board[BOARD_SIZE][BOARD_SIZE], Position p, bool legalMoves[BOARD_SIZE][BOARD_SIZE]) {
    const int KNIGHT_MOVES_X[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    const int KNIGHT_MOVES_Y[] = {1, -1, 2, -2, 2, -2, 1, -1};

    for (int i = 0; i < 8; i++) {
        Position move = {p.x + KNIGHT_MOVES_X[i], p.y + KNIGHT_MOVES_Y[i]};
        if (isValidPosition(move) && (board[move.x][move.y] == 0 || board[move.x][move.y] < board[p.x][p.y])) {
            legalMoves[move.x][move.y] = true;
        }
    }
}

// Calculates the best move for the given player using the minimax algorithm with alpha-beta pruning
Position calculateBestMove(int board[BOARD_SIZE][BOARD_SIZE], int player, int depth, int alpha, int beta) {
    if (depth == 0) {
        return (Position) {-1, -1};
    }

    int bestScore = (player == 1) ? -1000000 : 1000000;
    Position bestMove = {-1, -1};

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == player) {
                bool legalMoves[BOARD_SIZE][BOARD_SIZE] = {false};

                if (player == 1) {
                    calculateKnightMoves(board, (Position) {i, j}, legalMoves);
                } else {
                    // TODO: Implement code for the black player
                }

                for (int x = 0; x < BOARD_SIZE; x++) {
                    for (int y = 0; y < BOARD_SIZE; y++) {
                        if (legalMoves[x][y]) {
                            int nextBoard[BOARD_SIZE][BOARD_SIZE];
                            for (int a = 0; a < BOARD_SIZE; a++) {
                                for (int b = 0; b < BOARD_SIZE; b++) {
                                    nextBoard[a][b] = board[a][b];
                                }
                            }

                            nextBoard[x][y] = player;
                            nextBoard[i][j] = 0;

                            int score = (player == 1) ? manhattanDistance((Position) {x, y}, (Position) {0, BOARD_SIZE-1}) 
                                                     : -manhattanDistance((Position) {x, y}, (Position) {0, 0});

                            if (score >= bestScore && player == 1) {
                                bestScore = score;
                                bestMove = (Position) {x, y};
                            }

                            if (score <= bestScore && player == 2) {
                                bestScore = score;
                                bestMove = (Position) {x, y};
                            }

                            if (player == 1) {
                                alpha = (alpha > score) ? alpha : score;
                            } else {
                                beta = (beta < score) ? beta : score;
                            }

                            if (beta <= alpha) {
                                return bestMove;
                            }

                            Position nextMove = calculateBestMove(nextBoard, (player == 1) ? 2 : 1, depth - 1, alpha, beta);

                            if (player == 1 && manhattanDistance(nextMove, (Position) {0, BOARD_SIZE-1}) > bestScore) {
                                bestScore = manhattanDistance(nextMove, (Position) {0, BOARD_SIZE-1});
                                bestMove = (Position) {x, y};
                            } else if (player == 2 && -manhattanDistance(nextMove, (Position) {0, 0}) < bestScore) {
                                bestScore = -manhattanDistance(nextMove, (Position) {0, 0});
                                bestMove = (Position) {x, y};
                            }

                            if (player == 1) {
                                alpha = (alpha > bestScore) ? alpha : bestScore;
                            } else {
                                beta = (beta < bestScore) ? beta : bestScore;
                            }

                            if (beta <= alpha) {
                                return bestMove;
                            }
                        }
                    }
                }
            }
        }
    }

    return bestMove;
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
    };

    Position bestMove = calculateBestMove(board, 1, 2, -1000000, 1000000);

    printf("Best move: (%d, %d)\n", bestMove.x, bestMove.y);

    return 0;
}