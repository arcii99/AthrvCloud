//FormAI DATASET v1.0 Category: Dice Roller ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int number, i;
    srand(time(0)); //seed the random number generator with current time

    printf("~~~Welcome to the Peaceful Dice Roller program~~~\n");
    printf("How many dice would you like to roll? (Enter a positive integer): ");
    scanf("%d", &number);

    if(number > 0) {
        printf("\nYou have chosen to roll %d dice!\n", number);
        printf("Rolling the dice...please wait...\n\n");

        for(i = 1; i <= number; i++) {
            int dice_roll = (rand() % 6) + 1; //generate a random number between 1 and 6 (inclusive)
            printf("Dice %d: %d\n", i, dice_roll);
        }

        printf("\n~~~Thank you for using our peaceful dice roller program~~~\n");
    }
    else {
        printf("\nInvalid input. Please enter a positive integer.\n");
    }

    return 0;
}