//FormAI DATASET v1.0 Category: Checkers Game ; Style: mathematical
#include <stdio.h>
#define SIZE 8

char board[SIZE][SIZE]; /* an 8x8 board */

/* Function to initialize the board with pieces */
void initialize_board() {
    int i, j;
    for(i = 0; i < SIZE; i++) {
        for(j = 0; j < SIZE; j++) {
            if(i % 2 == 0) {
                if(j % 2 == 0) board[i][j] = ' ';
                else board[i][j] = 'B';
            }
            else {
                if(j % 2 == 0) board[i][j] = 'B';
                else board[i][j] = ' ';
            }
        }
    }
}

/* Function to print the board */
void print_board() {
    printf("  0 1 2 3 4 5 6 7\n");
    for(int i = 0; i < SIZE; i++) {
        printf("%d ", i);
        for(int j = 0; j < SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("%d\n", i);
    }
    printf("  0 1 2 3 4 5 6 7\n");
}

/* Main function */
int main() {
    initialize_board(); /* set up the board */
    print_board(); /* print the initial board */
    
    /* game loop */
    while(1) {
        /* players take turns making moves */
        
        /* check for a win condition */
        
        /* check for a draw condition */
    }
    
    return 0;
}