//FormAI DATASET v1.0 Category: Table Game ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Initializing the random number generator

    printf("Welcome to the C Table Game!\n");
    printf("The rules are simple:\n");
    printf("You will roll two dice.\n");
    printf("If the sum of the dice is even, you win!\n");
    printf("If the sum of the dice is odd, you lose.\n");
    printf("Are you ready to play?\n");

    char choice;
    int total;

    do {
        printf("Press any key to roll the dice...");
        getchar(); // Waiting for user input
        int dice1 = rand() % 6 + 1; // Generating random number between 1 to 6
        int dice2 = rand() % 6 + 1;
        total = dice1 + dice2;

        printf("You have rolled %d and %d, for a total of %d.\n", dice1, dice2, total);

        if (total % 2 == 0) {
            printf("Congratulations! You win!\n");
        } else {
            printf("Sorry, you lost. Try again.\n");
        }

        printf("Do you want to play again? (Y/N)\n");
        scanf(" %c", &choice); // Reading user input

        while ((getchar()) != '\n'); // Clearing the input buffer

    } while (choice == 'Y' || choice == 'y');

    printf("Thank you for playing the C Table Game!\n");

    return 0;
}