//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // seed random number generator
    srand(time(NULL));

    int sides, rolls, i, sum = 0;

    // prompt user for number of sides on the die
    printf("Enter the number of sides on the die: ");
    scanf("%d", &sides);

    // prompt user for number of rolls
    printf("Enter the number of times to roll the die: ");
    scanf("%d", &rolls);

    // roll the die and output the result
    for (i = 0; i < rolls; i++)
    {
        int result = rand() % sides + 1;
        printf("Roll %d: %d\n", i + 1, result);
        sum += result;
    }

    // output the total sum of all the rolls
    printf("Total: %d\n", sum);

    return 0;
}