//FormAI DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int numDice, numRolls, i, j, rollSum;
    char response;

    srand(time(NULL)); // use current time to seed random number generator

    do {
        printf("How many dice do you want to roll? (max 5): ");
        scanf("%d", &numDice);
        printf("How many times do you want to roll? (max 10): ");
        scanf("%d", &numRolls);

        if (numDice > 5 || numRolls > 10) {
            printf("Invalid input. Please try again.\n\n");
        } else {
            // roll the dice and display results
            for (i = 1; i <= numRolls; i++) {
                rollSum = 0;
                printf("Roll %d: ", i);
                for (j = 1; j <= numDice; j++) {
                    int roll = rand() % 6 + 1;
                    rollSum += roll;
                    printf("%d ", roll);
                }
                printf("= %d\n", rollSum);
            }

            // ask if user wants to roll again
            printf("\nDo you want to roll again? (y/n): ");
            scanf("%s", &response);
            printf("\n");
        }
    } while (response == 'y');

    return 0;
}