//FormAI DATASET v1.0 Category: Dice Roller ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice) {
    int total = 0;
    for (int i = 0; i < num_dice; i++) {
        total += (rand() % 6) + 1; // roll a single dice
    }
    return total;
}

int main() {
    srand(time(NULL)); // seed the random number generator
    printf("*** Welcome to the Dice Roller! ***\n");
    while (1) {
        printf("How many dice would you like to roll (or 0 to quit)? ");
        int num_dice;
        scanf("%d", &num_dice);
        if (num_dice == 0) {
            printf("Thanks for playing!\n");
            break;
        }
        printf("Rolling %d dice...\n", num_dice);
        int total = roll_dice(num_dice);
        printf("Result: %d\n\n", total);
    }
    return 0;
}