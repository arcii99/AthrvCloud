//FormAI DATASET v1.0 Category: Chess AI ; Style: complete
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 4

char board[BOARD_SIZE][BOARD_SIZE];
int score[2];

int evaluate_board() {
    int white_score = 0;
    int black_score = 0;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            // Determine score for white pieces
            if (board[i][j] == 'P') {
                white_score += 1;
            } else if (board[i][j] == 'N' || board[i][j] == 'B') {
                white_score += 3;
            } else if (board[i][j] == 'R') {
                white_score += 5;
            } else if (board[i][j] == 'Q') {
                white_score += 9;
            }

            // Determine score for black pieces
            if (board[i][j] == 'p') {
                black_score += 1;
            } else if (board[i][j] == 'n' || board[i][j] == 'b') {
                black_score += 3;
            } else if (board[i][j] == 'r') {
                black_score += 5;
            } else if (board[i][j] == 'q') {
                black_score += 9;
            }
        }
    }

    score[0] = white_score;
    score[1] = black_score;

    // Determine who is winning based on score
    if (white_score > black_score) {
        return 1;
    } else if (black_score > white_score) {
        return -1;
    } else return 0;
}

int miniMax(int depth, int alpha, int beta, int isMaxPlayer) {
    if (depth == MAX_DEPTH) {
        return evaluate_board();
    }

    if (isMaxPlayer) {
        int value = -10000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ' || board[i][j] == '.' || board[i][j] == '-') {
                    continue;
                }

                char piece = board[i][j];
                char temp = board[i][j];
                board[i][j] = ' ';
                int prev_score = score[0];
                int val = miniMax(depth+1, alpha, beta, !isMaxPlayer);
                board[i][j] = temp;
                score[0] = prev_score;
                value = (value > val) ? value : val;
                alpha = (alpha > value) ? alpha : value;
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return value;
    } else {
        int value = 10000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == ' ' || board[i][j] == '.' || board[i][j] == '-') {
                    continue;
                }

                char piece = board[i][j];
                char temp = board[i][j];
                board[i][j] = ' ';
                int prev_score = score[1];
                int val = miniMax(depth+1, alpha, beta, !isMaxPlayer);
                board[i][j] = temp;
                score[1] = prev_score;
                value = (value < val) ? value : val;
                beta = (beta < value) ? beta : value;
                if (beta <= alpha) {
                    break;
                }
            }
        }
        return value;
    }
}

int main() {
    // Initialize board
    char pieces[8] = {'R', 'N', 'B', 'Q', 'K', 'B', 'N', 'R'};
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (i == 0 || i == BOARD_SIZE - 1) {
                board[i][j] = pieces[j];
            } else if (i == 1) {
                board[i][j] = 'P';
            } else if (i == BOARD_SIZE - 2) {
                board[i][j] = 'p';
            } else {
                board[i][j] = ' ';
            }
        }
    }

    int isMaxPlayer = 1;
    int best_move = -1;
    int best_val = -10000;

    // Perform MiniMax with alpha-beta pruning
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ' || board[i][j] == '.' || board[i][j] == '-') {
                continue;
            }

            char piece = board[i][j];
            char temp = board[i][j];
            board[i][j] = ' ';
            int prev_score = isMaxPlayer ? score[0] : score[1];
            int val = miniMax(0, -10000, 10000, !isMaxPlayer);
            board[i][j] = temp;
            if (isMaxPlayer && val > best_val) {
                best_move = i*BOARD_SIZE + j;
                best_val = val;
            } else if (!isMaxPlayer && val < best_val) {
                best_move = i*BOARD_SIZE + j;
                best_val = val;
            }
            isMaxPlayer = !isMaxPlayer;
        }
    }

    printf("Best move: %d\n", best_move);

    return 0;
}