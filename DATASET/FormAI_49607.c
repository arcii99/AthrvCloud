//FormAI DATASET v1.0 Category: Checkers Game ; Style: statistical
#include <stdio.h>

#define BOARD_SIZE 8

void initialize_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if((i + j) % 2 == 0) {
                if(i < 3) {
                    board[i][j] = 'b';
                } else if(i > 4) {
                    board[i][j] = 'r';
                } else {
                    board[i][j] = 'o';
                }
            } else {
                board[i][j] = 's';
            }
        }
    }
}

void print_board(char board[BOARD_SIZE][BOARD_SIZE]) {
    printf("   ");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    
    return 0;
}