//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int rollDice(int min, int max) {
    return rand() % (max + 1 - min) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator using current time

    int sides;
    int numDice;
    int total = 0;

    printf("Welcome to the futuristic dice roller!\n");

    // Prompt user for number of sides and number of dice
    printf("How many sides does each die have? ");
    scanf("%d", &sides);
    printf("How many dice do you want to roll? ");
    scanf("%d", &numDice);

    // Print out the results of each roll and the total
    for (int i = 1; i <= numDice; i++) {
        int result = rollDice(1, sides);
        total += result;
        printf("Roll %d: %d\n", i, result);
    }
    printf("Total: %d\n", total);

    return 0;
}