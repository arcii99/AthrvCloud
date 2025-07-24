//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define WINNING_LINES 8

int board[BOARD_SIZE][BOARD_SIZE];

void initialize_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void display_board() {
    printf("\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf(" ");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c ", board[i][j] == 1 ? 'X' : board[i][j] == -1 ? 'O' : ' ');
            if (j != BOARD_SIZE - 1) printf("|");
        }
        printf("\n");
        if (i != BOARD_SIZE - 1) {
            printf("-----------\n");
        }
    }
    printf("\n");
}

int is_valid_move(int row, int col) {
    return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE && board[row][col] == 0;
}

int has_won(int player) {
    int sum = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        sum = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            sum += board[i][j];
        }
        if (sum == player * BOARD_SIZE) return 1;
    }

    for (int j = 0; j < BOARD_SIZE; j++) {
        sum = 0;
        for (int i = 0; i < BOARD_SIZE; i++) {
            sum += board[i][j];
        }
        if (sum == player * BOARD_SIZE) return 1;
    }

    sum = 0;
    for (int i = 0, j = 0; i < BOARD_SIZE && j < BOARD_SIZE; i++, j++) {
        sum += board[i][j];
    }
    if (sum == player * BOARD_SIZE) return 1;

    sum = 0;
    for (int i = 0, j = BOARD_SIZE - 1; i < BOARD_SIZE && j >= 0; i++, j--) {
        sum += board[i][j];
    }
    if (sum == player * BOARD_SIZE) return 1;

    return 0;
}

int evaluate_board() {
    if (has_won(1)) return 10;
    else if (has_won(-1)) return -10;
    else return 0;
}

int minimax(int depth, int is_maximizing_player) {
    int score = evaluate_board();
    if (score == 10 || score == -10 || depth == 0) return score;

    int best_score = is_maximizing_player ? -100 : 100;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = is_maximizing_player ? 1 : -1;
                int current_score = minimax(depth - 1, !is_maximizing_player);
                board[i][j] = 0;

                if (is_maximizing_player) {
                    if (current_score > best_score) {
                        best_score = current_score;
                    }
                } else {
                    if (current_score < best_score) {
                        best_score = current_score;
                    }
                }
            }
        }
    }
    return best_score;
}

void computer_move() {
    int best_score = -100;
    int best_move_i = -1;
    int best_move_j = -1;

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                int current_score = minimax(5, 0);
                board[i][j] = 0;
                if (current_score > best_score) {
                    best_score = current_score;
                    best_move_i = i;
                    best_move_j = j;
                }
            }
        }
    }
    board[best_move_i][best_move_j] = 1;
}

void player_move() {
    int row, col;
    printf("Enter row and column (0-2): ");
    scanf("%d %d", &row, &col);
    if (is_valid_move(row, col)) {
        board[row][col] = -1;
    } else {
        printf("Invalid move, try again.\n");
        player_move();
    }
}

int is_board_full() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    initialize_board();
    srand(time(NULL));
    int turn = rand() % 2 ? 1 : -1;
    printf("The game starts with the %s player.\n", turn == 1 ? "computer" : "player");

    while (!has_won(1) && !has_won(-1) && !is_board_full()) {
        if (turn == 1) {
            computer_move();
        } else {
            display_board();
            player_move();
        }
        turn *= -1;
    }

    display_board();
    if (has_won(1)) printf("The computer has won!\n");
    else if (has_won(-1)) printf("You have won!\n");
    else printf("It's a tie!\n");

    return 0;
}