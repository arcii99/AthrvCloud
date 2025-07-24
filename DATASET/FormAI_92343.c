//FormAI DATASET v1.0 Category: Poker Game ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function Prototypes
void shuffleDeck(int *deck);
void dealCards(int *deck, int **players, int numPlayers);
void printHand(int *hand);
int evaluateHand(int *hand);

int main()
{
    // Seed random number generator
    srand(time(NULL));

    // Initialize Card Deck
    int deck[52];
    for (int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }

    // Shuffle Card Deck
    shuffleDeck(deck);

    // Welcome Message
    printf("Welcome to the Cheerful C Poker Game!\n");

    // Get Number of Players
    int numPlayers;
    printf("How many players will be playing? (2-6): ");
    scanf("%d", &numPlayers);

    // Initialize players
    int *players[numPlayers];
    for (int i = 0; i < numPlayers; i++)
    {
        players[i] = malloc(5 * sizeof(int));
    }

    // Deal Cards
    dealCards(deck, players, numPlayers);

    // Print Each Player's Hand
    printf("\nEach player's hand:\n");
    for (int i = 0; i < numPlayers; i++)
    {
        printf("Player %d's hand: ", i+1);
        printHand(players[i]);
        printf("\n");
    }

    // Evaluate Each Player's Hand
    int scores[numPlayers];
    for (int i = 0; i < numPlayers; i++)
    {
        scores[i] = evaluateHand(players[i]);
    }

    // Determine Winner
    int maxScore = 0;
    int winner = 0;
    for (int i = 0; i < numPlayers; i++)
    {
        if (scores[i] > maxScore)
        {
            maxScore = scores[i];
            winner = i+1;
        }
    }

    // Print Winner
    printf("Player %d is the winner with a score of %d!\n", winner, maxScore);

    // Free Memory
    for (int i = 0; i < numPlayers; i++)
    {
        free(players[i]);
    }

    return 0;
}

// Function to Shuffle Card Deck
void shuffleDeck(int *deck)
{
    for (int i = 0; i < 52; i++)
    {
        int j = rand() % 52;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to Deal Cards
void dealCards(int *deck, int **players, int numPlayers)
{
    int deckIndex = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < numPlayers; j++)
        {
            players[j][i] = deck[deckIndex];
            deckIndex++;
        }
    }
}

// Function to Print a Player's Hand
void printHand(int *hand)
{
    for (int i = 0; i < 5; i++)
    {
        int cardValue = (hand[i] % 13) + 2;
        char cardSuit;
        switch (hand[i] / 13)
        {
            case 0:
                cardSuit = 'C';
                break;
            case 1:
                cardSuit = 'D';
                break;
            case 2:
                cardSuit = 'H';
                break;
            case 3:
                cardSuit = 'S';
                break;
        }
        printf("%d%c ", cardValue, cardSuit);
    }
}

// Function to Evaluate a Player's Hand
int evaluateHand(int *hand)
{
    // For now, just return a random score
    return rand() % 100;
}