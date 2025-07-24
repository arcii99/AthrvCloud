//FormAI DATASET v1.0 Category: Memory Game ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define GRID_SIZE 4

// Function to print the game board
void printBoard(int board[][GRID_SIZE]) {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%d\t", board[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int board[GRID_SIZE][GRID_SIZE] = {0}; // Initialize board with zeros
    int num_pairs = GRID_SIZE * GRID_SIZE / 2; // Calculate number of pairs required
    int pairs_left = num_pairs; // Initialize pairs left to be guessed as the required number of pairs
    int row1, col1, row2, col2;

    // Initialize random number generator
    srand((unsigned) time(NULL));

    // Place pairs randomly on the board
    for (int num = 1; num <= num_pairs; num++) {
        int pair_count = 0;
        while (pair_count < 2) {
            int random_row = rand() % GRID_SIZE;
            int random_col = rand() % GRID_SIZE;
            if (board[random_row][random_col] == 0) {
                board[random_row][random_col] = num; // Place the number on the board
                pair_count++; // Increment pair count
            }
        }
    }

    // Print the board for testing purposes
    printBoard(board);

    // Game loop
    while (pairs_left > 0) {
        printf("Enter two coordinates to reveal (in the format row1 col1 row2 col2): ");
        scanf("%d %d %d %d", &row1, &col1, &row2, &col2);

        // Check if the given coordinates are valid
        if (row1 < 0 || row1 >= GRID_SIZE || col1 < 0 || col1 >= GRID_SIZE ||
            row2 < 0 || row2 >= GRID_SIZE || col2 < 0 || col2 >= GRID_SIZE) {
            printf("Invalid coordinates. Please enter valid coordinates.\n");
            continue;
        }

        // Check if the two cells have already been matched
        if (board[row1][col1] == -1 || board[row2][col2] == -1) {
            printf("One or both of the cells have already been matched. Please enter new coordinates.\n");
            continue;
        }

        // Check if the two cells have the same number
        if (board[row1][col1] == board[row2][col2]) {
            board[row1][col1] = -1; // Mark the cells as matched
            board[row2][col2] = -1;
            pairs_left--; // Decrement the number of pairs left to be guessed
            printf("Hurray! You have matched a pair!\n");
        } else {
            printf("Oops! The two cells do not match. Please try again.\n");
        }
        // Print the updated board for testing purposes
        printBoard(board);
    }

    printf("Congratulations! You have won the game!");
    return 0;
}