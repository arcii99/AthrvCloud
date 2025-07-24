//FormAI DATASET v1.0 Category: Dice Roller ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    srand(time(NULL)); // Initialize random seed

    int dice1, dice2, sum;
    char choice;

    printf("Welcome to the Dice Roller program!\n");

    do {
        dice1 = (rand() % 6) + 1; // Generate a random number between 1 and 6 for the first dice
        dice2 = (rand() % 6) + 1; // Generate a random number between 1 and 6 for the second dice

        sum = dice1 + dice2; // Calculate the sum of the two dice

        printf("You rolled a %d and a %d!\n", dice1, dice2);

        if (sum == 7) {
            printf("WOW! You got a LUCKY 7! Congratulations!\n");
        } else {
            printf("Your total is %d.\n", sum);
        }

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("Thank you for using the Dice Roller program! Goodbye.\n");

    return 0;
}