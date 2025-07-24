//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 3
#define MAX_MOVES BOARD_SIZE * BOARD_SIZE
#define COMP_MOVE 1
#define HUMAN_MOVE -1

int board[BOARD_SIZE][BOARD_SIZE];

void clear_board() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void display_board() {
    printf("   A   B   C  \n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i + 1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == COMP_MOVE) {
                printf("| O ");
            } else if (board[i][j] == HUMAN_MOVE) {
                printf("| X ");
            } else {
                printf("|   ");
            }
        }
        printf("|\n");
    }
}

int get_move() {
    char input[10];
    int row, col;
    do {
        printf("Enter your move (e.g. A1): ");
        scanf("%s", input);
        col = input[0] - 'A';
        row = input[1] - '1';
    } while (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE || board[row][col] != 0);
    return row * BOARD_SIZE + col;
}

int check_winner(int player) {
    int diag1 = 0, diag2 = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        int row_sum = 0, col_sum = 0;
        for (int j = 0; j < BOARD_SIZE; j++) {
            row_sum += board[i][j];
            col_sum += board[j][i];
            if (i == j) diag1 += board[i][j];
            if (i + j == BOARD_SIZE - 1) diag2 += board[i][j];
        }
        if (row_sum == player * BOARD_SIZE || col_sum == player * BOARD_SIZE) {
            return 1;
        }
    }
    if (diag1 == player * BOARD_SIZE || diag2 == player * BOARD_SIZE) {
        return 1;
    }
    return 0;
}

int minimax(int depth, int max_player) {
    int score;
    if (depth == 0 || check_winner(COMP_MOVE) || check_winner(HUMAN_MOVE)) {
        score = check_winner(COMP_MOVE) ? 1 : (check_winner(HUMAN_MOVE) ? -1 : 0);
        return score;
    }
    if (max_player) {
        int best_score = -10000;
        for (int i = 0; i < MAX_MOVES; i++) {
            int row = i / BOARD_SIZE, col = i % BOARD_SIZE;
            if (board[row][col] == 0) {
                board[row][col] = COMP_MOVE;
                int curr_score = minimax(depth - 1, 0);
                board[row][col] = 0;
                if (curr_score > best_score) {
                    best_score = curr_score;
                }
            }
        }
        return best_score;
    } else {
        int best_score = 10000;
        for (int i = 0; i < MAX_MOVES; i++) {
            int row = i / BOARD_SIZE, col = i % BOARD_SIZE;
            if (board[row][col] == 0) {
                board[row][col] = HUMAN_MOVE;
                int curr_score = minimax(depth - 1, 1);
                board[row][col] = 0;
                if (curr_score < best_score) {
                    best_score = curr_score;
                }
            }
        }
        return best_score;
    }
}

void computer_move() {
    int best_score = -10000, best_move;
    for (int i = 0; i < MAX_MOVES; i++) {
        int row = i / BOARD_SIZE, col = i % BOARD_SIZE;
        if (board[row][col] == 0) {
            board[row][col] = COMP_MOVE;
            int curr_score = minimax(5, 0);
            board[row][col] = 0;
            if (curr_score > best_score) {
                best_score = curr_score;
                best_move = i;
            }
        }
    }
    int row = best_move / BOARD_SIZE, col = best_move % BOARD_SIZE;
    board[row][col] = COMP_MOVE;
}

int main() {
    clear_board();
    srand(time(NULL));
    int human_turn = rand() % 2; // Randomly decide who goes first
    while (!check_winner(COMP_MOVE) && !check_winner(HUMAN_MOVE)) {
        display_board();
        if (human_turn) {
            int move = get_move();
            int row = move / BOARD_SIZE, col = move % BOARD_SIZE;
            board[row][col] = HUMAN_MOVE;
        } else {
            printf("Computer's turn:\n");
            computer_move();
        }
        human_turn = !human_turn;
    }
    display_board();
    if (check_winner(COMP_MOVE)) {
        printf("Computer wins!\n");
    } else if (check_winner(HUMAN_MOVE)) {
        printf("You win!\n");
    } else {
        printf("It's a tie!\n");
    }
    return 0;
}