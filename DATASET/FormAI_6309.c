//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int dice;
    char c;
    srand(time(0)); // Seed the random number generator with the current time
    
    printf("Welcome to the dice roller!\n\n");
    
    do {
        printf("How many dice would you like to roll (1-3)? ");
        scanf("%d", &dice);
        
        if (dice < 1 || dice > 3) {
            printf("Invalid input! Please enter a number between 1 and 3.\n\n");
            continue;
        }
        
        printf("\nYou are rolling %d dice...\n\n", dice);
        
        int total = 0;
        for (int i = 0; i < dice; i++) {
            int roll = rand() % 6 + 1; // Generate a random number between 1 and 6 (inclusive)
            total += roll;
            printf("Dice %d: %d\n", i+1, roll);
        }
        
        printf("\nTotal: %d\n", total);
        
        printf("\nWould you like to roll again? (y/n) ");
        scanf(" %c", &c); // Note the space before %c to consume the previous newline character
        printf("\n");
        
    } while (c == 'y' || c == 'Y');
    
    printf("Thanks for rolling with us!\n");
    
    return 0;
}