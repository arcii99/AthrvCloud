//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int bingo_card[25];
    int bingo_numbers[75];
    int rows[5], cols[5], diag1, diag2;
    int count, number;

    // Seed the random number generator with current time
    srand(time(NULL));

    // Generate the bingo card with random numbers
    for (int i = 0; i < 25; i++) {
        bingo_card[i] = rand() % 75 + 1;
        for (int j = 0; j < i; j++) {
            if (bingo_card[i] == bingo_card[j]) {
                // If the number is already present, regenerate it
                i--;
                break;
            }
        }
    }

    // Generate the bingo numbers
    for (int i = 0; i < 75; i++) {
        bingo_numbers[i] = i + 1;
    }

    // Shuffle the bingo numbers randomly
    for (int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = bingo_numbers[i];
        bingo_numbers[i] = bingo_numbers[j];
        bingo_numbers[j] = temp;
    }

    // Initialize the rows, columns, and diagonals
    for (int i = 0; i < 5; i++) {
        rows[i] = 0;
        cols[i] = 0;
    }
    diag1 = 0;
    diag2 = 0;

    // Start the game
    count = 0;
    printf("Get ready to play Bingo!\n");
    while (1) {
        // Draw a number from the bingo numbers
        number = bingo_numbers[count];
        printf("The next number is: %d\n", number);
        count++;

        // Check if the number is present in the bingo card
        for (int i = 0; i < 25; i++) {
            if (bingo_card[i] == number) {
                // Mark the number on the bingo card
                bingo_card[i] = 0;

                // Update the rows, columns, and diagonals
                int row = i / 5;
                int col = i % 5;
                rows[row]++;
                cols[col]++;
                if (row == col) {
                    diag1++;
                }
                if (row + col == 4) {
                    diag2++;
                }

                // Check if any row, column, or diagonal is completed
                for (int j = 0; j < 5; j++) {
                    if (rows[j] == 5) {
                        printf("Bingo! You completed row %d.\n", j + 1);
                        return 0;
                    }
                    if (cols[j] == 5) {
                        printf("Bingo! You completed column %d.\n", j + 1);
                        return 0;
                    }
                }
                if (diag1 == 5) {
                    printf("Bingo! You completed diagonal 1.\n");
                    return 0;
                }
                if (diag2 == 5) {
                    printf("Bingo! You completed diagonal 2.\n");
                    return 0;
                }

                // Display the updated bingo card
                printf("Here is your updated bingo card:\n");
                for (int j = 0; j < 25; j++) {
                    if (bingo_card[j] == 0) {
                        printf("[  ] ");
                    } else {
                        printf("[%2d] ", bingo_card[j]);
                    }
                    if (j % 5 == 4) {
                        printf("\n");
                    }
                }
                break;
            }
            if (i == 24) {
                printf("Sorry, the number is not in your card.\n");
            }
        }
        printf("Press Enter to continue.\n");
        while (getchar() != '\n');
    }
    return 0;
}