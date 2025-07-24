//FormAI DATASET v1.0 Category: Game of Life ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 30

void initialize_board(int board[MAX_SIZE][MAX_SIZE]) {
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

int count_live_neighbors(int board[MAX_SIZE][MAX_SIZE], int x, int y) {
    int count = 0, i, j;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            int row = (x+i+MAX_SIZE) % MAX_SIZE;
            int col = (y+j+MAX_SIZE) % MAX_SIZE;
            count += board[row][col];
        }
    }
    count -= board[x][y];
    return count;
}

void update_board(int board[MAX_SIZE][MAX_SIZE]) {
    int new_board[MAX_SIZE][MAX_SIZE];
    int i, j;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            int live_neighbors = count_live_neighbors(board, i, j);
            if (board[i][j] == 1 && live_neighbors < 2) {
                new_board[i][j] = 0;
            } else if (board[i][j] == 1 && live_neighbors > 3) {
                new_board[i][j] = 0;
            } else if (board[i][j] == 0 && live_neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[MAX_SIZE][MAX_SIZE];
    int i, j, generation;

    srand(time(NULL)); 
    initialize_board(board);

    for (generation = 1; generation <= 50; generation++) {
        printf("Generation %d\n", generation);
        for (i = 0; i < MAX_SIZE; i++) {
            for (j = 0; j < MAX_SIZE; j++) {
                if (board[i][j] == 1) {
                    printf("*");
                } else {
                    printf(" ");
                }
            }
            printf("\n");
        }
        update_board(board);
        printf("\n");
    }
    return 0;
}