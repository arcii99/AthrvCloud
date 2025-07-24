//FormAI DATASET v1.0 Category: Game of Life ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40

void initialize_board(int board[ROWS][COLS]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

int get_live_neighbors(int board[ROWS][COLS], int row, int col) {
    int i, j, count = 0; 
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i >= 0 && i < ROWS && j >= 0 && j < COLS && !(i == row && j == col)) {
                count += board[i][j];
            }
        }
    }
    return count;
}

void simulate_generation(int board[ROWS][COLS]) {
    int i, j, live_neighbors;
    int new_board[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            live_neighbors = get_live_neighbors(board, i, j);
            if (board[i][j] == 1 && (live_neighbors == 2 || live_neighbors == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 0 && live_neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = 0;
            }
        }
    }
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    int i, j;
    printf("\033[2J\033[1;1H"); // clears the screen
    printf("Futuristic Game of Life\n\n");
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("[]");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    while (1) {
        print_board(board);
        simulate_generation(board);
    }
    return 0;
}