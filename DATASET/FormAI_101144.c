//FormAI DATASET v1.0 Category: Dice Roller ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int dice = 0;
    int result = 0;
    char choice = 'y';

    printf("Welcome to the Dice Roller Program!\n");

    while(choice == 'y') {
        printf("Please enter the number of dice you want to roll: ");
        scanf("%d", &dice);

        if(dice <= 0) {
            printf("Invalid input. Please enter a positive number.\n");
            continue;
        }

        result = 0;
        srand(time(NULL));

        for(int i = 1; i <= dice; i++) {
            result += (rand() % 6) + 1;
        }

        printf("You rolled a total of %d.\n", result);

        printf("Do you want to roll again? (y/n): ");
        scanf(" %c", &choice);
    }

    printf("Thank you for using the Dice Roller Program!\n");

    return 0;
}