//FormAI DATASET v1.0 Category: Poker Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define NUM_CARDS 52
#define NUM_PLAYERS 4

typedef struct {
    int rank;
    int suit;
} Card;

typedef struct {
    Card cards[5];
    int value;
} Hand;

// Function declarations
void shuffle(Card *deck);
void deal(Card *deck, Hand *hands);
void print_card(Card card);
void print_hand(Hand hand);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Initialize the deck
    Card deck[NUM_CARDS];
    for (int i = 0; i < NUM_SUITS; i++) {
        for (int j = 0; j < NUM_RANKS; j++) {
            deck[(i * NUM_RANKS) + j].rank = j;
            deck[(i * NUM_RANKS) + j].suit = i;
        }
    }

    // Shuffle the deck
    shuffle(deck);

    // Deal the cards
    Hand hands[NUM_PLAYERS];
    deal(deck, hands);

    // Print the hands
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d's hand:\n", i + 1);
        print_hand(hands[i]);
        printf("\n");
    }

    return 0;
}

void shuffle(Card *deck) {
    for (int i = NUM_CARDS - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void deal(Card *deck, Hand *hands) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < NUM_PLAYERS; j++) {
            hands[j].cards[i] = deck[(j * 5) + i];
        }
    }
}

void print_card(Card card) {
    switch (card.rank) {
        case 0:
            printf("Ace");
            break;
        case 10:
            printf("Jack");
            break;
        case 11:
            printf("Queen");
            break;
        case 12:
            printf("King");
            break;
        default:
            printf("%d", card.rank + 1);
            break;
    }

    printf(" of ");

    switch (card.suit) {
        case 0:
            printf("clubs");
            break;
        case 1:
            printf("diamonds");
            break;
        case 2:
            printf("hearts");
            break;
        default:
            printf("spades");
            break;
    }
}

void print_hand(Hand hand) {
    for (int i = 0; i < 5; i++) {
        print_card(hand.cards[i]);
        printf("\n");
    }
}