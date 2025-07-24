//FormAI DATASET v1.0 Category: Dice Roller ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char c;

    do {
        // Set the seed for the random number generator
        srand(time(NULL));

        // Generate two random numbers between 1 and 6
        int roll1 = rand() % 6 + 1;
        int roll2 = rand() % 6 + 1;

        // Print out the values of the dice
        printf("You rolled a %d and a %d\n", roll1, roll2);

        // Ask the user if they want to roll again
        printf("Roll again? (y/n): ");
        scanf(" %c", &c);
        printf("\n");
    } while (c == 'y' || c == 'Y');

    return 0;
}