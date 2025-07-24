//FormAI DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define the deck of cards and its suits
const char *suits[] = {"Spades", "Hearts", "Diamonds", "Clubs"};
const char *cards[] = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

// Function prototypes
void shuffle(int deck[]);
void dealCards(int deck[], int p1_hand[], int p2_hand[]);
void printHand(int hand[]);

int main()
{
    // Seed random number generator
    srand(time(NULL));
    
    // Define the deck and hands of player 1 and player 2
    int deck[52];
    int p1_hand[5] = {0};
    int p2_hand[5] = {0};
    
    // Fill the deck array with values 0-51
    for(int i = 0; i < 52; i++)
    {
        deck[i] = i;
    }
    
    // Shuffle the deck
    shuffle(deck);
    
    // Deal the cards to player 1 and player 2
    dealCards(deck, p1_hand, p2_hand);
    
    // Output the hands to the console
    printf("Player 1's Hand: ");
    printHand(p1_hand);
    printf("Player 2's Hand: ");
    printHand(p2_hand);
    
    return 0;
}

/**
 * Shuffle the deck array using the Fisher-Yates shuffle algorithm
 */
void shuffle(int deck[])
{
    int n = 52;
    while(n > 1)
    {
        int k = rand() % n;
        n--;
        int temp = deck[n];
        deck[n] = deck[k];
        deck[k] = temp;
    }
}

/**
 * Deal the cards to player 1 and player 2 by dividing the shuffled deck
 * into two equal halves
 */
void dealCards(int deck[], int p1_hand[], int p2_hand[])
{
    for(int i = 0; i < 5; i++)
    {
        p1_hand[i] = deck[i];
        p2_hand[i] = deck[i + 5];
    }
}

/**
 * Print out the given hand of cards in a human-readable format
 */
void printHand(int hand[])
{
    for(int i = 0; i < 5; i++)
    {
        int card = hand[i];
        printf("%s of %s", cards[card % 13], suits[card / 13]);
        if(i < 4) printf(", ");
    }
    printf("\n");
}