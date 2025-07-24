//FormAI DATASET v1.0 Category: Dice Roller ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(0));
    int diceNum, diceSides, rollAgain;
    printf("Welcome to the Surrealist Dice Roller!\n");
    printf("How many dice do you want to roll?\n");

    scanf("%d", &diceNum);
    printf("How many sides does each die have?\n");
    scanf("%d", &diceSides);

    do {
        int total = 0;
        printf("\nRolling...\n");
        for (int i = 0; i < diceNum; i++) {
            int roll = rand() % diceSides + 1;
            printf("Die %d: %d\n", i + 1, roll);
            total += roll;
        }
        printf("\nTotal: %d\n", total);

        char answers[][30] = {"The stars scream with jelly.",
                               "The moon shifts in your pocket.",
                               "The dice roll backwards.",
                               "You become a lizard.",
                               "Everything you see becomes soup.",
                               "The walls melt and call your name.",
                               "Your shadow grows wings."};

        printf("\nSurrealist Result: %s\n", answers[rand()%7]);

        printf("\nDo you want to roll again? (1 for yes, 0 for no)\n");
        scanf("%d", &rollAgain);

    } while (rollAgain == 1);
    printf("Thank you for playing the Surrealist Dice Roller. Goodbye!\n");

    return 0;
}