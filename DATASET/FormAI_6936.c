//FormAI DATASET v1.0 Category: Poker Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define DECK_SIZE 52
#define HAND_SIZE 5

typedef enum {CLUBS, DIAMONDS, HEARTS, SPADES} Suit;
typedef enum {ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING} Rank;

typedef struct Card {
    Suit suit;
    Rank rank;
} Card;

void initializeDeck(Card deck[DECK_SIZE]) {
    int i;
    for (i = 0; i < 13; i++) {
        deck[i].suit = CLUBS;
        deck[i].rank = i;
        deck[13 + i].suit = DIAMONDS;
        deck[13 + i].rank = i;
        deck[26 + i].suit = HEARTS;
        deck[26 + i].rank = i;
        deck[39 + i].suit = SPADES;
        deck[39 + i].rank = i;
    }
}

void shuffleDeck(Card deck[DECK_SIZE]) {
    srand(time(NULL));
    int i, j;
    Card temp;
    for (i = DECK_SIZE - 1; i > 0; i--) {
        j = rand() % (i + 1);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}

void printCard(Card card) {
    switch (card.rank) {
        case ACE:   printf("Ace");
                    break;
        case TWO:   printf("Two");
                    break;
        case THREE: printf("Three");
                    break;
        case FOUR:  printf("Four");
                    break;
        case FIVE:  printf("Five");
                    break;
        case SIX:   printf("Six");
                    break;
        case SEVEN: printf("Seven");
                    break;
        case EIGHT: printf("Eight");
                    break;
        case NINE:  printf("Nine");
                    break;
        case TEN:   printf("Ten");
                    break;
        case JACK:  printf("Jack");
                    break;
        case QUEEN: printf("Queen");
                    break;
        case KING:  printf("King");
                    break;
    }
    
    printf(" of ");
    
    switch (card.suit) {
        case CLUBS:    printf("Clubs");
                        break;
        case DIAMONDS: printf("Diamonds");
                        break;
        case HEARTS:   printf("Hearts");
                        break;
        case SPADES:   printf("Spades");
                        break;
    }
}

void printHand(Card hand[HAND_SIZE]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        printCard(hand[i]);
        printf("\n");
    }
}

int compareCards(const void* a, const void* b) {
    const Card* cardA = (const Card*)a;
    const Card* cardB = (const Card*)b;
    if (cardA->rank < cardB->rank) return -1;
    if (cardA->rank > cardB->rank) return 1;
    if (cardA->suit < cardB->suit) return -1;
    if (cardA->suit > cardB->suit) return 1;
    return 0;
}

bool isFlush(Card hand[HAND_SIZE]) {
    int i;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hand[i].suit != hand[0].suit) {
            return false;
        }
    }
    return true;
}

bool isStraight(Card hand[HAND_SIZE]) {
    qsort(hand, HAND_SIZE, sizeof(Card), compareCards);
    int i;
    for (i = 1; i < HAND_SIZE; i++) {
        if (hand[i].rank != hand[i - 1].rank + 1) {
            return false;
        }
    }
    return true;
}

void dealHand(Card deck[DECK_SIZE], Card hand[HAND_SIZE]) {
    int i;
    for (i = 0; i < HAND_SIZE; i++) {
        hand[i] = deck[i];
    }
}

int main() {
    Card deck[DECK_SIZE];
    initializeDeck(deck);
    shuffleDeck(deck);
    
    Card hand[HAND_SIZE];
    dealHand(deck, hand);
    
    printf("Your hand:\n");
    printHand(hand);
    
    if (isFlush(hand)) {
        printf("Flush!\n");
    } else if (isStraight(hand)) {
        printf("Straight!\n");
    } else {
        printf("Sorry, nothing :(\n");
    }
    
    return 0;
}