//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int faces, number, roll, i;
    char choice;

    srand(time(NULL)); //To ensure that random numbers are generated differently every time

    printf("*** Welcome to the Dice Roller! ***\n");

    do {
        printf("How many faces does the dice have? ");
        scanf("%d", &faces);

        printf("How many dice would you like to roll? ");
        scanf("%d", &number);

        printf("\nRolling...");
        for (i = 0; i < number; i++) {
            roll = (rand() % faces) + 1; //Generating random numbers between 1 and number of faces
            printf("\nThe %d-sided dice rolled %d.", faces, roll);
        }

        printf("\n\nWould you like to roll again? (y/n) ");
        scanf(" %c", &choice);

    } while (choice == 'y' || choice == 'Y');

    printf("\nThank you for using the Dice Roller!\n");

    return 0;
}