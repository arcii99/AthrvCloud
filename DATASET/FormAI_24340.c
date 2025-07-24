//FormAI DATASET v1.0 Category: Dice Roller ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num_dice, num_sides, num_rolls;

    printf("How many dice? ");
    scanf("%d", &num_dice);

    printf("How many sides? ");
    scanf("%d", &num_sides);

    printf("How many rolls? ");
    scanf("%d", &num_rolls);

    // seed the random number generator
    srand(time(NULL));

    int i, j, total;
    for (i = 1; i <= num_rolls; i++)
    {
        total = 0;
        printf("Roll %d: ", i);

        for (j = 1; j <= num_dice; j++)
        {
            int roll = rand() % num_sides + 1;
            printf("%d ", roll);
            total += roll;
        }

        printf("= %d\n", total);
    }

    return 0;
}