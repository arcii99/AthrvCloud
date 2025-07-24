//FormAI DATASET v1.0 Category: Poker Game ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the deck of cards
char *deck[] = {"Ace of Hearts","2 of Hearts","3 of Hearts","4 of Hearts","5 of Hearts",
                "6 of Hearts","7 of Hearts","8 of Hearts","9 of Hearts","10 of Hearts",
                "Jack of Hearts","Queen of Hearts","King of Hearts",
                "Ace of Clubs","2 of Clubs","3 of Clubs","4 of Clubs","5 of Clubs",
                "6 of Clubs","7 of Clubs","8 of Clubs","9 of Clubs","10 of Clubs",
                "Jack of Clubs","Queen of Clubs","King of Clubs",
                "Ace of Diamonds","2 of Diamonds","3 of Diamonds","4 of Diamonds","5 of Diamonds",
                "6 of Diamonds","7 of Diamonds","8 of Diamonds","9 of Diamonds","10 of Diamonds",
                "Jack of Diamonds","Queen of Diamonds","King of Diamonds",
                "Ace of Spades","2 of Spades","3 of Spades","4 of Spades","5 of Spades",
                "6 of Spades","7 of Spades","8 of Spades","9 of Spades","10 of Spades",
                "Jack of Spades","Queen of Spades","King of Spades"};

// Function to shuffle the deck of cards
void shuffleDeck(char *deck[], int deckSize)
{
    srand(time(0));
    for (int i = 0; i < deckSize; i++)
    {
        int randomIndex = rand() % deckSize;
        char *temp = deck[i];
        deck[i] = deck[randomIndex];
        deck[randomIndex] = temp;
    }
}

// Function to deal cards to players
void dealCards(char *deck[], int playerCount, int handSize)
{
    for(int i=0;i<handSize;i++)
    {
        for(int j=0;j<playerCount;j++)
        {
            printf("Player %d was dealt: %s\n", j+1, deck[(i*playerCount)+j]);
        }
    }
}

int main()
{
    const int playerCount = 3;  // Number of players
    const int handSize = 5;     // Size of each player's hand
    const int deckSize = 52;    // Number of cards in the deck

    // Shuffle the deck
    shuffleDeck(deck, deckSize);

    // Deal cards to players
    dealCards(deck, playerCount, handSize);

    return 0;
}