//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
// C Dice Roller program in Alan Turing style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides;
    int rolls;
    int roll;
    int i, j;

    srand(time(NULL)); // seed the random number generator with the current time

    printf("== WELCOME TO THE DICE ROLLER ==\n\n");

    while (1) {
        printf("Enter the number of sides (or enter -1 to exit): ");
        scanf("%d", &sides);

        if (sides == -1) {
            break; // exit program if user inputs -1
        }

        printf("Enter the number of rolls: ");
        scanf("%d", &rolls);

        printf("\nRolling the %d-sided dice %d times...\n\n", sides, rolls);

        for (i = 0; i < rolls; i++) {
            roll = rand() % sides + 1; // generate random number between 1 and sides
            printf("%d\n", roll);
        }

        printf("\n");
    }

    printf("Thanks for using the dice roller!\n");

    return 0;
}