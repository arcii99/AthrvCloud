//FormAI DATASET v1.0 Category: Memory Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 16  // define the board size
#define MAX_GUESS_COUNT 8 // define the maximum number of guesses

int main()
{
    int board[BOARD_SIZE]; // initialize the board array
    int guess[MAX_GUESS_COUNT] = {0}; // initialize the guess array
    int remaining = BOARD_SIZE; // initialize the remaining pairs to be found
    int guessCount = 0; // initialize the guess count

    // Fill board with pairs of numbers from 1 to 8 randomly
    srand(time(NULL));
    for (int i = 0; i < BOARD_SIZE; i += 2) {
        int num = rand() % 8 + 1;

        board[i] = num;
        board[i + 1] = num;
    }

    // Shuffle board
    for (int i = 0; i < BOARD_SIZE; i++) {
        int temp = board[i];
        int j = rand() % BOARD_SIZE;

        board[i] = board[j];
        board[j] = temp;
    }

    // Game loop
    while (remaining > 0 && guessCount < MAX_GUESS_COUNT) {
        printf("\nRemaining pairs: %d   Guess count: %d\n", remaining, guessCount);

        // Print board
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (guess[i / 2] || i % 4 == 0) {
                printf("\n");
            }

            if (guess[i / 2]) {
                printf("%2d ", board[i]);
            } else {
                printf("   ");
            }
        }

        // Get user input
        int first, second;
        do {
            printf("\n\nEnter two distinct numbers between 1 and 16 separated by a space: ");
        } while (scanf("%d %d", &first, &second) != 2 || first < 1 || first > BOARD_SIZE || second < 1 || second > BOARD_SIZE || first == second || guess[(first - 1) / 2] || guess[(second - 1) / 2]);

        // Check guess
        guessCount++;
        if (board[first - 1] == board[second - 1]) {
            guess[(first - 1) / 2] = 1;
            guess[(second - 1) / 2] = 1;
            remaining--;
        } else {
            printf("\nSorry, those numbers are not a match.\n");
        }
    }

    // Game over
    printf("\n\nGAME OVER!\n");
    if (remaining == 0) {
        printf("You won in %d guesses!\n", guessCount);
    } else {
        printf("You lost! The remaining pairs were:\n");
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (!guess[i / 2]) {
                printf("%2d ", board[i]);
            } else {
                printf("   ");
            }

            if (i % 4 == 3) {
                printf("\n");
            }
        }
    }

    return 0;
}