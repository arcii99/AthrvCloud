//FormAI DATASET v1.0 Category: Poker Game ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS_PER_HAND 5
#define NUM_PLAYERS 4
#define DECK_SIZE 52

typedef enum {
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
} Rank;

typedef enum {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
} Suit;

typedef struct {
    Rank rank;
    Suit suit;
} Card;

typedef struct {
    Card hand[CARDS_PER_HAND];
    int score;
} Player;

void shuffle_deck(Card deck[]) {
    int i, j;
    Card temp;
    for (i = 0; i < DECK_SIZE; i++) {
        j = rand() % DECK_SIZE;
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void print_card(Card card) {
    switch (card.rank) {
        case ACE:
            printf("Ace of ");
            break;
        case TWO:
            printf("Two of ");
            break;
        case THREE:
            printf("Three of ");
            break;
        case FOUR:
            printf("Four of ");
            break;
        case FIVE:
            printf("Five of ");
            break;
        case SIX:
            printf("Six of ");
            break;
        case SEVEN:
            printf("Seven of ");
            break;
        case EIGHT:
            printf("Eight of ");
            break;
        case NINE:
            printf("Nine of ");
            break;
        case TEN:
            printf("Ten of ");
            break;
        case JACK:
            printf("Jack of ");
            break;
        case QUEEN:
            printf("Queen of ");
            break;
        case KING:
            printf("King of ");
            break;
    }
    switch (card.suit) {
        case CLUBS:
            printf("Clubs\n");
            break;
        case DIAMONDS:
            printf("Diamonds\n");
            break;
        case HEARTS:
            printf("Hearts\n");
            break;
        case SPADES:
            printf("Spades\n");
            break;
    }
}

int main() {
    Card deck[DECK_SIZE];
    Player players[NUM_PLAYERS];

    srand(time(NULL));

    int i, j, k;
    k = 0;
    for (i = 1; i <= 13; i++) {
        for (j = 0; j < 4; j++) {
            deck[k].rank = i;
            deck[k].suit = j;
            k++;
        }
    }

    shuffle_deck(deck);

    for (i = 0; i < NUM_PLAYERS; i++) {
        for (j = 0; j < CARDS_PER_HAND; j++) {
            players[i].hand[j] = deck[(i * CARDS_PER_HAND) + j];
            print_card(players[i].hand[j]);
        }
    }

    return 0;
}