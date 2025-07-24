//FormAI DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int sides, rolls, i;
    int total = 0;

    srand(time(0)); // Setting the seed for random number generation
    
    printf("Welcome to the Dice Roller Program!\n");
    printf("How many sides does your die have? ");
    scanf("%d", &sides);

    printf("How many times do you want to roll the dice? ");
    scanf("%d", &rolls);

    printf("Rolling the dice %d times...\n", rolls);

    for(i = 0; i < rolls; i++) {
        int roll = (rand() % sides) + 1; // Generating a random number between 1 and the number of sides of the dice
        printf("Roll #%d: %d\n", i+1, roll);
        total += roll; // Keeping track of the total of all the rolls
    }

    printf("Total: %d\n", total); // Printing the total of all the rolls

    return 0; // Exiting the program
}