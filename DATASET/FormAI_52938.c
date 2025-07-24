//FormAI DATASET v1.0 Category: Dice Roller ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed for random generation

    int roll_num; // Number of rolls requested by user
    printf("How many times would you like to roll the dice?\n");
    scanf("%d", &roll_num);

    // Roll the dice specified number of times and display results
    printf("Rolling the dice %d times...\n", roll_num);
    printf("Results: ");
    for (int i = 0; i < roll_num; i++) {
        int roll = rand() % 6 + 1; // Random number generation between 1-6
        printf("%d ", roll);
    }
    printf("\n");

    return 0;
}