//FormAI DATASET v1.0 Category: Poker Game ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

// Card struct defining the properties of a card: rank and suit
typedef struct Card {
    int rank;
    char suit;
} Card;

// Function to print a card's rank and suit
void print_card(Card card) {
    char* rank_str;
    switch (card.rank) {
        case 1: rank_str = "Ace"; break;
        case 11: rank_str = "Jack"; break;
        case 12: rank_str = "Queen"; break;
        case 13: rank_str = "King"; break;
        default: rank_str = card.rank + '0'; break;
    }
    printf("%s of %c's\n", rank_str, card.suit);
}

// Function to initialize a deck of cards
void init_deck(Card* deck) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int rank = (i % 13) + 1;
        char suit;
        if (i < 13) {
            suit = 'D';
        } else if (i < 26) {
            suit = 'H';
        } else if (i < 39) {
            suit = 'C';
        } else {
            suit = 'S';
        }
        deck[i] = (Card) {rank, suit};
    }
}

// Function to shuffle a deck of cards
void shuffle_deck(Card* deck) {
    srand(time(NULL));
    for (int i = DECK_SIZE - 1; i > 0; i--) {
        int j = rand() % i;
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

// Function to deal a hand of cards from a deck
void deal_hand(Card* deck, Card* hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

// Function to print a hand of cards
void print_hand(Card* hand) {
    for (int i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
    }
}

int main() {
    Card deck[DECK_SIZE];
    init_deck(deck);
    shuffle_deck(deck);

    Card player_hand[HAND_SIZE];
    deal_hand(deck, player_hand);

    printf("Your hand:\n");
    print_hand(player_hand);

    return 0;
}