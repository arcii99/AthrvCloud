//FormAI DATASET v1.0 Category: Dice Roller ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    /* Function to simulate the rolling of one six-sided dice */
    return (rand() % 6) + 1;
}

int main() {
    /* Seed the random number generator */
    srand(time(NULL));

    /* Prompt the user for the number of dice and rolls */
    int num_dice, num_rolls;
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &num_rolls);

    /* Allocate memory for the results array */
    int *results = (int *) malloc(num_dice * num_rolls * sizeof(int));

    /* Roll the dice and store the results in the array */
    for (int i = 0; i < num_rolls; i++) {
        for (int j = 0; j < num_dice; j++) {
            results[i * num_dice + j] = roll_dice();
        }
    }

    /* Print the results */
    for (int i = 0; i < num_rolls; i++) {
        printf("Roll %d: ", i+1);
        for (int j = 0; j < num_dice; j++) {
            printf("%d ", results[i * num_dice + j]);
        }
        printf("\n");
    }

    /* Free the memory used by the results array */
    free(results);

    return 0;
}