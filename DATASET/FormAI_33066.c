//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to print the bingo card
void printCard(int card[ROWS][COLS]) {
    printf("\n\n");
    printf("|B | I | N | G | O |\n");

    for (int row = 0; row < ROWS; row++) {
        printf("------------------\n");
        for (int col = 0; col < COLS; col++) {
            if (card[row][col] == -1) {
                printf("|  |");
            } else {
                printf("|%2d|", card[row][col]);
            }
        }
        printf("\n");
    }
    printf("------------------\n\n");
}

int main() {
    int card[ROWS][COLS];
    int usedNumbers[76] = {0};

    // Seed the random number generator
    srand(time(NULL));

    // Initialize the card with -1 to represent empty slots
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            card[row][col] = -1;
        }
    }

    // Generate the numbers for the card
    for (int col = 0; col < COLS; col++) {
        int numbers[15];
        int count = 0;
        while (count < 15) {
            int number = rand() % 15 + 1 + col * 15;
            if (!usedNumbers[number]) {
                numbers[count] = number;
                usedNumbers[number] = 1;
                count++;
            }
        }
        // Fill the column with the generated numbers
        for (int row = 0; row < ROWS; row++) {
            card[row][col] = numbers[row];
        }
    }

    // Generate the free space in the middle of the card
    card[2][2] = -1;

    // Print the initial card
    printCard(card);

    // Simulate the bingo game
    int numberCount = 0;
    while (numberCount < 25) {
        // Generate a random number between 1 and 75
        int number = rand() % 75 + 1;

        // Check if the number has already been called
        if (usedNumbers[number]) {
            continue;
        }

        // Call the number
        printf("The number is: %d\n", number);
        usedNumbers[number] = 1;
        numberCount++;

        // Check if any numbers on the card match the called number
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                if (card[row][col] == number) {
                    card[row][col] = -1;
                    printCard(card);
                    
                    // Check if the player has won
                    int rowSum = 0, colSum = 0, diagSum1 = 0, diagSum2 = 0;
                    for (int i = 0; i < ROWS; i++) {
                        rowSum = 0;
                        colSum = 0;
                        for (int j = 0; j < COLS; j++) {
                            rowSum += (card[i][j] == -1);
                            colSum += (card[j][i] == -1);
                        }
                        if (rowSum == ROWS || colSum == COLS) {
                            printf("Congratulations, you won!\n");
                            return 0;
                        }
                        diagSum1 += (card[i][i] == -1);
                        diagSum2 += (card[i][COLS - 1 - i] == -1);
                    }
                    if (diagSum1 == ROWS || diagSum2 == ROWS) {
                        printf("Congratulations, you won!\n");
                        return 0;
                    }
                }
            }
        }
    }

    // If we reach here, it means the player has not won
    printf("Sorry, better luck next time!\n");
    return 0;
}