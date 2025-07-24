//FormAI DATASET v1.0 Category: Dice Roller ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rolls, sides, i, total = 0;
    srand(time(NULL)); // initialize random seed

    printf("Welcome to the Super Amazing Dice Roller!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &rolls);

    printf("How many sides should each die have? ");
    scanf("%d", &sides);

    printf("Rolling %d %d-sided dice...\n\n", rolls, sides);

    for (i = 1; i <= rolls; i++) {
        int roll = rand() % sides + 1; // generate random num between 1 and sides
        printf("Die %d: %d\n", i, roll);
        total += roll; // keep track of total roll value
    }

    printf("\nTotal roll value: %d\n", total);

    printf("\nThanks for using the Super Amazing Dice Roller! Goodbye!");

    return 0;
}