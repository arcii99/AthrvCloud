//FormAI DATASET v1.0 Category: Dice Roller ; Style: puzzling
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int diceRoll, totalRolls = 0; // Initializing two integer variables, diceRoll and totalRolls, to hold the dice roll value and count of rolls respectively.

    srand(time(0)); // This will seed the random number generator for different sequences of random numbers every time the program runs.
	
    printf("It's a dice roller program! Roll the dice and try your luck! \n"); // Introduction to the dice roller program.
	
    while(1){ // An infinite loop is used here.
        printf("Roll the dice by entering any number from 1-6: ");
        scanf("%d", &diceRoll); // Scanning the user input for the dice roll value.

        if(diceRoll > 6 || diceRoll < 1){ // Checking whether the user input is a valid dice roll or not. In case it is invalid, code will display a message on the console and ask for input again.
            printf("Invalid Dice Roll! Try Again. \n");
            continue; // Continues back to the start of the loop.
        }

        totalRolls++; // Increment the total number of rolls performed by the user.
        printf("The dice rolled a %d \n", diceRoll); // Displays the value of the dice rolled by the user.
		
		if(totalRolls == 10){ // Roll limit of 10 is set for the user.
            printf("\n\nYou have exhausted the number of rolls available. \n\n"); 
            break; // Exiting the infinite loop
        }

        if(diceRoll == 6){ // In case if the dice roll is a 6, code will display a message on the console and user can roll again.
            printf("You got a SIX!!! Roll Again\n");
            continue; // Continues back to the start of the loop.
        }

        printf("You lost the chance to roll again. \n\n"); // In case, the dice roll is not 6, displays this message.
    }

    printf("You rolled the dice %d times \n", totalRolls); // Displays the number of rolls performed by the user.
    printf("Thanks for using the Dice Roller! \n\n");

    return 0;
}