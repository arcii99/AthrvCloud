//FormAI DATASET v1.0 Category: Chess engine ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define BOARD_SIZE 8

int board[BOARD_SIZE][BOARD_SIZE];

/* Function to initialize the chess board */
void initializeBoard() {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            board[i][j] = rand() % 2;
        }
    }
}

/* Function to display the chess board in a cool style */
void displayBoard() {
    int i, j;
    printf("\t\t\t\t\t  A  B  C  D  E  F  G  H\n");
    printf("\t\t\t\t\t *************************\n");
    for(i=0; i<BOARD_SIZE; i++) {
        printf("\t\t\t\t\t%d", BOARD_SIZE-i);
        for(j=0; j<BOARD_SIZE; j++) {
            printf("|");
            if(board[i][j] == 0) {
                printf("  ");
            }
            else {
                printf("♜ ");
            }
        }
        printf("|\n\t\t\t\t\t *************************\n");
    }
}

/* Main function */
int main() {
    srand(time(NULL)); // Set random seed
    printf("\n\t\t\t\t\tWe are going to play a game of chess, but with a twist!\n\n");
    printf("\t\t\t\t\t    Each player will only have rooks on the board!\n\n");
    printf("\t\t\t\t\tWatch out for those pesky pawns that will try to attack your rooks!\n\n");

    initializeBoard(); // Initialize the chess board randomly
    displayBoard(); // Display the chess board

    return 0;
}