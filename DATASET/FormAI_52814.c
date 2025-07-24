//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the size of the Bingo card
#define ROWS 5
#define COLS 5

// Function to generate a random number between 1 and max_num
int rand_num(int max_num) {
    return (rand() % max_num) + 1;
}

int main() {
    // Initialize RNG
    srand(time(NULL));

    // Define the Bingo card
    int card[ROWS][COLS] = {0};

    // Generate the numbers for the Bingo card
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Generate a random number between the appropriate range
            int num_range = 15;
            if (j == 2 && i == 2) {
                // The center spot is always free
                card[i][j] = 0;
            } else {
                int max_num = (num_range * j) + num_range;
                int min_num = max_num - num_range + 1;
                card[i][j] = rand_num(num_range) + min_num;
            }
        }
    }

    // Print the Bingo card
    printf("  B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == 0) {
                printf("| F ");
            } else {
                printf("| %2d", card[i][j]);
            }
        }
        printf("|\n");
    }

    printf("\n");

    // Play the game
    printf("Let's play Bingo!\n");
    int numbers[75] = {0};
    int num_index = 0;

    while (1) {
        // Draw a random number
        int next_num = rand_num(75);

        // Check if the number has already been drawn
        int already_drawn = 0;
        for (int i = 0; i < num_index; i++) {
            if (numbers[i] == next_num) {
                already_drawn = 1;
                break;
            }
        }

        if (already_drawn) {
            // The number has already been drawn, skip this iteration
            continue;
        }

        // Add the number to the list of drawn numbers
        numbers[num_index] = next_num;
        num_index++;

        // Print the number that was drawn
        printf("The next number is: %d\n", next_num);

        // Check if the number is on the player's card
        int found_number = 0;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == next_num) {
                    // Mark the number on the card as found
                    card[i][j] = 0;
                    found_number = 1;
                    break;
                }
            }
        }

        // Print the updated Bingo card
        printf("  B   I   N   G   O\n");
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == 0) {
                    printf("| F ");
                } else {
                    printf("| %2d", card[i][j]);
                }
            }
            printf("|\n");
        }
        printf("\n");

        if (!found_number) {
            // The number was not on the player's card, continue to the next iteration
            continue;
        }

        // Check if the player has won
        int all_zeros = 1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] != 0) {
                    all_zeros = 0;
                    break;
                }
            }
        }

        if (all_zeros) {
            // The player has won, end the game
            printf("BINGO!! You win!\n");
            break;
        }
    }

    return 0;
}