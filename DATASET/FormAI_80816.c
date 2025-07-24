//FormAI DATASET v1.0 Category: Dice Roller ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int i, j, min, max, num;

    srand(time(NULL));  //Seed the random number generator

    printf("Enter the minimum value of the dice: ");
    scanf("%d", &min);

    printf("Enter the maximum value of the dice: ");
    scanf("%d", &max);

    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &num);

    printf("\nThe result of rolling the dice %d times between %d and %d is:\n\n", num, min, max);

    for (i = 1; i <= num; i++)
    {
        printf("Roll %d: ", i);

        j = (rand() % (max - min + 1)) + min;

        printf("%d\n", j);
    }

    return 0;
}