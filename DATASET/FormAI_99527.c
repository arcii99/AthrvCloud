//FormAI DATASET v1.0 Category: Dice Roller ; Style: funny
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    int i, num, roll_again;
    char choice;

    srand(time(NULL)); //Seed the random number generator with current time

    printf("\n########################################");
    printf("\n# Welcome to the Fun Dice Rolling Game! #");
    printf("\n########################################\n");

    do{
        printf("\nEnter the number of dice you want to roll: ");
        scanf("%d", &num);

        printf("\nRolling the dice...");

        for(i=0; i<num; i++){
            printf("\nDice %d: %d", i+1, (rand()%6)+1);
        }

        printf("\n\nDo you want to roll again?(y/n): ");
        scanf(" %c", &choice);

        if(choice=='y')
            roll_again = 1;
        else if(choice=='n')
            roll_again=0;
        else{
            printf("\nPlease enter a valid choice!\n");
            roll_again=1;
        }

    }while(roll_again);

    printf("\nThanks for playing! Hope you had a fun time.\n\n");

    return 0;
}