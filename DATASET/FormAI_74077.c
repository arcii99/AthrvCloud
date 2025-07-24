//FormAI DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int min, max, num;
    char choice;

    printf("Welcome to the Dice Roller!\n\n");

    do {
        printf("Enter the minimum number: ");
        scanf("%d", &min);

        printf("Enter the maximum number: ");
        scanf("%d", &max);

        if(min >= max) {
            printf("\nInvalid input. Minimum must be less than maximum.\n\n");
            continue;
        }

        srand(time(0));

        num = (rand() % (max - min + 1)) + min;
        printf("\nThe dice rolled: %d\n\n", num);

        printf("Do you want to roll again? (Y/N): ");
        scanf(" %c", &choice);

        if(choice != 'Y' && choice != 'y' && choice != 'N' && choice != 'n') {
            printf("\nInvalid input. Please enter 'Y' or 'N'.\n\n");
        }

        printf("\n");

    } while(choice == 'Y' || choice == 'y');

    printf("Thanks for playing!\n");

    return 0;
}