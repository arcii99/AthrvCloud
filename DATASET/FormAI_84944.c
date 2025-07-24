//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to get random number within given range
int getRandom(int min, int max) {
    return (rand()%(max-min+1)) + min;
}

int main() {
    int dice1, dice2, total;
    char choice;

    printf("Welcome to Medieval Dice Roller!\n");
    printf("Press any key to roll the dice.\n");

    // Setting up random seed
    srand(time(0));

    do {
        getchar();  // pause until user presses any key
        dice1 = getRandom(1, 6);
        dice2 = getRandom(1, 6);
        total = dice1 + dice2;

        printf("\nYou rolled a %d and a %d, totaling to %d.\n", dice1, dice2, total);

        if (total == 2) {
            printf("Sorry, you rolled a snake eyes.\n");
        } else if (total <= 7) {
            printf("Low roll, better luck next time.\n");
        } else {
            printf("Great roll! The gods are in your favor.\n");
        }

        printf("Would you like to roll again? (y/n) ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing Medieval Dice Roller!\n");

    return 0;
}