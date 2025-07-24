//FormAI DATASET v1.0 Category: Game ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define SIZE 10
#define MAX_VALUE 9

// Function declarations
void printBoard(int board[][SIZE]);
void shiftSquares(int board[][SIZE]);

// Main function
int main() {
    srand(time(NULL));

    // Initialize the board with random values
    int board[SIZE][SIZE];
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            board[row][col] = rand() % MAX_VALUE + 1;
        }
    }

    // Print the initial board
    printf("Initial Board:\n");
    printBoard(board);

    // Shift the squares in the board
    shiftSquares(board);

    // Print the final board
    printf("Final Board:\n");
    printBoard(board);

    return 0;
}

// Function definitions
void printBoard(int board[][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            printf("%d ", board[row][col]);
        }
        printf("\n");
    }
    printf("\n");
}

void shiftSquares(int board[][SIZE]) {
    int rowShift = rand() % SIZE;
    int colShift = rand() % SIZE;
    int value = board[rowShift][colShift];

    // Shift the rows
    for (int row = 0; row < SIZE; row++) {
        int temp = board[row][0];
        board[row][0] = board[row][1];
        board[row][1] = temp;
    }

    // Shift the columns
    for (int col = 0; col < SIZE; col++) {
        int temp = board[0][col];
        board[0][col] = board[1][col];
        board[1][col] = temp;
    }

    // Update the shifted square
    board[rowShift][colShift] = value;
}