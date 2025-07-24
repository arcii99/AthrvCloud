//FormAI DATASET v1.0 Category: Poker Game ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define CARDS 52
#define FACES 13
#define HAND 5
#define DECKS 2

typedef struct {
    int face;
    int suit;
} Card;

void fillDeck(Card* const deck);
void shuffleDeck(Card* const deck);

int main() {
    Card deck[CARDS * DECKS];
    fillDeck(deck);
    shuffleDeck(deck);
    Card hand[HAND];
    int i, j;
    for(i = 0; i < HAND; ++i) {
        hand[i] = deck[i];
    }
    printf("Your Hand:\n");
    for(i = 0; i < HAND; ++i) {
        printf("%d%c\n", hand[i].face < 11 ? hand[i].face : hand[i].face == 11 ? 'J' : hand[i].face == 12 ? 'Q' : hand[i].face == 13 ? 'K' : 'A', hand[i].suit == 0 ? 'H' : hand[i].suit == 1 ? 'D' : hand[i].suit == 2 ? 'C' : 'S');
    }

    int pair = 0;
    int three = 0;
    int four = 0;
    int flush = 1;
    int straight = 1;

    for(i = 0; i < HAND - 1; ++i) {
        if(hand[i].face == hand[i+1].face) {
            if(i == 2) {
                three = 1;
            }
            else if(i == 1) {
                pair++;
            }
            else if(i == 0) {
                if(hand[i+2].face == hand[i+3].face) {
                    four = 1;
                }
                else {
                    pair++;
                }
            }
        }
        if(hand[i].suit != hand[i+1].suit) {
            flush = 0;
        }
        if(hand[i].face + 1 != hand[i+1].face) {
            straight = 0;
        }
    }

    if(pair == 1 && three == 1) {
        printf("Full house!\n");
    }
    else if(four == 1) {
        printf("Four of a kind!\n");
    }
    else if(three == 1) {
        printf("Three of a kind!\n");
    }
    else if(pair == 2) {
        printf("Two pair!\n");
    }
    else if(pair == 1) {
        printf("One pair!\n");
    }
    else if(flush == 1) {
        printf("Flush!\n");
    }
    else if(straight == 1) {
        printf("Straight!\n");
    }
    else {
        printf("High card!\n");
    }

    return 0;
}

void fillDeck(Card* const deck) {
    int i;
    for(i = 0; i < CARDS * DECKS; ++i) {
        deck[i].face = i % FACES + 2;
        deck[i].suit = i / FACES;
    }
}

void shuffleDeck(Card* const deck) {
    int i, j;
    Card temp;
    for(i = 0; i < CARDS * DECKS; ++i) {
        j = rand() % (CARDS * DECKS);
        temp = deck[i];
        deck[i] = deck[j];
        deck[j] = temp;
    }
}