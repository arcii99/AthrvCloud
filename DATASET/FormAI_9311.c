//FormAI DATASET v1.0 Category: Checkers Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

void initialize_board(int board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            // Set all squares to 0 (empty)
            board[row][col] = 0;
        }
    }
    
    // Set initial position of red player
    board[0][1] = 1;
    board[0][3] = 1;
    board[0][5] = 1;
    board[0][7] = 1;
    board[1][0] = 1;
    board[1][2] = 1;
    board[1][4] = 1;
    board[1][6] = 1;
    board[2][1] = 1;
    board[2][3] = 1;
    board[2][5] = 1;
    board[2][7] = 1;
    
    // Set initial position of black player
    board[5][0] = 2;
    board[5][2] = 2;
    board[5][4] = 2;
    board[5][6] = 2;
    board[6][1] = 2;
    board[6][3] = 2;
    board[6][5] = 2;
    board[6][7] = 2;
    board[7][0] = 2;
    board[7][2] = 2;
    board[7][4] = 2;
    board[7][6] = 2;
}

void print_board(int board[][BOARD_SIZE]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            printf("|");
            switch (board[row][col]) {
                case 0:
                    printf(" ");
                    break;
                case 1:
                    printf("r");
                    break;
                case 2:
                    printf("b");
                    break;
                case 3:
                    printf("R");
                    break;
                case 4:
                    printf("B");
                    break;
                default:
                    break;
            }
        }
        printf("|\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    print_board(board);
    return 0;
}