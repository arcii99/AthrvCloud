//FormAI DATASET v1.0 Category: Table Game ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// function prototypes
void initializeTable(int table[], int numSeats, int playerCount);
void printTable(int table[], int numSeats);
void shuffleCards(int deck[], int numCards);
void dealCards(int deck[], int numCards, int hand[], int handSize);
void printHand(int hand[], int handSize);
int countPoints(int hand[], int handSize);
int getNextPlayer(int current, int numPlayers);

int main()
{
    // game parameters
    const int NUM_SEATS = 6;
    const int NUM_PLAYERS = 4;
    const int NUM_CARDS = 52;
    const int HAND_SIZE = 2;

    // initialize table and deck
    int table[NUM_SEATS];
    int deck[NUM_CARDS];
    initializeTable(table, NUM_SEATS, NUM_PLAYERS);
    shuffleCards(deck, NUM_CARDS);

    // play game
    int roundCount = 0;
    int dealer = 0;
    while (roundCount < 3) {
        // deal cards
        int hands[NUM_PLAYERS][HAND_SIZE];
        for (int i = 0; i < NUM_PLAYERS; i++) {
            dealCards(deck, NUM_CARDS, hands[i], HAND_SIZE);
        }

        // print hands and points
        printf("Round %d: Dealer=%d\n", roundCount+1, dealer);
        for (int i = 0; i < NUM_PLAYERS; i++) {
            printf("Player %d hand: ", i+1);
            printHand(hands[i], HAND_SIZE);
            int points = countPoints(hands[i], HAND_SIZE);
            printf("points=%d\n", points);
        }

        // update dealer and round count
        dealer = getNextPlayer(dealer, NUM_PLAYERS);
        roundCount++;
    }

    return 0;
}

// initialize table with players
void initializeTable(int table[], int numSeats, int playerCount)
{
    srand(time(NULL)); // seed random number generator
    for (int i = 0; i < numSeats; i++) {
        table[i] = (i < playerCount) ? rand() % 1000 + 1 : 0; // assign random player ID to seat or zero if empty
    }
}

// print table state
void printTable(int table[], int numSeats)
{
    printf("Table: ");
    for (int i = 0; i < numSeats; i++) {
        printf("%d ", table[i]);
    }
    printf("\n");
}

// shuffle deck of cards
void shuffleCards(int deck[], int numCards)
{
    srand(time(NULL)); // seed random number generator
    for (int i = 0; i < numCards; i++) {
        deck[i] = i+1; // assign card number
    }
    for (int i = 0; i < numCards; i++) {
        // swap current card with random card
        int j = rand() % numCards;
        int temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// deal cards from deck to hand
void dealCards(int deck[], int numCards, int hand[], int handSize)
{
    static int dealtCount = 0; // static variable to track how many cards have been dealt
    for (int i = 0; i < handSize; i++) {
        hand[i] = deck[dealtCount++];
    }
}

// print hand of cards
void printHand(int hand[], int handSize)
{
    for (int i = 0; i < handSize; i++) {
        printf("%d ", hand[i]);
    }
}

// count total points in hand of cards
int countPoints(int hand[], int handSize)
{
    int sum = 0;
    for (int i = 0; i < handSize; i++) {
        int card = hand[i];
        int rank = (card - 1) % 13 + 1;
        sum += (rank > 10) ? 10 : rank;
    }
    return sum;
}

// get next player's index in circular seating arrangement
int getNextPlayer(int current, int numPlayers)
{
    return (current + 1) % numPlayers;
}