//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h> 
#include <stdlib.h> 
#include <time.h> 

int main() 
{
    char choice = 'y'; // initialize choice to roll the dice to "yes"
    do
    {
        int n; 
        printf("Welcome to the Happy Dice Roller!\n");
        printf("How many dice would you like to roll? ");
        scanf("%d", &n);
        
        printf("\nRolling %d dice...\n\n", n);
        
        int sum = 0; // initialize sum of all dice to 0
        srand(time(NULL)); // seed the random number generator with the current time
        
        for(int i = 0; i < n; i++) 
        {
            int roll = rand() % 6 + 1; // roll a dice
            printf("Dice %d: %d\n", i+1, roll);
            sum += roll; // add the roll to the sum of all dice
        }
        
        printf("\nTotal sum of the rolled dice is: %d", sum);
        printf("\n\nWould you like to roll again? (y/n) ");
        scanf(" %c", &choice);
        printf("\n");
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for using the Happy Dice Roller! Goodbye.");
    return 0; 
}