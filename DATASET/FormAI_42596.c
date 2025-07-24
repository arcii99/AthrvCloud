//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {

    int result;
    char response;

    printf("Welcome to the Dice Rolling Game!\n");

    do {
        srand(time(NULL));
        result = rand() % 6 + 1;

        printf("\nYou have rolled a %d!", result);

        printf("\n\nWould you like to roll again? (y/n): ");
        scanf(" %c", &response);
    } while (response == 'y' || response == 'Y');

    printf("\n\nThanks for playing! Goodbye.\n");

    return 0;
}