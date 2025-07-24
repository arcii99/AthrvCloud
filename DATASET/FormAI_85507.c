//FormAI DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numOfRolls, numOfSides, total = 0;
    srand(time(NULL)); // initialize seed for rand function using current time

    printf("How many dice would you like to roll? ");
    scanf("%d", &numOfRolls);

    printf("How many sides does each die have? ");
    scanf("%d", &numOfSides);

    printf("\nRolling %d %d-sided dice...\n\n", numOfRolls, numOfSides);

    for(int i=1; i<=numOfRolls; i++) {
        int roll = rand() % numOfSides + 1; // generate random number between 1 and numOfSides
        printf("Dice %d: %d\n", i, roll);
        total += roll; // add roll to total
    }

    printf("\nTotal: %d", total); // print total of all rolls

    return 0;
}