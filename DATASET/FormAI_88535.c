//FormAI DATASET v1.0 Category: Table Game ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function to generate random number between 1 to 6
int rollDice()
{
    return rand() % 6 + 1;
}
 
int main()
{
    int player1Position = 1, player2Position = 1;
    srand(time(NULL));
    
    while(player1Position < 100 && player2Position < 100)
    {
        int player1Dice = rollDice();
        int player2Dice = rollDice();
        
        printf("\nPlayer 1 rolled a %d and moved %d positions", player1Dice, player1Dice);
        player1Position += player1Dice;
        if(player1Position == 10)
        {
            player1Position = 50;
            printf("\nPlayer 1 climbed a ladder to position 50");
        }
        else if(player1Position == 20)
        {
            player1Position = 30;
            printf("\nPlayer 1 was caught by a snake and moved back to position 30");
        }
        else if(player1Position == 60)
        {
            player1Position = 85;
            printf("\nPlayer 1 climbed a ladder to position 85");
        }
        else if(player1Position == 70)
        {
            player1Position = 55;
            printf("\nPlayer 1 was caught by a snake and moved back to position 55");
        }
        else if(player1Position == 100)
        {
            printf("\nPlayer 1 reached the final position and won the game!!");
            break;
        }
        
        printf("\nPlayer 2 rolled a %d and moved %d positions", player2Dice, player2Dice);
        player2Position += player2Dice;
        if(player2Position == 10)
        {
            player2Position = 50;
            printf("\nPlayer 2 climbed a ladder to position 50");
        }
        else if(player2Position == 20)
        {
            player2Position = 30;
            printf("\nPlayer 2 was caught by a snake and moved back to position 30");
        }
        else if(player2Position == 60)
        {
            player2Position = 85;
            printf("\nPlayer 2 climbed a ladder to position 85");
        }
        else if(player2Position == 70)
        {
            player2Position = 55;
            printf("\nPlayer 2 was caught by a snake and moved back to position 55");
        }
        else if(player2Position == 100)
        {
            printf("\nPlayer 2 reached the final position and won the game!!");
            break;
        }
    }
    
    return 0;
}