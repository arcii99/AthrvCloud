//FormAI DATASET v1.0 Category: Funny ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    
    // Welcome user!
    printf("Welcome to the Fantastic Dice Simulator!\n");
    
    // Ask the user to input how many rolls they want
    int n;
    printf("\nHow many times would you like to roll the dice? Please enter a number between 1 and 10.\n");
    scanf("%d", &n);
    
    // Check if the input is valid
    while (n < 1 || n > 10)
    {
        printf("Invalid input! Please enter a number between 1 and 10.\n");
        scanf("%d", &n);
    }
    
    // Simulate the rolls
    int i;
    printf("\nRolling the dice %d times...\n\n", n);
    for (i = 0; i < n; i++)
    {
        // Generate a random number between 1 and 6
        int r = rand() % 6 + 1;
        
        // Output the result to the user
        printf("Roll %d: %d\n", i+1, r);
    }
    
    // Thank the user for using the program
    printf("\nThank you for using the Fantastic Dice Simulator! Goodbye!\n");
    
    return 0;
}