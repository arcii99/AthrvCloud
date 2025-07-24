//FormAI DATASET v1.0 Category: Dice Roller ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll a dice
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));
    
    int keepPlaying = 1;
    printf("Welcome to Dice Roller!\n");
    while (keepPlaying) {
        printf("How many dice would you like to roll? ");
        int numDice;
        scanf("%d", &numDice);
        if (numDice <= 0) {
            printf("Invalid input.\n");
            continue;
        }
        printf("Rolling %d dice...\n", numDice);
        int total = 0;
        for (int i = 0; i < numDice; i++) {
            int result = rollDice();
            printf("Dice %d: %d\n", i + 1, result);
            total += result;
        }
        printf("Total: %d\n", total);
        printf("Would you like to roll again? (1=yes, 0=no) ");
        scanf("%d", &keepPlaying);
    }
    printf("Thanks for playing!\n");
    return 0;
}