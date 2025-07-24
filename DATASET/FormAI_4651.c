//FormAI DATASET v1.0 Category: Dice Roller ; Style: interoperable
#include<stdio.h> // to use the input and output functions
#include<stdlib.h> // to use the random number generator function

int main() {
    int dice, rolls, i, total = 0;
    char response;

    printf("Welcome to C Dice Roller!\n");

    do {
        printf("Enter the number of dice to roll: ");
        scanf("%d", &dice);

        printf("Enter the number of rolls per dice: ");
        scanf("%d", &rolls);

        printf("Rolling %d dice %d times:\n", dice, rolls);

        for(i=0; i<dice; i++) { // loop through each dice
            printf("Dice #%d:\n", i+1);
            total = 0;

            for(int j=0; j<rolls; j++) { // roll each dice the given number of times
                int result = rand() % 6 + 1;
                total += result;
                printf("\tRoll #%d: %d\n", j+1, result);
            }

            printf("Total for dice #%d: %d\n", i+1, total);
        }

        printf("Would you like to roll again? (y/n): ");
        scanf(" %c", &response);

    } while(response == 'y' || response == 'Y');

    printf("Thank you for using C Dice Roller!\n");

    return 0;
}