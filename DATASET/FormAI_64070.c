//FormAI DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, sides, total = 0;
    char answer;
    
    printf("Welcome to the Dice Roller Program!\n");
    printf("----------------------------------\n");
    
    do
    {
        printf("Enter the number of dice you want to roll: ");
        scanf("%d", &num);
        
        printf("Enter the number of sides on the dice: ");
        scanf("%d", &sides);
        
        printf("\nRolling %d %d-sided dice...\n\n", num, sides);
        
        srand(time(NULL));
        
        for(int i = 0; i < num; i++)
        {
            int roll = rand() % sides + 1;
            printf("Dice %d: %d\n", i+1, roll);
            total += roll;
        }
        
        printf("\nTotal: %d\n", total);
        
        printf("\nWould you like to roll again? (Y/N) ");
        scanf(" %c", &answer);
        
        total = 0;
        
    } while(answer == 'Y' || answer == 'y');
    
    printf("\nThank you for using the Dice Roller Program!\n");
    printf("-------------------------------------------\n\n");
    
    return 0;
}