//FormAI DATASET v1.0 Category: Dice Roller ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(int sides) {
    return (rand() % sides) + 1;
}

void printResults(int result) {
    printf("You rolled a %d!\n", result);
}

int main() {
    srand(time(NULL));
    int sides = 0;
    printf("Enter the number of sides for your dice: ");
    scanf("%d", &sides);

    if (sides < 2) {
        printf("Invalid number of sides. Must be at least 2.\n");
        return 1;
    }

    char choice = ' ';
    do {
        printf("Press enter to roll the dice...\n");
        getchar(); // clear input buffer
        rollDice(sides);
    } while ((choice = getchar()) == '\n');

    return 0;
}