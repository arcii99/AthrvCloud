//FormAI DATASET v1.0 Category: Game of Life ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 50
#define COLS 50

void initialize_board(int board[][COLS]) {
    srand(time(NULL));
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = rand()%2;
        }
    }
}

void print_board(int board[][COLS]) {
    int i, j;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            printf("%c ", board[i][j] ? '#' : '.');
        }
        printf("\n");
    }
}

void update_board(int board[][COLS]) {
    int new_board[ROWS][COLS];
    int i, j, neighbors, sum;
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            neighbors = 0;
            sum = -board[i][j];
            if(i > 0) {
                neighbors += board[i-1][j];
                if(j > 0) {
                    neighbors += board[i-1][j-1];
                }
                if(j < COLS-1) {
                    neighbors += board[i-1][j+1];
                }
            }
            if(i < ROWS-1) {
                neighbors += board[i+1][j];
                if(j > 0) {
                    neighbors += board[i+1][j-1];
                }
                if(j < COLS-1) {
                    neighbors += board[i+1][j+1];
                }
            }
            if(j > 0) {
                neighbors += board[i][j-1];
            }
            if(j < COLS-1) {
                neighbors += board[i][j+1];
            }
            if(board[i][j] && (neighbors == 2 || neighbors == 3)) {
                new_board[i][j] = 1;
            }
            else if(!board[i][j] && neighbors == 3) {
                new_board[i][j] = 1;
            }
            else {
                new_board[i][j] = 0;
            }
        }
    }
    for(i=0; i<ROWS; i++) {
        for(j=0; j<COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    for(int i=0;i<100;i++) {
        system("cls||clear");
        print_board(board);
        update_board(board);
        usleep(100000);
    }
    return 0;
}