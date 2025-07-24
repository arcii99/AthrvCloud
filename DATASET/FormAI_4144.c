//FormAI DATASET v1.0 Category: Dice Roller ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int n, i, sum = 0;
    char yn;

    //Seed random number generator
    srand((unsigned) time(NULL));

    //Get number of dice to roll
    printf("How many dice would you like to roll? ");
    scanf("%d", &n);
    printf("\n");

    //Roll the dice
    for(i=1; i<=n; i++) {
        printf("Die %d rolled: %d\n", i, rand() % 6 + 1);
    }

    //Ask to roll again
    printf("\nRoll again? (Y/N): ");
    scanf(" %c", &yn);

    //Roll again if user enters 'y' or 'Y'
    if(yn == 'y' || yn == 'Y') {
        main();
    } else {
        printf("Goodbye!");
    }

    return 0;
}