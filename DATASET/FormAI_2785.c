//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>

int main() {
    char response = 'Y';
    printf("Welcome to the C Dice Roller\n");

    do {
        int numDice, numSides;
        printf("How many dice do you want to roll? ");
        scanf("%d", &numDice);

        printf("How many sides does each die have? ");
        scanf("%d", &numSides);

        printf("Rolling %d D%d...\n", numDice, numSides);

        srand(time(NULL));
        int total = 0;

        for(int i = 0; i < numDice; i++) {
            int roll = rand() % numSides + 1;
            printf("Roll %d: %d\n", i+1, roll);
            total += roll;
        }

        printf("Total: %d\n", total);

        printf("Do you want to roll again? (Y/N) ");
        do {
            scanf(" %c", &response);
            response = toupper(response);
            if(response != 'Y' && response != 'N') {
                printf("Invalid input. Please enter Y or N. ");
            }
        } while(response != 'Y' && response != 'N');
    } while(response == 'Y');

    printf("Thanks for rolling with the C Dice Roller!\n");

    return 0;
}