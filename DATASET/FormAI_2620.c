//FormAI DATASET v1.0 Category: Poker Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// global constants
#define N_CARDS 52
#define N_RANKS 13
#define N_SUITS 4

// enumeration constants for card suits and ranks
enum suits { CLUBS, DIAMONDS, HEARTS, SPADES };
enum ranks { ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };

// structure for a card
struct card {
    enum suits suit;
    enum ranks rank;
};

// array of cards
struct card deck[N_CARDS];

// function to initialize the deck of cards
void initialize_deck() {
    int i;
    for (i = 0; i < N_CARDS; i++) {
        deck[i].rank = i % N_RANKS;
        deck[i].suit = i / N_RANKS;
    }
}

// function to shuffle the deck of cards
void shuffle_deck() {
    int i, j;
    struct card temp;
    srand(time(NULL));
    for (i = 0; i < N_CARDS; i++) {
        j = rand() % N_CARDS;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// function to print a card
void print_card(struct card c) {
    char* suits_name[] = { "Clubs", "Diamonds", "Hearts", "Spades" };
    char* ranks_name[] = { "Ace", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };
    printf("%s of %s\n", ranks_name[c.rank], suits_name[c.suit]);
}

// function to print the deck of cards
void print_deck() {
    int i;
    for (i = 0; i < N_CARDS; i++) {
        print_card(deck[i]);
    }
}

// main function
int main() {
    // initialize the deck of cards
    initialize_deck();
    printf("Initial deck:\n");
    print_deck();
    
    // shuffle the deck of cards
    shuffle_deck();
    printf("Shuffled deck:\n");
    print_deck();

    return 0;
}