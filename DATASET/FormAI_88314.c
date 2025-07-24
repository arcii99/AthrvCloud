//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

/*
* Function to display the Tic Tac Toe board.
*/
void display_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j]);
            if (j != BOARD_SIZE - 1) {
                printf("|");
            }
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

/*
* Function to update the Tic Tac Toe board.
*/
void update_board(char board[BOARD_SIZE][BOARD_SIZE], int row, int col, char symbol) {
    board[row][col] = symbol;
}

/*
* Function to check if a move is valid or not.
*/
int is_move_valid(char board[BOARD_SIZE][BOARD_SIZE], int row, int col) {
    if (row < 0 || row > BOARD_SIZE - 1 || col < 0 || col > BOARD_SIZE - 1) {
        return 0;
    }
    if (board[row][col] != ' ') {
        return 0;
    }
    return 1;
}

/*
* Function to check if a player has won.
*/
int has_won(char board[BOARD_SIZE][BOARD_SIZE], char symbol) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        int row_count = 0;
        int col_count = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == symbol) {
                row_count++;
            }
            if (board[j][i] == symbol) {
                col_count++;
            }
        }
        if (row_count == BOARD_SIZE || col_count == BOARD_SIZE) {
            return 1;
        }
    }
    int diag_count = 0;
    int rev_diag_count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][i] == symbol) {
            diag_count++;
        }
        if (board[i][BOARD_SIZE - i - 1] == symbol) {
            rev_diag_count++;
        }
    }
    if (diag_count == BOARD_SIZE || rev_diag_count == BOARD_SIZE) {
        return 1;
    }
    return 0;
}

/*
* AI logic to determine the best move based on minimax algorithm
*/
int minmax(char board[BOARD_SIZE][BOARD_SIZE], char player, char ai, int depth) {
    if (has_won(board, ai)) {
        return 10 - depth;
    } else if (has_won(board, player)) {
        return depth - 10;
    } else if (depth == BOARD_SIZE * BOARD_SIZE) {
        return 0;
    }
    int best_score = (player == ai) ? -1000 : 1000;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                if (player == ai) {
                    update_board(board, i, j, ai);
                    int score = minmax(board, player, ai, depth + 1);
                    if (score > best_score) {
                        best_score = score;
                    }
                } else {
                    update_board(board, i, j, player);
                    int score = minmax(board, player, ai, depth + 1);
                    if (score < best_score) {
                        best_score = score;
                    }
                }
                update_board(board, i, j, ' ');
            }
        }
    }
    return best_score;
}

/*
* Function to determine the best move
*/
void get_best_move(char board[BOARD_SIZE][BOARD_SIZE], char player, char ai, int *row, int *col) {
    int best_score = -1000;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                update_board(board, i, j, ai);
                int score = minmax(board, player, ai, 0);
                update_board(board, i, j, ' ');
                if (score > best_score) {
                    best_score = score;
                    *row = i;
                    *col = j;
                }
            }
        }
    }
}

/*
* Main function
*/
int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    printf("You will be playing against an AI.\n");
    display_board(board);
    char player = 'X';
    char ai = 'O';
    int turn = 1;
    while (turn <= BOARD_SIZE * BOARD_SIZE) {
        if (turn % 2 != 0) {
            printf("It's your turn! Enter row and column (e.g 1 2): ");
            int row, col;
            scanf("%d %d", &row, &col);
            row--;
            col--;
            if (is_move_valid(board, row, col)) {
                update_board(board, row, col, player);
                turn++;
                if (has_won(board, player)) {
                    printf("Congratulations! You won!\n");
                    display_board(board);
                    return 0;
                }
            } else {
                printf("Invalid move. Please try again.\n");
                continue;
            }
        } else {
            printf("AI's turn...\n");
            int row, col;
            get_best_move(board, player, ai, &row, &col);
            update_board(board, row, col, ai);
            turn++;
            if (has_won(board, ai)) {
                printf("You lost! Better luck next time.\n");
                display_board(board);
                return 0;
            }
        }
        display_board(board);
    }
    printf("It's a tie!\n");
    display_board(board);
    return 0;
}