//FormAI DATASET v1.0 Category: Game of Life ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 80
#define HEIGHT 24
#define ALIVE '*'
#define DEAD ' '

void initialize_board(char board[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = (rand() % 2 == 0) ? ALIVE : DEAD;
        }
    }
}

void print_board(char board[HEIGHT][WIDTH]) {
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            printf("%c", board[i][j]);
        }
        printf("\n");
    }
}

int get_num_neighbors(char board[HEIGHT][WIDTH], int x, int y) {
    int i, j, num = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            int x1 = x + i, y1 = y + j;
            if (x1 < 0 || x1 >= HEIGHT || y1 < 0 || y1 >= WIDTH) continue;
            if (board[x1][y1] == ALIVE) num++;
        }
    }
    return num;
}

void update_board(char board[HEIGHT][WIDTH]) {
    char new_board[HEIGHT][WIDTH];
    int i, j;
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            int num_neighbors = get_num_neighbors(board, i, j);
            if (board[i][j] == ALIVE && (num_neighbors < 2 || num_neighbors > 3)) {
                new_board[i][j] = DEAD;
            } else if (board[i][j] == DEAD && num_neighbors == 3) {
                new_board[i][j] = ALIVE;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    srand(time(NULL));
    char board[HEIGHT][WIDTH];
    initialize_board(board);
    while (1) {
        printf("\033[2J\033[1;1H"); // clear console and reset cursor position
        print_board(board);
        update_board(board);
        getchar();
    }
    return 0;
}