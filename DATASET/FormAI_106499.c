//FormAI DATASET v1.0 Category: Checkers Game ; Style: curious
#include <stdio.h>

#define DIMENSION 8 // Checker boards are always 8x8

// The checker board is represented using a 2D array
char board[DIMENSION][DIMENSION];

// Initialize the board with checkers in their starting positions
void initializeBoard() {
    for(int i=0; i<DIMENSION; i++) {
        for(int j=0; j<DIMENSION; j++) {
            if(i < 3 && (i+j) % 2 == 0) {
                board[i][j] = 'X'; // Mark this as a black checker piece
            } else if (i > 4 && (i+j) % 2 == 0) {
                board[i][j] = 'O'; // Mark this as a red checker piece
            } else {
                board[i][j] = ' '; // Empty spot on the board
            }
        }
    }
}

// Print the current state of the board
void printBoard() {
    printf("   1  2  3  4  5  6  7  8\n");
    printf(" +-----------------------+\n");
    for(int i=0; i<DIMENSION; i++) {
        printf("%c| ", 'A' + i); // Display the row indicator
        for(int j=0; j<DIMENSION; j++) {
            printf("%c | ", board[i][j]);
        }
        printf("\n +-----------------------+\n");
    }
}

int main() {
    initializeBoard(); // Initialize the board with pieces in their starting positions
    printBoard(); // Display the initial board setup

    // TODO: Implement the rest of the main game loop here
    //       - Keep track of whose turn it is
    //       - Allow players to make valid moves
    //       - End the game when one player has captured all of the other player's pieces

    return 0;
}