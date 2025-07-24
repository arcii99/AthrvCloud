//FormAI DATASET v1.0 Category: Poker Game ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constants
#define DECK_SIZE 52
#define NUM_CARDS 5
#define NUM_PLAYERS 3

// Define card structure
struct Card
{
    int number;
    char suit;
};

// Declare functions
void shuffleDeck(struct Card deck[]);
void dealCards(struct Card deck[], struct Card players[][NUM_CARDS]);

int main()
{
    // Declare variables
    struct Card deck[DECK_SIZE];
    struct Card players[NUM_PLAYERS][NUM_CARDS];

    // Initialize deck
    for (int i = 0; i < DECK_SIZE; i++)
    {
        deck[i].number = i % 13 + 1;
        if (i < 13)
        {
            deck[i].suit = 'H';
        }
        else if (i < 26)
        {
            deck[i].suit = 'S';
        }
        else if (i < 39)
        {
            deck[i].suit = 'D';
        }
        else
        {
            deck[i].suit = 'C';
        }
    }

    // Shuffle deck
    shuffleDeck(deck);

    // Deal cards to players
    dealCards(deck, players);

    // Print players' hands
    for (int i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Player %d's hand:\n", i+1);
        for (int j = 0; j < NUM_CARDS; j++)
        {
            printf("%d%c ", players[i][j].number, players[i][j].suit);
        }
        printf("\n");
    }

    return 0;
}

// Function to shuffle deck of cards
void shuffleDeck(struct Card deck[])
{
    srand(time(NULL));
    for (int i = 0; i < DECK_SIZE; i++)
    {
        int j = rand() % DECK_SIZE;
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal cards to players
void dealCards(struct Card deck[], struct Card players[][NUM_CARDS])
{
    int card_index = 0;
    for (int i = 0; i < NUM_CARDS; i++)
    {
        for (int j = 0; j < NUM_PLAYERS; j++)
        {
            players[j][i] = deck[card_index];
            card_index++;
        }
    }
}