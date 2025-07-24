//FormAI DATASET v1.0 Category: Dice Roller ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice, sides, roll, min, max, i;
    char choice;

    srand(time(NULL));  // Seeds the random number generator

    printf("Welcome to Dice Roller!\n\n");

    do {
        printf("Enter the number of dice to roll: ");
        scanf("%d", &dice);

        printf("Enter the number of sides per die: ");
        scanf("%d", &sides);

        printf("\n");

        min = dice;  // Minimum possible roll
        max = dice * sides;  // Maximum possible roll
        roll = 0;  // Initialize the total roll

        for (i = 0; i < dice; i++) {
            roll += rand() % sides + 1;  // Add a random roll for each die
        }

        printf("You rolled: %d\n", roll);

        if (roll == min) {
            printf("Wow, that was terrible!\n");
        } else if (roll == max) {
            printf("Awesome, that was a perfect roll!\n");
        } else {
            printf("Not bad!\n");
        }

        printf("\nDo you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nThanks for rolling with us!\n");

    return 0;
}