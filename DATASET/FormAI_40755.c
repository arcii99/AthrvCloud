//FormAI DATASET v1.0 Category: Dice Roller ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll the dice
int rollDice() {
    return (rand() % 6) + 1;
}

int main() {
    // Seed the random number generator with current time
    srand((unsigned int)time(NULL));
    
    int numDice;
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    int total = 0;
    for (int i = 0; i < numDice; i++) {
        int roll = rollDice();
        printf("Dice %d: %d\n", i+1, roll);
        total += roll;
    }
    printf("Total roll: %d\n", total);

    return 0;
}