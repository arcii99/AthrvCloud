//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice, int num_sides);

int main(void)
{
    int num_dice, num_sides, roll_total;
    char choice;

    srand((unsigned) time(NULL)); // Seed random number generator

    do {
        // Get input from user
        printf("Enter the number of dice to roll: ");
        scanf("%d", &num_dice);

        printf("Enter the number of sides per die: ");
        scanf("%d", &num_sides);

        // Roll the dice
        roll_total = roll_dice(num_dice, num_sides);

        // Display result
        printf("You rolled a total of %d\n", roll_total);

        // Ask user if they want to roll again
        printf("Roll again? (y/n): ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    return 0;
}

int roll_dice(int num_dice, int num_sides)
{
    int i, roll, total = 0;

    for(i = 0; i < num_dice; i++) {
        roll = rand() % num_sides + 1; // Generate random roll between 1 and num_sides
        total += roll;
        printf("Roll %d: %d\n", i+1, roll); // Display each roll
    }

    return total;
}