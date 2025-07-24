//FormAI DATASET v1.0 Category: Dice Roller ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice();

int main() {
    int sides, rolls, i;
    char choice;

    srand(time(0));

    do {
        printf("Enter the number of sides on your dice: ");
        scanf("%d", &sides);

        printf("Enter the number of rolls you want to make: ");
        scanf("%d", &rolls);

        printf("Rolling %d %d-sided dice...\n", rolls, sides);

        for(i = 0; i < rolls; i++) {
            printf("Roll %d: %d\n", i+1, roll_dice(sides));
        }

        printf("Do you want to roll again? (Y/N): ");
        scanf(" %c", &choice);

    } while(choice == 'y' || choice == 'Y');

    printf("Thanks for rolling with us!\n");

    return 0;
}

int roll_dice(int sides) {
    return (rand() % sides) + 1;
}