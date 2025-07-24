//FormAI DATASET v1.0 Category: Dice Roller ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice(void);
void printResult(int);

int main()
{
    int diceRoll1, diceRoll2, diceSum;

    srand(time(NULL)); //generates a new random seed for each run

    diceRoll1 = rollDice();
    diceRoll2 = rollDice();
    diceSum = diceRoll1 + diceRoll2;

    printf("You rolled a %d and a %d\n", diceRoll1, diceRoll2);
    printResult(diceSum);

    return 0;
}

int rollDice(void)
{
    return (rand() % 6) + 1; //returns a random number between 1 and 6 inclusive
}

void printResult(int diceSum)
{
    switch(diceSum)
    {
        case 2:
            printf("You rolled a snake eyes!\n");
            break;
        case 7:
            printf("You rolled a lucky seven!\n");
            break;
        case 12:
            printf("You rolled boxcars!\n");
            break;
        default:
            printf("Your roll added up to %d\n", diceSum);
            break;
    }
}