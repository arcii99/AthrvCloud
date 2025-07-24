//FormAI DATASET v1.0 Category: Chess engine ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int minimax(int depth, int alpha, int beta, int player) {
    if (depth == 0) {
        int score = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == player) {
                    score++;
                } else if (board[i][j] == -player) {
                    score--;
                }
            }
        }
        return score;
    }
    if (player == 1) {
        int best_score = -9999;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = player;
                    best_score = max(best_score, minimax(depth-1, alpha, beta, -player));
                    board[i][j] = 0;
                    alpha = max(alpha, best_score);
                    if (alpha >= beta) {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 9999;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == 0) {
                    board[i][j] = player;
                    best_score = min(best_score, minimax(depth-1, alpha, beta, -player));
                    board[i][j] = 0;
                    beta = min(beta, best_score);
                    if (beta <= alpha) {
                        return best_score;
                    }
                }
            }
        }
        return best_score;
    }
}

void print_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 1) {
                printf("x ");
            } else if (board[i][j] == -1) {
                printf("o ");
            } else {
                printf("_ ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void player_move() {
    int row, col;
    do {
        printf("Enter row and column of your move (e.g. 0 0): ");
        scanf("%d %d", &row, &col);
    } while (board[row][col] != 0);
    board[row][col] = 1;
}

void computer_move() {
    int best_score = -9999;
    int best_row = -1;
    int best_col = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = -1;
                int score = minimax(5, -9999, 9999, 1);
                board[i][j] = 0;
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    board[best_row][best_col] = -1;
}

int main() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
    while (1) {
        print_board();
        player_move();
        if (minimax(5, -9999, 9999, -1) == -1) {
            printf("You win!\n");
            break;
        }
        computer_move();
        if (minimax(5, -9999, 9999, 1) == 1) {
            printf("Computer wins!\n");
            break;
        }
    }
    return 0;
}