//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1 and 6
int rollDice() {
    srand(time(NULL)); // seed the generator
    return rand() % 6 + 1; // generate random number between 1 and 6
}

int main() {
    int dice1, dice2, total;

    printf("Welcome to the visionary DICE ROLLER!\n\n");

    while(1) {
        printf("Roll the dice? (Y/N): ");
        char choice;
        scanf(" %c", &choice);

        if(choice == 'Y' || choice == 'y') {
            dice1 = rollDice();
            dice2 = rollDice();
            total = dice1 + dice2;

            printf("\nDice 1: %d\nDice 2: %d\nTotal: %d\n\n", dice1, dice2, total);

            if(total == 7) {
                printf("You got LUCKY! You rolled a 7!!!\n\n");
            }
        }
        else if(choice == 'N' || choice == 'n') {
            printf("Thanks for playing! Have a good day!\n");
            break;
        }
        else {
            printf("Invalid Choice! Please choose again.\n\n");
        }
    }

    return 0;
}