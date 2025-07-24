//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3
#define PLAYER_TOKEN 'X'
#define AI_TOKEN 'O'
#define EMPTY_TOKEN ' '

char board[BOARD_SIZE][BOARD_SIZE];

int evaluate_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        // Check rows
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == PLAYER_TOKEN) {
                return -10;
            } else if (board[i][0] == AI_TOKEN) {
                return 10;
            }
        }
        // Check columns
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == PLAYER_TOKEN) {
                return -10;
            } else if (board[0][i] == AI_TOKEN) {
                return 10;
            }
        }
    }
    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == PLAYER_TOKEN) {
            return -10;
        } else if (board[0][0] == AI_TOKEN) {
            return 10;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == PLAYER_TOKEN) {
            return -10;
        } else if (board[0][2] == AI_TOKEN) {
            return 10;
        }
    }
    // No winner yet
    return 0;
}

int minimax(int depth, int is_max_player) {
    int score = evaluate_board();
    if (score == 10 || score == -10) {
        // Someone has won
        return score;
    }
    if (depth == 0) {
        // Board is full
        return 0;
    }

    if (is_max_player) {
        int best_score = -1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == EMPTY_TOKEN) {
                    board[i][j] = AI_TOKEN;
                    int current_score = minimax(depth - 1, !is_max_player);
                    board[i][j] = EMPTY_TOKEN;
                    if (current_score > best_score) {
                        best_score = current_score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == EMPTY_TOKEN) {
                    board[i][j] = PLAYER_TOKEN;
                    int current_score = minimax(depth - 1, !is_max_player);
                    board[i][j] = EMPTY_TOKEN;
                    if (current_score < best_score) {
                        best_score = current_score;
                    }
                }
            }
        }
        return best_score;
    }
}

void make_best_move() {
    int best_score = -1000;
    int best_row = -1;
    int best_col = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == EMPTY_TOKEN) {
                board[i][j] = AI_TOKEN;
                int current_score = minimax(5, 0);
                board[i][j] = EMPTY_TOKEN;
                if (current_score > best_score) {
                    best_score = current_score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    board[best_row][best_col] = AI_TOKEN;
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("| ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    int player_turn = 1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_TOKEN;
        }
    }
    printf("Welcome to Tic Tac Toe! You are playing as X and the AI is playing as O.\n");
    while (evaluate_board() == 0) {
        if (player_turn) {
            int row, col;
            printf("Enter a row (1-3) and column (1-3) to place your token: ");
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != EMPTY_TOKEN) {
                printf("Invalid move, try again.\n");
            } else {
                board[row][col] = PLAYER_TOKEN;
                player_turn = 0;
            }
        } else {
            printf("AI is thinking...\n");
            make_best_move();
            player_turn = 1;
        }
        print_board();
    }
    if (evaluate_board() == 10) {
        printf("AI wins!\n");
    } else if (evaluate_board() == -10) {
        printf("Player wins!\n");
    } else {
        printf("It's a draw!\n");
    }
    return 0;
}