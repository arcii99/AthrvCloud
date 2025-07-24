//FormAI DATASET v1.0 Category: Game of Life ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30

void print_board(char board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int count_neighbors(char board[HEIGHT][WIDTH], int row, int col) {
    int count = 0;

    for (int i = row - 1; i <= row + 1; i++) {
        for (int j = col - 1; j <= col + 1; j++) {
            if (i == row && j == col) continue;
            if (i < 0 || i >= HEIGHT || j < 0 || j >= WIDTH) continue;
            if (board[i][j] == '*') count++;
        }
    }

    return count;
}

void update_board(char board[HEIGHT][WIDTH]) {
    char new_board[HEIGHT][WIDTH];

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int count = count_neighbors(board, i, j);
            if (board[i][j] == '*') {
                if (count == 2 || count == 3) new_board[i][j] = '*';
                else new_board[i][j] = ' ';
            } else {
                if (count == 3) new_board[i][j] = '*';
                else new_board[i][j] = ' ';
            }
        }
    }

    memcpy(board, new_board, sizeof(board));
}

int main() {
    char board[HEIGHT][WIDTH];
    memset(board, ' ', sizeof(board));

    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (rand() % 2 == 0) board[i][j] = '*';
        }
    }

    for (int i = 0; i < 100; i++) {
        print_board(board);
        update_board(board);
        printf("\n");
    }

    return 0;
}