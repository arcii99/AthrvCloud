//FormAI DATASET v1.0 Category: Poker Game ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define SUIT_SIZE 13
#define HAND_SIZE 2

enum Suit {
    DIAMONDS,
    CLUBS,
    HEARTS,
    SPADES
};

char* suit_to_string(enum Suit suit) {
    switch (suit) {
        case DIAMONDS:
            return "Diamonds";
        case CLUBS:
            return "Clubs";
        case HEARTS:
            return "Hearts";
        case SPADES:
            return "Spades";
    }
}

struct Card {
    enum Suit suit;
    int value;
};

struct Hand {
    struct Card cards[HAND_SIZE];
};

void shuffle_deck(struct Card* deck) {
    for (int i = 0; i < DECK_SIZE; i++) {
        int r = rand() % DECK_SIZE;
        struct Card temp = deck[i];
        deck[i] = deck[r];
        deck[r] = temp;
    }
}

int main() {
    struct Card deck[DECK_SIZE];
    struct Hand player_hand;
    
    // Initialize deck
    int card_counter = 0;
    for (int suit = DIAMONDS; suit <= SPADES; suit++) {
        for (int value = 1; value <= SUIT_SIZE; value++) {
            struct Card card = {suit, value};
            deck[card_counter] = card;
            card_counter++;
        }
    }
    
    // Shuffle deck
    srand(time(NULL));
    shuffle_deck(deck);
    
    // Deal player's hand
    for (int i = 0; i < HAND_SIZE; i++) {
        player_hand.cards[i] = deck[i];
    }
    
    // Print player's hand
    printf("Player's hand:\n");
    for (int i = 0; i < HAND_SIZE; i++) {
        printf("\t%s of value %d\n", suit_to_string(player_hand.cards[i].suit), player_hand.cards[i].value);
    }
    
    return 0;
}