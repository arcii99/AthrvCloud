//FormAI DATASET v1.0 Category: Game of Life ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 40
#define GENERATIONS 50

void initialize_board(int board[ROWS][COLS]) {
    srand(time(0));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[ROWS][COLS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%c ", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

int count_neighbours(int board[ROWS][COLS], int i, int j) {
    int count = 0;
    for(int x=-1; x<=1; x++) {
        for(int y=-1; y<=1; y++) {
            if(x != 0 || y != 0) {
                int r = i + x;
                int c = j + y;
                if(r >= 0 && r < ROWS && c >= 0 && c < COLS) {
                    count += board[r][c];
                }
            }
        }
    }
    return count;
}

void update_board(int board[ROWS][COLS]) {
    int new_board[ROWS][COLS];
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            int neighbours = count_neighbours(board, i, j);
            if(board[i][j]) {
                new_board[i][j] = (neighbours == 2 || neighbours == 3);
            }
            else {
                new_board[i][j] = (neighbours == 3);
            }
        }
    }
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    printf("Initial Board:\n");
    print_board(board);
    for(int g=0; g<GENERATIONS; g++) {
        printf("Generation: %d\n", g+1);
        update_board(board);
        print_board(board);
    }
    return 0;
}