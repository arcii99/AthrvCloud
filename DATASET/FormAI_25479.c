//FormAI DATASET v1.0 Category: Chess AI ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the size of the chessboard
#define BOARD_SIZE 8

// Define the maximun depth of the search tree
#define MAX_DEPTH 3

// Define the scoring values for each piece type
#define KING_VALUE 99999
#define QUEEN_VALUE 900
#define ROOK_VALUE 500
#define BISHOP_VALUE 330
#define KNIGHT_VALUE 320
#define PAWN_VALUE 100

int evaluate(int board[][BOARD_SIZE]);
int minimax(int board[][BOARD_SIZE], int depth, bool maximizingPlayer, int alpha, int beta);
void copy_board(int board[][BOARD_SIZE], int copy[][BOARD_SIZE]);

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {{-2,-3,-4,-5,-6,-4,-3,-2},
                                          {-1,-1,-1,-1,-1,-1,-1,-1},
                                          {0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0},
                                          {0,0,0,0,0,0,0,0},
                                          {1,1,1,1,1,1,1,1},
                                          {2,3,4,5,6,4,3,2}}; // Starting chessboard
    int score = evaluate(board);
    printf("Initial board score: %d\n\n", score);

    int bestMoveScore = -999999;
    int bestMoveStart[2], bestMoveEnd[2];
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] > 0) { // If it's the AI's turn to move
                for(int k=0; k<BOARD_SIZE; k++) {
                    for(int l=0; l<BOARD_SIZE; l++) {
                        if(board[k][l] <= 0) { // If the target square is empty or occupied by an enemy piece
                            int copy[BOARD_SIZE][BOARD_SIZE];
                            copy_board(board, copy);
                            copy[k][l] = copy[i][j];
                            copy[i][j] = 0;
                            int moveScore = minimax(copy, MAX_DEPTH, false, -99999, 99999);
                            if(moveScore > bestMoveScore) {
                                bestMoveScore = moveScore;
                                bestMoveStart[0] = i; bestMoveStart[1] = j;
                                bestMoveEnd[0] = k; bestMoveEnd[1] = l;
                            }
                        }
                    }
                }
            }
        }
    }

    printf("Best move score: %d\n", bestMoveScore);
    printf("Best move: %c%d to %c%d\n", bestMoveStart[1]+97, 8-bestMoveStart[0], bestMoveEnd[1]+97, 8-bestMoveEnd[0]);
}

// Evaluate the current state of the board
int evaluate(int board[][BOARD_SIZE]) {
    int score = 0;
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            switch(board[i][j]) {
                case 1: score += PAWN_VALUE; break;
                case 2: score += KNIGHT_VALUE; break;
                case 3: score += BISHOP_VALUE; break;
                case 4: score += ROOK_VALUE; break;
                case 5: score += QUEEN_VALUE; break;
                case 6: score += KING_VALUE; break;
                case -1: score -= PAWN_VALUE; break;
                case -2: score -= KNIGHT_VALUE; break;
                case -3: score -= BISHOP_VALUE; break;
                case -4: score -= ROOK_VALUE; break;
                case -5: score -= QUEEN_VALUE; break;
                case -6: score -= KING_VALUE; break;
            }
        }
    }
    return score;
}

// Recursively search for the best move using minimax algorithm
int minimax(int board[][BOARD_SIZE], int depth, bool maximizingPlayer, int alpha, int beta) {
    if(depth == 0) {
        return evaluate(board);
    }

    if(maximizingPlayer) {
        int maxScore = -99999;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] > 0) {
                    for(int k=0; k<BOARD_SIZE; k++) {
                        for(int l=0; l<BOARD_SIZE; l++) {
                            if(board[k][l] <= 0) {
                                int copy[BOARD_SIZE][BOARD_SIZE];
                                copy_board(board, copy);
                                copy[k][l] = copy[i][j];
                                copy[i][j] = 0;
                                int score = minimax(copy, depth-1, false, alpha, beta);
                                if(score > maxScore) {
                                    maxScore = score;
                                }
                                if(maxScore > alpha) {
                                    alpha = maxScore;
                                }
                                if(beta <= alpha) {
                                    return maxScore;
                                }
                            }
                        }
                    }
                }
            }
        }
        return maxScore;
    } else {
        int minScore = 99999;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] < 0) {
                    for(int k=0; k<BOARD_SIZE; k++) {
                        for(int l=0; l<BOARD_SIZE; l++) {
                            if(board[k][l] >= 0) {
                                int copy[BOARD_SIZE][BOARD_SIZE];
                                copy_board(board, copy);
                                copy[k][l] = copy[i][j];
                                copy[i][j] = 0;
                                int score = minimax(copy, depth-1, true, alpha, beta);
                                if(score < minScore) {
                                    minScore = score;
                                }
                                if(minScore < beta) {
                                    beta = minScore;
                                }
                                if(beta <= alpha) {
                                    return minScore;
                                }
                            }
                        }
                    }
                }
            }
        }
        return minScore;
    }
}

// Copy one chessboard to another
void copy_board(int board[][BOARD_SIZE], int copy[][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            copy[i][j] = board[i][j];
        }
    }
}