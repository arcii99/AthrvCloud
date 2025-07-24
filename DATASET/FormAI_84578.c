//FormAI DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Constants
#define NUM_CARDS 52
#define NUM_RANKS 13
#define NUM_SUITS 4
#define HAND_SIZE 5

// Enumeration types
typedef enum { CLUBS, DIAMONDS, HEARTS, SPADES } suit;
typedef enum { ACE, KING, QUEEN, JACK, TEN, NINE, EIGHT, SEVEN, SIX, FIVE, FOUR, THREE, TWO } rank;

// Struct types
typedef struct {
    rank rank;
    suit suit;
} card;

typedef struct {
    card hand[HAND_SIZE];
    int score;
} player;

// Function prototypes
void shuffle_deck(card deck[]);
void deal_cards(card deck[], player players[]);
void calculate_score(player players[]);

/* Main function */
int main(void) {
    srand((unsigned) time(NULL)); // Seed random number generator
    
    card deck[NUM_CARDS]; // Declare and initialize deck of cards
    
    // Initialize deck of cards
    for (int i = 0; i < NUM_RANKS; i++) {
        for (int j = 0; j < NUM_SUITS; j++) {
            deck[NUM_SUITS*i+j].rank = i;
            deck[NUM_SUITS*i+j].suit = j;
        }
    }
    
    shuffle_deck(deck); // Shuffle deck of cards
    
    player players[2]; // Declare players
    
    deal_cards(deck, players); // Deal cards to players
    
    calculate_score(players); // Calculate score of each player
    
    // Print debug information
    printf("Player 1's hand:");
    for (int i = 0; i < HAND_SIZE; i++) {
        printf(" (%d, %d)", players[0].hand[i].rank, players[0].hand[i].suit);
    }
    printf("\n");
    
    printf("Player 2's hand:");
    for (int i = 0; i < HAND_SIZE; i++) {
        printf(" (%d, %d)", players[1].hand[i].rank, players[1].hand[i].suit);
    }
    printf("\n");
    
    printf("Player 1's score: %d\n", players[0].score);
    printf("Player 2's score: %d\n", players[1].score);
    
    return 0;
}

/* Shuffle deck of cards */
void shuffle_deck(card deck[]) {
    for (int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

/* Deal cards to players */
void deal_cards(card deck[], player players[]) {
    for (int i = 0; i < HAND_SIZE; i++) {
        players[0].hand[i] = deck[i];
        players[1].hand[i] = deck[i+HAND_SIZE];
    }
}

/* Calculate score of each player */
void calculate_score(player players[]) {
    for (int i = 0; i < 2; i++) {
        int score = 0;
        for (int j = 0; j < HAND_SIZE; j++) {
            score += players[i].hand[j].rank;
        }
        players[i].score = score;
    }
}