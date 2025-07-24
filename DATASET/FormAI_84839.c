//FormAI DATASET v1.0 Category: Dice Roller ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, rolls, i, j;
    char response;
    srand(time(NULL)); // Seed random number generator
    
    do {
        // Get user input for number of sides and rolls
        printf("How many sides should the dice have? ");
        scanf("%d", &sides);
        printf("How many times should the dice be rolled? ");
        scanf("%d", &rolls);

        // Create an array to store the results of each roll
        int results[rolls];

        // Roll the dice the specified number of times and store the results
        for (i = 0; i < rolls; i++) {
            results[i] = (rand() % sides) + 1;
        }

        // Print out the results in a user-friendly way
        printf("\nRolling %d %d-sided dice...\n", rolls, sides);
        printf("Results:\n");
        for (i = 0; i < rolls; i++) {
            printf("Roll %d: ", i+1);
            for (j = 0; j < results[i]; j++) {
                printf("*");
            }
            printf("\n");
        }

        // Ask the user if they want to roll again
        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &response);
        printf("\n");

    } while (response == 'y');

    return 0;
}