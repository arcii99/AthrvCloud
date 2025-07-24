//FormAI DATASET v1.0 Category: Game of Life ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 30

void initialize_board(int board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j] ? 'X' : ' ');
        }
        printf("\n");
    }
    printf("\n");
}

int count_neighbors(int board[HEIGHT][WIDTH], int i, int j) {
    int count = 0;
    for (int k = i-1; k <= i+1; k++) {
        for (int l = j-1; l <= j+1; l++) {
            if (k < 0 || k >= HEIGHT || l < 0 || l >= WIDTH || (k == i && l == j)) {
                continue;
            }
            count += board[k][l];
        }
    }
    return count;
}

void iterate_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int count = count_neighbors(board, i, j);
            if (board[i][j]) {
                new_board[i][j] = (count == 2 || count == 3) ? 1 : 0;
            } else {
                new_board[i][j] = (count == 3) ? 1 : 0;
            }
        }
    }
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[HEIGHT][WIDTH];
    srand(time(NULL));
    initialize_board(board);
    for (int i = 0; i < 1000; i++) {
        print_board(board);
        iterate_board(board);
    }
    return 0;
}