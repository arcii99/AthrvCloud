//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 25

// Function to generate a random number between 1 and 75
int generateRandomNumber() {
    return (rand() % 75) + 1;
}

int main() {
    // Array to hold the numbers that are already called
    int calledNumbers[75] = {0};

    // Initialize random seed
    srand(time(NULL));

    // Shuffle the numbers 1 to 75 to simulate the calling of numbers
    int shuffledNumbers[75];
    for (int i = 0; i < 75; i++) {
        shuffledNumbers[i] = i + 1;
    }
    for (int i = 0; i < 75; i++) {
        int j = rand() % 75;
        int temp = shuffledNumbers[i];
        shuffledNumbers[i] = shuffledNumbers[j];
        shuffledNumbers[j] = temp;
    }

    // Bingo card
    int bingoCard[SIZE];
    for (int i = 0; i < SIZE; i++) {
        bingoCard[i] = -1; // Initialize the card with -1
    }

    // Fill the bingo card with random numbers in the appropriate range
    int i = 0;
    while (i < SIZE) {
        int randomNumber = generateRandomNumber();
        if (bingoCard[i] == -1 && (randomNumber >= i * 3 + 1 && randomNumber <= (i + 1) * 3)) {
            bingoCard[i] = randomNumber;
            i++;
        }
    }

    // Print the bingo card
    printf("BINGO CARD:\n");
    for (int i = 0; i < SIZE; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("%2d ", bingoCard[i]);
    }
    printf("\n");

    // Call numbers until someone wins
    int playerOneWins = 0, playerTwoWins = 0;
    for (int i = 0; i < 75; i++) {
        int calledNumber = shuffledNumbers[i];

        // Check if the number is already called
        if (calledNumbers[calledNumber - 1] == 1) {
            continue;
        }
        calledNumbers[calledNumber - 1] = 1;

        // Check if the number is on a player's card and mark it off if it is
        for (int j = 0; j < SIZE / 2; j++) {
            if (bingoCard[j] == calledNumber) {
                bingoCard[j] = -1;
                break;
            }
        }
        for (int j = SIZE / 2; j < SIZE; j++) {
            if (bingoCard[j] == calledNumber) {
                bingoCard[j] = -1;
                break;
            }
        }

        // Check if a player has won
        // Player one wins
        if (bingoCard[0] == -1 && bingoCard[1] == -1 && bingoCard[2] == -1 && bingoCard[3] == -1 && bingoCard[4] == -1) {
            playerOneWins = 1;
            break;
        }
        if (bingoCard[5] == -1 && bingoCard[6] == -1 && bingoCard[7] == -1 && bingoCard[8] == -1 && bingoCard[9] == -1) {
            playerOneWins = 1;
            break;
        }
        if (bingoCard[10] == -1 && bingoCard[11] == -1 && bingoCard[13] == -1 && bingoCard[14] == -1 && bingoCard[15] == -1) {
            playerOneWins = 1;
            break;
        }
        if (bingoCard[20] == -1 && bingoCard[21] == -1 && bingoCard[23] == -1 && bingoCard[24] == -1) {
            playerOneWins = 1;
            break;
        }
        if (bingoCard[0] == -1 && bingoCard[5] == -1 && bingoCard[10] == -1 && bingoCard[15] == -1 && bingoCard[20] == -1) {
            playerOneWins = 1;
            break;
        }
        // Player two wins
        if (bingoCard[4] == -1 && bingoCard[9] == -1 && bingoCard[13] == -1 && bingoCard[18] == -1 && bingoCard[23] == -1) {
            playerTwoWins = 1;
            break;
        }
        if (bingoCard[3] == -1 && bingoCard[8] == -1 && bingoCard[12] == -1 && bingoCard[17] == -1 && bingoCard[22] == -1) {
            playerTwoWins = 1;
            break;
        }
        if (bingoCard[1] == -1 && bingoCard[6] == -1 && bingoCard[16] == -1 && bingoCard[21] == -1) {
            playerTwoWins = 1;
            break;
        }
        if (bingoCard[2] == -1 && bingoCard[7] == -1 && bingoCard[17] == -1 && bingoCard[22] == -1) {
            playerTwoWins = 1;
            break;
        }
        if (bingoCard[0] == -1 && bingoCard[6] == -1 && bingoCard[18] == -1 && bingoCard[24] == -1) {
            playerTwoWins = 1;
            break;
        }
    }

    // Print the winner
    if (playerOneWins) {
        printf("PLAYER ONE WINS!\n");
    } else if (playerTwoWins) {
        printf("PLAYER TWO WINS!\n");
    } else {
        printf("NO WINNER :(\n");
    }

    return 0;
}