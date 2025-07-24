//FormAI DATASET v1.0 Category: Game of Life ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 30
#define COLUMNS 60

void generate_initial_board(int board[ROWS][COLUMNS]) {
    srand(time(NULL));
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int random_num = rand() % 100;
            if(random_num < 30) {
                board[i][j] = 1;
            }
            else {
                board[i][j] = 0;
            }
        }
    }
}

void print_board(int board[ROWS][COLUMNS]) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            if(board[i][j] == 1) {
                printf("#");
            }
            else {
                printf(".");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void copy_board(int board[ROWS][COLUMNS], int new_board[ROWS][COLUMNS]) {
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            new_board[i][j] = board[i][j];
        }
    }
}

int count_neighbors(int board[ROWS][COLUMNS], int row, int col) {
    int count = 0;
    int start_row = row - 1;
    int start_col = col - 1;
    int end_row = row + 1;
    int end_col = col + 1;

    if(start_row < 0) {
        start_row = 0;
    }
    if(start_col < 0) {
        start_col = 0;
    }
    if(end_row > ROWS-1) {
        end_row = ROWS-1;
    }
    if(end_col > COLUMNS-1) {
        end_col = COLUMNS-1;
    }

    for(int i=start_row; i<=end_row; i++) {
        for(int j=start_col; j<=end_col; j++) {
            if(i == row && j == col) {
                continue;
            }
            if(board[i][j] == 1) {
                count++;
            }
        }
    }

    return count;
}

void update_board(int board[ROWS][COLUMNS]) {
    int new_board[ROWS][COLUMNS];
    copy_board(board, new_board);

    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLUMNS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j] == 0) {
                if(neighbors == 3) {
                    new_board[i][j] = 1;
                }
            }
            else {
                if(neighbors < 2 || neighbors > 3) {
                    new_board[i][j] = 0;
                }
            }
        }
    }

    copy_board(new_board, board);
}

int main() {
    int board[ROWS][COLUMNS];
    generate_initial_board(board);

    // Print initial board
    printf("Welcome to the game of life medieval style!\n");
    printf("Initial board:\n");
    print_board(board);

    // Update board for 50 generations
    for(int i=1; i<=50; i++) {
        printf("Generation %d:\n", i);
        update_board(board);
        print_board(board);
    }

    return 0;
}