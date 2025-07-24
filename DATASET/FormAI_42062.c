//FormAI DATASET v1.0 Category: Poker Game ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARDS 52

enum Suit {
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES
};

enum Rank {
    ACE = 1,
    TWO,
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
    KING
};

struct Card {
    enum Suit suit;
    enum Rank rank;
};

struct Hand {
    struct Card cards[5];
};

void shuffle(struct Card *deck) {
    srand(time(NULL)); // Seed the random number generator
    for(int i = 0; i < NUM_CARDS; i++) {
        int j = rand() % NUM_CARDS;
        struct Card temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(struct Card card) {
    switch(card.rank) {
        case ACE:
            printf("A");
            break;
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        case TEN:
            printf("T");
            break;
        case JACK:
            printf("J");
            break;
        case QUEEN:
            printf("Q");
            break;
        case KING:
            printf("K");
            break;
    }

    switch(card.suit) {
        case CLUBS:
            printf("c");
            break;
        case DIAMONDS:
            printf("d");
            break;
        case HEARTS:
            printf("h");
            break;
        case SPADES:
            printf("s");
            break;
    }
}

void printHand(struct Hand *hand) {
    for(int i = 0; i < 5; i++) {
        printCard(hand->cards[i]);
        printf(" ");
    }
    printf("\n");
}

void deal(struct Card *deck, struct Hand *hand) {
    static int cardIndex = 0;
    for(int i = 0; i < 5; i++) {
        hand->cards[i] = deck[cardIndex++];
    }
}

int main() {
    struct Card deck[NUM_CARDS];
    for(int i = 1; i <= 13; i++) {
        deck[i-1].rank = i;
        deck[i-1].suit = CLUBS;
    }
    for(int i = 1; i <= 13; i++) {
        deck[i+12].rank = i;
        deck[i+12].suit = DIAMONDS;
    }
    for(int i = 1; i <= 13; i++) {
        deck[i+25].rank = i;
        deck[i+25].suit = HEARTS;
    }
    for(int i = 1; i <= 13; i++) {
        deck[i+38].rank = i;
        deck[i+38].suit = SPADES;
    }

    shuffle(deck);

    struct Hand playerHand;
    deal(deck, &playerHand);

    printf("Your hand: ");
    printHand(&playerHand);

    return 0;
}