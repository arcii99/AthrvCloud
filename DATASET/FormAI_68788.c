//FormAI DATASET v1.0 Category: Poker Game ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to shuffle an array
void shuffle(int *deck, int n)
{
    for (int i = 0; i < n; i++)
    {
        int j = rand() % n;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to convert card number to card name
char cardName(int card)
{
    switch (card)
    {
        case 1: return 'A';
        case 11: return 'J';
        case 12: return 'Q';
        case 13: return 'K';
        default: return card + '0';
    }
}

int main()
{
    // Initialize the deck and shuffle it
    int deck[52];
    for (int i = 0; i < 52; i++)
    {
        deck[i] = (i % 13) + 1;
    }
    srand(time(NULL));
    shuffle(deck, 52);

    // Deal the cards and print them on the screen
    printf("Dealing the cards...\n\n");
    int player1[5], player2[5];
    for (int i = 0; i < 5; i++)
    {
        player1[i] = deck[i];
        player2[i] = deck[i + 5];
        printf("Player 1 card %d: %c\n", i + 1, cardName(player1[i]));
        printf("Player 2 card %d: %c\n", i + 1, cardName(player2[i]));
    }

    // Determine the winner
    int player1Score = 0, player2Score = 0;
    for (int i = 0; i < 5; i++)
    {
        if (player1[i] == 1)
        {
            player1Score += 14;
        }
        else
        {
            player1Score += player1[i];
        }
        if (player2[i] == 1)
        {
            player2Score += 14;
        }
        else
        {
            player2Score += player2[i];
        }
    }
    printf("\nPlayer 1 score: %d\n", player1Score);
    printf("Player 2 score: %d\n", player2Score);
    if (player1Score > player2Score)
    {
        printf("\nPlayer 1 wins!\n");
    }
    else if (player2Score > player1Score)
    {
        printf("\nPlayer 2 wins!\n");
    }
    else
    {
        printf("\nIt's a tie!\n");
    }

    return 0;
}