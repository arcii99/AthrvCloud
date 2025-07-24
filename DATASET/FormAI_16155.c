//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: modular
#include <stdio.h>
#include <stdlib.h>

// Global Variables
char board[3][3];
char player = 'X';
char computer = 'O';

// Function Declarations
void initialize_board();
void display_board();
int check_for_winner();
int minimax(int depth, int isMax);
int get_best_move();

// Function Definitions
void initialize_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
}

void display_board() {
    printf("\nTic Tac Toe Game:\n\n");
    printf("   0   1   2\n");
    printf("0  %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("  ---|---|---\n");
    printf("1  %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("  ---|---|---\n");
    printf("2  %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
}

int check_for_winner() {
    // Check Rows for Winner
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == player) {
                return -1;
            } else if (board[i][0] == computer) {
                return 1;
            }
        }
    }
    // Check Columns for Winner
    for (int j = 0; j < 3; j++) {
        if (board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == player) {
                return -1;
            } else if (board[0][j] == computer) {
                return 1;
            }
        }
    }
    // Check Diagonals for Winner
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == player) {
            return -1;
        } else if (board[0][0] == computer) {
            return 1;
        }
    }
    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        if (board[2][0] == player) {
            return -1;
        } else if (board[2][0] == computer) {
            return 1;
        }
    }
    return 0;
}

int minimax(int depth, int isMax) {
    int score = check_for_winner();
    if (score == 1) {
        return score;
    }
    if (score == -1) {
        return score;
    }
    if (depth == 9) {
        return 0;
    }
    if (isMax) {
        int best = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = computer;
                    best = fmax(best, minimax(depth+1, !isMax));
                    board[i][j] = '-';
                }
            }
        }
        return best;
    } else {
        int best = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = player;
                    best = fmin(best, minimax(depth+1, !isMax));
                    board[i][j] = '-';
                }
            }
        }
        return best;
    }
}

int get_best_move() {
    int bestValue = -1000;
    int bestRow = -1;
    int bestCol = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = computer;
                int moveValue = minimax(0, 0);
                board[i][j] = '-';
                if (moveValue > bestValue) {
                    bestRow = i;
                    bestCol = j;
                    bestValue = moveValue;
                }
            }
        }
    }
    return (10*bestRow) + bestCol;
}

// Main Function
int main() {
    initialize_board();
    display_board();
    printf("\nComputer plays %c, You play %c\n\n", computer, player);
    for (int i = 0; i < 9; i++) {
        if (i % 2 == 0) {
            int move;
            printf("Enter a row and column number (0-2) separated by a space: ");
            scanf("%d", &move);
            int row = move / 10;
            int col = move % 10;
            if (board[row][col] == '-') {
                board[row][col] = player;
            } else {
                printf("Invalid Move\n");
                i--;
                continue;
            }
        } else {
            int move = get_best_move();
            int row = move / 10;
            int col = move % 10;
            board[row][col] = computer;
            printf("Computer Moves to (%d, %d)\n", row, col);
        }
        display_board();
        int winner = check_for_winner();
        if (winner == -1) {
            printf("\nCongratulations! You win!\n");
            return 0;
        } else if (winner == 1) {
            printf("\nGame Over! Computer Wins!\n");
            return 0;
        } else if (i == 8) {
            printf("\nGame Over! It's a Draw!\n");
            return 0;
        }
    }
    return 0;
}