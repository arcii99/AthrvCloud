//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
// C Dice Roller program in Alan Touring style

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Set the random seed based on the current time
    srand(time(NULL));
    
    // Declare variables for the number of dice and sides 
    int num_dice, num_sides;
    
    // Get user input for the number of dice and sides
    printf("How many dice do you want to roll?\n");
    scanf("%d", &num_dice);
    
    printf("How many sides on each die?\n");
    scanf("%d", &num_sides);
    
    // Roll the dice and display the results
    int total = 0;
    printf("Rolling %d %d-sided dice...\n", num_dice, num_sides);
    
    for (int i = 0; i < num_dice; i++) {
        int roll = rand() % num_sides + 1;
        printf("Die %d rolls %d\n", i+1, roll);
        total += roll;
    }
    
    printf("Total: %d", total);
    
    return 0;
}