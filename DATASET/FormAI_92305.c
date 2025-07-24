//FormAI DATASET v1.0 Category: Poker Game ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DECK_SIZE 52
#define CARDS_IN_HAND 5

typedef enum { 
    HEARTS, 
    DIAMONDS, 
    CLUBS, 
    SPADES
} Suit;

typedef struct {
    int value;
    Suit suit;
} Card;

void print_card(Card c) {
    char s;
    switch (c.suit) {
        case HEARTS: s = 'H'; break;
        case DIAMONDS: s = 'D'; break;
        case CLUBS: s = 'C'; break;
        case SPADES: s = 'S'; break;
    }
    if (c.value > 10) {
        switch (c.value) {
            case 11: printf("J"); break;
            case 12: printf("Q"); break;
            case 13: printf("K"); break;
            case 14: printf("A"); break;
        }
    }
    else {
        printf("%d", c.value);
    }
    printf("%c ", s);
}

void shuffle_deck(Card *deck, int n) {
    srand(time(NULL));
    int i, j;
    Card temp;
    for (i = n-1; i > 0; i--) {
        j = rand() % (i+1);
        temp = deck[j];
        deck[j] = deck[i];
        deck[i] = temp;
    }
}

void deal_hand(Card *deck, Card *hand, int n) {
    int i;
    for (i = 0; i < n; i++) {
        hand[i] = deck[i];
    }
}

int is_flush(Card *hand, int n) {
    Suit s = hand[0].suit;
    int i;
    for (i = 1; i < n; i++) {
        if (hand[i].suit != s) {
            return 0;
        }
    }
    return 1;
}

int is_straight(Card *hand, int n) {
    int i;
    for (i = 0; i < n-1; i++) {
        if (hand[i+1].value != hand[i].value + 1) {
            return 0;
        }
    }
    return 1;
}

int evaluate_hand(Card *hand, int n) {
    int rank = 0;
    if (is_flush(hand, n)) {
        if (is_straight(hand, n)) {
            if (hand[0].value == 10) {
                rank = 9; // royal flush
            }
            else {
                rank = 8; // straight flush
            }
        }
        rank = 5; // flush
    }
    else if (is_straight(hand, n)) {
        rank = 4; // straight
    }
    // add other ranks here
    return rank;
}

int main() {
    Card deck[DECK_SIZE];
    Card hand[CARDS_IN_HAND];
    int i;
    for (i = 0; i < DECK_SIZE; i++) {
        deck[i].value = i % 13 + 2;
        if (i < 13) {
            deck[i].suit = HEARTS;
        }
        else if (i < 26) {
            deck[i].suit = DIAMONDS;
        }
        else if (i < 39) {
            deck[i].suit = CLUBS;
        }
        else {
            deck[i].suit = SPADES;
        }
    }
    shuffle_deck(deck, DECK_SIZE);
    deal_hand(deck, hand, CARDS_IN_HAND);
    for (i = 0; i < CARDS_IN_HAND; i++) {
        print_card(hand[i]);
    }
    printf("\nHand rank: %d\n", evaluate_hand(hand, CARDS_IN_HAND));
    return 0;
}