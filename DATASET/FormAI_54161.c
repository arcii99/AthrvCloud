//FormAI DATASET v1.0 Category: Dice Roller ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numRolls, numSides, i, j;
    char c;

    // Seed random number generator
    srand(time(NULL));

    // Prompt user for number of rolls and number of sides
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);
    printf("Enter the number of sides: ");
    scanf("%d", &numSides);

    // Roll the dice and display results
    printf("\nRolling %d %d-sided dice...\n\n", numRolls, numSides);
    for (i = 1; i <= numRolls; i++) {
        printf("Roll %d: ", i);
        for (j = 0; j < numSides; j++) {
            printf("%d ", rand() % numSides + 1);
        }
        printf("\n");
    }

    // Prompt user to roll again
    printf("\nWould you like to roll again? (y/n) ");
    scanf(" %c", &c);
    if (c == 'y' || c == 'Y') {
        main(); // Recursive call to main function
    } else {
        printf("\nGoodbye!\n");
    }

    return 0;
}