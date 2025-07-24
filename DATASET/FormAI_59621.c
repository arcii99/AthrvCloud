//FormAI DATASET v1.0 Category: Dice Roller ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_DICE_VAL 1
#define MAX_DICE_VAL 6

// Function to simulate dice roll
int roll_dice(int num_of_dice) {
    int i, total = 0;
    for(i = 0; i < num_of_dice; i++) {
        total += (rand() % MAX_DICE_VAL) + MIN_DICE_VAL;
    }
    return total;
}

int main() {

    int num_of_dice;
    char c;

    srand((unsigned) time(NULL)); // Seed random number generator with time

    printf("Welcome to the C Dice Roller! Press 'Q' to quit at any time.\n");

    while(1) {
        printf("How many dice do you want to roll? ");
        if(scanf("%d", &num_of_dice) == 0) {
            // User entered something other than an integer
            scanf("%c", &c); // Clear input buffer
            if(c == 'Q' || c == 'q') {
                printf("Thank you for using the C Dice Roller!\n");
                break; // Exit program
            }
            else {
                printf("Invalid input, please try again.\n");
                continue; // Ask for input again
            }
        }
        if(num_of_dice < 1) {
            printf("You must roll at least one dice, please try again.\n");
            continue; // Ask for input again
        }
        int total = roll_dice(num_of_dice);
        printf("You rolled a total of %d with %d dice.\n", total, num_of_dice);
    }

    return 0;
}