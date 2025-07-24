//FormAI DATASET v1.0 Category: Chess AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define BOARD_SIZE 8

int evaluate(int board[BOARD_SIZE][BOARD_SIZE]) {
    int score = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                score += 1; // add 1 point for each pawn
            } else if (board[i][j] == -1) {
                score -= 1; // subtract 1 point for each opponent's pawn
            }
        }
    }
    return score;
}

int minimax(int board[BOARD_SIZE][BOARD_SIZE], int depth, int alpha, int beta, int maximizing_player) {
    if (depth == 0) {
        // end node reached, evaluate the board
        return evaluate(board);
    }

    if (maximizing_player) {
        int max_val = INT_MIN;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 1) {
                    // simulate a move by moving the pawn one square forward
                    int new_board[BOARD_SIZE][BOARD_SIZE];
                    for (int k = 0; k < BOARD_SIZE; k++) {
                        for (int l = 0; l < BOARD_SIZE; l++) {
                            new_board[k][l] = board[k][l];
                        }
                    }
                    new_board[i][j] = 0;
                    new_board[i-1][j] = 1;
                    // call minimax recursively
                    int val = minimax(new_board, depth-1, alpha, beta, 0);
                    max_val = val > max_val ? val : max_val;
                    alpha = alpha > val ? alpha : val;
                    if (beta <= alpha) {
                        // beta cutoff, no need to explore further
                        break;
                    }
                }
            }
        }
        return max_val;
    } else {
        int min_val = INT_MAX;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == -1) {
                    // simulate a move by moving the opponent's pawn one square forward
                    int new_board[BOARD_SIZE][BOARD_SIZE];
                    for (int k = 0; k < BOARD_SIZE; k++) {
                        for (int l = 0; l < BOARD_SIZE; l++) {
                            new_board[k][l] = board[k][l];
                        }
                    }
                    new_board[i][j] = 0;
                    new_board[i+1][j] = -1;
                    // call minimax recursively
                    int val = minimax(new_board, depth-1, alpha, beta, 1);
                    min_val = val < min_val ? val : min_val;
                    beta = beta < val ? beta : val;
                    if (beta <= alpha) {
                        // alpha cutoff, no need to explore further
                        break;
                    }
                }
            }
        }
        return min_val;
    }
}

int choose_move(int board[BOARD_SIZE][BOARD_SIZE]) {
    int best_move = -1;
    int best_val = INT_MIN;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                // simulate a move by moving the pawn one square forward
                int new_board[BOARD_SIZE][BOARD_SIZE];
                for (int k = 0; k < BOARD_SIZE; k++) {
                    for (int l = 0; l < BOARD_SIZE; l++) {
                        new_board[k][l] = board[k][l];
                    }
                }
                new_board[i][j] = 0;
                new_board[i-1][j] = 1;
                // call minimax to evaluate the move
                int val = minimax(new_board, 3, INT_MIN, INT_MAX, 0);
                if (val > best_val) {
                    best_move = i * BOARD_SIZE + j;
                    best_val = val;
                }
            }
        }
    }
    return best_move;
}

int main() {
    // initialize the board, white pawns are 1, black pawns are -1
    int board[BOARD_SIZE][BOARD_SIZE] = {
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
        {1, 1, 1, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    srand(time(NULL)); // seed the random number generator

    int turn = 0; // white goes first
    int game_over = 0;
    while (!game_over) {
        if (turn % 2 == 0) {
            // white's turn, choose a move and update the board
            int move = choose_move(board);
            board[move/BOARD_SIZE][move%BOARD_SIZE] = 0;
            board[(move/BOARD_SIZE)-1][move%BOARD_SIZE] = 1;
            printf("White moved: %c%d to %c%d\n", move%BOARD_SIZE+'a', BOARD_SIZE-(move/BOARD_SIZE), move%BOARD_SIZE+'a', BOARD_SIZE-(move/BOARD_SIZE)-1);
        } else {
            // black's turn, choose a random move and update the board
            int possible_moves[BOARD_SIZE];
            int num_moves = 0;
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == -1) {
                        if (i < BOARD_SIZE-1 && board[i+1][j] == 0) {
                            // pawn can move one square forward
                            possible_moves[num_moves] = i * BOARD_SIZE + j;
                            num_moves++;
                        }
                    }
                }
            }
            if (num_moves == 0) {
                // no possible moves, game over
                printf("Black wins!\n");
                game_over = 1;
                continue;
            }
            int move = possible_moves[rand() % num_moves];
            board[move/BOARD_SIZE][move%BOARD_SIZE] = 0;
            board[(move/BOARD_SIZE)+1][move%BOARD_SIZE] = -1;
            printf("Black moved: %c%d to %c%d\n", move%BOARD_SIZE+'a', BOARD_SIZE-(move/BOARD_SIZE), move%BOARD_SIZE+'a', BOARD_SIZE-(move/BOARD_SIZE)+1);
        }
        turn++;
        if (turn == 2 * BOARD_SIZE) {
            // maximum number of turns reached, game over
            printf("White wins!\n");
            game_over = 1;
        }
    }
    return 0;
}