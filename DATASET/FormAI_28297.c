//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int diceRolls[6] = {0}; // initialize all indexes to 0
    srand(time(NULL)); // seed the random number generator with current time

    printf("How many times do you want to roll the dice? ");
    int numRolls;
    scanf("%d", &numRolls);

    for (int i = 0; i < numRolls; i++) {
        int roll = rand() % 6; // generates a random number between 0 and 5
        diceRolls[roll]++; // increment the count for that number rolled
    }

    printf("Dice Roll Results:\n");

    for (int i = 0; i < 6; i++) {
        printf("%d: %d times\n", i+1, diceRolls[i]); // print the count for each number
    }

    return 0;
}