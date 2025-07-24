//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

char board[BOARD_SIZE][BOARD_SIZE];

void reset_board() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void print_board() {
    int i, j;
    printf("   ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    printf("  -----------\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d |", i);
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n");
        printf("  -----------\n");
    }
}

int check_winner() {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
            return 1;
    }
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] != ' ' && board[0][j] == board[1][j] && board[1][j] == board[2][j])
            return 1;
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
        return 1;
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
        return 1;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                return 0;
            }
        }
    }
    return -1;
}

int evaluate(char player) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return 1;
    }
    for (j = 0; j < BOARD_SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player)
            return 1;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return 1;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return 1;
    return 0;
}

int minimax(char player, int depth) {
    int max_score = -2, min_score = 2, score, i, j;
    int winner = check_winner();
    if (winner == 1)
        return evaluate(player);
    else if (winner == -1)
        return 0;
    else if (depth == 0) {
        return 0;
    }
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                if (player == 'X') {
                    score = minimax('O', depth - 1);
                    if (score > max_score) max_score = score;
                }
                else {
                    score = minimax('X', depth - 1);
                    if (score < min_score) min_score = score;
                }
                board[i][j] = ' ';
            }
        }
    }
    return player == 'X' ? max_score : min_score;
}

void make_move(char player) {
    int i, j;
    int max_score = -2, score;
    int move_i, move_j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = player;
                score = minimax(player == 'X' ? 'O' : 'X', 8);
                if (score > max_score) {
                    max_score = score;
                    move_i = i;
                    move_j = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    board[move_i][move_j] = player;
}

int main() {
    reset_board();
    char player = 'X';
    while (check_winner() == 0) {
        if (player == 'X') {
            int i, j;
            printf("Enter your move (row column):");
            scanf("%d %d", &i, &j);	
            if (i >= 0 && i < BOARD_SIZE && j >= 0 && j < BOARD_SIZE && board[i][j] == ' ') {
                board[i][j] = player;
                player = 'O';
            }
            else {
                printf("Invalid move!\n");
            }
        }
        else {
            make_move(player);
            player = 'X';
        }
        print_board();
    }
    int winner = check_winner();
    if (winner == 1) {
        printf("Player %c wins!\n", player == 'X' ? 'O' : 'X');
    }
    else {
        printf("Tie game!\n");
    }
    return 0;
}