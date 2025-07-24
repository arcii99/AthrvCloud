//FormAI DATASET v1.0 Category: Dice Roller ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int userChoice, diceResult;
    char answer;
    
    srand(time(NULL)); //Sets the seed for the random number generator
    
    printf("Welcome to the Dice Roller Program!\n");
    do {
        printf("\nPlease choose an option:\n1. Roll dice\n2. Exit\n");
        scanf("%d", &userChoice);
        
        switch (userChoice) {
            case 1: //Rolling the dice
                printf("\nRolling the dice...\n");
                diceResult = rand() % 6 + 1; //Generates a random number between 1 and 6
                printf("The dice shows: %d!\n", diceResult);
                break;
                
            case 2: //Exiting the program
                printf("\nThank you for using the Dice Roller Program! Goodbye!\n");
                exit(0); //Exits the program with code 0, indicating success
                
            default: //Invalid choice
                printf("\nInvalid choice! Please try again.\n");
                break;
        }
        
        printf("\nDo you want to roll the dice again? (Y/N)\n");
        scanf(" %c", &answer);
    } while (answer == 'Y' || answer == 'y');
    
    return 0;
}