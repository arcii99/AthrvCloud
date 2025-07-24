//FormAI DATASET v1.0 Category: Chess AI ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int evaluateBoard(int board[BOARD_SIZE][BOARD_SIZE], int depth, int maxPlayer);
int miniMax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int maxPlayer, int alpha, int beta);

// main function
int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {-1, -2, -3, -4, -5, -3, -2, -1},
        {-6, -6, -6, -6, -6, -6, -6, -6},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {6, 6, 6, 6, 6, 6, 6, 6},
        {1, 2, 3, 4, 5, 3, 2, 1},
    };
    int bestMove = miniMax(board, 3, 1, -1000, 1000);
    printf("Best move: %d\n", bestMove);
    return 0;
}

// evaluates the current state of the board
int evaluateBoard(int board[BOARD_SIZE][BOARD_SIZE], int depth, int maxPlayer) {
    int pawnValue = 1;
    int knightValue = 3;
    int bishopValue = 3;
    int rookValue = 5;
    int queenValue = 9;
    int kingValue = 100;
    int playerScore = 0;
    int opponentScore = 0;
    int i, j;
    for(i = 0; i < BOARD_SIZE; i++) {
        for(j = 0; j < BOARD_SIZE; j++) {
            int piece = board[i][j];
            if(piece == 0) {
                continue;
            }
            if(piece == 1) { // pawn
                if(maxPlayer == 1) {
                    playerScore += pawnValue;
                } else {
                    opponentScore += pawnValue;
                }
            } else if(piece == 2) { // knight
                if(maxPlayer == 1) {
                    playerScore += knightValue;
                } else {
                    opponentScore += knightValue;
                }
            } else if(piece == 3) { // bishop
                if(maxPlayer == 1) {
                    playerScore += bishopValue;
                } else {
                    opponentScore += bishopValue;
                }
            } else if(piece == 4) { // rook
                if(maxPlayer == 1) {
                    playerScore += rookValue;
                } else {
                    opponentScore += rookValue;
                }
            } else if(piece == 5) { // queen
                if(maxPlayer == 1) {
                    playerScore += queenValue;
                } else {
                    opponentScore += queenValue;
                }
            } else if(piece == 6) { // king
                if(maxPlayer == 1) {
                    playerScore += kingValue;
                } else {
                    opponentScore += kingValue;
                }
            } else if(piece == -1) { // black pawn
                if(maxPlayer == 2) {
                    playerScore += pawnValue;
                } else {
                    opponentScore += pawnValue;
                }
            } else if(piece == -2) { // black knight
                if(maxPlayer == 2) {
                    playerScore += knightValue;
                } else {
                    opponentScore += knightValue;
                }
            } else if(piece == -3) { // black bishop
                if(maxPlayer == 2) {
                    playerScore += bishopValue;
                } else {
                    opponentScore += bishopValue;
                }
            } else if(piece == -4) { // black rook
                if(maxPlayer == 2) {
                    playerScore += rookValue;
                } else {
                    opponentScore += rookValue;
                }
            } else if(piece == -5) { // black queen
                if(maxPlayer == 2) {
                    playerScore += queenValue;
                } else {
                    opponentScore += queenValue;
                }
            } else if(piece == -6) { // black king
                if(maxPlayer == 2) {
                    playerScore += kingValue;
                } else {
                    opponentScore += kingValue;
                }
            }
        }
    }
    if(maxPlayer == 1) {
        return playerScore - opponentScore;
    } else {
        return opponentScore - playerScore;
    }
}

// uses the minimax algorithm to determine the best move for the current player
int miniMax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int maxPlayer, int alpha, int beta) {
    if(depth == 0) {
        return evaluateBoard(board, depth, maxPlayer);
    }
    int i, j;
    int bestScore;
    if(maxPlayer == 1) { // white player (maximizer)
        bestScore = -1000;
        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] <= 0) { // skip positions with black pieces or empty positions
                    continue;
                }
                int temp = board[i][j];
                board[i][j] = 0;
                int tempScore = evaluateBoard(board, depth, maxPlayer);
                int score = miniMax(board, depth - 1, 2, alpha, beta);
                if(score > bestScore) {
                    bestScore = score;
                }
                alpha = alpha > score ? alpha : score;
                board[i][j] = temp;
                if(beta <= alpha) { // alpha-beta pruning
                    break;
                }
            }
        }
    } else { // black player (minimizer)
        bestScore = 1000;
        for(i = 0; i < BOARD_SIZE; i++) {
            for(j = 0; j < BOARD_SIZE; j++) {
                if(board[i][j] >= 0) { // skip positions with white pieces or empty positions
                    continue;
                }
                int temp = board[i][j];
                board[i][j] = 0;
                int tempScore = evaluateBoard(board, depth, maxPlayer);
                int score = miniMax(board, depth - 1, 1, alpha, beta);
                if(score < bestScore) {
                    bestScore = score;
                }
                beta = beta < score ? beta : score;
                board[i][j] = temp;
                if(beta <= alpha) { // alpha-beta pruning
                    break;
                }
            }
        }
    }
    return bestScore;
}