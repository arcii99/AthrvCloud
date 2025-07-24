//FormAI DATASET v1.0 Category: Game of Life ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h> // for usleep()

#define ROWS 20
#define COLS 40

void initialise(char board[ROWS][COLS]) {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            board[r][c] = (rand() % 2 == 0) ? '.' : '0';
        }
    }
}

void display(char board[ROWS][COLS]) {
    int r, c;
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            putchar(board[r][c]);
        }
        putchar('\n');
    }
}

int count_neighbors(char board[ROWS][COLS], int row, int col) {
    int count = 0, r, c;
    
    for (r = row - 1; r <= row + 1; r++) {
        for (c = col - 1; c <= col + 1; c++) {
            if (r < 0 || r >= ROWS || c < 0 || c >= COLS) continue;
            if (r == row && c == col) continue;
            if (board[r][c] == '0') count++;
        }
    }
    
    return count;
}

void iterate(char board[ROWS][COLS]) {
    int r, c, neighbors;
    char new_board[ROWS][COLS];
    
    for (r = 0; r < ROWS; r++) {
        for (c = 0; c < COLS; c++) {
            neighbors = count_neighbors(board, r, c);
            if (board[r][c] == '0') {
                if (neighbors == 2 || neighbors == 3) {
                    new_board[r][c] = '0';
                } else {
                    new_board[r][c] = '.';
                }
            } else {
                if (neighbors == 3) {
                    new_board[r][c] = '0';
                } else {
                    new_board[r][c] = '.';
                }
            }
        }
    }
    
    memcpy(board, new_board, ROWS * COLS * sizeof(char));
}

int main() {
    char board[ROWS][COLS];
    initialise(board);
    
    while (1) {
        display(board);
        iterate(board);
        usleep(100000);
    }
    
    return 0;
}