//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int choice;
    int numDice;
    int numSides;
    printf("Welcome to Genius Dice Roller!\n");
    do {
        printf("==============================\n");
        printf("Please choose an option:\n");
        printf("[1] Roll a single die\n");
        printf("[2] Roll multiple dice\n");
        printf("[3] Quit\n");
        printf("==============================\n");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("How many sides would you like the die to have? ");
            scanf("%d", &numSides);
            srand(time(0));
            int result = rand() % numSides + 1;
            printf("Your result is: %d\n", result);
        } else if (choice == 2) {
            printf("How many dice would you like to roll? ");
            scanf("%d", &numDice);
            printf("How many sides would you like each die to have? ");
            scanf("%d", &numSides);
            srand(time(0));
            int total = 0;
            for (int i = 1; i <= numDice; i++) {
                int result = rand() % numSides + 1;
                printf("Roll %d: %d\n", i, result);
                total += result;
            }
            printf("Total: %d\n", total);
        } else if (choice == 3) {
            printf("Thanks for using Genius Dice Roller!");
            return 0;
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}