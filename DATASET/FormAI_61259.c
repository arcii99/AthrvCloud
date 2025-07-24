//FormAI DATASET v1.0 Category: Game of Life ; Style: Ken Thompson
#include <stdio.h>
#include <unistd.h>
#include <string.h>

#define ROWS 20
#define COLS 20

void display_board(int board[ROWS][COLS]) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j] ? '*' : '.');
        }
        printf("\n");
    }
}

int num_alive_neighbours(int row, int col, int board[ROWS][COLS]) {
    int count = 0;
    for(int i=row-1; i<=row+1; i++) {
        for(int j=col-1; j<=col+1; j++) {
            if(i!=row || j!=col) {
                if(board[(i+ROWS)%ROWS][(j+COLS)%COLS]) {
                    count++;
                }
            }
        }
    }
    return count;
}

void next_generation(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    memset(new_board, 0, ROWS*COLS*sizeof(int));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int alive_neighbours = num_alive_neighbours(i, j, board);
            if(board[i][j]) {
                if(alive_neighbours < 2 || alive_neighbours > 3) {
                    new_board[i][j] = 0;
                } else {
                    new_board[i][j] = 1;
                }
            } else {
                if(alive_neighbours == 3) {
                    new_board[i][j] = 1;
                }
            }
        }
    }
    memcpy(board, new_board, ROWS*COLS*sizeof(int));
}

int main() {
    int board[ROWS][COLS] = {{0}};
    board[2][1] = 1;
    board[2][2] = 1;
    board[2][3] = 1;

    display_board(board);
    for(int i=0; i<10; i++) {
        usleep(500000);
        printf("\033[H\033[J");
        next_generation(board);
        display_board(board);
    }
    return 0;
}