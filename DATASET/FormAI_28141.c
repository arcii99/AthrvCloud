//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define WINNING_VALUE 2048

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%4d", board[i][j]);
        }
        printf("\n");
    }
}

int get_random_number(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

void add_random_tile(int board[BOARD_SIZE][BOARD_SIZE]) {
    int value = get_random_number(1, 10) == 10 ? 4 : 2;
    int row, col;
    do {
        row = get_random_number(0, BOARD_SIZE - 1);
        col = get_random_number(0, BOARD_SIZE - 1);
    } while (board[row][col] != 0);
    board[row][col] = value;
}

int move_board(int board[BOARD_SIZE][BOARD_SIZE], int dir) {
    int score = 0;
    int tmp_board[BOARD_SIZE][BOARD_SIZE] = {0};

    if (dir == 0) { // up
        for (int j = 0; j < BOARD_SIZE; j++) {
            int k = 0;
            for (int i = 0; i < BOARD_SIZE; i++) {
                if (board[i][j] != 0) {
                    if (tmp_board[k][j] == board[i][j]) {
                        tmp_board[k][j] *= 2;
                        score += tmp_board[k][j];
                        k++;
                    } else if (tmp_board[k][j] == 0) {
                        tmp_board[k][j] = board[i][j];
                    } else {
                        k++;
                        tmp_board[k][j] = board[i][j];
                    }
                }
            }
        }
    } else if (dir == 1) { // down
        for (int j = 0; j < BOARD_SIZE; j++) {
            int k = BOARD_SIZE - 1;
            for (int i = BOARD_SIZE - 1; i >= 0; i--) {
                if (board[i][j] != 0) {
                    if (tmp_board[k][j] == board[i][j]) {
                        tmp_board[k][j] *= 2;
                        score += tmp_board[k][j];
                        k--;
                    } else if (tmp_board[k][j] == 0) {
                        tmp_board[k][j] = board[i][j];
                    } else {
                        k--;
                        tmp_board[k][j] = board[i][j];
                    }
                }
            }
        }
    } else if (dir == 2) { // left
        for (int i = 0; i < BOARD_SIZE; i++) {
            int k = 0;
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] != 0) {
                    if (tmp_board[i][k] == board[i][j]) {
                        tmp_board[i][k] *= 2;
                        score += tmp_board[i][k];
                        k++;
                    } else if (tmp_board[i][k] == 0) {
                        tmp_board[i][k] = board[i][j];
                    } else {
                        k++;
                        tmp_board[i][k] = board[i][j];
                    }
                }
            }
        }
    } else if (dir == 3) { // right
        for (int i = 0; i < BOARD_SIZE; i++) {
            int k = BOARD_SIZE - 1;
            for (int j = BOARD_SIZE - 1; j >= 0; j--) {
                if (board[i][j] != 0) {
                    if (tmp_board[i][k] == board[i][j]) {
                        tmp_board[i][k] *= 2;
                        score += tmp_board[i][k];
                        k--;
                    } else if (tmp_board[i][k] == 0) {
                        tmp_board[i][k] = board[i][j];
                    } else {
                        k--;
                        tmp_board[i][k] = board[i][j];
                    }
                }
            }
        }
    }

    int moved = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != tmp_board[i][j]) {
                board[i][j] = tmp_board[i][j];
                moved = 1;
            }
        }
    }
    return moved ? score : -1;
}

int game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == 0) {
                return 0; // not game over
            }
            if (j != BOARD_SIZE - 1 && board[i][j] == board[i][j+1]) {
                return 0; // not game over
            }
            if (i != BOARD_SIZE - 1 && board[i][j] == board[i+1][j]) {
                return 0; // not game over
            }
        }
    }
    return 1; // game over
}

int main() {
    srand(time(NULL));
    int score = 0;
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    add_random_tile(board);
    add_random_tile(board);
    print_board(board);
    while (!game_over(board)) {
        printf("Enter move (w = up, s = down, a = left, d = right): ");
        char move;
        scanf(" %c", &move);
        int moved = 0;
        if (move == 'w') {
            printf("Moving up\n");
            score += move_board(board, 0);
            moved = 1;
        } else if (move == 's') {
            printf("Moving down\n");
            score += move_board(board, 1);
            moved = 1;
        } else if (move == 'a') {
            printf("Moving left\n");
            score += move_board(board, 2);
            moved = 1;
        } else if (move == 'd') {
            printf("Moving right\n");
            score += move_board(board, 3);
            moved = 1;
        } else {
            printf("Invalid move\n");
        }
        if (moved) {
            add_random_tile(board);
            print_board(board);
            printf("Score: %d\n", score);
        }
        if (score >= WINNING_VALUE) {
            printf("You win!\n");
            break;
        }
    }
    if (game_over(board)) {
        printf("Game over!\n");
    }
    return 0;
}