//FormAI DATASET v1.0 Category: Chess engine ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

// Define the chess board as a 2D integer array
int chess_board[8][8] = {
    {-1, -2, -3, -4, -5, -3, -2, -1},
    {-6, -6, -6, -6, -6, -6, -6, -6},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0},
    {6, 6, 6, 6, 6, 6, 6, 6},
    {1, 2, 3, 4, 5, 3, 2, 1}
};

// Define a function to print the chess board
void print_board(){
    int i, j;
    for (i=0; i<8; i++){
        printf("%d ", 8-i);
        for (j=0; j<8; j++){
            printf("%d ", chess_board[i][j]);
        }
        printf("\n");
    }
    printf("  a b c d e f g h\n");
}

// Define the main function
int main(void) {
    // Initialize the chess board
    print_board();
    return 0;
}