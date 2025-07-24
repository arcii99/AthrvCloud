//FormAI DATASET v1.0 Category: Dice Roller ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    int dice, numFaces, rollAgain;
    srand(time(0)); // Seed the random number generator with the current time

    printf("Welcome to the C Dice Roller!\n");

    do {
        printf("\nEnter the number of faces on your dice: ");
        scanf("%d", &numFaces);

        if(numFaces < 1) {
            printf("\nInvalid number of faces. Please enter a positive integer greater than 0.\n");
            continue; // Start the loop again
        }

        dice = rand() % numFaces + 1; // Random number between 1 and numFaces inclusive
        printf("You rolled a %d!\n", dice);

        printf("\nDo you want to roll again? Enter 1 for yes or 0 for no: ");
        scanf("%d", &rollAgain);

    } while(rollAgain == 1);

    printf("\nThanks for playing! Goodbye.\n");

    return 0;
}