//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char player = 'X';
char computer = 'O';

void draw_board(char board[3][3]) {
    printf("\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
}

int evaluate(char board[3][3]) {
    int i;
    for (i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == player) return 10;
            else if (board[i][0] == computer) return -10;
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == player) return 10;
            else if (board[0][i] == computer) return -10;
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == player) return 10;
        else if (board[0][0] == computer) return -10;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == player) return 10;
        else if (board[0][2] == computer) return -10;
    }
    return 0;
}

int minimax(char board[3][3], int depth, int is_maximizing) {
    int score = evaluate(board);
    if (score == 10 || score == -10) return score;
    if (depth == 0) return 0;
    int i, j;
    if (is_maximizing) {
        int best_score = -1000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = player;
                    int current_score = minimax(board, depth - 1, 0);
                    board[i][j] = '-';
                    if (current_score > best_score) best_score = current_score;
                }
            }
        }
        return best_score;
    } else {
        int best_score = 1000;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[i][j] == '-') {
                    board[i][j] = computer;
                    int current_score = minimax(board, depth - 1, 1);
                    board[i][j] = '-';
                    if (current_score < best_score) best_score = current_score;
                }
            }
        }
        return best_score;
    }
}

void computer_move(char board[3][3]) {
    int i, j;
    int best_score = -1000;
    int move_i = -1, move_j = -1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (board[i][j] == '-') {
                board[i][j] = player;
                int current_score = minimax(board, 5, 0);
                board[i][j] = '-';
                if (current_score > best_score) {
                    best_score = current_score;
                    move_i = i;
                    move_j = j;
                }
            }
        }
    }
    board[move_i][move_j] = computer;
}

int main() {
    char board[3][3];
    int i, j;
    srand(time(NULL));
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            board[i][j] = '-';
        }
    }
    draw_board(board);
    while (1) {
        printf("Enter row and column (1-3), separated by space: ");
        int row, col;
        scanf("%d %d", &row, &col);
        if (row < 1 || row > 3 || col < 1 || col > 3) {
            printf("Invalid input.\n");
            continue;
        }
        if (board[row - 1][col - 1] != '-') {
            printf("That cell is already occupied.\n");
            continue;
        }
        board[row - 1][col - 1] = player;
        draw_board(board);
        int score = evaluate(board);
        if (score == 10) {
            printf("You win!\n");
            break;
        }
        if (score == 0) {
            int n_empty = 0;
            for (i = 0; i < 3; i++) {
                for (j = 0; j < 3; j++) {
                    if (board[i][j] == '-') n_empty++;
                }
            }
            if (n_empty == 0) {
                printf("Draw.\n");
                break;
            }
        }
        computer_move(board);
        draw_board(board);
        score = evaluate(board);
        if (score == -10) {
            printf("Computer wins!\n");
            break;
        }
    }
    return 0;
}