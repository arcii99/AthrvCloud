//FormAI DATASET v1.0 Category: Memory Game ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 4

int main() {
    int board[SIZE][SIZE] = {0}; // Create the memory board.
    int temp[SIZE*SIZE] = {0}; // Temporary array to shuffle the numbers.
    int row, col, row2, col2, temp_num, counter = 1, moves = 0;
    char guess1, guess2;
    srand(time(NULL)); // Initialize random seed.

    // Initialize temporary array with numbers.
    for (int i = 0; i < SIZE*SIZE; i++) {
        temp[i] = counter;
        counter++;
    }

    // Shuffle the numbers in temporary array.
    for (int i = 0; i < SIZE*SIZE; i++) {
        row = rand() % SIZE;
        col = rand() % SIZE;

        do {
            row2 = rand() % SIZE;
            col2 = rand() % SIZE;
        } while (row2 == row && col2 == col);

        temp_num = temp[i];
        temp[i] = temp[row2*SIZE+col2];
        temp[row2*SIZE+col2] = temp_num;

        // Place shuffled numbers onto the board until board is full.
        if (board[row][col] == 0) {
            board[row][col] = temp[i];
        } else {
            i--;
        }
    }

    // Print the board.
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            printf("%3d", board[i][j]);
        }
        printf("\n");
    }

    // Main game loop.
    do {
        // Prompt user for first guess.
        printf("\nEnter first guess (row col): ");
        scanf("%d %d", &row, &col);
        guess1 = board[row][col];

        // Prompt user for second guess.
        printf("Enter second guess (row col): ");
        scanf("%d %d", &row2, &col2);
        guess2 = board[row2][col2];

        // If guesses match, remove tiles and increment moves.
        if (guess1 == guess2) {
            board[row][col] = 0;
            board[row2][col2] = 0;
            moves++;
        } else {
            printf("No match!\n");
        }

        // Check if game is over.
        counter = 0;
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                if (board[i][j] != 0) {
                    counter++;
                }
            }
        }
    } while (counter > 0);

    // Print game statistics.
    printf("\nCongratulations! You won in %d moves.\n", moves);

    return 0;
}