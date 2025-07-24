//FormAI DATASET v1.0 Category: Game of Life ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void print_board(int board[ROWS][COLS]) {
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(board[i][j]) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void update_board(int board[ROWS][COLS]) {
    int i, j, n;
    int newboard[ROWS][COLS];

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            n = 0;
            n += ( i > 0              && j > 0              && board[i-1][j-1]) ? 1 : 0;
            n += ( i > 0                                    && board[i-1][ j ]) ? 1 : 0;
            n += ( i > 0              && j < COLS - 1       && board[i-1][j+1]) ? 1 : 0;
            n += (                     j > 0              && board[ i ][j-1]) ? 1 : 0;
            n += (                     j < COLS - 1       && board[ i ][j+1]) ? 1 : 0;
            n += ( i < ROWS - 1       && j > 0              && board[i+1][j-1]) ? 1 : 0;
            n += ( i < ROWS - 1                             && board[i+1][ j ]) ? 1 : 0;
            n += ( i < ROWS - 1       && j < COLS - 1       && board[i+1][j+1]) ? 1 : 0;

            newboard[i][j] = board[i][j];

            if(board[i][j]) {
                if(n < 2 || n > 3) {
                    newboard[i][j] = 0;
                }
            } else {
                if(n == 3) {
                    newboard[i][j] = 1;
                }
            }
        }
    }

    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            board[i][j] = newboard[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS] = { {0} };
    srand(time(NULL));

    // initialize board with random cells
    int i, j;
    for(i = 0; i < ROWS; i++) {
        for(j = 0; j < COLS; j++) {
            if(rand() % 100 < 20) {
                board[i][j] = 1;
            }
        }
    }

    // run game of life
    while(1) {
        system("cls"); // clear screen before each update
        print_board(board);
        update_board(board);
        usleep(100000); // sleep for 0.1 second
    }

    return 0;
}