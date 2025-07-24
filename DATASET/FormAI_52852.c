//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 0 and 100
int generateRandomNumber() {
    return rand() % 101;
}

int main() {
    // Seed the random number generator with current time
    srand(time(NULL));

    // Declare variables
    int invasionProbability = generateRandomNumber();
    int userInput;

    // Print welcome message and prompt user for input
    printf("Welcome to the Alien Invasion Probability Calculator! \n");
    printf("Please enter the number of Alien Spaceships detected: ");
    scanf("%d", &userInput);

    // Calculate the probability of an alien invasion
    if (invasionProbability >= 50) {
        if (userInput > 0 && userInput <= 5) {
            printf("\nALERT! The probability of an alien invasion is very high! Evacuate immediately!\n\n");
        } else if (userInput > 5 && userInput <= 10) {
            printf("\nWARNING! The probability of an alien invasion is moderate. Prepare for defense measures.\n\n");
        } else {
            printf("\nThere is no immediate threat of an alien invasion. Thank you for using the Alien Invasion Probability Calculator.\n\n");
        }
    } else {
        printf("\nThere is no immediate threat of an alien invasion. Thank you for using the Alien Invasion Probability Calculator.\n\n");
    }

    return 0;
}