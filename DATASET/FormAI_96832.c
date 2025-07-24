//FormAI DATASET v1.0 Category: Dice Roller ; Style: grateful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int sides, rolls, i, sum=0, num;
    
    printf("Welcome to the Dice Roller program!\n\n");
    printf("How many sides does your dice have? ");
    scanf("%d", &sides);
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &rolls);
    
    printf("\nRolling...\n");
    
    // Set the seed for the random number generator
    srand(time(NULL));
    
    for(i=0; i<rolls; i++)
    {
        // Generate a random number between 1 and the number of sides on the dice
        num = rand() % sides + 1;
        printf("Roll %d: %d\n", i+1, num);
        sum += num;
    }
    
    printf("\nTotal: %d\n", sum);
    printf("Average roll: %.2f\n", (float)sum/rolls);
    
    return 0;
}