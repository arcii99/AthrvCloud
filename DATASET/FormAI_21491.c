//FormAI DATASET v1.0 Category: Game ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10

void create_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

void place_bombs(int board[BOARD_SIZE][BOARD_SIZE]) {
    int num_bombs = 15;
    int i, j, count;
    count = 0;
    srand(time(NULL));
    while (count < num_bombs) {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        if (board[i][j] != -1) {
            board[i][j] = -1;
            count++;
        }
    }
}

void update_counts(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != -1) {
                int count = 0;
                int k, l;
                for (k = i - 1; k <= i + 1; k++) {
                    for (l = j - 1; l <= j + 1; l++) {
                        if (k >= 0 && k < BOARD_SIZE && l >= 0 && l < BOARD_SIZE && board[k][l] == -1) {
                            count++;
                        }
                    }
                }
                board[i][j] = count;
            }
        }
    }
}

void play_game(int board[BOARD_SIZE][BOARD_SIZE], int visible[BOARD_SIZE][BOARD_SIZE], int *num_unexplored) {
    int cur_row, cur_col;
    int status = 0;
    while (status == 0) {
        printf("Enter row and column to explore: ");
        scanf("%d%d", &cur_row, &cur_col);
        if (board[cur_row][cur_col] == -1) {
            printf("BOOM! Game over.\n");
            status = -1;
        } else {
            visible[cur_row][cur_col] = 1;
            *num_unexplored -= 1;
            if (*num_unexplored == 0) {
                printf("Congratulations, you won!\n");
                status = 1;
            } else {
                print_board(visible);
            }
        }
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int visible[BOARD_SIZE][BOARD_SIZE];
    int i, j, num_unexplored;
    create_board(board);
    place_bombs(board);
    update_counts(board);
    num_unexplored = BOARD_SIZE * BOARD_SIZE - 15;
    create_board(visible);
    print_board(visible);
    play_game(board, visible, &num_unexplored);
    return 0;
}