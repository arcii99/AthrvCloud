//FormAI DATASET v1.0 Category: Dice Roller ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int dice;
    char choice;
    srand(time(NULL));
    
    printf("Welcome to the Dice Roller!!!\n");
    
    do{
        printf("\nSelect a number of dice to roll (1-3): ");
        scanf(" %d", &dice);
        while(getchar() != '\n');
        
        switch(dice){
            case 1:
                printf("\nYou rolled a %d!", rand()%6+1);
                break;
            case 2:
                printf("\nYou rolled a %d and a %d!", rand()%6+1, rand()%6+1);
                break;
            case 3:
                printf("\nYou rolled a %d, a %d, and a %d!", rand()%6+1, rand()%6+1, rand()%6+1);
                break;
            default:
                printf("\nInvalid input. Please select 1, 2, or 3 dice to roll.");
                break;
        }
        
        printf("\n\nWould you like to roll again? (y/n): ");
        scanf(" %c", &choice);
        while(getchar() != '\n');
    }while(choice == 'y' || choice == 'Y');
    
    printf("\nThank you for using the Dice Roller!");
    
    return 0;
}