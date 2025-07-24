//FormAI DATASET v1.0 Category: Dice Roller ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void roll_dice() {
    int roll;

    srand(time(NULL));
    roll = rand()%6 + 1;

    printf("You rolled a %d!\n", roll);
}

int main() {
    char again = 'y';

    while(again == 'y' || again == 'Y') {
        printf("Press enter to roll the dice!\n");
        getchar(); // wait for user to press enter
        roll_dice();

        printf("Roll again? (y/n)");
        scanf(" %c", &again);
    }

    printf("Thanks for playing!\n");
    return 0;
}