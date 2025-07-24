//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int roll, i;
    char answer;

    srand(time(NULL)); // Seed the random number generator

    do {
        printf("How many dice do you want to roll? ");
        scanf("%d", &roll);

        printf("You rolled:");

        for(i = 0; i < roll; i++) {
            printf(" %d", (rand() % 6) + 1);
        }

        printf("\nDo you want to roll again? (y/n) ");
        scanf(" %c", &answer);
    } while(answer == 'y' || answer == 'Y');

    printf("Thanks for playing!\n");

    return 0;
}