//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 3

int board[SIZE][SIZE] = {0};
int player = 1;
int computer = -1;

void display_board() {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 1) {
                printf("X ");
            } else if (board[i][j] == -1) {
                printf("O ");
            } else {
                printf("- ");
            }
        }
        printf("\n");
    }
}

int check_win() {
    // Check rows
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return board[i][0];
        }
    }

    // Check columns
    for (int i = 0; i < SIZE; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return board[0][i];
        }
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return board[0][0];
    }

    if (board[2][0] == board[1][1] && board[1][1] == board[0][2]) {
        return board[2][0];
    }

    return 0;
}

int minimax(int depth, int current_player) {
    int score;
    int max_score = -2;
    int min_score = 2;

    if (check_win() == computer) {
        return 1;
    }

    if (check_win() == player) {
        return -1;
    }

    if (depth == 0) {
        return 0;
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = current_player;
                if (current_player == computer) {
                    score = minimax(depth - 1, player);
                    if (score > max_score) {
                        max_score = score;
                    }
                } else {
                    score = minimax(depth - 1, computer);
                    if (score < min_score) {
                        min_score = score;
                    }
                }
                board[i][j] = 0;
            }
        }
    }

    if (current_player == computer) {
        return max_score;
    } else {
        return min_score;
    }
}

void computer_move() {
    int best_score = -2;
    int row, col;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = computer;
                int score = minimax(6, player);
                board[i][j] = 0;

                if (score > best_score) {
                    best_score = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    board[row][col] = computer;
    printf("Computer played (row, col): %d %d\n", row+1, col+1);
}

int main() {
    srand(time(NULL));
    printf("---------------------\n");
    printf("Welcome to Tic Tac Toe\n");
    printf("---------------------\n");

    int turn = rand() % 2;
    if (turn == 0) {
        printf("Computer goes first!\n");
        computer_move();
    } else {
        printf("You go first!\n");
    }

    while (1) {
        display_board();
        int row, col;
        printf("Enter row and column (1-3): ");
        scanf("%d %d", &row, &col);
        if (board[row-1][col-1] != 0) {
            printf("Invalid move! Try again.\n");
            continue;
        }
        board[row-1][col-1] = player;
        if (check_win() == player) {
            printf("Congratulations! You won!\n");
            break;
        }
        if (check_win() == -1) {
            printf("Oops! You lost!\n");
            break;
        }
        computer_move();
        if (check_win() == player) {
            printf("Congratulations! You won!\n");
            break;
        }
        if (check_win() == -1) {
            printf("Oops! You lost!\n");
            break;
        }
    }

    return 0;
}