//FormAI DATASET v1.0 Category: Poker Game ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Represents a card in a deck
typedef struct {
    int rank;
    int suit;
} Card;

// Represents a hand in poker
typedef struct {
    Card cards[HAND_SIZE];
    int rank;
} Hand;

// Function prototypes
void shuffleDeck(Card *deck);
void dealHand(Card *deck, Hand *hand);
void printHand(Hand *hand);

// Main function
int main() {
    // Initialize deck of cards
    Card deck[DECK_SIZE];
    for(int i = 0; i < DECK_SIZE; i++) {
        deck[i].rank = (i % 13) + 1;
        deck[i].suit = i / 13;
    }

    // Shuffle the deck
    shuffleDeck(deck);

    // Deal a hand
    Hand hand;
    dealHand(deck, &hand);

    // Print the hand
    printHand(&hand);

    return 0;
}

// Shuffles the deck of cards
void shuffleDeck(Card *deck) {
    srand(time(NULL));
    for(int i = 0; i < DECK_SIZE; i++) {
        int j = rand() % DECK_SIZE;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Deals a hand from the deck
void dealHand(Card *deck, Hand *hand) {
    for(int i = 0; i < HAND_SIZE; i++) {
        hand->cards[i] = deck[i];
    }
}

// Prints the hand
void printHand(Hand *hand) {
    printf("Your hand:\n");
    for(int i = 0; i < HAND_SIZE; i++) {
        printf("%d of ", hand->cards[i].rank);
        switch(hand->cards[i].suit) {
            case 0:
                printf("hearts");
                break;
            case 1:
                printf("diamonds");
                break;
            case 2:
                printf("clubs");
                break;
            case 3:
                printf("spades");
                break;
        }
        printf("\n");
    }
}