//FormAI DATASET v1.0 Category: Dice Roller ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice()
{
    return rand() % 6 + 1; // returns a random number between 1 and 6
}

int main()
{
    srand(time(NULL)); // this line seeds the random number generator with the current time

    int numRolls;
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls);

    int rolls[numRolls]; // create an array to store all the rolls

    for (int i = 0; i < numRolls; i++) {
        rolls[i] = rollDice(); // store each roll in the array
    }

    // print out all the rolls in the array
    for (int i = 0; i < numRolls; i++) {
        printf("Roll %d: %d\n", i+1, rolls[i]);
    }

    return 0;
}