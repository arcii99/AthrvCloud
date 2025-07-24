//FormAI DATASET v1.0 Category: Dice Roller ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1; // Returns number between 1 to 6 (inclusive)
}

int main() {
    srand(time(NULL)); // Seeds the random number generator with current time
    int totalRolls = 0;
    int numRolls[6] = {0}; // Initializes an array to store the number of times each number is rolled

    printf("Welcome to the Dice Roller program!\n");
    printf("Enter the number of times you want to roll the dice: ");
    
    while (scanf("%d", &totalRolls) != 1 || totalRolls <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        while (getchar() != '\n'); // Clears the input buffer
    }

    printf("\nRolling the dice %d times...\n", totalRolls);

    for (int i = 0; i < totalRolls; i++) {
        int roll = rollDice();
        numRolls[roll-1]++;
    }

    printf("\nResults:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d: %d (%.2f%%)\n", i+1, numRolls[i], (float)numRolls[i]/totalRolls * 100);
    }

    return 0;
}