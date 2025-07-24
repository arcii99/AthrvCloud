//FormAI DATASET v1.0 Category: Checkers Game ; Style: sophisticated
#include <stdio.h>

//Define the board and its dimensions
#define BOARD_DIMENSION 8

int board[BOARD_DIMENSION][BOARD_DIMENSION];

void initialize_board() {
    //Fill the board with empty spaces
    for(int i = 0; i < BOARD_DIMENSION; i++) {
        for(int j = 0; j < BOARD_DIMENSION; j++) {
            board[i][j] = 0;
        }
    }
    
    //Assign the starting positions for the pieces
    for(int i = 0; i < BOARD_DIMENSION; i++) {
        for(int j = 0; j < BOARD_DIMENSION; j++) {
            if((i + j) % 2 == 0) {
                if(i < 3) {
                    board[i][j] = 1;
                }
                else if(i > 4) {
                    board[i][j] = 2;
                }
            }
        }
    }
}

void display_board() {
    //Print column numbers
    printf("  ");
    for(int i = 0; i < BOARD_DIMENSION; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    //Print board state
    for(int i = 0; i < BOARD_DIMENSION; i++) {
        printf("%d ", i);
        for(int j = 0; j < BOARD_DIMENSION; j++) {
            printf("%d ", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    initialize_board();
    display_board();
    
    return 0;
}