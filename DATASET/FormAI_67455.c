//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int numRolls;
    int numSides;
    int i;
    int result;

    srand(time(NULL)); // seed the random number generator

    printf("Welcome to the Cheerful Dice Roller Program!\n");
    printf("How many times would you like to roll the dice? (Enter a positive integer): ");
    scanf("%d", &numRolls);
    while (numRolls <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        scanf("%d", &numRolls);
    }

    printf("How many sides does your dice have? (Enter a positive integer): ");
    scanf("%d", &numSides);
    while (numSides <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        scanf("%d", &numSides);
    }

    printf("\nRolling the dice %d times...\n", numRolls);

    for (i = 1; i <= numRolls; i++) {
        result = rand() % numSides + 1;
        printf("Roll %d: %d\n", i, result);
    }

    printf("\nThank you for using the Cheerful Dice Roller Program! We hope you have a great day.\n");

    return 0;
}