//FormAI DATASET v1.0 Category: Memory Game ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(int board[][BOARD_SIZE]) {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%d  ", board[i][j]);
        }
        printf("\n");
    }
}

void shuffle_board(int board[][BOARD_SIZE]) {
    srand(time(NULL));
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            int r1 = rand() % BOARD_SIZE;
            int c1 = rand() % BOARD_SIZE;
            int r2 = rand() % BOARD_SIZE;
            int c2 = rand() % BOARD_SIZE;
            int temp = board[r1][c1];
            board[r1][c1] = board[r2][c2];
            board[r2][c2] = temp;
        }
    }
}

int main() {
    int initial_board[BOARD_SIZE][BOARD_SIZE] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};
    int board[BOARD_SIZE][BOARD_SIZE];
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            board[i][j] = initial_board[i][j];
        }
    }
    shuffle_board(board);
    int moves = 0;
    while(1) {
        printf("Moves: %d\n", moves++);
        print_board(board);
        int x, y;
        printf("Enter x and y\n");
        scanf("%d %d", &x, &y);
        if(x < 0 || x >= BOARD_SIZE || y < 0 || y >= BOARD_SIZE) {
            printf("Invalid move, try again.\n");
            continue;
        }
        int empty_row, empty_col;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(board[i][j] == 0) {
                    empty_row = i;
                    empty_col = j;
                    break;
                }
            }
        }
        if((x == empty_row-1 && y == empty_col) || (x == empty_row+1 && y == empty_col) || (x == empty_row && y == empty_col-1) || (x == empty_row && y == empty_col+1)) {
            int temp = board[x][y];
            board[x][y] = 0;
            board[empty_row][empty_col] = temp;
        } else {
            printf("Invalid move, try again.\n");
        }
        int win = 1;
        for(int i=0; i<BOARD_SIZE; i++) {
            for(int j=0; j<BOARD_SIZE; j++) {
                if(i == BOARD_SIZE-1 && j == BOARD_SIZE-1) {
                    break;
                }
                if(board[i][j] != i*BOARD_SIZE+j+1) {
                    win = 0;
                    break;
                }
            }
            if(!win) {
                break;
            }
        }
        if(win) {
            printf("Congratulations, you won!\n");
            break;
        }
    }
    return 0;
}