//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int sides) {
    // generates a random number between 1 and `sides`
    return rand() % sides + 1;
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    int sides;
    printf("Welcome to Ye Olde Dice Roller!\n");
    printf("Enter the number of sides on your dice (between 2 and 20): ");
    scanf("%d", &sides);
    
    // check if the input is within range
    if (sides < 2 || sides > 20) {
        printf("Invalid input. Please enter a number between 2 and 20.\n");
        return 0;
    }
    
    char choice;
    do {
        printf("\nEnter 'r' to roll the dice or 'q' to quit: ");
        scanf(" %c", &choice);
        if (choice == 'r') {
            printf("Rolling the dice...\n");
            int result = roll_dice(sides);
            printf("You rolled a %d!\n", result);
        } else if (choice == 'q') {
            printf("Fare thee well, adventurer!\n");
            return 0;
        } else {
            printf("Invalid input. Please enter 'r' to roll or 'q' to quit.\n");
        }
    } while (1);
    
    return 0;
}