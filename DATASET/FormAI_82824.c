//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

char board[3][3];
char player = 'X';

void print_board() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        return 0;
    }
    if (board[row][col] != '_') {
        return 0;
    }
    return 1;
}

int check_winner() {
    int i, j;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '_') {
            return 1;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '_') {
            return 1;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '_') {
        return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '_') {
        return 1;
    }
    return 0;
}

int evaluate_move(int row, int col, char symbol) {
    board[row][col] = symbol;
    if (check_winner()) {
        board[row][col] = '_';
        if (symbol == player) {
            return -1;
        }
        return 1;
    }
    int i, j;
    int is_full = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                is_full = 0;
                break;
            }
        }
        if (!is_full) {
            break;
        }
    }
    if (is_full) {
        board[row][col] = '_';
        return 0;
    }
    int best_score;
    if (symbol == player) {
        best_score = -1000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    int score = evaluate_move(i, j, 'O');
                    if (score > best_score) {
                        best_score = score;
                    }
                }
            }
        }
    } else {
        best_score = 1000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '_') {
                    int score = evaluate_move(i, j, 'X');
                    if (score < best_score) {
                        best_score = score;
                    }
                }
            }
        }
    }
    board[row][col] = '_';
    return best_score;
}

void computer_move() {
    int i, j;
    int best_score = -1000;
    int best_move_i = -1;
    int best_move_j = -1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '_') {
                int score = evaluate_move(i, j, 'O');
                if (score > best_score) {
                    best_score = score;
                    best_move_i = i;
                    best_move_j = j;
                }
            }
        }
    }
    board[best_move_i][best_move_j] = 'O';
    printf("Computer played at (%d, %d)\n", best_move_i + 1, best_move_j + 1);
}

int main() {
    int row, col;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = '_';
        }
    }
    printf("Welcome to Tic Tac Toe!\n");
    printf("The coordinates go from row 1 to row 3 and column 1 to column 3.\n");
    printf("Here is the initial board:\n");
    print_board();
    while (!check_winner()) {
        if (player == 'X') {
            printf("Player X, enter a row number (1-3): ");
            scanf("%d", &row);
            printf("Player X, enter a column number (1-3): ");
            scanf("%d", &col);
            row--;
            col--;
            if (is_valid_move(row, col)) {
                board[row][col] = player;
                player = 'O';
            } else {
                printf("That is not a valid move. Try again.\n");
            }
        } else {
            printf("Computer is thinking...\n");
            computer_move();
            player = 'X';
        }
        printf("\n");
        print_board();
    }
    if (player == 'X') {
        printf("Congratulations! You won!\n");
    } else {
        printf("Sorry, the computer won. Better luck next time!\n");
    }
    return 0;
}