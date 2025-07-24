//FormAI DATASET v1.0 Category: Game of Life ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

#define ROWS 20
#define COLS 20

void initialize_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void display_board(int board[ROWS][COLS]) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j] ? '*' : ' ');
        }
        printf("\n");
    }
}

int count_neighbors(int board[ROWS][COLS], int i, int j) {
    int count = 0;
    for (int a = -1; a <= 1; a++) {
        for (int b = -1; b <= 1; b++) {
            if (a == 0 && b == 0) continue;
            int x = i + a, y = j + b;
            if (x < 0 || x >= ROWS || y < 0 || y >= COLS) continue;
            if (board[x][y]) count++;
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS] = {0};
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if (board[i][j]) {
                if (neighbors == 2 || neighbors == 3) new_board[i][j] = 1;
            } else {
                if (neighbors == 3) new_board[i][j] = 1;
            }
        }
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    for (int i = 0; i < 50; i++) {
        printf("*** Generation %d ***\n", i);
        display_board(board);
        update_board(board);
    }
    return 0;
}