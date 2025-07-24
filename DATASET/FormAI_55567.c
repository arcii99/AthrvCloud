//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to roll the dice
int rollDice()
{
    int randomNum;
    srand(time(NULL)); //seeding the random number generator with the current time
    randomNum = rand() % 6 + 1; //generating random number between 1 and 6
    return randomNum; //returning the result of roll
}

int main()
{
    int numRolls, i, result;

    printf("Welcome to the Dice Roller program!\n\n");

    printf("How many times would you like to roll the dice? ");
    scanf("%d", &numRolls);

    if(numRolls<=0) //invalid input, exiting the program with an error message
    {
        printf("\nInvalid input! Number of rolls should be a non-zero positive integer.\n");
        printf("Exiting program...\n");
        return 0;
    }

    printf("\nAlright! Rolling the dice %d times...\n\n", numRolls);

    for(i=1; i<=numRolls; i++)
    {
        result = rollDice(); //rolling the dice
        printf("Roll %d: %d\n", i, result); //printing the result of the roll
    }

    printf("\nAll rolls complete! Thanks for playing. Goodbye!\n");

    return 0;
}