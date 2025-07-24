//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
/* Donald Knuth style Dice Roller Program */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int num_dice, num_sides, i, j, roll, sum;
    char again;

    srand((unsigned) time(NULL)); // initialize random number generator

    do {
        sum = 0; // initialize sum to zero
        printf("\nEnter the number of dice to roll: ");
        scanf("%d", &num_dice);

        printf("\nEnter the number of sides per die: ");
        scanf("%d", &num_sides);

        printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);
        printf("\nRoll results:\n");

        for (i = 0; i < num_dice; i++) {
            roll = (rand() % num_sides) + 1; // generate random dice roll
            printf("Die %d: %d\n", i+1, roll);
            sum += roll; // add roll to sum
        }

        printf("\nTotal: %d\n", sum);

        printf("\nRoll again? (y/n): ");
        scanf(" %c", &again);

    } while (again == 'y' || again == 'Y');

    return 0;
}