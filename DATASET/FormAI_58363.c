//FormAI DATASET v1.0 Category: Dice Roller ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i, num, roll, faces;
    char choice;
    srand((unsigned)time(NULL)); // Seed for random number generator
    
    printf("Welcome to Dice Roller Program!\n");
    printf("Enter the number of dice you would like to roll: ");
    scanf("%d", &num);
    printf("Enter the number of faces on each die: ");
    scanf("%d", &faces);
    
    printf("\nRolling %d dice with %d faces each...\n\n", num, faces);
    
    for(i = 1; i <= num; i++)
    {
        roll = rand() % faces + 1;
        printf("Dice %d: %d\n", i, roll);
    }
    
    printf("\nWould you like to roll again? (Y/N): ");
    scanf(" %c", &choice);
    
    while(choice == 'Y' || choice == 'y')
    {
        printf("\nEnter the number of dice you would like to roll: ");
        scanf("%d", &num);
        printf("Enter the number of faces on each die: ");
        scanf("%d", &faces);
        
        printf("\nRolling %d dice with %d faces each...\n\n", num, faces);
        
        for(i = 1; i <= num; i++)
        {
            roll = rand() % faces + 1;
            printf("Dice %d: %d\n", i, roll);
        }
        
        printf("\nWould you like to roll again? (Y/N): ");
        scanf(" %c", &choice);
    }
    
    return 0;
}