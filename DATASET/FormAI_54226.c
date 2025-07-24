//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3];

void init_board()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board()
{
    int i, j;
    printf("\n");
    for (i = 0; i < 3; i++) {
        printf(" %c | %c | %c ", board[i][0], board[i][1], board[i][2]);
        if (i != 2) {
            printf("\n---+---+---\n");
        }
    }
    printf("\n");
}

bool is_valid_move(int row, int col)
{
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        return true;
    }
    return false;
}

bool is_game_over()
{
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
    }
    for (j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            return true;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

int evaluate_board()
{
    int score = 0;
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') {
                score = -10;
            } else if (board[i][0] == 'O') {
                score = 10;
            }
        }
    }
    for (j = 0; j < 3; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j]) {
            if (board[0][j] == 'X') {
                score = -10;
            } else if (board[0][j] == 'O') {
                score = 10;
            }
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') {
            score = -10;
        } else if (board[0][0] == 'O') {
            score = 10;
        }
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') {
            score = -10;
        } else if (board[0][2] == 'O') {
            score = 10;
        }
    }
    return score;
}

int minimax(int depth, bool is_maximizing_player)
{
    if (is_game_over()) {
        return evaluate_board();
    }
    if (is_maximizing_player) {
        int best_score = -1000;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(depth + 1, !is_maximizing_player);
                    board[i][j] = ' ';
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        int i, j;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(depth + 1, !is_maximizing_player);
                    board[i][j] = ' ';
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
        return best_score;
    }
}

void make_best_move()
{
    int best_score = -1000;
    int best_row = -1;
    int best_col = -1;
    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(0, false);
                board[i][j] = ' ';
                if (score > best_score) {
                    best_score = score;
                    best_row = i;
                    best_col = j;
                }
            }
        }
    }
    board[best_row][best_col] = 'O';
}

int main()
{
    init_board();
    printf("Welcome to Tic Tac Toe!\n");
    printf("You are playing as X against the computer.\n");
    printf("To make a move, enter the row and column numbers.\n\n");
    print_board();
    while (!is_game_over()) {
        int row, col;
        printf("Enter row number (0-2): ");
        scanf("%d", &row);
        printf("Enter column number (0-2): ");
        scanf("%d", &col);
        if (is_valid_move(row, col)) {
            board[row][col] = 'X';
            if (!is_game_over()) {
                make_best_move();
                printf("Computer made a move:\n");
                print_board();
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    int score = evaluate_board();
    printf("Game over!\n");
    print_board();
    if (score == -10) {
        printf("You won!\n");
    } else if (score == 10) {
        printf("Computer won!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}