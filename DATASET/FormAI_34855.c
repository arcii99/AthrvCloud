//FormAI DATASET v1.0 Category: Poker Game ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4

typedef enum { HEARTS, DIAMONDS, CLUBS, SPADES } suit;

typedef struct
{
    suit s;
    int rank;
} card;

void shuffleCards(card deck[], int n);
void dealCards(card deck[], card hands[][NUM_CARDS / NUM_PLAYERS]);

int main()
{
    card deck[NUM_CARDS], hands[NUM_PLAYERS][NUM_CARDS / NUM_PLAYERS];
    int i, j;

    /* Generate the deck */
    int index = 0;
    for (i = 0; i < NUM_SUITS; i++)
    {
        for (j = 0; j < NUM_RANKS; j++)
        {
            deck[index].s = i;
            deck[index].rank = j;
            index++;
        }
    }

    /* Shuffle the deck */
    srand(time(NULL));
    shuffleCards(deck, NUM_CARDS);

    /* Deal the cards */
    dealCards(deck, hands);

    /* Print the hands */
    for (i = 0; i < NUM_PLAYERS; i++)
    {
        printf("Player %d's hand:\n", i+1);
        for (j = 0; j < NUM_CARDS / NUM_PLAYERS; j++)
        {
            printf("%2d %s\n", hands[i][j].rank + 1, 
                hands[i][j].s == HEARTS ? "Hearts" : 
                hands[i][j].s == DIAMONDS ? "Diamonds" :
                hands[i][j].s == CLUBS ? "Clubs" : "Spades");
        }
        printf("\n");
    }

    return 0;
}

/* Function to shuffle the deck */
void shuffleCards(card deck[], int n)
{
    int i, j;
    card temp;

    for (i = 0; i < n; i++)
    {
        j = rand() % n;

        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Function to deal the cards */
void dealCards(card deck[], card hands[][NUM_CARDS / NUM_PLAYERS])
{
    int i, j, k = 0;

    for (i = 0; i < NUM_CARDS / NUM_PLAYERS; i++)
    {
        for (j = 0; j < NUM_PLAYERS; j++)
        {
            hands[j][i] = deck[k++];
        }
    }
}