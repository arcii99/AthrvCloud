//FormAI DATASET v1.0 Category: Dice Roller ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate random number between 1 to 6 (inclusive)
int rollDice()
{
    return rand() % 6 + 1;
}

int main()
{
    srand(time(NULL)); // Seed to generate random numbers

    int dice; // Variable to store result of dice roll

    printf("====================\n");
    printf("|     Dice Roll     |\n");
    printf("====================\n");

    do {
        printf("Press 'r' key to roll the dice or 'q' key to quit: ");
        char ch = getchar(); // Get user input

        if (ch == 'q' || ch == 'Q') {
            printf("Exiting...\n");
            break;
        }

        if (ch == 'r' || ch == 'R') {
            printf("Rolling the dice...\n");
            dice = rollDice();
            printf("The result is: %d\n", dice);
        }

        // Clear input buffer
        while ((ch = getchar()) != '\n' && ch != EOF);

    } while (1);

    return 0;
}