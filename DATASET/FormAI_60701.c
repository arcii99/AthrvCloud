//FormAI DATASET v1.0 Category: Dice Roller ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numSides, total = 0;
  
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);
  
    printf("How many sides should the dice have? ");
    scanf("%d", &numSides);

    /* Seed the random number generator */
    srand(time(NULL));
  
    /* Roll the dice and print out the results */
    for (int i = 1; i <= numDice; i++) {
        int roll = rand() % numSides + 1;
        printf("Dice #%d: %d\n", i, roll);
        total += roll;
    }


    /* If it's only one dice, mention singular */
    if (numDice == 1)
        printf("You rolled a singular 1d%d for a total of %d.\n", numSides, total);
    else
        printf("You rolled %d dices with %d sides each for a total of %d.\n", numDice, numSides, total);

    return 0;
}