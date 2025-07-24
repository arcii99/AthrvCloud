//FormAI DATASET v1.0 Category: Dice Roller ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_dice(int);

int main()
{
    int dice_faces; // The number of faces on the dice
    int num_rolls; // The number of times the dice will be rolled
    int total = 0; // Stores the sum of all rolls
    
    // Set the random seed based on the current time
    srand(time(NULL));
    
    // Get user input for the number of faces
    printf("Welcome to Retro Dice Roller!\n");
    printf("Enter the number of faces on the dice: ");
    scanf("%d", &dice_faces);
    
    // Get user input for the number of rolls
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &num_rolls);
    
    // Roll the dice the specified number of times and add the result to the total
    for(int i = 1; i <= num_rolls; i++)
    {
        int roll_result = roll_dice(dice_faces);
        printf("Roll %d: %d\n", i, roll_result);
        total += roll_result;
    }
    
    // Print the total of all rolls
    printf("The total of all rolls is: %d\n", total);
    
    return 0;
}

// Function to generate a random number between 1 and num_faces (inclusive)
int roll_dice(int num_faces)
{
    return (rand() % num_faces) + 1;
}