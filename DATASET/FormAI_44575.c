//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int totalDice, numSides, rollCount, sum = 0;
    
    printf("Welcome to the Medieval Dice Roller!\n");
    printf("Enter the total number of dice you want: ");
    scanf("%d", &totalDice);
    printf("Enter the number of sides each dice should have: ");
    scanf("%d", &numSides);
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &rollCount);
    
    srand(time(NULL));
    
    for(int i = 0; i < rollCount; i++)
    {
        printf("\nRoll %d:\n", i+1);
        for(int j = 0; j < totalDice; j++)
        {
            int roll = rand() % numSides + 1;
            printf("Dice %d: %d\n", j+1, roll);
            sum += roll;
        }
        printf("Total: %d\n", sum);
        if(sum == totalDice * numSides)
        {
            printf("Congratulations, you rolled a perfect score!\n");
        }
        else if(sum == totalDice)
        {
            printf("Bad luck, you rolled the lowest possible score.\n");
        }
        else if(sum == totalDice * numSides - totalDice + 1)
        {
            printf("Oh no, you rolled the worst possible score!\n");
        }
        sum = 0;
    }
    printf("\nThanks for playing!\n");
    return 0;
}