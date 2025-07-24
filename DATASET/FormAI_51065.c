//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Set the seed for the random number generator
    srand(time(NULL));
    
    // Declare variables
    int num_dice, num_sides, i, j, total = 0;
    
    // Prompt user for number of dice and number of sides on each die
    printf("Welcome to the Dice Roller program!\n");
    printf("How many dice would you like to roll? ");
    scanf("%d", &num_dice);
    printf("How many sides does each die have? ");
    scanf("%d", &num_sides);
    
    // Roll the dice and add up the total
    for (i = 0; i < num_dice; i++) {
        int roll = rand() % num_sides + 1;
        printf("You rolled a %d!\n", roll);
        total += roll;
    }
    
    // Display the total
    printf("Your total score is: %d\n", total);
    
    // Ask the user if they would like to roll again
    char again;
    printf("Would you like to roll again? (y/n) ");
    scanf(" %c", &again);
    
    // If the user wants to roll again, repeat the process
    if (again == 'y' || again == 'Y') {
        main();
    } else {
        printf("Thanks for using the Dice Roller program! Goodbye!\n");
    }
    
    return 0;
}