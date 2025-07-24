//FormAI DATASET v1.0 Category: Dice Roller ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, numDice;

    // Seed the random generator with time
    srand(time(NULL));

    // Get input from user
    printf("How many sides does each die have? ");
    scanf("%d", &sides);
    printf("How many dice would you like to roll? ");
    scanf("%d", &numDice);

    // Calculate and print the sum of the rolls
    int sum = 0;
    for (int i = 0; i < numDice; i++) {
        int roll = rand() % sides + 1;
        sum += roll;
        printf("Roll %d: %d\n", i+1, roll);
    }
    printf("Total: %d\n", sum);

    return 0;
}