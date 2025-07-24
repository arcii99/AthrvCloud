//FormAI DATASET v1.0 Category: Dice Roller ; Style: Sherlock Holmes
//The game of chance can sometimes lead to a mystery. Let's roll the dice and see what fate has in store for us.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int die1, die2, sum = 0;
    srand(time(NULL)); //Seed the random number generator
    
    printf("Welcome to the Dice Game!\n");
    printf("Press enter to begin.\n");
    getchar(); //Wait for the user to press enter
    
    die1 = (rand() % 6) + 1; //Roll the first die
    printf("You rolled a %d.\n", die1);
    
    die2 = (rand() % 6) + 1; //Roll the second die
    printf("You rolled a %d.\n", die2);
    
    sum = die1 + die2; //Calculate the sum of the dice
    
    if (sum == 7) {
        printf("Congratulations, you won!\n");
    } else {
        printf("Sorry, you lost. Better luck next time!\n");
    }
    
    return 0;
}