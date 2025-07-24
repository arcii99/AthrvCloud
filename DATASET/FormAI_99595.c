//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Welcome message
    printf("\nWelcome to the Cryptic Dice Roller!\n");
    printf("\nRolling the dice...\n");

    // Seed the random number generator with the current time
    srand(time(NULL));

    // Roll the dice 5 times
    int rolls[5];
    for (int i = 0; i < 5; i++) {
        // Generate a random number between 1 and 6
        int roll = rand() % 6 + 1;
        
        // Store the roll in the rolls array
        rolls[i] = roll;
    }

    // Display the rolls
    printf("\nYour rolls are:");
    for (int i = 0; i < 5; i++) {
        printf(" %d", rolls[i]);
    }

    // Calculate the total roll
    int total_roll = 0;
    for (int i = 0; i < 5; i++) {
        total_roll += rolls[i];
    }

    // Display the total roll
    printf("\nYour total roll is: %d\n", total_roll);

    // Exit message
    printf("\nThanks for using the Cryptic Dice Roller! Good luck!\n");

    return 0;
}