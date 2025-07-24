//FormAI DATASET v1.0 Category: Dice Roller ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice()
{
    int num;
    num = rand() % 6 + 1;
    return num;
}

int main()
{
    srand(time(NULL));
    int dice1, dice2;
    printf("\nWelcome to the futuristic dice roller.\n");
    printf("Are you ready to roll? Press 1 to continue.\n");
    int start;
    scanf("%d", &start);

    while (start == 1)
    {
        dice1 = rollDice();
        dice2 = rollDice();
        printf("\nYou rolled a %d and a %d\n", dice1, dice2);
        if (dice1 == dice2)
        {
            printf("You got a double!! Roll again!\n");
        }
        else
        {
            printf("Would you like to roll again? Press 1 to continue or any other key to exit\n");
            scanf("%d", &start);
        }
    }

    printf("\nThanks for using the futuristic dice roller. Goodbye!\n");
    return 0;
}