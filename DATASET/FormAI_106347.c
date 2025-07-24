//FormAI DATASET v1.0 Category: Game of Life ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define ROWS 25
#define COLS 25

void init_board(int board[ROWS][COLS]);
void print_board(int board[ROWS][COLS]);
int count_neighbors(int row, int col, int board[ROWS][COLS]);
void update_board(int board[ROWS][COLS]);
void glitch();

int main(void) {
    int board[ROWS][COLS];
    
    init_board(board);
    while(1) {
        print_board(board);
        update_board(board);
        glitch();
    }
    
    return 0;
}

void init_board(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    system("clear");
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j] == 1)
                printf("*");
            else
                printf(" ");
        }
        printf("\n");
    }
}

int count_neighbors(int row, int col, int board[ROWS][COLS]) {
    int i, j, count = 0;
    for(i = -1; i < 2; i++) {
        for(j = -1; j < 2; j++) {
            if(i == 0 && j == 0)
                continue;
            if(row + i == -1 || row + i == ROWS || col + j == -1 || col + j == COLS)
                continue;
            if(board[row+i][col+j] == 1)
                count++;
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    int i, j, neighbors;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            neighbors = count_neighbors(i, j, board);
            if(board[i][j] == 1 && neighbors < 2)
                new_board[i][j] = 0;
            else if(board[i][j] == 1 && (neighbors == 2 || neighbors == 3))
                new_board[i][j] = 1;
            else if(board[i][j] == 1 && neighbors > 3)
                new_board[i][j] = 0;
            else if(board[i][j] == 0 && neighbors == 3)
                new_board[i][j] = 1;
            else
                new_board[i][j] = board[i][j];
        }
    }
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

void glitch() {
    usleep(10000);
    int i;
    for(i = 0; i < ROWS * COLS; i++) {
        printf(" ");
    }
}