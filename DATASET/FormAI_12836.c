//FormAI DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

void initialize_board(int board[][COLS]);
void print_board(int board[][COLS]);
void update_board(int board[][COLS], int temp_board[][COLS]);

int main() {
    srand(time(NULL));
    int board[ROWS][COLS];
    int temp_board[ROWS][COLS];
    initialize_board(board);
    while (1) {
        system("clear");
        print_board(board);
        update_board(board, temp_board);
        getchar();
    }
    return 0;
}

void initialize_board(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("O ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

void update_board(int board[][COLS], int temp_board[][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = 0;
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (!(k == 0 && l == 0)) {
                        int row = i + k;
                        int col = j + l;
                        if (row >= 0 && row < ROWS && col >= 0 && col < COLS && board[row][col] == 1) {
                            neighbors++;
                        }
                    }
                }
            }
            if (board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                temp_board[i][j] = 0;
            } else if (board[i][j] == 0 && neighbors == 3) {
                temp_board[i][j] = 1;
            } else {
                temp_board[i][j] = board[i][j];
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = temp_board[i][j];
        }
    }
}