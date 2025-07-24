//FormAI DATASET v1.0 Category: Dice Roller ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with time
    int sides, rolls, total = 0;
    bool quit = false;

    printf("Welcome to the Dice Roller!\n");

    do {
        printf("Enter the number of sides on the dice (type 0 to quit): ");
        scanf("%d", &sides);

        if (sides > 0) {
            printf("Enter the number of rolls: ");
            scanf("%d", &rolls);

            printf("\nRolling %d %d-sided dice...\n", rolls, sides);

            for (int i = 0; i < rolls; i++) {
                int result = rand() % sides + 1;
                printf("Roll %d: %d\n", i+1, result);
                total += result; // add the result to the total
            }

            printf("\nTotal: %d\n\n", total);
            total = 0; // reset the total for the next roll
        } else {
            printf("Thanks for rolling with us!\n");
            quit = true;
        }
    } while (!quit);

    return 0;
}