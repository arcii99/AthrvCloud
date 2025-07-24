//FormAI DATASET v1.0 Category: Dice Roller ; Style: Claude Shannon
#include <stdio.h>  //Header files
#include <stdlib.h> 
#include <time.h> 

int main() {
    int diceRoll;   //Variable declaration
    srand(time(NULL));  //Seed random number generator with time
    diceRoll = rand() % 6 + 1;  //Generate a random number between 1 and 6
    printf("You rolled a %d!\n", diceRoll); //Print the result
    return 0;   //End the program
}