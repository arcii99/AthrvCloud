//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to roll a dice
int roll_dice(int num_sides) {
    int result = rand() % num_sides + 1;
    return result;
}

int main() {
    srand(time(NULL));
    
    int num_dice, num_sides, i, total, max_limit;
    
    printf("Welcome to the Medieval Dice Roller!\n");
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num_dice);
    printf("Enter the number of sides on each die: ");
    scanf("%d", &num_sides);
    printf("Enter the maximum limit for rolling the dice (1 - 100): ");
    scanf("%d", &max_limit);
    
    printf("\nRolling %d dice with %d sides each...\n\n", num_dice, num_sides);
    
    // roll the dice and display the results
    for(i = 1, total = 0; i <= num_dice; i++) {
        int roll = roll_dice(num_sides);
        printf("Die %d: %d\n", i, roll);
        total += roll;
    }
    
    // check if the total exceeds the maximum limit
    if(total > max_limit) {
        printf("\nTotal rolled: %d\n", total);
        printf("Whoa! That's too high for this realm. Please try again.\n");
    } else {
        printf("\nTotal rolled: %d\n", total);
        printf("Congratulations! You are a true champion of the dice.\n");
    }
    
    return 0;
}