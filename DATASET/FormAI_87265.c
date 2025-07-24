//FormAI DATASET v1.0 Category: Game of Life ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 20
#define COLS 60

void initialize_board(int board[][COLS]);
void print_board(int board[][COLS]);
void evolve(int board[][COLS]);

int main() {
    int board[ROWS][COLS];
    initialize_board(board);
    print_board(board);
    while(1) {
        printf("Press enter to continue or type 'q' to quit.\n");
        char c = getchar();
        if(c == 'q') {
            break;
        }
        evolve(board);
        print_board(board);
    }
    return 0;
}

void initialize_board(int board[][COLS]) {
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

void print_board(int board[][COLS]) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            printf("%c", board[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int count_neighbors(int board[][COLS], int i, int j) {
    int count = 0;
    for(int k = i-1; k <= i+1; k++) {
        for(int l = j-1; l <= j+1; l++) {
            if(k >= 0 && k < ROWS && l >= 0 && l < COLS && board[k][l]) {
                count++;
            }
        }
    }
    if(board[i][j]) {
        count--;
    }
    return count;
}

void evolve(int board[][COLS]) {
    int new_board[ROWS][COLS];
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            int neighbors = count_neighbors(board, i, j);
            if(board[i][j] && (neighbors < 2 || neighbors > 3)) {
                new_board[i][j] = 0;
            } else if(!board[i][j] && neighbors == 3) {
                new_board[i][j] = 1;
            } else {
                new_board[i][j] = board[i][j];
            }
        }
    }
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            board[i][j] = new_board[i][j];
        }
    }
}