//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_dice, num_sides, i, j;
    char response;
    srand(time(NULL));

    do {
        printf("Enter the number of dice you want to roll: ");
        scanf("%d", &num_dice);
        printf("Enter the number of sides on each die: ");
        scanf("%d", &num_sides);

        printf("You rolled: ");
        for (i = 0; i < num_dice; i++) {
            printf("%d ", (rand() % num_sides) + 1);
        }
        printf("\n");

        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &response);

    } while (response == 'y' || response == 'Y');

    printf("Thank you for rolling!\n");
    return 0;
}