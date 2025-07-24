//FormAI DATASET v1.0 Category: Game of Life ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROWS 20
#define COLS 20

// function to initialize the game board with random values
void init_board(int board[][COLS]) {
    srand(time(NULL));
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

// function to print the game board
void print_board(int board[][COLS]) {
    int i, j;
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("# ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

// function to count the number of live neighbors for a given cell
int count_neighbors(int board[][COLS], int i, int j) {
    int count = 0;
    int x, y;
    for (x = i - 1; x <= i + 1; x++) {
        for (y = j - 1; y <= j + 1; y++) {
            if (x >= 0 && x < ROWS && y >= 0 && y < COLS && !(x == i && y == j)) {
                count += board[x][y];
            }
        }
    }
    return count;
}

// function to update the game board based on the rules of the game
void update_board(int board[][COLS]) {
    int new_board[ROWS][COLS];
    int i, j, count;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            count = count_neighbors(board, i, j);
            new_board[i][j] = board[i][j];
            if (count == 3 && board[i][j] == 0) {
                new_board[i][j] = 1;
            } else if ((count < 2 || count > 3) && board[i][j] == 1) {
                new_board[i][j] = 0;
            }
        }
    }
    memcpy(board, new_board, sizeof(new_board));
}

// main function to run the game of life
int main() {
    int board[ROWS][COLS];
    init_board(board);
    print_board(board);
    while (1) {
        update_board(board);
        print_board(board);
        usleep(50000);
    }
    return 0;
}