//FormAI DATASET v1.0 Category: Dice Roller ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to roll dice */
int roll_dice(int sides) {
    return rand() % sides + 1;
}

int main() {
    int num_dice, num_sides;
    int i, total = 0;
    char response;

    srand(time(NULL)); // Set seed for random number generation
    
    printf("Welcome to the Dice Roller Program!\n");
    
    do {
        /* Prompt user for number of dice and sides */
        printf("\nHow many dice would you like to roll? ");
        scanf("%d", &num_dice);
        
        printf("How many sides does each die have? ");
        scanf("%d", &num_sides);
        
        /* Roll the dice and display the results */
        printf("\nRolling %d %d-sided dice...\n", num_dice, num_sides);
        for (i = 0; i < num_dice; i++) {
            int roll = roll_dice(num_sides);
            printf("Die %d: %d\n", i+1, roll);
            total += roll;
        }
        printf("Total: %d\n", total);
        
        /* Ask user if they want to roll again */
        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &response);
        
        /* Reset total for next roll */
        total = 0;
        
    } while (response == 'y');
    
    printf("\nThank you for using the Dice Roller Program!\n");

    return 0;
}