//FormAI DATASET v1.0 Category: Dice Roller ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() 
{
    printf("Welcome to the Dice Roller program! Press Enter to roll the dice! Enter X to exit: ");
    char input = getchar();
    
    while(input != 'X') // loop until user enters 'X'
    {
        if(input == '\n') // if user pressed Enter, roll the dice
        {
            srand(time(NULL)); // generate a seed for the random number generator
            int roll = rand() % 6 + 1; // generate a random number between 1 and 6
            
            printf("You rolled a: ");
            
            switch(roll) // print out the result of the roll
            {
                case 1:
                    printf(" _______\n|       |\n|   *   |\n|       |\n|_______|\n");
                    break;
                case 2:
                    printf(" _______\n|       |\n| *   * |\n|       |\n|_______|\n");
                    break;
                case 3:
                    printf(" _______\n| *     |\n|   *   |\n|     * |\n|_______|\n");
                    break;
                case 4:
                    printf(" _______\n| *   * |\n|       |\n| *   * |\n|_______|\n");
                    break;
                case 5:
                    printf(" _______\n| *   * |\n|   *   |\n| *   * |\n|_______|\n");
                    break;
                case 6:
                    printf(" _______\n| *   * |\n| *   * |\n| *   * |\n|_______|\n");
                    break;
            }
        }
        
        input = getchar(); // get the user's input again
    }
    
    printf("Thanks for using the Dice Roller program! Goodbye!");
    return 0;
}