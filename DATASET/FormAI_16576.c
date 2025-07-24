//FormAI DATASET v1.0 Category: Dice Roller ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to roll the dice
int rollDice() {
    int dice = rand() % 6 + 1; //Generate random number between 1 and 6
    return dice;
}

int main() {
    srand(time(NULL)); //Seed the random number generator with current time
    int num1, num2;
    char input;

    //Loop until the user chooses to exit
    do {
        printf("Press any key to roll the dice: ");
        scanf(" %c", &input);
        num1 = rollDice();
        num2 = rollDice();

        printf("\nDice one shows: %d", num1);
        printf("\nDice two shows: %d", num2);

        //Check for snake eyes (1,1) or boxcars (6,6)
        if(num1 == 1 && num2 == 1){
            printf("\n\nSnake eyes! Roll again!\n\n");
        }
        else if(num1 == 6 && num2 == 6){
            printf("\n\nBoxcars! Roll again!\n\n");
        }
        else{
            printf("\n\nWould you like to roll again? (Y/N): ");
            scanf(" %c", &input);
        }

    } while(input == 'y' || input == 'Y');

    return 0;
}