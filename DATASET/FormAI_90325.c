//FormAI DATASET v1.0 Category: Poker Game ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    // Initialize deck of cards
    char *card_types[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    char *card_numbers[13] = {"Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King"};
    int deck[52];
    int c = 0;
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            deck[c] = (j+1) * (i+1);
            c++;
        }
    }
    
    // Shuffle deck
    srand(time(NULL));
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
    
    // Deal cards to players
    int player1[2], player2[2];
    player1[0] = deck[0];
    player1[1] = deck[1];
    player2[0] = deck[2];
    player2[1] = deck[3];
    
    // Print cards
    printf("Player 1: %s of %s, %s of %s\n", card_numbers[(player1[0]-1)%13], card_types[(player1[0]-1)/13], card_numbers[(player1[1]-1)%13], card_types[(player1[1]-1)/13]);
    printf("Player 2: %s of %s, %s of %s\n", card_numbers[(player2[0]-1)%13], card_types[(player2[0]-1)/13], card_numbers[(player2[1]-1)%13], card_types[(player2[1]-1)/13]);
    
    // Evaluate player hands
    int player1_score = player1[0] + player1[1];
    int player2_score = player2[0] + player2[1];
    
    // Print winner
    if (player1_score > player2_score)
    {
        printf("Player 1 wins with a score of %d!\n", player1_score);
    }
    else if (player2_score > player1_score)
    {
        printf("Player 2 wins with a score of %d!\n", player2_score);
    }
    else
    {
        printf("It's a tie!\n");
    }
    
    return 0;
}