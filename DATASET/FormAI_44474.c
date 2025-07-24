//FormAI DATASET v1.0 Category: Poker Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define CARD_SIZE 2
#define MAX_CARDS 5

enum Suit {
    HEARTS,
    CLUBS,
    DIAMONDS,
    SPADES,
};

enum Rank {
    TWO = 2,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
    ACE,
};

typedef struct {
    int rank;
    int suit;
} Card;

char* RANK_MAPPING[] = {
    "0",
    "0",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "T",
    "J",
    "Q",
    "K",
    "A",
};

char* SUIT_MAPPING[] = {
    "H",
    "C",
    "D",
    "S",
};

void print_card(Card card) {
    char str[CARD_SIZE+1];
    sprintf(str, "%s%s", RANK_MAPPING[card.rank], SUIT_MAPPING[card.suit]);
    printf("%s ", str);
}

void print_hand(Card *hand, int size) {
    printf("Your hand: ");
    for (int i = 0; i < size; i++) {
        print_card(hand[i]);
    }
    printf("\n");
}

void shuffle_deck(Card *deck, int size) {
    srand(time(NULL));
    for (int i = size - 1; i >= 1; i--) {
        int j = rand() % (i + 1);
        Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void fill_deck(Card *deck, int size) {
    for (int i = 0; i < size; i++) {
        Card card = {
            .rank = i % 13 + 2,
            .suit = i / 13,
        };
        deck[i] = card;
    }
}

int main() {
    Card deck[DECK_SIZE];
    fill_deck(deck, DECK_SIZE);
    shuffle_deck(deck, DECK_SIZE);
    
    Card hand[MAX_CARDS];
    for (int i = 0; i < MAX_CARDS; i++) {
        hand[i] = deck[i];
    }
    print_hand(hand, MAX_CARDS);

    return 0;
}