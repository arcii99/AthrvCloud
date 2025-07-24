//FormAI DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int num_dice);

int main(void) 
{
    // initialize random seed
    srand(time(NULL));
    
    int num_dice, num_rolls;
    printf("Welcome to the Dice Roller Program!\n");
    printf("Enter number of dice to roll: ");
    scanf("%d", &num_dice);
    printf("Enter number of times to roll the dice: ");
    scanf("%d", &num_rolls);
    
    for (int i = 0; i < num_rolls; i++) 
    {
        int result = roll_dice(num_dice);
        printf("Roll %d: %d\n", i+1, result);
    }
    
    printf("Thank you for using the Dice Roller Program!\n");
    return 0;
}

// Function to roll dice
int roll_dice(int num_dice) 
{
    int sum = 0;
    for (int i = 0; i < num_dice; i++) 
    {
        int roll = rand() % 6 + 1;
        printf("Dice %d: %d\n", i+1, roll);
        sum += roll;
    }
    return sum;
}