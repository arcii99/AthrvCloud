//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice() {
    return (rand() % 6) + 1;
}

int main() {
    srand(time(0));

    int num_dice;
    printf("How many dice do you want to roll?\n");
    scanf("%d", &num_dice);

    int sum = 0;
    for (int i = 0; i < num_dice; i++) {
        int roll = roll_dice();
        sum += roll;
        printf("You rolled a %d\n", roll);
    }

    printf("Total: %d\n", sum);

    return 0;
}