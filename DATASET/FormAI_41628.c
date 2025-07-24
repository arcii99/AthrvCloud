//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int diceCount, diceSides, i, j, sum;
    char answer;
    
    do {

        printf("How many dice do you want to roll? (max 10) ");
        scanf("%d", &diceCount);

        while (diceCount > 10) {
            printf("That is too many dice. Please enter a number between 1 and 10. ");
            scanf("%d", &diceCount);
        }

        printf("How many sides do the dice have? ");
        scanf("%d", &diceSides);

        printf("You want to roll %d d%d's. Is that correct? (y/n) ", diceCount, diceSides);
        scanf(" %c", &answer);

    } while (answer != 'y');

    printf("\nRolling...\n");
    
    srand(time(NULL));
    
    for (i = 1; i <= diceCount; i++) {
        
        int roll = rand() % diceSides + 1;
        printf("Die %d: %d\n", i, roll);
        sum += roll;
    }
    
    if (diceCount > 1) {
        printf("\nTotal: %d", sum);
    }
    
    return 0;
}