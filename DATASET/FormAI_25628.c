//FormAI DATASET v1.0 Category: Dice Roller ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int rollDice();

int main()
{
    int dice1, dice2, total, point=0;
    char choice;

    srand(time(NULL));

    printf("Welcome to the Dice Roller!\n\n");
    printf("Press any key to roll the dice...\n\n");

    getchar();

    dice1 = rollDice();
    dice2 = rollDice();
    total = dice1 + dice2;
    printf("You rolled: %d + %d = %d\n", dice1, dice2, total);

    if(total == 7 || total == 11) // Natural Win
        printf("You win!\n\n");

    else if(total == 2 || total == 3 || total == 12) // Craps
        printf("You Lose!\n\n");

    else // Point established
    {
        point = total;
        printf("Point established: %d\n\n", point);
        printf("Press any key to roll the dice again...\n\n");
        getchar();

        do
        {
            dice1 = rollDice();
            dice2 = rollDice();
            total = dice1 + dice2;
            printf("You rolled: %d + %d = %d\n", dice1, dice2, total);

            if(total == 7) // Lose
            {
                printf("You Lose!\n\n");
                break;
            }

            else if(total == point) // Win
            {
                printf("You Win!\n\n");
                break;
            }

            else // Roll again
                printf("Press any key to roll the dice again...\n\n");
                getchar(); 
        }
        while(total != 7 && total != point);
    }

    printf("Game Over!\n\n");

    return 0;
}

int rollDice()
{
    return rand()%6 + 1;
}