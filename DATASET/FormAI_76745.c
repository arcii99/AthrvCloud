//FormAI DATASET v1.0 Category: Checkers Game ; Style: future-proof
#include <stdio.h>

#define BOARD_SIZE 8

void printBoard(char board[][BOARD_SIZE]) {
    printf("  ");
    for(int col = 0; col < BOARD_SIZE; col++) {
        printf("%d ", col);
    }
    printf("\n");
    
    for(int row = 0; row < BOARD_SIZE; row++) {
        printf("%d ", row);
        for(int col = 0; col < BOARD_SIZE; col++) {
            printf("%c ", board[row][col]);
        }
        printf("\n");
    }
}

int main() {
    char board[BOARD_SIZE][BOARD_SIZE];
    for(int row = 0; row < BOARD_SIZE; row++) {
        for(int col = 0; col < BOARD_SIZE; col++) {
            if((row + col) % 2 == 0) {
                if(row < 3) {
                    board[row][col] = 'O';
                } else if(row > 4) {
                    board[row][col] = 'X';
                } else {
                    board[row][col] = ' ';
                }
            } else {
                board[row][col] = ' ';
            }
        }
    }
    
    printBoard(board);
    
    return 0;
}