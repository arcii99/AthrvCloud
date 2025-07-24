//FormAI DATASET v1.0 Category: Game of Life ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

void initialize_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = 0;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            if (board[i][j] == 1) {
                printf("* ");
            } else {
                printf(". ");
            }
        }
        printf("\n");
    }
}

int count_live_neighbors(int board[ROWS][COLS], int row, int col) {
    int i, j, count = 0;
    for (i = row - 1; i <= row + 1; i++) {
        for (j = col - 1; j <= col + 1; j++) {
            if (i < 0 || i >= ROWS || j < 0 || j >= COLS) {
                continue;
            }
            
            if (i == row && j == col) {
                continue;
            }
            
            if (board[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int i, j, count;
    int new_board[ROWS][COLS];
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            count = count_live_neighbors(board, i, j);
            if (board[i][j] == 1 && count < 2) {
                new_board[i][j] = 0;
            } else if (board[i][j] == 1 && (count == 2 || count == 3)) {
                new_board[i][j] = 1;
            } else if (board[i][j] == 1 && count > 3) {
                new_board[i][j] = 0;
            } else if (board[i][j] == 0 && count == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    
    // Populate the board with some life
    board[5][5] = 1;
    board[5][6] = 1;
    board[6][5] = 1;
    board[6][6] = 1;
    
    int i;
    for (i = 0; i < 10; i++) {
        printf("Generation %d:\n", i);
        print_board(board);
        update_board(board);
        printf("\n");
    }
    
    return 0;
}