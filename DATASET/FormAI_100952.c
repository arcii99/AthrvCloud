//FormAI DATASET v1.0 Category: Dice Roller ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to simulate rolling of dice
int rollDice() {
    int roll;
    roll = (rand() % 6) + 1; // Generates random number between 1-6
    return roll;
}

int main() {
    int numDice, numRolls, sum;
    printf("Enter the number of dice you want to roll: ");
    scanf("%d", &numDice);
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls);
    printf("\n");
    srand(time(NULL)); // Initializes random number generator

    for (int i = 0; i < numRolls; i++) {
        sum = 0;
        printf("Roll %d: ", i+1);
        for (int j = 0; j < numDice; j++) {
            int roll = rollDice();
            printf("%d ", roll);
            sum += roll;
        }
        printf("Sum: %d\n", sum);
    }
    return 0;
}