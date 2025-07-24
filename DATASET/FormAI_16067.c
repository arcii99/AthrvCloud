//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 40
#define HEIGHT 20

void clear_screen() {
    system("clear || cls");
}

void wait_n_seconds(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

void init_board(int board[HEIGHT][WIDTH]) {
    clear_screen();
    srand(time(NULL));
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = rand() % 2; // randomly set each cell to 0 or 1
        }
    }
}

void draw_board(int board[HEIGHT][WIDTH]) {
    clear_screen();
    printf(" ");
    for (int i = 0; i < WIDTH; i++) {
        printf("_");
    }
    printf("\n");

    for (int i = 0; i < HEIGHT; i++) {
        printf("|");
        for (int j = 0; j < WIDTH; j++) {
            if (board[i][j] == 0) {
                printf(" ");
            } else {
                printf("*");
            }
        }
        printf("|\n");
    }

    printf(" ");
    for (int i = 0; i < WIDTH; i++) {
        printf("_");
    }
    printf("\n");
}

int get_live_neighbours(int board[HEIGHT][WIDTH], int row, int col) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            int x = row + i;
            int y = col + j;
            if (x >= 0 && x < HEIGHT && y >= 0 && y < WIDTH && !(i == 0 && j == 0)) {
                count += board[x][y];
            }
        }
    }
    return count;
}

void evolve_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            int live_neighbours = get_live_neighbours(board, i, j);
            if (board[i][j] == 1 && (live_neighbours < 2 || live_neighbours > 3)) {
                new_board[i][j] = 0; // any live cell with fewer than two or more than three live neighbors dies
            } else if (board[i][j] == 0 && live_neighbours == 3) {
                new_board[i][j] = 1; // any dead cell with exactly three live neighbors becomes a live cell
            } else {
                new_board[i][j] = board[i][j]; // all other cells remain the same
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
    init_board(board);
    while (1) {
        draw_board(board);
        evolve_board(board);
        wait_n_seconds(1);
    }
    return 0;
}