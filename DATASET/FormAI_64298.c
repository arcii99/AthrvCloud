//FormAI DATASET v1.0 Category: Dice Roller ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int roll_again = 1;
    char name[20];

    printf("Welcome to the Dice Roller!\n");
    printf("Please enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Let's roll some dice!\n", name);

    // Keep rolling dice until user decides to quit
    while (roll_again) {
        int num_dice, num_sides, sum;
        printf("How many dice would you like to roll? ");
        scanf("%d", &num_dice);
        printf("How many sides do the dice have? ");
        scanf("%d", &num_sides);
        sum = 0;

        // Roll each die and keep track of total sum
        printf("\nRolling %dd%d...\n", num_dice, num_sides);
        for (int i = 0; i < num_dice; i++) {
            int roll = rand() % num_sides + 1;
            printf("Die %d rolled a %d\n", i + 1, roll);
            sum += roll;
        }
        printf("Total sum: %d\n\n", sum);

        // Ask the user if they want to roll again
        printf("Roll again? (1 for yes, 0 for no) ");
        scanf("%d", &roll_again);
        printf("\n");
    }

    printf("Thank you for playing, %s! Goodbye!\n", name);
    return 0;
}