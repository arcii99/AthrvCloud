//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

void show_board(int board[SIZE][SIZE]);
int check_winner(int board[SIZE][SIZE], int player);
int minimax(int board[SIZE][SIZE], int depth, int player);
int ai_move(int board[SIZE][SIZE], int player);

int main() {
    int board[SIZE][SIZE] = {{0}};

    int player = 1;
    int winner = 0;
    int move_count = 0;

    printf("Welcome to Tic Tac Toe!\n\n");

    show_board(board);

    while (!winner && move_count < SIZE*SIZE) {
        int row, col;

        if (player == 1) {
            printf("Player 1's turn:\n");
            printf("Enter row [1-3]: ");
            scanf("%d", &row);
            printf("Enter col [1-3]: ");
            scanf("%d", &col);

            if (board[row-1][col-1]) {
                printf("Invalid move!\n");
                continue;
            }
            board[row-1][col-1] = 1;
        } else {
            printf("AI's turn:\n");
            ai_move(board, player);
        }

        show_board(board);

        winner = check_winner(board, player);
        player = (player == 1) ? 2 : 1;
        move_count++;
    }

    if (winner) {
        printf("Player %d is the winner!\n", winner);
    } else {
        printf("It's a tie!\n");
    }

    return 0;
}

/* Displays the current state of the board */
void show_board(int board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == 2) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

/* Checks if the given player has won */
int check_winner(int board[SIZE][SIZE], int player) {
    int i, j;

    /* Check rows */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != player) {
                break;
            }
        }
        if (j == SIZE) {
            return player;
        }
    }

    /* Check columns */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[j][i] != player) {
                break;
            }
        }
        if (j == SIZE) {
            return player;
        }
    }

    /* Check diagonal */
    for (i = 0; i < SIZE; i++) {
        if (board[i][i] != player) {
            break;
        }
    }
    if (i == SIZE) {
        return player;
    }

    /* Check reverse diagonal */
    for (i = 0; i < SIZE; i++) {
        if (board[i][SIZE-i-1] != player) {
            break;
        }
    }
    if (i == SIZE) {
        return player;
    }

    return 0;
}

/* Evaluates the current state of the board for the given player */
int evaluate(int board[SIZE][SIZE], int player) {
    int i, j;

    /* Check rows */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] != player) {
                break;
            }
        }
        if (j == SIZE) {
            return 1;
        }
    }

    /* Check columns */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[j][i] != player) {
                break;
            }
        }
        if (j == SIZE) {
            return 1;
        }
    }

    /* Check diagonal */
    for (i = 0; i < SIZE; i++) {
        if (board[i][i] != player) {
            break;
        }
    }
    if (i == SIZE) {
        return 1;
    }

    /* Check reverse diagonal */
    for (i = 0; i < SIZE; i++) {
        if (board[i][SIZE-i-1] != player) {
            break;
        }
    }
    if (i == SIZE) {
        return 1;
    }

    return 0;
}

/* Implements the minimax algorithm for AI move selection */
int minimax(int board[SIZE][SIZE], int depth, int player) {
    int i, j, score;
    int max_score = -2;
    int min_score = 2;

    if (depth == 0 || check_winner(board, 1) || check_winner(board, 2)) {
        return evaluate(board, 2);
    }

    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = player;

                score = minimax(board, depth-1, (player == 1) ? 2 : 1);

                if (player == 2) { /* AI seeks to maximize the score */
                    if (score > max_score) {
                        max_score = score;
                    }
                } else { /* Player seeks to minimize the score */
                    if (score < min_score) {
                        min_score = score;
                    }
                }

                board[i][j] = 0; /* Undo move */
            }
        }
    }

    return (player == 2) ? max_score : min_score;
}

/* Chooses an AI move */
int ai_move(int board[SIZE][SIZE], int player) {
    int i, j, score;
    int best_row = -1;
    int best_col = -1;
    int max_score = -2;

    /* Choose the first available move if no board positions are marked */
    if (!board[SIZE/2][SIZE/2]) {
        board[SIZE/2][SIZE/2] = player;
        return;
    }

    /* Use minimax to evaluate all possible moves */
    for (i = 0; i < SIZE; i++) {
        for (j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = player;

                score = minimax(board, 8, (player == 1) ? 2 : 1);

                if (score > max_score) {
                    max_score = score;
                    best_row = i;
                    best_col = j;
                }

                board[i][j] = 0; /* Undo move */
            }
        }
    }

    board[best_row][best_col] = player;
}