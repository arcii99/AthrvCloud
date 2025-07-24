//FormAI DATASET v1.0 Category: Dice Roller ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int roll_die()
{
    return rand() % 6 + 1;
}

int main()
{
    srand(time(NULL));
    int num_rolls = 0;
    int sum = 0;
    char choice = 'y';
    
    while (choice == 'y' || choice == 'Y')
    {
        printf("Enter the number of dice you want to roll: ");
        scanf("%d", &num_rolls);
        
        for (int i = 0; i < num_rolls; i++)
        {
            int roll = roll_die();
            printf("Roll %d: %d\n", i+1, roll);
            sum += roll;
        }
        
        printf("Total: %d\n", sum);
        sum = 0;
        
        printf("Do you want to roll again? (y/n) ");
        scanf(" %c", &choice);
    }
    
    printf("Thanks for playing!\n");
    
    return 0;
}