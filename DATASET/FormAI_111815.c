//FormAI DATASET v1.0 Category: Poker Game ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define NUM_PLAYERS 4
#define HAND_SIZE 5

typedef enum {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} SUIT;

typedef enum {
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
    ACE
} RANK;

typedef struct {
    SUIT suit;
    RANK rank;
} CARD;

CARD deck[DECK_SIZE] = {
    {CLUBS, TWO}, {CLUBS, THREE}, {CLUBS, FOUR}, {CLUBS, FIVE}, {CLUBS, SIX},
    {CLUBS, SEVEN}, {CLUBS, EIGHT}, {CLUBS, NINE}, {CLUBS, TEN}, {CLUBS, JACK},
    {CLUBS, QUEEN}, {CLUBS, KING}, {CLUBS, ACE},
    {DIAMONDS, TWO}, {DIAMONDS, THREE}, {DIAMONDS, FOUR}, {DIAMONDS, FIVE}, {DIAMONDS, SIX},
    {DIAMONDS, SEVEN}, {DIAMONDS, EIGHT}, {DIAMONDS, NINE}, {DIAMONDS, TEN}, {DIAMONDS, JACK},
    {DIAMONDS, QUEEN}, {DIAMONDS, KING}, {DIAMONDS, ACE},
    {HEARTS, TWO}, {HEARTS, THREE}, {HEARTS, FOUR}, {HEARTS, FIVE}, {HEARTS, SIX},
    {HEARTS, SEVEN}, {HEARTS, EIGHT}, {HEARTS, NINE}, {HEARTS, TEN}, {HEARTS, JACK},
    {HEARTS, QUEEN}, {HEARTS, KING}, {HEARTS, ACE},
    {SPADES, TWO}, {SPADES, THREE}, {SPADES, FOUR}, {SPADES, FIVE}, {SPADES, SIX},
    {SPADES, SEVEN}, {SPADES, EIGHT}, {SPADES, NINE}, {SPADES, TEN}, {SPADES, JACK},
    {SPADES, QUEEN}, {SPADES, KING}, {SPADES, ACE}
};

CARD deck_copy[DECK_SIZE];

CARD hand[NUM_PLAYERS][HAND_SIZE];

void shuffle_deck(void) {
    srand(time(NULL));
    int i, idx;
    for (i = 0; i < DECK_SIZE; i++) {
        deck_copy[i].suit = deck[i].suit;
        deck_copy[i].rank = deck[i].rank;
    }
    for (i = 0; i < DECK_SIZE; i++) {
        idx = rand() % DECK_SIZE;
        CARD temp = deck_copy[i];
        deck_copy[i] = deck_copy[idx];
        deck_copy[idx] = temp;
    }
}

void deal_cards(void) {
    int i, j;
    for (j = 0; j < HAND_SIZE; j++) {
        for (i = 0; i < NUM_PLAYERS; i++) {
            hand[i][j] = deck_copy[(NUM_PLAYERS * j) + i];
        }
    }
}

void print_card(CARD c) {
    switch (c.rank) {
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
            printf("10");
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
        case ACE:
            printf("A");
            break;
    }
    switch (c.suit) {
        case CLUBS:
            printf("C");
            break;
        case DIAMONDS:
            printf("D");
            break;
        case HEARTS:
            printf("H");
            break;
        case SPADES:
            printf("S");
            break;
    }
}

void print_hand(CARD *hand) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        print_card(hand[i]);
        printf(" ");
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    shuffle_deck();
    deal_cards();
    int i, j;
    for (i = 0; i < NUM_PLAYERS; i++) {
        printf("Player %d: ", i+1);
        print_hand(hand[i]);
    }
    return 0;
}