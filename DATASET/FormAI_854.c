//FormAI DATASET v1.0 Category: Table Game ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int playerScore = 0, computerScore = 0, currentPlayer = 1, diceValue = 0;
    char hold;
    srand(time(0)); //seed the random number generator with current time
    
    printf("\t\t Welcome to C Table Game!\n");
    printf("----------------------------------------------\n");
    printf("\tRules:\n");
    printf("\t1. You and the computer will take alternate turns.\n");
    printf("\t2. On your turn, you will roll a dice. The value of the dice will be added to your score.\n");
    printf("\t3. If you roll a 1, your score for that turn is zero and your turn ends.\n");
    printf("\t4. You can choose to hold your score any time you like.\n");
    printf("\t5. The first player to reach 50 points wins!\n");
    printf("----------------------------------------------\n\n");
    
    while(playerScore < 50 && computerScore < 50)
    {
        printf("Player Score: %d \t Computer Score: %d\n", playerScore, computerScore);
        
        //player's turn
        if(currentPlayer == 1)
        {
            printf("\nPlayer's turn.\n");
            printf("Press any key to roll the dice...");
            fflush(stdin);
            scanf("%c", &hold); //waiting for a key press
            diceValue = (rand() % 6) + 1; //generating random value between 1 to 6
            printf("You rolled a %d.\n", diceValue);
            
            if(diceValue == 1)
            {
                printf("Your turn ends with a score of zero.\n");
                currentPlayer = 2; //switching turn to computer
                continue;
            }
            playerScore += diceValue; //adding dice value to player's score
            
            printf("Do you want to hold? (Y/N): ");
            fflush(stdin);
            scanf(" %c", &hold);
            if(hold == 'Y' || hold == 'y')
            {
                printf("You held your score of %d.\n", playerScore);
                currentPlayer = 2; //switching turn to computer
            }
        }
        //computer's turn
        else
        {
            printf("\nComputer's turn.\n");
            diceValue = (rand() % 6) + 1;
            printf("Computer rolled a %d.\n", diceValue);
            
            if(diceValue == 1)
            {
                printf("Computer's turn ends with a score of zero.\n");
                currentPlayer = 1; //switching turn to player
                continue;
            }
            computerScore += diceValue;
            
            if(computerScore >= 50)
                break;
            
            if(computerScore >= 30 || (playerScore - computerScore) >= 20)
            {
                printf("Computer held its score of %d.\n", computerScore);
                currentPlayer = 1; //switching turn to player
            }
            else
                printf("Computer continues its turn.\n");
        }
    }
    
    printf("\nFinal Scores:\n");
    printf("Player Score: %d \t Computer Score: %d\n", playerScore, computerScore);
    
    if(playerScore >= 50)
        printf("\nCongratulations!! You won the game.\n");
    else
        printf("\nSorry, You lost the game. Better luck next time.\n");
    
    return 0;
}