//FormAI DATASET v1.0 Category: Game ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the game board
#define ROWS 10
#define COLS 10

// Function to initialize the game board with random numbers
void initialize_board(int board[][COLS]) {
    srand(time(NULL)); // Seed the random number generator with current time
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            board[i][j] = rand() % 10; // Generate a random number between 0 and 9
        }
    }
}

// Function to print the game board
void print_board(int board[][COLS]) {
    printf("\n");
    for(int i=0; i<ROWS; i++) {
        for(int j=0; j<COLS; j++) {
            printf("%d ", board[i][j]); // Print each cell of the game board
        }
        printf("\n");
    }
}

int main() {
    int board[ROWS][COLS];

    initialize_board(board); // Initialize the game board
    print_board(board); // Print the game board

    return 0;
}