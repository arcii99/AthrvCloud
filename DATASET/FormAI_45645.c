//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
}

void print_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

bool is_move_valid(int row, int col) {
    if (row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == '-') {
        return true;
    }
    return false;
}

bool check_win(char player) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
            return true;
        }
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
            return true;
        }
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
        return true;
    }
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
        return true;
    }
    return false;
}

int minimax(bool is_maximizing) {
    if (check_win('O')) {
        return 1;
    }
    if (check_win('X')) {
        return -1;
    }
    bool is_board_full = true;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                is_board_full = false;
            }
        }
    }
    if (is_board_full) {
        return 0;
    }
    if (is_maximizing) {
        int best_score = -1000000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = 'O';
                    int score = minimax(false);
                    board[i][j] = '-';
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000000;
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = 'X';
                    int score = minimax(true);
                    board[i][j] = '-';
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

void make_move() {
    int best_score = -1000000;
    int row = -1;
    int col = -1;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == '-') {
                board[i][j] = 'O';
                int score = minimax(false);
                board[i][j] = '-';
                if (score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }
    board[row][col] = 'O';
}

int main() {
    initialize_board();
    while (true) {
        print_board();
        int row;
        int col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        row--;
        col--;
        if (is_move_valid(row, col)) {
            board[row][col] = 'X';
            if (check_win('X')) {
                print_board();
                printf("You win!\n");
                break;
            }
            make_move();
            if (check_win('O')) {
                print_board();
                printf("Computer wins!\n");
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}