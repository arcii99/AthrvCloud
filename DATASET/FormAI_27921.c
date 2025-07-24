//FormAI DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 20

void initialize_board(int board[][COLS], int rows, int cols) {
    srand(time(NULL));
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void display_board(int board[][COLS], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c ", board[i][j] ? 'X' : '.');
        }
        printf("\n");
    }
}

int is_valid(int i, int j, int rows, int cols) {
    return (i >= 0 && i < rows) && (j >= 0 && j < cols);
}

int count_neighbors(int board[][COLS], int i, int j, int rows, int cols) {
    int count = 0;
    int row, col;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) continue;
            row = i + dx;
            col = j + dy;
            if (is_valid(row, col, rows, cols) && board[row][col]) 
                count++;
        }
    }
    return count;
}

void play_life(int board[][COLS], int rows, int cols) {
    int next_state[ROWS][COLS];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int neighbors = count_neighbors(board, i, j, rows, cols);
            if (board[i][j] == 1 && neighbors < 2)
                next_state[i][j] = 0;
            else if (board[i][j] == 1 && (neighbors == 2 || neighbors == 3))
                next_state[i][j] = 1;
            else if (board[i][j] == 1 && neighbors > 3)
                next_state[i][j] = 0;
            else if (board[i][j] == 0 && neighbors == 3)
                next_state[i][j] = 1;
            else 
                next_state[i][j] = board[i][j];
        }
    }
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            board[i][j] = next_state[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    int count = 0;
    initialize_board(board, ROWS, COLS);
    while (count < 1000) {
        printf("Generation %d:\n", count+1);
        display_board(board, ROWS, COLS);
        printf("\n");
        play_life(board, ROWS, COLS);
        count++;
        sleep(1);
        system("clear");
    }
    return 0;
}