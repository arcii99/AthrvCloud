//FormAI DATASET v1.0 Category: Dice Roller ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice()
{
    return rand() % 6 + 1;
}

int main()
{
    int dice1, dice2, total;
    char playAgain = 'y';
    srand(time(NULL));

    printf("Welcome to the Dice Roller game!\n");

    while (playAgain == 'y')
    {
        dice1 = rollDice();
        dice2 = rollDice();
        total = dice1 + dice2;

        printf("You rolled a %d and a %d, which has a total of %d.\n", dice1, dice2, total);

        if (total == 7 || total == 11)
            printf("Congratulations! You won!\n");
        else if (total == 2 || total == 3 || total == 12)
            printf("Sorry, you lost!\n");
        else
        {
            printf("You didn't win or lose, so you get to roll again!\n");
            printf("Press any key to roll your dice again.\n");
            scanf(" %c", &playAgain);
        }
    }

    printf("Thanks for playing the Dice Roller game! Goodbye!\n");

    return 0;
}