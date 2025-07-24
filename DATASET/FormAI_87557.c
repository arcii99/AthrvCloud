//FormAI DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int faces = 6;  // Number of faces of each die
    int num_dice = 2;  // Number of dice to roll
    int results[13] = {0};  // Array to store results of each possible combination
    
    srand(time(NULL));  // Seed the random number generator with current time
    
    printf("Welcome to the C Dice Roller!\n");
    printf("Enter the number of faces of each die (default 6): ");
    scanf("%d", &faces);
    printf("Enter the number of dice to roll (default 2): ");
    scanf("%d", &num_dice);
    printf("\nRolling %d dice with %d faces each...\n", num_dice, faces);
    
    // Roll the dice and store the results in the array
    for (int i = 0; i < 1000000; i++)
    {
        int roll = 0;
        for (int j = 0; j < num_dice; j++)
        {
            roll += (rand() % faces) + 1;
        }
        results[roll]++;
    }
    
    // Print the results for each possible combination
    printf("\nResults\n-------\n");
    for (int i = num_dice; i <= (num_dice * faces); i++)
    {
        double percent = (double) results[i] / 10000;
        printf("%2d: %9d (%5.2f%%)\n", i, results[i], percent);
    }
    
    return 0;
}