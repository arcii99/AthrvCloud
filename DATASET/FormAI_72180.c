//FormAI DATASET v1.0 Category: Checkers Game ; Style: funny
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

typedef enum {
    RED = 'R',
    BLACK = 'B'
} checker_t;

typedef enum {
    EMPTY = ' '
} empty_t;

void initialize_board() {
    for(int row=0;row<BOARD_SIZE;row++) {
        for(int column=0;column<BOARD_SIZE;column++) {
            if((row+column)%2 == 0) {
                if(row<3) {
                    board[row][column] = BLACK;
                } else if(row>4) {
                    board[row][column] = RED;
                } else {
                    board[row][column] = EMPTY;
                }
            } else {
                board[row][column] = EMPTY;
            }
        }
    }
}

void print_board() {
    printf("   1 2 3 4 5 6 7 8\n");
    for(int row=0;row<BOARD_SIZE;row++) {
        printf("%d ",row+1);
        for(int column=0;column<BOARD_SIZE;column++) {
            printf("|%c",board[row][column]);
        }
        printf("|\n");
    }
}

int main() {
    initialize_board();
    print_board();
    return 0;
}