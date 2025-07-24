//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 20
#define M 40
#define GENERATIONS 100

void print_board(char board[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(char board[N][M], int row, int col) {
    int count = 0;
    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < N && j >= 0 && j < M && board[i][j] == 'O' && !(i == row && j == col)) {
                count++;
            }
        }
    }
    return count;
}

void update_board(char board[N][M]) {
    char new_board[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j] == 'O') {
                if (neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = ' ';
                } else {
                    new_board[i][j] = 'O';
                }
            } else {
                if (neighbors == 3) {
                    new_board[i][j] = 'O';
                } else {
                    new_board[i][j] = ' ';
                }
            }
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    char board[N][M];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (rand() % 2 == 0) {
                board[i][j] = 'O';
            } else {
                board[i][j] = ' ';
            }
        }
    }
    for (int i = 0; i < GENERATIONS; i++) {
        system("clear");
        printf("Generation: %d\n", i + 1);
        print_board(board);
        update_board(board);
        usleep(50000);
    }
    return 0;
}