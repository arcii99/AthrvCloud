//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: careful
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 5

// Function to print a bingo card
void printCard(int card[ROWS][COLS]) {
    printf("B   I   N   G   O\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (i == 2 && j == 2) {
                printf(" F  ");
            } else {
                printf("%2d  ", card[i][j]);
            }
        }
        printf("\n");
    }
}

// Function to check if a number is already on the card
bool isOnCard(int card[ROWS][COLS], int num) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (card[i][j] == num) {
                return true;
            }
        }
    }
    return false;
}

// Function to generate a random number that is not already on the card
int getNewNumber(int card[ROWS][COLS]) {
    int num;
    do {
        num = rand() % 15 + 1;
        if (num == 1) {
            num = 'B';
        } else if (num == 2) {
            num = 'I';
        } else if (num == 3) {
            num = 'N';
        } else if (num == 4) {
            num = 'G';
        } else if (num == 5) {
            num = 'O';
        } else {
            num = (num - 6) * 5 + rand() % 5 + 1;
        }
    } while (isOnCard(card, num));
    return num;
}

int main() {
    srand(time(NULL));  // Seed the random number generator

    // Initialize the card with 0's
    int card[ROWS][COLS] = {0};

    // Fill in the card with random numbers
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            card[i][j] = getNewNumber(card);
        }
    }

    // Print the card
    printCard(card);

    // Play the game
    int nums[75] = {0};
    int numIndex = 0;
    bool gameOver = false;
    while (!gameOver) {
        // Generate a new random number
        int num = getNewNumber(card);

        // Print the number
        printf("Next number: %d\n", num);

        // Check if the number is on the card
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (card[i][j] == num) {
                    card[i][j] = 0;  // Mark the number as found on the card
                    break;
                }
            }
        }

        // Add the number to the list of called numbers
        nums[numIndex++] = num;

        // Check for a Bingo
        bool bingo = false;
        for (int i = 0; i < ROWS; i++) {
            if (card[i][0] == 0 && card[i][1] == 0 && card[i][2] == 0 && card[i][3] == 0 && card[i][4] == 0) {
                bingo = true;
                break;
            }
            if (card[0][i] == 0 && card[1][i] == 0 && card[2][i] == 0 && card[3][i] == 0 && card[4][i] == 0) {
                bingo = true;
                break;
            }
        }
        if (card[0][0] == 0 && card[1][1] == 0 && card[2][2] == 0 && card[3][3] == 0 && card[4][4] == 0) {
            bingo = true;
        }
        if (card[0][4] == 0 && card[1][3] == 0 && card[2][2] == 0 && card[3][1] == 0 && card[4][0] == 0) {
            bingo = true;
        }
        if (bingo) {
            printf("BINGO!!!\n");
            gameOver = true;
        }

        // Check for a tied game
        if (numIndex == 75) {
            printf("Tied game.\n");
            gameOver = true;
        }
    }

    // Print the list of called numbers
    printf("Called numbers:\n");
    for (int i = 0; i < numIndex; i++) {
        printf("%3d ", nums[i]);
        if ((i + 1) % 15 == 0) {
            printf("\n");
        }
    }

    return 0;
}