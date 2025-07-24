//FormAI DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to roll and print the dice values
void rollDice(int numDice, int numSides) {
    int total = 0;
    printf("Rolling %d dice with %d sides...\n", numDice, numSides);
    for (int i = 0; i < numDice; i++) {
        int value = rand() % numSides + 1;
        printf("Dice %d: %d\n", i+1, value);
        total += value;
    }
    printf("Total: %d\n", total);
}

int main() {
    srand(time(NULL));  // Seed the random number generator
    
    int numDice, numSides, repeat;
    char choice;
    do {
        printf("Enter the number of dice: ");
        scanf("%d", &numDice);
        printf("Enter the number of sides on the dice: ");
        scanf("%d", &numSides);
        rollDice(numDice, numSides);
        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
    
    return 0;
}