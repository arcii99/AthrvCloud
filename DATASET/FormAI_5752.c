//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Seed random number generator
    srand(time(NULL));

    // Create an array to store 75 integers
    int bingo[75];

    // Populate array with numbers 1-75
    for (int i = 0; i < 75; i++) {
        bingo[i] = i + 1;
    }

    // Shuffle the array
    for (int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = bingo[i];
        bingo[i] = bingo[j];
        bingo[j] = temp;
    }

    // Print the shuffled array
    printf("BINGO NUMBERS:\n");
    for (int i = 0; i < 75; i++) {
        printf("%d ", bingo[i]);
        if ((i + 1) % 15 == 0) {
            printf("\n");
        }
    }

    // Start the game
    int guess, count = 0;
    char choice;

    printf("\n");

    // Keep playing until the user chooses to quit
    do {
        // Get user's guess
        printf("Enter your guess (1-75): ");
        scanf("%d", &guess);

        // Check if guess is valid
        if (guess < 1 || guess > 75) {
            printf("Invalid guess. Please enter a number between 1 and 75.\n");
            continue;
        }

        // Check if guess is correct
        for (int i = 0; i < 75; i++) {
            if (bingo[i] == guess) {
                bingo[i] = -1;  // Mark number as called
                count++;
                break;
            }
        }

        // Print the updated bingo board
        printf("\nBINGO BOARD:\n");
        for (int i = 0; i < 75; i++) {
            if (bingo[i] == -1) {
                printf("X ");
            } else {
                printf("%d ", bingo[i]);
            }
            if ((i + 1) % 15 == 0) {
                printf("\n");
            }
        }

        // Check if user has won
        if (count >= 5) {
            printf("\nBINGO! You have won!\n");
            break;
        }

        // Ask user if they want to continue playing
        printf("\nDo you want to continue playing? (y/n): ");
        scanf(" %c", &choice);

    } while (choice != 'n');

    // Say goodbye
    printf("\nThank you for playing BINGO!\n");

    return 0;
}