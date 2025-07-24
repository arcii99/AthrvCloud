//FormAI DATASET v1.0 Category: Dice Roller ; Style: invasive
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    srand(time(NULL));  //generating seed for the random number generator

    char choice;

    do{
        int numOfDice;

        //prompting user input
        printf("Enter the number of dice to roll: ");
        scanf("%d", &numOfDice);

        //checking for invalid input
        while(getchar() != '\n');

        //prompting user input
        printf("Enter the number of sides on each die: ");
        int sides;
        scanf("%d", &sides);

        //checking for invalid input
        while(getchar() != '\n');

        //displaying the roll result for each die
        printf("\n\nRolling..\n\n");

        for(int i=0; i<numOfDice; i++){
            int roll = rand()%sides + 1;
            printf("Die %d: %d\n", i+1, roll);
        }

        //prompting user to continue or exit
        printf("\n\nDo you want to roll again? (Y/N) ");
        scanf("%c", &choice);

        //checking for invalid input
        while(getchar() != '\n');

    }while(choice=='y' || choice=='Y');

    return 0;
}