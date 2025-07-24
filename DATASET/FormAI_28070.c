//FormAI DATASET v1.0 Category: Poker Game ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(NULL));
    int deck[52];
    
    for(int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }
    for(int i = 51; i > 0; i--)
    {
        int j = rand() % (i+1);
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    int playerHand[5];
    int computerHand[5];
    int playerScore = 0;
    int computerScore = 0;
    
    printf("Welcome to the Poker Game!\n");
    printf("Your hand:\n");
    
    for(int i = 0; i < 5; i++)
    {
        playerHand[i] = deck[i];
        printf("%d ", playerHand[i]);
    }
    
    printf("\nComputer's hand:\n");
    
    for(int i = 5; i < 10; i++)
    {
        computerHand[i-5] = deck[i];
        printf("%d ", computerHand[i-5]);
    }
    
    for(int i = 0; i < 5; i++)
    {
        int playerCardValue = playerHand[i] % 13;
        int computerCardValue = computerHand[i] % 13;
        
        if(playerCardValue > computerCardValue)
        {
            playerScore++;
        }
        else if(computerCardValue > playerCardValue)
        {
            computerScore++;
        }
    }
    
    printf("\n\nYour score: %d\n", playerScore);
    printf("Computer's score: %d\n", computerScore);
    
    if(playerScore > computerScore)
    {
        printf("Congratulations, you won!\n");
    }
    else if(computerScore > playerScore)
    {
        printf("Sorry, the computer won!\n");
    }
    else
    {
        printf("It's a tie!\n");
    }
    
    return 0;
}