//FormAI DATASET v1.0 Category: Game of Life ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 50
#define HEIGHT 50

void init_board(int board[HEIGHT][WIDTH]) {
    srand(time(NULL));
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[HEIGHT][WIDTH]) {
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            if(board[i][j] == 0) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

int count_neighbors(int board[HEIGHT][WIDTH], int x, int y) {
    int count = 0;
    for(int i=-1; i<=1; i++) {
        for(int j=-1; j<=1; j++) {
            int row = (x+i+HEIGHT) % HEIGHT;
            int col = (y+j+WIDTH) % WIDTH;
            if(board[row][col] == 1 && !(i == 0 && j == 0)) {
                count++;
            }
        }
    }
    return count;
}

void update_board(int board[HEIGHT][WIDTH]) {
    int new_board[HEIGHT][WIDTH];
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j] == 1 && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0;
            } else if(board[i][j] == 0 && neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    for(int i=0; i<HEIGHT; i++) {
        for(int j=0; j<WIDTH; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[HEIGHT][WIDTH];
    init_board(board);
    print_board(board);
    for(int i=0; i<100; i++) {
        update_board(board);
        printf("Generation %d:\n", i+1);
        print_board(board);
    }
    return 0;
}