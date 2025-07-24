//FormAI DATASET v1.0 Category: Dice Roller ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, rolls, sum = 0, i;
    srand(time(NULL));  //seed the random number generator

    printf("Enter number of sides on the dice: ");
    scanf("%d", &sides);

    printf("Enter number of rolls: ");
    scanf("%d", &rolls);

    printf("Rolling the %d-sided dice %d times...\n", sides, rolls);

    for(i = 0; i < rolls; i++)
    {
        int roll = rand() % sides + 1;  //generate a random number between 1 and sides
        printf("Roll %d: %d\n", i+1, roll);
        sum += roll;  //add the roll to the sum
    }

    printf("Sum of all rolls: %d\n", sum);

    return 0;
}